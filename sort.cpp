#include <iostream>
using namespace std;

#include <stdlib.h>
#include <time.h>

#define MAXTAB 50

void BubbleSort(int t[], int nSize); //sortowanie babelkowe
void SelectionSort(int t[], int nSize); //proste wybieranie
void InsertionSort(int t[], int nSize); //proste wstawianie


void initTab(int t[], int nSize);
void printTab(int t[], int nSize);
int main() {
	int t[MAXTAB] = { 1,	2,	0,	4,  5 };
	//				t[0],t[1],t[2],t[3],t[4]

	int tab[MAXTAB] = { 0 }; //pozostale sa zerami z automatu


	int t1[] = { 1,2,3,4,5,6,7,8,9,0 };
	int size = sizeof(t1) / sizeof(int);
	memset(t1, 0, size * sizeof(int));

	initTab(tab, MAXTAB);
	cout << "niesortowane" << endl;
	printTab(tab, MAXTAB);

	cout << "Bubble Sort" << endl;
	BubbleSort(tab, MAXTAB);
	printTab(tab, MAXTAB);

	cout << "Selection Sort" << endl;
	SelectionSort(tab, MAXTAB);
	printTab(tab, MAXTAB);

	cout << "Insertion Sort" << endl;
	InsertionSort(tab, MAXTAB);
	printTab(tab, MAXTAB);
	return 0;
}

void initTab(int t[], int nSize) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < nSize; i++) {
		t[i] = rand();
	}
}

void printTab(int t[], int nSize) {
	for (int i = 0; i < nSize; i++) {
		cout << t[i] << " ";
		if (((i + 1) % 10) == 0 ) {
			cout << endl;
		}
	}
	cout << endl;
}

void BubbleSort(int t[], int nSize) {
    for (int i = 0; i < nSize - 1; i ++ ) {
        for (int j = nSize - 1; j > i; j--) {
			if (t[j] < t[j - 1]) {
				int temp = t[j];
				t[j] = t[j - 1];
				t[j - 1] = temp; //zmiana kolejnosc
			}
        }
    }
}

void SelectionSort(int t[], int nSize) {
	for (int i = 0; i < nSize - 1; i++) {
		int min = t[i];
		int ix = i;
		for (int j = i + 1; j < nSize; j++) {
			if (t[j] < min) {
				min = t[j];
				ix = j;
			}
			//zamiana
			t[ix] = t[i];
			t[i] = min;

		}
	}
}

void InsertionSort(int t[], int nSize) {
	for (int i = 1; i < nSize; i++) {
		int x = t[i];
		int j = i - 1;
		while (j >= 0 && t[j] > x) {
			t[j + 1] = t[j--];

		}
	}
}
