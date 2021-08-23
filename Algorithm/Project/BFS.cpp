#include "BFS.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <list>
#include <queue>

void BFS()
{
	//1. Graph ����
	struct Node
	{
		int value;
		std::vector<Node*> link;
		bool check;
	};

	std::vector<Node*> Graph;
	std::queue<Node*> Visit;

	for (int i = 0; i < 8; ++i)
	{
		Node* pNode = new Node;
		pNode->value = i;
		pNode->check = false;
		Graph.push_back(pNode);
	}

	//0�� ���
	Graph[0]->link.push_back(Graph[1]);
	Graph[0]->link.push_back(Graph[2]);
	Graph[0]->link.push_back(Graph[7]);


	//1�� ���
	Graph[1]->link.push_back(Graph[0]);
	Graph[1]->link.push_back(Graph[6]);

	//2�� ���
	Graph[2]->link.push_back(Graph[0]);
	Graph[2]->link.push_back(Graph[3]);
	Graph[2]->link.push_back(Graph[4]);

	//3�� ���
	Graph[3]->link.push_back(Graph[2]);
	Graph[3]->link.push_back(Graph[4]);

	//4�� ���
	Graph[4]->link.push_back(Graph[2]);
	Graph[4]->link.push_back(Graph[3]);

	//5�� ���
	Graph[5]->link.push_back(Graph[6]);

	//6�� ���
	Graph[6]->link.push_back(Graph[1]);
	Graph[6]->link.push_back(Graph[5]);
	Graph[6]->link.push_back(Graph[7]);

	//7�� ���
	Graph[7]->link.push_back(Graph[0]);
	Graph[7]->link.push_back(Graph[6]);

	// BFS ���� (�Ÿ��� ���� ����� ������ Ž��)

	int i = 0;
	while (true)
	{
		// �ѹ��� �湮���� ���� ����� ���
		if (!Graph[i]->check)
		{
			// �湮 ó��
			Visit.push(Graph[i]);
			Graph[i]->check = true;
			std::cout << i << "->";
		}


		// �湮 �ߴ� �����
		else
		{
			// ���� ó���� �ִ� ��带 ���� ��
			Node& pNode = *Visit.front();
			Visit.pop();

			// ���� ��� �� �湮���� ���� ��带 ��� ť�� ������ �� �湮ó����.
			for (size_t j = 0; j < pNode.link.size(); ++j)
			{
				// ���� üũ�ϰ� �ִ� ����� ��尡 �湮�� �� ���� �����
				if (!pNode.link[j]->check)
				{
					// Queue�� Push �� �湮 ó����.
					Visit.push(pNode.link[j]);
					pNode.link[j]->check= true;
					std::cout << j << "->";
				}
			}

			// Queue�� ���� ó�� ��带 ���� Ž���� ���� �ٲ���.
			if (!Visit.empty())
			{
				i = Visit.front()->value;
			}

			else
			{
				break;
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
	std::cout << '\n';

}
