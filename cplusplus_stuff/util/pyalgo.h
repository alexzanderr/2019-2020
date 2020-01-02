#pragma once

#include <iostream>
#include <cmath>
#include "builtins.py.h"
#include "pylist.h"

using namespace std;
// from util


double RealFromTwoIntNumbers(const int &x, const int &y) {
    double ycopy = y;
    int digits = TotalDigits(y);
    double power = 1;
    while (digits) {
        power *= 10;
        digits--;
    }
    ycopy = ycopy / power;
    return x + ycopy;
}

bool BisectYear(const int &year) {
    if (year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)) {
        return true;
    }
    return false;
}

int gcdr(int x, int y) {
    if (x == y) {
        return x;
    }
    if (x > y) {
        return gcdr(x - y, y);
    }
    else {
        return gcdr(x, y - x);
    }
}

int gcd(const int &x, const int &y) {
    int cx = x;
    int cy = y;
    while (cx != cy) {
        if (cx > cy) {
            cx -= cy;
        }
        else {
            cy -= cx;
        }
    }
    return cx;
}

int DigitSum(const int &number) {
    int *array = IterableFromInt(number);
    const int result = sum(array);
    return result;
}

int NumberOfDigits(const int &number) {
    int *array = IterableFromInt(number);
    const int size = len(array);
    return size;
}

int BinarySearch(const int *arr, const int &element) {
    int start = 0;
    int stop = len(arr) - 1;
    while (start <= stop) {
        int mij = (start + stop) / 2;
        if (element == arr[mij]) {
            return mij;
        }                               
        else if (element < arr[mij]) {
            stop = mij - 1;
        }
        else {
            start = mij + 1;
        }
    }
    return -1;
}

int BinarySearch(const int *arr, int start, int stop, const int &element) {
    while (start <= stop) {
        int mij = (start + stop) / 2;
        if (element == arr[mij]) {
            return mij;
        }                               
        else if (element < arr[mij]) {
            stop = mij - 1;
        }
        else {
            start = mij + 1;
        }
    }
    return -1;
}
        
void FiboInterval(const int &start, const int &stop) {
    int f1 = 0;
    int f2 = 0;
    int fnext = 1;  
    for(size_t counter = start; counter < stop; counter++) {
        while (fnext < counter) {
            f1 = f2;
            f2 = fnext;
            fnext = f1 + f2;
        }
        if (fnext == counter) {
            cout << counter << " ";
        }
    }
}

void AddHoursAndMinutes(const int &h, const int &m, 
                        const int &hplus, const int &mplus) {
    int remainder = -1;
    int total_hrs = h + hplus;
    int total_mins = m + mplus;
    if (total_mins >= 60) {
        remainder = total_mins / 60;
        total_hrs += remainder;
        total_mins -= remainder * 60;
    } 
    if(total_hrs > 23) {
        remainder = total_hrs / 24;
        total_hrs -= remainder * 24;
    }
    cout << total_hrs << ":" << total_mins << endl;
}

void AddMinutes(const int &h, const int &m, const int &mplus) {
    int remainder = -1;
    int total_hrs = h;
    int total_mins = m + mplus;
    if (total_mins >= 60) {
        remainder = total_mins / 60;
        total_hrs += remainder;
        total_mins -= remainder * 60;
    } 
    if(total_hrs > 23) {
        remainder = total_hrs / 24;
        total_hrs -= remainder * 24;
    }
    cout << total_hrs << ":" << total_mins << endl;
}

int PrimDiv(const int *arr, const int &left, const int &right) {
    if (left == right) {
        return 1;
    }
    else {
        const int mid = (left + right) >> 1;
        if (PrimDiv(arr, left, mid) and PrimDiv(arr, mid + 1, right) and 
            arr[mid] <= arr[mid + 1]) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

int** MatrixUpDownPlus(const int &dim) {
    int **matrix = new int*[dim];
    for(size_t iter = 0; iter < dim; iter++) {
        matrix[iter] = new int[dim];
    }
    for(size_t iter = 0; iter < dim; iter++) {
        matrix[iter][0] = iter + 1;
        matrix[dim - 1][iter] = dim;
    }
    for(size_t iter = 1; iter < dim; iter++) {
        for(size_t jiter = 0; jiter < dim - 1; jiter++) {
            matrix[jiter][iter] = matrix[jiter][iter - 1] + 
                                  matrix[jiter + 1][iter - 1];
        }
    }
    return matrix;
}


bool IsDescending(const int *arr) {
    const int size = len(arr);
    for(size_t iter = 1; iter < size; iter++) {
        if (arr[iter - 1] > arr[iter]) {
            return false;
        }
    }
    return true;
}


// eficient one
int DivisorSum(int number) {
    int suum = 0;
    for(size_t iter = 1; iter * iter <= number; iter++) {
        if (number % iter == 0) {
            suum += iter + number / iter;
        }
    }
    if (sqrt(number) == floor(sqrt(number))) {
        suum -= sqrt(number);
    }
    return suum;
}

bool VerifyDoubleElements(const int *arr) {
    const int size = len(arr);
    bool exists = false;
    for(size_t iter = 1; iter < size; iter++) {
        if (arr[iter - 1] == 2 * arr[iter]) {
            exists = true;
        }
    }
    return exists;
}

int TotalEvenDigits(const int &number) {
    int copy = number;
    int result = 0;
    while (copy) {
        if (copy % 10 % 2 == 0) {
            result++;
        }
        copy /= 10;
    }
    return result;
}

bool Distinct2By2(const int *arr) {
    const int size = len(arr);
    for(size_t iter = 1; iter < size; iter++) {
        if (arr[iter - 1] == arr[iter]) {
            return false;
        }
    }
    return true;
}

#include <vector>
#include <unordered_set>

bool HasPairWithSum(const vector<int> arr, const int &sum) {
    unordered_set<int> complements;
    for(auto elem : arr) {
        if (complements.find(elem) != complements.end()) {
            return true;
        }
        complements.insert(sum - elem);
    }
    return false;
}

int PairsOfDiofEc(int *arr, const int &a, const int &b, const int &c) {
    int *copy = arr;
    int pairs = 0;
    const int size = len(arr);
    for(size_t iter = 0; iter < size; iter++) {
        if(copy[iter] != -1) {
            int x = copy[iter];
            int y = sqrt((c - (a * x * x)) / b);
            int pivot = BinarySearch(arr, iter + 1, len(arr) - 1, y);
            if (pivot != -1) {
                pairs++;
                copy[iter] = copy[pivot] = -1;
                if (a == b) {
                    pairs++;
                }
            }
        }
    }
    return pairs;
}

//Se citeste de la tastatura un numar natural n (n <= 500) si apoi n cifre separate prin spatii. Se
//cere sa se afiseze pe ecran cele n cifre citite, în ordine crescatoare, separate prin cate un
//spatiu
//Exemplu: pentru n = 19 si cifrele 3 3 0 9 2 1 2 1 3 7 1 5 2 7 1 0 3 2 3 se va
//afisa pe ecran 0 0 1 1 1 1 2 2 2 2 3 3 3 3 3 5 7 7 9
int* SequenceOfDigitsSorted(const int *arr, const int &size) {
    int *freqarr = new int[10]{0};
    for(size_t iter = 0; iter < size; iter++) {
        freqarr[arr[iter]]++;
    }
    int *sequence = new int[size];
    int index = 0;
    for(size_t iter = 0; iter <= 9; iter++) {
        if (freqarr[iter] != 0) {
            for(size_t jiter = 0; jiter < freqarr[iter]; jiter++) {
                sequence[index++] = iter;
            }
        }
    }
    return sequence;
}

// @ sum: 1 + 2 + ... + N
int GaussSum(const int &number) {
    int calculation = 1;
    for (size_t iter = 2; iter < number; iter++) {
        calculation += iter;
    }
    calculation += number; // i chose to put this here because
    // i dont want for forloop to compare everytime if(iter == N)--->pointless (takes computational time)
    return calculation;
}

bool RealNumComp(const double &arg1, const double &arg2) {
    double eps = 1e-10;
    return abs(arg2 - arg1) < eps;
}

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

// @ product: 1 * 2 * ... * N
int Factorial(const int &number) {
    if (number == 0) {
        return 1;
    }
    else {
        int calculation = 1;
        for (size_t iter = 2; iter < number; iter++) {
            calculation *= iter;
        }
        calculation *= number;
        // i dont want for forloop to compare everytime if(iter == N)--->pointless (takes computational time)
        return calculation;
    }
}

bool PrimeNumber(const size_t number) {
    if (number < 2) {
        return false;
    }
    if (number > 2 && number % 2 == 0) {
        return false;
    }
    for (size_t div = 3; div * div <= number; div += 2) {
        if (number % div == 0) {
            return false;
        }
    }
    return true;
}

void VisualRiemannZetaFunction(const int S, const unsigned long long int N) {
    for (size_t iter = 1; iter <= N; iter++) {
        cout << /*fixed << setprecision(3) <<*/
            1.0 / pow(iter, S) << " ";
    }
    cout << endl;
}

double ReturnRiemannZetaFunction(const int S, const unsigned long long int N) {
    if (S == -2) {
        return 0.0;
    }
    else if (S == -1) {
        return -1.0 / 12.0;
    }
    else if (S == 0) {
        return -1.0 / 2.0;
    }
    else if (S == 2) {
        return (PI * PI) / 6.0;
    }
    else if (S == 4) {
        return (PI * PI * PI * PI) / 90.0;
    }
    else {
        double SUM = 0.0;
        for (size_t iter = 1; iter <= N; iter++) {
            SUM += 1.0 / pow(iter, S);
        }
        return SUM;
    }
}

void GeneratePrimeN(const size_t N, unsigned int lineSize = 0) {
    for (size_t iterator = 1; iterator <= N; iterator += 2) {
        if (PrimeNumber(iterator)) {
            lineSize++;
            if (lineSize % 10 == 0) {
                cout << "\n";
            }
            cout << iterator << " ";
        }
    }
}

void Merge(int *vector, int left, int mid, int right) {
    int aux[10000] = { 0 }, i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (vector[i] < vector[j]) {
            aux[k++] = vector[i++];
        }
        else {
            aux[k++] = vector[j++];
        }
    }
    while (i <= mid) {
        aux[k++] = vector[i++];
    }
    while (j <= right) {
        aux[k++] = vector[j++];
    }
    k = 0;
    for (size_t iter = left; iter <= right; iter++) {
        vector[iter] = aux[k++];
    }
}

void MergeSort(int *vector, int left, int right) {
    if (right - left <= 1) {
        if (vector[left] > vector[right]) {
            int aux = vector[left];
            vector[left] = vector[right];
            vector[right] = aux;
        }
    }
    else {
        int mid = (left + right) / 2;
        MergeSort(vector, left, mid);
        MergeSort(vector, mid + 1, right);
        Merge(vector, left, mid, right);
    }
}

bool SevenInclusion(int param) {
	while (param != 0) {
		if (param % 10 == 7) {
			return true;
		}
		param /= 10;
	}
	return false;
}

int determ(int a[4][4], int n) {
	int det = 0, p, h, k, i, j, temp[4][4];
	if (n == 1) {
		return a[0][0];
	}
	else if (n == 2) {
		det = (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
		return det;
	}
	else {
		for (p = 0; p < n; p++) {
			h = 0;
			k = 0;
			for (i = 1; i < n; i++) {
				for (j = 0; j < n; j++) {
					if (j == p) {
						continue;
					}
					temp[h][k] = a[i][j];
					k++;
					if (k == n - 1) {
						h++;
						k = 0;
					}
				}
			}
			det = det + a[0][p] * pow(-1, p) * determ(temp, n - 1);
		}
		return det;
	}
}

void BoltzSequenceGenerator(const int length) {
	for (size_t iter = 1; iter <= length; iter++) {
		if (iter % 7 == 0 || SevenInclusion(iter)) {
			cout << iter << " ";
		}
	}
}