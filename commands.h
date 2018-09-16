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