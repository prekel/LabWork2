#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "../LabWork2.Lib/functions.h"
#include "commands.h"
#include "options.h"

struct command commands[COMMANDS_COUNT] = {
		{"help",            {"Вывод справки",                    "Print help"},
				{"Без аргумента: Выводит описание всех команд\nС аргументом (help <имя_команды>): Выводит подробное описание команды\n",
						"Without argument: Print all commands description\nWith argument (help <cmd_name>): Print detailed info about command\n"}},

		{"setsize",         {"Установка размера массива",        "Set array size"},
				{"Устанавливает размер массива, использование: setsize <array_size>\nДопустимы только натуральные числа\n",
						"Sets size of array, usage: setsize <array_size>\nOnly natural numbers are allowed\n"}},

		{"fillmanual",      {"Ввод значений вручную",            "Entering values manually"},
				{"Без аргумента: Начинает считывание значений массива, каждый считывается с новой строки через enter\nС аргументом (fillmanual <значения_через_пробел>): Считывает значения массива используя пробел как разделитель\nДопустимые значения: Рациональное число большее нуля\n",
						"Without argument: Begins reading the values of the array, each read from a new line via enter\nWith argument (help <cmd_name>): Reads the values of the array using a space as a separator\nValid values: Rational number greater than zero\n"}},

		{"fillrandom",      {"Заполнение случайными значениями", "Filling with random values"},
				{"31",
						"32"}},

		{"calculateresist", {"Вычислить сопротивление",          "Calculate resistance"},
				{"Вычисляет сопротивление для последовательного и параллельного соеденения, значения массива должны быть введены\n",
						"Calculates the resistance for serial and parallel connections, array values must be entered\n"}},

		{"print",           {"Печать массива",                   "Print array"},
				{"51",
						"52"}},

		{"switchlang",      {"Switch language to English",       "Переключить язык на русский"},
				{"Переключает язык на английский\n",
						"Switches language to Russian\n"}},

		{"exit",            {"Выход из программы",               "Exiting the program"},
				{"Завершает программу\n",
						"Ends the program\n"}},
};

struct errmessages errormessages = {
		{"Команда не найдена",             "Command not found"},
		{"Введено неверное значение(-ия)", "Invalid value(-s) entered"},
		{"Введено неверное значение",      "Invalid value entered"},
		{"Значение не введено",            "Value not entered"},
		{"Введено слишком много значений", "Too many values entered"},
		{"Введено слишком мало значений",  "Too few values entered"},
		{"Значения массива не определены", "Values not entered"}
};

struct mssages messages = {
		{"Введите элемент №",                                    "Enter element #"},
		{"Общее сопротивление при последовательном соединении:", "Total resistance with serial connection:  "},
		{"Общее сопротивление при параллельном соединении:    ", "Total resistance with parallel connection:"},
};

void help_void() {
	for (int i = 0; i < COMMANDS_COUNT; i++) {
		printf("%s - %s\n", commands[i].name, commands[i].description[lang]);
	}
}

void help(char *cmd) {
	bool find = false;
	for (int i = 0; i < COMMANDS_COUNT; i++) {
		if (strcmp(cmd, commands[i].name) == 0) {
			find = true;
			printf("%s", commands[i].info[lang]);
		}
	}
	if (find == false) {
		printf("%s", errormessages.cmd_not_found[lang]);
	}
}

void setsize(struct resistarray *resist, int size) {
	resist->n = size;
	resist->values = (double *) malloc(size * sizeof(double));
	resist->isSized = true;
	resist->isCalculated = false;
}

int input_line(char *str) {
	fgets(str, MAX_STRING_LENGTH, stdin);
	int size = strlen(str);
	str[strlen(str) - 1] = '\0';
	return size;
}

int cycle_input_int(char *output, bool(*checker)(int)) {
	int n;
	char string_number[100];
	while (true) {
		printf("%s", output);
		//scanf("%s", string_number);
		input_line(string_number);
		int code = sscanf(string_number, "%d", &n);
		if (!checker(n)) continue;
		if (code > 0) break;
	}
	return n;
}

double cycle_input_double(char *output, bool(*checker)(double)) {
	double n;
	char string_number[100];
	while (true) {
		printf("%s", output);
		//scanf("%s", string_number);
		input_line(string_number);
		int code = sscanf(string_number, "%lf", &n);
		if (!checker(n)) continue;
		if (code > 0) break;
	}
	return n;
}

void fillmanual(struct resistarray *resist, char **arrstr, int firstindex) {
	int code;
	for (int i = 0; i < resist->n; i++) {
		if (!sscanf(arrstr[i + firstindex], "%lf", &resist->values[i]))
			printf("%s\n", errormessages.invalid_values[lang]);
	}
	resist->isFilled = true;
	resist->isCalculated = false;
}

void fillmanual_void(struct resistarray *resist) {
	char output[MAX_STRING_LENGTH];
	for (int i = 0; i < resist->n; i++) {
		//if (lang == LANGUAGE_RUSSIAN) sprintf(output, "Введите элемент №%d: ", i + 1);
		//else sprintf(output, "Enter element #%d: ", i + 1);
		sprintf(output, "%s%d: ", messages.enter_value_number[lang], i + 1);
		resist->values[i] = cycle_input_double(output, checkerResist);
	}
	resist->isFilled = true;
	resist->isCalculated = false;
}

void calculateresist(struct resistarray *resist) {
	resist->parallel = parallel_resist(resist->n, resist->values);
	resist->serial = serial_resist(resist->n, resist->values);
	resist->isCalculated = true;
}

void printresist(struct resistarray *resist) {
	printf("%s%15.6lf\n", messages.serial_resist[lang], resist->serial);
	printf("%s%15.6lf\n", messages.parallel_resist[lang], resist->parallel);
}