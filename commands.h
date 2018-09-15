#pragma once

#include "macro.h"

struct command {
	char *name;
	char *description[2];
	char *info[2];
};
struct command commands[COMMANDS_COUNT];

void help_void(int lang);
void help(char *cmd, int lang);