#pragma once

#include "macro.h"

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
struct resistarray resist;

void help_void(int lang);
void help(char *cmd, int lang);

void setsize(struct resistarray *resist, int size);