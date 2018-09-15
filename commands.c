#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "commands.h"
#include "macro.h"

struct command commands[COMMANDS_COUNT] = {
		{"help",            {"Вывод справки",                    "Print help"},
				{"Без аргумента: Выводит описание всех команд\nС аргументом (help <имя_команды>): Выводит подробное описание команды\n",
						"Without argument: Print all commands description\nWith argument (help <cmd_name>): Print detailed info about command]\n"}},

		{"setsize",         {"Установка размера массива",        "Set array size"},
				{"11",
						"12"}},

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

		{"switchlang",      {"Switch language to english",       "Переключить язык на русский"},
				{"61",
						"62"}},

		{"exit",            {"Выход из программы",               "Exiting the program"},
				{"71",
						"72"}},
};

void help_void(int lang) {
	for (int i = 0; i < COMMANDS_COUNT; i++) {
		printf("%s - %s\n", commands[i].name, commands[i].description[lang]);
	}
}

char *cmd_not_found[2] = {"Команда не найдена", "Command not found"};

void help(char *cmd, int lang) {
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
