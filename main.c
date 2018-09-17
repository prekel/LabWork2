#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../LabWork2.Lib/functions.h"
#include "options.h"
#include "commands.h"
#include "messages.h"
#include "input.h"

//int lang = 0;

int main(int argc, char *argv[]) {
	srand(time(NULL));
	if (argc == 1 && strcmp(argv[0], "-en") == 0) lang = LANGUAGE_ENGLISH;

	struct resistarray resist;

	int n;
	char output[MAX_STRING_LENGTH];

	char string_command[MAX_STRING_LENGTH];
	char **split_command;

	printf("%s", messages.start[LANGUAGE_RUSSIAN]);
	printf("%s", messages.start[LANGUAGE_ENGLISH]);

	while (true) {
		printf("> ");
		input_line(string_command);
		int count = split(string_command, ' ', &split_command);

			// Enter
		if (strcmp(string_command, "\0") == 0) {
			continue;
		}
			// help
		else if (strcmp(split_command[0], commands[0].name) == 0) {
			if (count == 1) help_void();
			else help(split_command[1]);
		}
			// setsize
		else if (strcmp(split_command[0], commands[1].name) == 0) {
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
		else if (strcmp(split_command[0], commands[2].name) == 0) {
			if (!resist.isSized) {
				printf("%s\n", errormessages.not_sized[lang]);
				continue;
			}
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
			// fillrandom
		else if (strcmp(split_command[0], commands[3].name) == 0) {
			if (!resist.isSized) {
				printf("%s\n", errormessages.not_sized[lang]);
				continue;
			}
			if (count < 3) {
				printf("%s\n", errormessages.too_few[lang]);
				continue;
			}
			if (count > 3) {
				printf("%s\n", errormessages.too_much[lang]);
				continue;
			}
			int min, max;
			int code1 = sscanf(split_command[1], "%d", &min);
			int code2 = sscanf(split_command[2], "%d", &max);
			if (code1 == 0 || code2 == 0 || !checkerN(min) || !checkerN(max) || min > max) {
				printf("%s\n", errormessages.invalid_natural_value[lang]);
				continue;
			}
			fillrandom(&resist, min, max);
		}
			// changevalue
		else if (strcmp(split_command[0], commands[4].name) == 0) {
			if (!resist.isFilled || !resist.isSized) {
				printf("%s\n", errormessages.not_sized_or_not_filled[lang]);
				continue;
			}
			if (count < 3) {
				printf("%s\n", errormessages.too_few[lang]);
				continue;
			}
			if (count > 3) {
				printf("%s\n", errormessages.too_much[lang]);
				continue;
			}
			int index;
			double val;
			int code1 = sscanf(split_command[1], "%d", &index);
			int code2 = sscanf(split_command[2], "%lf", &val);
			if (code1 == 0 || code2 == 0 || index < 0 || index >= resist.n || !checkerResist(val)) {
				printf("%s\n", errormessages.invalid_values[lang]);
				continue;
			}
			changevalue(&resist, index, val);
		}
			// calculateresist
		else if (strcmp(split_command[0], commands[5].name) == 0) {
			if (!resist.isFilled || !resist.isSized) {
				printf("%s\n", errormessages.not_sized_or_not_filled[lang]);
				continue;
			}
			if (!resist.isCalculated) {
				calculateresist(&resist);
			}
			printresist(&resist);
		}
			// print
		else if (strcmp(split_command[0], commands[6].name) == 0) {
			if (!resist.isFilled || !resist.isSized) {
				printf("%s\n", errormessages.not_sized_or_not_filled[lang]);
				continue;
			}
			print(&resist);
		}
			// switchlang
		else if (strcmp(split_command[0], commands[7].name) == 0) {
			lang = 1 - lang;
		}
			// exit
		else if (strcmp(split_command[0], commands[8].name) == 0) {
			free(resist.values);
			return 0;
		} else {
			printf("%s\n", errormessages.cmd_not_found[lang]);
		}

		for (int j = 0; j < count; j++) {
			free(split_command[j]);
		}
	}

	//free(resist.values);
	//return 0;
}