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
		{"help",            {"����� �������",                    "Print help"},
				{"��� ���������: ������� �������� ���� ������\n� ���������� (help <���_�������>): ������� ��������� �������� �������\n",
						"Without argument: Print all commands description\nWith argument (help <cmd_name>): Print detailed info about command\n"}},

		{"setsize",         {"��������� ������� �������",        "Set array size"},
				{"������������� ������ �������, �������������: setsize <array_size>\n��������� ������ ����������� �����\n",
						"Sets size of array, usage: setsize <array_size>\nOnly natural numbers are allowed\n"}},

		{"fillmanual",      {"���� �������� �������",            "Entering values manually"},
				{"��� ���������: �������� ���������� �������� �������, ������ ����������� � ����� ������ ����� enter\n� ���������� (fillmanual <��������_�����_������>): ��������� �������� ������� ��������� ������ ��� �����������\n���������� ��������: ������������ ����� ������� ����\n",
						"Without argument: Begins reading the values of the array, each read from a new line via enter\nWith argument (help <cmd_name>): Reads the values of the array using a space as a separator\nValid values: Real number greater than zero\n"}},

		{"fillrandom",      {"���������� ���������� ����������", "Filling with random values"},
				{"��������� ���������� ���������� �� min �� max, �������������: fillrandom <min> <max>\nmin � max - ����������� �����, min < max\n",
						"Fills with random values from min to max, usage: fillrandom <min> <max>\nmin and max are natural numbers, min < max\n"}},

		{"changevalue",     {"�������� ��������",                "Change Value"},
				{"������ ��������, �������������: changevalue <�����> <��������>\n����� - ����������� �����, �������� - ������������ ������ ����\n",
						"Changes the value, usage: changevalue <index> <value>\nIndex - natural number, value - real number"}},

		{"calculateresist", {"��������� �������������",          "Calculate resistance"},
				{"��������� ������������� ��� ����������������� � ������������� ����������, �������� ������� ������ ���� �������\n",
						"Calculates the resistance for serial and parallel connections, array values must be entered\n"}},

		{"print",           {"������ �������",                   "Print array"},
				{"������� ������\n",
						"Displays an array\n"}},

		{"switchlang",      {"Switch language to English",       "����������� ���� �� �������"},
				{"����������� ���� �� ����������\n",
						"Switches language to Russian\n"}},

		{"exit",            {"����� �� ���������",               "Exiting the program"},
				{"��������� ���������\n",
						"Ends the program\n"}}
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
	if (resist->isSized) {
		free(resist->values);
	}
	resist->n = size;
	resist->values = (double *) malloc(size * sizeof(double));
	resist->isSized = true;
	resist->isFilled = false;
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
		//if (lang == LANGUAGE_RUSSIAN) sprintf(output, "������� ������� �%d: ", i + 1);
		//else sprintf(output, "Enter element #%d: ", i + 1);
		sprintf(output, "%s%d: ", messages.enter_value_number[lang], i + 1);
		resist->values[i] = cycle_input_double(output, checkerResist);
	}
	resist->isFilled = true;
	resist->isCalculated = false;
}

void fillrandom(struct resistarray *resist, int min, int max) {
	for (int i = 0; i < resist->n; i++) {
		resist->values[i] = randominterval(min, max);
	}
	resist->isFilled = true;
	resist->isCalculated = false;
}

void changevalue(struct resistarray *resist, int index, double value) {
	resist->values[index] = value;
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