#include "DFS.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <list>
#include <stack>

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
		pNode->value = i + 1;
		pNode->check = false;
		Graph.push_back(pNode);
	}

	//1�� ���
	Graph[0]->link.push_back(Graph[1]);
	Graph[0]->link.push_back(Graph[2]);
	Graph[0]->link.push_back(Graph[7]);

	//2�� ���
	Graph[1]->link.push_back(Graph[0]);
	Graph[1]->link.push_back(Graph[6]);

	//3�� ���
	Graph[2]->link.push_back(Graph[0]);
	Graph[2]->link.push_back(Graph[3]);
	Graph[2]->link.push_back(Graph[4]);

	//4�� ���
	Graph[3]->link.push_back(Graph[2]);
	Graph[3]->link.push_back(Graph[4]);

	//5�� ���
	Graph[4]->link.push_back(Graph[2]);
	Graph[4]->link.push_back(Graph[3]);

	//6�� ���
	Graph[5]->link.push_back(Graph[6]);

	//7�� ���
	Graph[6]->link.push_back(Graph[1]);
	Graph[6]->link.push_back(Graph[5]);
	Graph[6]->link.push_back(Graph[7]);

	//8�� ���
	Graph[7]->link.push_back(Graph[0]);
	Graph[7]->link.push_back(Graph[6]);


	//2. DFS
	int i = 0;
	while (true)
	{
		// �ѹ��� �湮���� ���� ����� ���
		if (!Graph[i]->check)
		{
			// �湮 ó��
			Graph[i]->check = true;
			Visit.push(Graph[i]);
			std::cout << i + 1 << "->";
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
					i = Graph[i]->link[j]->value - 1;
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
					i = Visit.top()->value - 1;

				}

				else
				{
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

