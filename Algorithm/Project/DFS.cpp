#include "DFS.h"
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <iostream>

void DFS()
{
	// ���� List ����� ����� ����.

	//1. Graph ����
	struct Node
	{
		int value;
		std::vector<Node*> link;
		bool check;
	};

	std::vector<Node*> Graph;
	std::stack<Node*> Visit;

	for (int i = 0; i < 8; ++i)
	{
		Node* pNode = new Node;
		pNode->value = i;
		pNode->check = false;
		Graph.push_back(pNode);
	}

	//0�� ���
	Graph[0]->link.push_back(Graph[1]);

	//1�� ���
	Graph[1]->link.push_back(Graph[0]);
	Graph[1]->link.push_back(Graph[2]);

	//2�� ���
	Graph[2]->link.push_back(Graph[1]);
	Graph[2]->link.push_back(Graph[3]);
	Graph[2]->link.push_back(Graph[4]);

	//3�� ���
	Graph[3]->link.push_back(Graph[2]);

	//4�� ���
	Graph[4]->link.push_back(Graph[2]);
	Graph[4]->link.push_back(Graph[5]);
	Graph[4]->link.push_back(Graph[6]);
	Graph[4]->link.push_back(Graph[7]);

	//5�� ���
	Graph[5]->link.push_back(Graph[4]);

	//6�� ���
	Graph[6]->link.push_back(Graph[4]);

	//7�� ���
	Graph[7]->link.push_back(Graph[4]);


	//2. DFS
	int i = 4;
	while (true)
	{
		// �ѹ��� �湮���� ���� ����� ���
		if (!Graph[i]->check)
		{
			// �湮 ó��
			Graph[i]->check = true;
			Visit.push(Graph[i]);
			std::cout << i << "->";
		}


		// �湮 �ߴ� �����
		else
		{
			// �湮���� ���� ����� ��尡 �ִ��� üũ.
			for (size_t j = 0; j < Graph[i]->link.size(); ++j)
			{
				// ����� ��尡 �湮�� �� ���� �����
				if (!Graph[i]->link[j]->check)
				{
					// ���� �湮�� ��� ��ȣ�� �����ش�.
					i = Graph[i]->link[j]->value;
					break;
				}
			}

			// �湮���� ���� ���� ��尡 ���ٸ�
			// ���ÿ��� ���� �� ���� �ֻ�� ��带 ���� Ž���� ���� �������ش�.
			if (Graph[i] == Visit.top())
			{
				Visit.pop();

				if (0 != Visit.size())
				{
					i = Visit.top()->value;

				}

				else
				{
					std::cout <<'\n';
					break;
				}
			}

		}

	}



	std::vector<Node*>::iterator iter = Graph.begin();
	std::vector<Node*>::iterator iterEnd = Graph.end();

	// �޸� ����
	for (; iter != iterEnd; ++iter)
	{
		delete (*iter);
	}

	// ���Ϳ� �Ҵ�� �޸� ����
	
	Graph.clear();
}



bool CheckIceBox(int _x, int _y, int _n, int _m, int _Graph[][1000])
{
	if (_x <= -1 || _x >= _n || _y <= -1 || _y >= _m)
	{
		return false;
	}
	// ���� ��带 ���� �湮���� �ʾҴٸ�
	if (_Graph[_x][_y] == 0)
	{
		// �ش� ��� �湮 ó��
		_Graph[_x][_y] = 1;

		// ��, ��, ��, ���� ��ġ�鵵 ��� ��������� ȣ��
		CheckIceBox(_x - 1, _y,_n,_m, _Graph);
		CheckIceBox(_x, _y - 1,_n,_m,_Graph);
		CheckIceBox(_x + 1, _y, _n, _m, _Graph);
		CheckIceBox(_x, _y + 1, _n, _m, _Graph);
		return true;
	}
	return false;
}

void FreezingDrinks()
{
	int N, M;
	int Graph[1000][1000];
	std::cin >> N >> M;

	// 2���� ����Ʈ�� �� ���� �Է� �ޱ�
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%1d", &Graph[i][j]);
		}
	}

	// ��� ���(��ġ)�� ���Ͽ� ����� ä���
	int result = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) 
		{
			// ���� ��ġ���� DFS ����
			if (CheckIceBox(i, j, N,M, Graph)) {
				result += 1;
			}
		}
	}
	std::cout << result << '\n'; // ���� ��� 
}

