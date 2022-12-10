#include "Sorting.h"
#include "STLheader.h"

using namespace std;

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
		for (int compareIndex = currentIndex - 1; compareIndex >= 0; --compareIndex)
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
	int leftIndex = startIndex + 1;
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

	QuickSort(arrData, startIndex, rightIndex - 1);
	QuickSort(arrData, leftIndex + 1, endIndex);

}

void CountSort(int* arrData, int arrSize, int minValue, int maxValue)
{
	int sortSize = (maxValue - minValue) + 1;
	int* arrSort = new int[sortSize] { 0 };

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

void UpToDown()
{
	int count = 0;
	std::cin >> count;
	
	int* arrSort = new int[count];


	for (int i = 0; i < count; ++i)
	{
		std::cin >> arrSort[i];
	}

	std::sort(arrSort, arrSort+count, std::greater<>());

	for (int i = 0; i < count; ++i)
	{
		std::cout << arrSort[i] << ' ';
	}
}

void PrintStudent()
{
	int studentCount = 0;
	std::cin >> studentCount;
	std::map<int, std::string> studentData;

	for (int i = 0; i < studentCount; ++i)
	{
		std::string name;
		int score;
		std::cin >> name >> score;

		studentData[score] = name;
	}

	auto iter = studentData.begin();
	auto iterEnd = studentData.end();

	for (; iter != iterEnd; ++iter)
	{
		std::cout << iter->second << ' ';
	}
}

void SevenDwarfs()
{
	std::vector<int> arrNumber;
	arrNumber.resize(9);
	int totalValue = 0;

	for (int i = 0; i < 9; ++i)
	{
		std::cin >> arrNumber[i];
		totalValue += arrNumber[i];
	}
	
	// 7���� �ε����� ����
	std::sort(arrNumber.begin(), arrNumber.end());
	
	
	for (int i = 0; i < arrNumber.size(); ++i)
	{
		for (int j = 0; j < arrNumber.size(); ++j)
		{
			if (i == j)
			{
				continue;
			}

			int number = arrNumber[i] + arrNumber[j];

			if ((totalValue - number) == 100)
			{
				for (int k = 0; k < arrNumber.size(); k++)
				{
					if (k == i || k == j)
					{
						continue;
					}

					std::cout << arrNumber[k] << '\n';
				}

				return;
			}
		}
	}

}

int MakeMinimumValue(vector<int> A, vector<int> B)
{
	int answer = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	int length = A.size();

	for (int i = 0; i < length; ++i)
	{
		answer += A[i] * B[i];
	}

	return answer;
}
