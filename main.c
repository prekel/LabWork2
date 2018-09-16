#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "../LabWork2.Lib/functions.h"
#include "options.h"
#include "commands.h"

//int lang = 0;

struct resistarray resist;

int main(int argc, char *argv[]) {
	if (argc == 1 && strcmp(argv[0], "-en") == 0) lang = LANGUAGE_ENGLISH;

	int n;
	char output[100];

	char string_command[MAX_STRING_LENGTH];
	char **split_command;

	printf("Введите \"help\" для справки, \"help <имя_команды>\" для подробного описания команды\n");
	printf("Enter \"help\" for help, \"help <сmd_name>\" for detailed info about command\n");

	while (true) {
		printf("> ");
		input_line(string_command);
		if (strcmp(string_command, "\n") == 0) continue;
		int count = split(string_command, ' ', &split_command);
		// help
		if (strcmp(split_command[0], commands[0].name) == 0) {
			if (count == 1) help_void();
			else help(split_command[1]);
		}
		// setsize
		if (strcmp(split_command[0], commands[1].name) == 0) {
			if (count == 1) {
				printf("%s\n", errormessages.value_not_entered[lang]);
				continue;
			}
			int size;
			int code = sscanf(split_command[1], "%d", &size);
			if (code == 0 || !checkerN(size)) {
				printf("%s\n", errormessages.invalid_natural_value[lang]);
				continue;
			}
			setsize(&resist, size);
		}
		// fillmanual
		if (strcmp(split_command[0], commands[2].name) == 0) {
			if (count == 1) {
				fillmanual_void(&resist);
			} else {
				int n1 = count - 1;
				if (n1 > resist.n) {
					printf("%s\n", errormessages.too_much[lang]);
					continue;
				}
				if (n1 < resist.n) {
					printf("%s\n", errormessages.too_few[lang]);
					continue;
				}
				fillmanual(&resist, split_command, 1);
			}
		}
		// calculateresist
		if (strcmp(split_command[0], commands[4].name) == 0) {
			if (resist.isFilled == false || resist.isSized == false) {
				printf("%s\n", errormessages.not_sized_or_not_filled[lang]);
			}
			if (!resist.isCalculated) {
				calculateresist(&resist);
			}
			printresist(&resist);
		}
		// switchlang
		if (strcmp(split_command[0], commands[6].name) == 0) {
			lang = 1 - lang;
		}
		// exit
		if (strcmp(split_command[0], commands[7].name) == 0) {
			return 0;
		}
	}
//	n = cycle_input_int("N: ", checkerN);
//
//	double *resist = (double *) malloc(n * sizeof(double));
//	for (int i = 0; i < n; i++) {
//		sprintf(output, "R n%d: ", i + 1);
//		resist[i] = cycle_input_double(output, checkerResist);
//	}
//
//	printf("R serial:   %15.6lf\n", serial_resist(n, resist));
//	printf("R parallel: %15.6lf\n", parallel_resist(n, resist));
//	fflush(stdout);
//	free(resist);
	//}

	return 0;
}