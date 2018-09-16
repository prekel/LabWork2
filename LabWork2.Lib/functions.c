#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

double serial_resist(int n, const double a[]) {
	double sum = 0;
	for (int i = 0; i < n; i++) sum += a[i];
	return sum;
}

double parallel_resist(int n, const double a[]) {
	double prod = 1;
	for (int i = 0; i < n; i++) prod *= a[i];
	double sum = 0;
	for (int i = 0; i < n; i++) sum += prod / a[i];
	return prod / sum;
}

bool checkerN(int n) {
	if (n <= 0) return false;
	return true;
}

bool checkerResist(double n) {
	if (n <= 0) return false;
	return true;
}

int split(const char *str, char c, char ***arr) {
	int count = 1;
	int token_len = 1;
	int i = 0;
	char *p;
	char *t;

	p = str;
	while (*p != '\0') {
		if (*p == c)
			count++;
		p++;
	}

	*arr = (char **) malloc(sizeof(char *) * count);
	//if (*arr == NULL)
	//	exit(1);

	p = str;
	while (*p != '\0') {
		if (*p == c) {
			(*arr)[i] = (char *) malloc(sizeof(char) * token_len);
			//if ((*arr)[i] == NULL)
			//	exit(1);

			token_len = 0;
			i++;
		}
		p++;
		token_len++;
	}
	(*arr)[i] = (char *) malloc(sizeof(char) * token_len);
	//if ((*arr)[i] == NULL)
	//	exit(1);

	i = 0;
	p = str;
	t = ((*arr)[i]);
	while (*p != '\0') {
		if (*p != c && *p != '\0') {
			*t = *p;
			t++;
		} else {
			*t = '\0';
			i++;
			t = ((*arr)[i]);
		}
		p++;
	}

	return count;
}

int randominterval(int min, int max) {
	return (rand() % (max - min)) + min;
}