#ifndef LABWORK2_MESSAGES_H
#define LABWORK2_MESSAGES_H

struct errmessages {
	char *cmd_not_found[2];
	char *invalid_values[2];
	char *invalid_natural_value[2];
	char *value_not_entered[2];
	char *too_much[2];
	char *too_few[2];
	char *not_sized_or_not_filled[2];
	char *not_sized[2];
};
struct errmessages errormessages;
struct mssages {
	char *enter_value_number[2];
	char *parallel_resist[2];
	char *serial_resist[2];
};
struct mssages messages;

#endif //LABWORK2_MESSAGES_H
