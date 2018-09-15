#pragma once

#include <stdbool.h>

double serial_resist(int n, const double a[]);
double parallel_resist(int n, const double a[]);

bool checkerN(int n);
bool checkerResist(double n);

int split(const char *str, char c, char ***arr);