#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "../LabWork2.Lib/functions.h"

#define MAX_STRING_LENGTH 100
#define COMMANDS_COUNT 8

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

struct command {
	char *name, *description_ru, *description_en;
};

int main() {
	int n;
	char output[100];

	struct command commands[COMMANDS_COUNT] = {
			{"help",            "Вывод справки",                           "Print help"},
			{"setsize",         "Установка размера массива",               "Set array size"},
			{"fillmanual",      "Установка значений вручную через пробел", ""},
			{"fillrandom",      "4",                                       ""},
			{"calculateresist", "5",                                       ""},
			{"print",           "6",                                       ""},
			{"switchlang",      "7",                                       ""},
			{"exit",            "Выход из программы",                      ""},
	};

	char string_command[MAX_STRING_LENGTH];
	printf("Введите help для справки\n");
	while (true) {
		printf("> ");
		scanf("%s", string_command);
		if (strcmp(string_command, commands[0].name) == 0) {
			for (int i = 0; i < COMMANDS_COUNT; i++) {
				printf("%s - %s\n", commands[i].name, commands[i].description_ru);
			}
		}
		if (strcmp(string_command, commands[7].name) == 0) {
			return 0;
		}
	}
	n = cycle_input_int("N: ", checkerN);

	double *resist = (double *) malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		sprintf(output, "R n%d: ", i + 1);
		resist[i] = cycle_input_double(output, checkerResist);
	}

	printf("R serial:   %15.6lf\n", serial_resist(n, resist));
	printf("R parallel: %15.6lf\n", parallel_resist(n, resist));
	fflush(stdout);
	free(resist);
	//}

	return 0;
}