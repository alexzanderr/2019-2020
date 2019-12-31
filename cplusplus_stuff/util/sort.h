#pragma once

void QuickSort(int *vector, int left, int right) {
	int aux;
	int i = left;
	int j = right;
	int mid = vector[(left + right) / 2];
	// partition
	while (i <= j) {
		while (vector[i] < mid) {
			i++;
		}
		while (vector[j] > mid) {
			j--;
		}
		if (i <= j) {
			aux = vector[i];
			vector[i] = vector[j];
			vector[j] = aux;
			i++;
			j--;
		}
	}
	// recursion
	if (left < j) {
		QuickSort(vector, left, j);
	}
	if (i < right) {
		QuickSort(vector, i, right);
	}
}