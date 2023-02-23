#pragma once
#include "STLHeader.h"
using namespace std;

// ���� ����
void SelectionSort();

// ���� ����
void InsertionSort();

// �� ����
void QuickSort(int* arrData, int startIndex, int endIndex);

void CountSort(int* arrData, int arrSize, int minValue, int maxValue);

// 22.12.25 ���α׷��ӽ� H-Index
int HIndex(vector<int> citations);

// 22.12.2 ���α׷��ӽ� H-Index
long long WorkOverTime(int n, vector<int> works);

// 22.2.1 ���α׷��ӽ� ���� ����
int NumberGame(vector<int> A, vector<int> B);
