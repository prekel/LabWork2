#ifndef COMMANDS_H
#define COMMANDS_H

#include "options.h"

struct command {
	char *name;
	char *description[2];
	char *info[2];
};
struct command commands[COMMANDS_COUNT];

struct resistarray {
	int n;
	double *values;
};

void help_void();
void help(char *cmd);

void setsize(struct resistarray *resist, int size);


void fillmanual(struct resistarray *resist, char **arrstr, int firstindex);

#endif