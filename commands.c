#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "../LabWork2.Lib/functions.h"
#include "commands.h"
#include "options.h"
#include "messages.h"
#include "input.h"

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
				{"Заполняет случайными значениями от min до max, использование: fillrandom <min> <max>\nmin и max - натуральные числа\n",
						"Fills with random values from min to max, usage: fillrandom <min> <max>\nmin and max are natural numbers\n"}},

		{"calculateresist", {"Вычислить сопротивление",          "Calculate resistance"},
				{"Вычисляет сопротивление для последовательного и параллельного соеденения, значения массива должны быть введены\n",
						"Calculates the resistance for serial and parallel connections, array values must be entered\n"}},

		{"print",           {"Печать массива",                   "Print array"},
				{"Выводит массив\n",
						"Displays an array\n"}},

		{"switchlang",      {"Switch language to English",       "Переключить язык на русский"},
				{"Переключает язык на английский\n",
						"Switches language to Russian\n"}},

		{"exit",            {"Выход из программы",               "Exiting the program"},
				{"Завершает программу\n",
						"Ends the program\n"}},
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

void print(struct resistarray *resist) {
	for (int i = 0; i < resist->n; i++) {
		printf("%15.6lf\n", resist->values[i]);
	}
}