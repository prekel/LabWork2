#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "../LabWork2.Lib/functions.h"
#include "macro.h"
#include "commands.h"

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

int input_line(char *str) {
	fgets(str, MAX_STRING_LENGTH, stdin);
	int size = strlen(str);
	str[strlen(str) - 1] = '\0';
	return size;
}

int lang = 0;

struct resistarray resist;

int main(int argc, char *argv[]) {
	if (argc == 1 && strcmp(argv[0], "-en") == 0) lang = 1;

	int n;
	char output[100];

	char string_command[MAX_STRING_LENGTH];
	char **split_command;

	printf("Введите \"help\" для справки, \"help <имя_команды>\" для подробного описания команды\n");
	printf("Enter \"help\" for help, \"help <сmd_name>\" for detailed info about command\n");

	while (true) {
		printf("> ");
		input_line(string_command);
		int count = split(string_command, ' ', &split_command);
		// help
		if (strcmp(split_command[0], commands[0].name) == 0) {
			if (count == 1) help_void(lang);
			else help(split_command[1], lang);
		}
		// setsize
		if (strcmp(split_command[0], commands[1].name) == 0) {
			if (count == 1) continue;
			int size;
			int code = sscanf(split_command[1], "%d", &size);
			if (code == 0 || !checkerN(size)) continue;
			setsize(&resist, size);
		}
		// switchlang
		if (strcmp(string_command, commands[6].name) == 0) {
			lang = 1 - lang;
		}
		// exit
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