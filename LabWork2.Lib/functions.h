#ifndef LABWORK2_LIB_FUNCTIONS_H
#define LABWORK2_LIB_FUNCTIONS_H

#include <stdbool.h>

double serial_resist(int n, const double a[]);

double parallel_resist(int n, const double a[]);

bool checkerN(int n);

bool checkerResist(double n);

int split(const char *str, char c, char ***arr);

int randominterval(int min, int max);

#endif