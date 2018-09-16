#ifndef COMMANDS_H
#define COMMANDS_H

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
};
struct errmessages errormessages;

struct resistarray {
	int n;
	double *values;
};

void help_void();
void help(char *cmd);

void setsize(struct resistarray *resist, int size);


void fillmanual(struct resistarray *resist, char **arrstr, int firstindex);

void fillmanual_void(struct resistarray *resist);

#endif