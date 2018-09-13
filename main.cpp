#include <stdio.h>
#include "../LabWork2.Lib/functions.h"

int main() {
	int n;
	printf("N: ");
	scanf("%d", &n);
	char string_number[100];
	double resist[1000];
	for (int i = 0; i < n; i++) {
		while (1) {
			printf("R n%d: ", i + 1);
			scanf("%s", string_number);
			int code = sscanf(string_number, "%lf", &resist[i]);
			if (resist[i] == 0) continue;
			if (code > 0) break;
		};
	}

	printf("R serial:   %15.6lf\n", serial_resist(n, resist));
	printf("R parallel: %15.6lf\n", parallel_resist(n, resist));
	fflush(stdout);

	return 0;
}