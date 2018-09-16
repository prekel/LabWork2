#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
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
				{"21",
						"22"}},

		{"fillrandom",      {"Заполнение случайными значениями", "Filling with random values"},
				{"31",
						"32"}},

		{"calculateresist", {"Вычислить сопротивление",          "Calculate resistance"},
				{"41",
						"42"}},

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

void help_void() {
	for (int i = 0; i < COMMANDS_COUNT; i++) {
		printf("%s - %s\n", commands[i].name, commands[i].description[lang]);
	}
}

char *cmd_not_found[2] = {"Команда не найдена", "Command not found"};

void help(char *cmd) {
	bool find = false;
	for (int i = 0; i < COMMANDS_COUNT; i++) {
		if (strcmp(cmd, commands[i].name) == 0) {
			find = true;
			printf("%s", commands[i].info[lang]);
		}
	}
	if (find == false) {
		printf("%s", cmd_not_found[lang]);
	}
}

void setsize(struct resistarray *resist, int size) {
	resist->n = size;
	resist->values = (double *) malloc(size * sizeof(double));
}


int cycle_input_int(char *output, bool(*checker)(int)) {
	int n;
	char string_number[100];
	while (1) {
		printf("%s", output);
		scanf("%s", string_number);
		int code = sscanf(string_number, "%d", &n);
		if (!checker(n)) continue;
		if (code > 0) break;
	}
	return n;
}

double cycle_input_double(char *output, bool(*checker)(double)) {
	double n;
	char string_number[100];
	while (1) {
		printf("%s", output);
		scanf("%s", string_number);
		int code = sscanf(string_number, "%lf", &n);
		if (!checker(n)) continue;
		if (code > 0) break;
	}
	return n;
}

char *invalid_values[2] = {"Введено неверное значение(-ия)", "Invalid value(-s) entered"};

void fillmanual(struct resistarray *resist, char **arrstr, int firstindex)
{
	int code;
	for (int i = 0; i < resist->n; i++) {
		if (!sscanf(arrstr[i + firstindex], "%lf", &resist->values[i]))
			printf("%s\n", invalid_values[lang]);
	}
}