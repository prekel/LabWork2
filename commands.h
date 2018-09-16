#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdbool.h>

#include "options.h"

struct command {
	char *name;
	char *description[2];
	char *info[2];
};
struct command commands[COMMANDS_COUNT];

struct errmessages {
	char *cmd_not_found[2];
	char *invalid_values[2];
	char *invalid_natural_value[2];
	char *value_not_entered[2];
	char *too_much[2];
	char *too_few[2];
	char *not_sized_or_not_filled[2];
};
struct errmessages errormessages;

struct mssages {
	char *enter_value_number[2];
	char *parallel_resist[2];
	char *serial_resist[2];
};
struct mssages messages;

struct resistarray {
	int n;
	double *values;
	bool isSized;
	bool isFilled;
	bool isCalculated;
	double serial;
	double parallel;
};

void help_void();
void help(char *cmd);

void setsize(struct resistarray *resist, int size);

int input_line(char *str);

void fillmanual(struct resistarray *resist, char **arrstr, int firstindex);

void fillmanual_void(struct resistarray *resist);

void calculateresist(struct resistarray *resist);
void printresist(struct resistarray *resist);

#endif