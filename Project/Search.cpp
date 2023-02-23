#include "Search.h"

int BinarySearch(vector<int> data, int dest)
{
	int answer = -1;

	int start = 0;
	int end = data.size()-1;
	int pivot = 0;

	// start�� end���� Ŀ���� Ž�� ������
	while (start <= end)
	{
		pivot = (start + end) / 2;

		if (data[pivot] == dest)
		{
			answer = pivot;
			break;
		}
		
		// pivot > dest�� ��� ū ���� �� �ʿ䰡 ����
		else if(data[pivot] > dest)
		{
			end = pivot - 1;
		}

		// pivot < dest�� ��� ���� ���� �� �ʿ䰡 ����
		else
		{
			start = pivot + 1;
		}
	}

	return answer;
}
 