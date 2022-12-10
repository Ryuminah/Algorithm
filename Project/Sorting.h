#pragma once
#include "STLheader.h"

// ���� ����
void SelectionSort();

// ���� ����
void InsertionSort();

// �� ����
void QuickSort(int* arrData, int startIndex, int endIndex);

// ��� ����
void CountSort(int* arrData, int arrSize, int minValue, int maxValue);


////////////////////////////////////// ���� //////////////////////////////////////
// �������� 2�� ������ �Ʒ���
void UpToDown();

// �������� 3�� ������ �Ʒ���
void PrintStudent();

// ���� 2309�� �ϰ�������
void SevenDwarfs();

// ���α׷��ӽ� �ּڰ� �����
int MakeMinimumValue(std::vector<int> A, std::vector<int> B);