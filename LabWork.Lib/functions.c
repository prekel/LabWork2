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