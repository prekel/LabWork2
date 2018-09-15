#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "../LabWork2.Lib/functions.h"

bool checkerN(int n)
{
	if (n <= 0) return false;
	return true;
}

bool checkerResist(double n)
{
	if (n <= 0) return false;
	return true;
}

int cycle_input_int(char *output, bool(*checker)(int))
{
	int n;
	char string_number[100];
	while (1) {
		printf("%s", output);
		scanf("%s", string_number);
		int code = sscanf(string_number, "%d", &n);
		if (!checker(n)) continue;
		if (code > 0) break;
	}
	return n;
}

double cycle_input_double(char *output, bool(*checker)(double))
{
	double n;
	char string_number[100];
	while (1) {
		printf("%s", output);
		scanf("%s", string_number);
		int code = sscanf(string_number, "%lf", &n);
		if (!checker(n)) continue;
		if (code > 0) break;
	}
	return n;
}

int main() {
	int n;
	char output[100];
	n = cycle_input_int("N: ", checkerN);

	double *resist = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		sprintf(output, "R n%d: ", i + 1);
		resist[i] = cycle_input_double(output, checkerResist);
	}

	printf("R serial:   %15.6lf\n", serial_resist(n, resist));
	printf("R parallel: %15.6lf\n", parallel_resist(n, resist));
	fflush(stdout);
	free(resist);

	return 0;
}