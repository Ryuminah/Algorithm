#include "Sorting.h"
#include <vector>
#include <iostream>

void SelectionSort()
{
	std::vector<int> arr{ 7,5,9,0,3,1,6,2,4,8 };

	int arrSize = (int)arr.size();				// �迭�� �� ������
	int minIndex = 0;							// ���� ���� ���� ������ �ִ� �ε���
	
	std::cout << "���� �� : ";

	for (int i = 0; i < arrSize; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << '\n';

	// �迭 Ž��
	for (int frontIndex = 0; frontIndex < arrSize; ++frontIndex)
	{
		minIndex = frontIndex;

		// ���� ���� ���� �ε����� ������ �� ���� ���� �߰��ϸ� ��ü
		for (int compareIndex = frontIndex + 1; compareIndex < arrSize; compareIndex++)
		{
			if (arr[minIndex] > arr[compareIndex])
				minIndex = compareIndex;
		}
		
		// �� ���� ����
		int smallestValue = arr[minIndex];		
		arr[minIndex] = arr[frontIndex];
		arr[frontIndex] = smallestValue;
	}

	std::cout << "���� �� : ";

	for (int i = 0; i < arrSize; ++i)
	{
		std::cout  << arr[i] << " " ;
	}
}

void InsertionSort()
{
	int arr[10] = { 7,5,9,0,3,1,6,2,4,8 };

	int arrSize = 10;				// �迭�� �� ������
	int minIndex = 0;				// ���� ���� ���� ������ �ִ� �ε���

	std::cout << "���� �� : ";

	for (int i = 0; i < arrSize; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << '\n';

	// ���� ������ �ι�° �ε��� ���� ������ (ù��° �����ʹ� �� ��ü�� ���ĵǾ� �ִٰ� �Ǵ��ϱ� ����) 
	for (int currentIndex = 1; currentIndex < arrSize; ++currentIndex)
	{
		// ���� �ε����� ��
		int currentValue = arr[currentIndex];

		// �ڽź��� ���� �ε����� ��ȸ�ϸ� ���� �������� �ڸ��� ã�´�.
		for (int compareIndex = currentIndex-1 ; compareIndex >= 0; --compareIndex)
		{
			int compareValue = arr[compareIndex];

			// currentValue�� ���� ������ �� �۴ٸ� ��ġ�� �ű��
			if (currentValue < compareValue)
			{
				arr[compareIndex + 1] = compareValue;
				arr[compareIndex] = currentValue;
			}
			
			// currentValue�� �� ũ�ٸ� �״�� �����.
			else
			{
				break;
			}

		}
	}

	std::cout << "���� �� : ";


	for (int i = 0; i < arrSize; ++i)
	{
		std::cout << arr[i] << " ";
	}
}

void QuickSort(int* arrData, int startIndex, int endIndex)
{
	if (startIndex >= endIndex)
	{
		return;
	}


	// �Ǻ��� ����
	int pivotValue = arrData[startIndex];
	int leftIndex = startIndex+1;
	int rightIndex = endIndex;
	
	// ���ʿ����� �Ǻ����� ū �����͸� ����, �����ʿ������� �Ǻ����� ���� �����͸� �����Ѵ�.

	while (leftIndex <= rightIndex)
	{
		while (leftIndex <= endIndex && (arrData[leftIndex] <= pivotValue))
		{
			++leftIndex;
		}

		while (rightIndex > startIndex && (arrData[rightIndex] >= pivotValue))
		{
			--rightIndex;

		}

		int leftValue = arrData[leftIndex];
		int rightValue = arrData[rightIndex];

		// �ε����� �������� ��� �������� �����͸� pivot���� �ٲ��ش�
		if (leftIndex > rightIndex)
		{
			arrData[startIndex] = rightValue;
			arrData[rightIndex] = pivotValue;
		}

		else
		{
			arrData[leftIndex] = rightValue;
			arrData[rightIndex] = leftValue;
		}
	}

	// ���� ���� ������ ��, ��� ������ �ݺ��Ѵ�.

	QuickSort(arrData, startIndex, rightIndex -1);
	QuickSort(arrData, leftIndex+1, endIndex);

}

void CountSort(int* arrData, int arrSize, int minValue, int maxValue)
{
	int sortSize = (maxValue - minValue) + 1;
	int* arrSort = new int[sortSize]{ 0 };

	for (int i = 0; i < arrSize; ++i)
	{
		int currentValue = arrData[i];
		++arrSort[currentValue];
	}

	std::cout << "���� �� : ";

	for (int i = 0; i < sortSize; ++i)
	{
		int valueCount = arrSort[i];
		
		if (valueCount == 0)
		{
			continue;
		}

		else
		{
			while (valueCount > 0)
			{
				std::cout << i << " ";
				--valueCount;
			}
		}
	}
	
	delete[] arrSort;
}


void CountSort()
{
	int arr[] = { 7,5,9,0,3,1,6,2,9,1,4, 8,0,5,2 };

	int arrSize = 10;				// �迭�� �� ������
	int minIndex = 0;				// ���� ���� ���� ������ �ִ� �ε���

	std::cout << "���� �� : ";

	for (int i = 0; i < arrSize; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << '\n';
}


int HIndex(vector<int> citations)
{
	int answer = 0;

	sort(citations.begin(), citations.end(), greater<int>());

	for (int i = 0; i < citations.size(); ++i)
	{
		if (citations[i] > i)
			++answer;
		else
			break;
	}

	return answer;
}


long long WorkOverTime(int n, vector<int> works)
{
	long long answer = 0;
	priority_queue<int> q;

	int totalTime = 0;
	for (int i = 0; i < works.size(); ++i)
	{
		totalTime += works[i];
		q.push(works[i]);
	}

	if (totalTime <= n)
	{
		return 0;
	}

	while (n != 0)
	{
		int maxTime = q.top();
		q.pop();

		if (maxTime != 0) --maxTime;

		q.push(maxTime);
		--n;
	}

	while (!q.empty())
	{
		answer += q.top() * q.top();
		q.pop();
	}

	return answer;
}

int NumberGame(vector<int> A, vector<int> B)
{
	int answer = 0;
	priority_queue<int> aQ;
	priority_queue<int> bQ;

	for (int i = 0; i < A.size(); ++i)
	{
		aQ.push(A[i]);
		bQ.push(B[i]);
	}

	while (!aQ.empty())
	{
		int aNumber = aQ.top();
		aQ.pop();

		int bNumber = bQ.top();

		if (bNumber > aNumber)
		{
			++answer;
			bQ.pop();
		}
	}

	return answer;
}

