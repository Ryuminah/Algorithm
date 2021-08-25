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

void FreezingDrinks()
{
	enum Position {X,Y};
	enum Direction { R, L, U, D};

	struct Ice
	{
		bool m_Check = false;
		int m_Ice;
		int pos[2];
	};

	int N, M;
	int result = 0;
	std::cin >> N >> M;
	std::cin.ignore();

	std::vector<Ice*> IceBox;

	// �� ä���
	for (int y = 0; y < M; ++y)
	{
		for (int x = 0; x  < N; ++x)
		{
			Ice* pIce = new Ice;
			pIce->pos[X] = x;
			pIce->pos[Y] = y;
			pIce->m_Ice = (int)std::cin.get() - '0';

			IceBox.push_back(pIce);
			
		}
			std::cin.ignore();
	}

	// Logic
	for (size_t i = 0; i < IceBox.size(); ++i)
	{
		Ice* CheckIce;

		// ���� Ž������ ���� ������ �����¿츦 Ž��.
		if (0 == IceBox[i]->m_Ice && !IceBox[i]->m_Check)
		{
			CheckIce = IceBox[i];
			CheckIce->m_Check = true;

			// ���� ��� ���ϴ� ����
			while (true)
			{
				int block = 0;

				// �� ������ üũ
				for (int dir = 0; dir < 4; ++dir)
				{
					// ���� ������ ��ġ�� ����
					int nextPos[2] = { CheckIce->pos[X], CheckIce->pos[Y] };
					switch (dir)
					{
					case R:
						nextPos[X] += 1;
						break;
					case L:
						nextPos[X] -= 1;
						break;
					case U:
						nextPos[Y] -= 1;
						break;
					case D:
						nextPos[Y] += 1;
						break;
					}

					// ����Ʋ�� ��ġ���� ����� ���
					if (nextPos[X] < 0 || nextPos[X] >= N || nextPos[Y] < 0 || nextPos[Y] >= N)
					{
						++block;
						continue;
					}

					// �����ϴ� ������ ���
					else
					{
						// �����̳� �ȿ��� ���� ã��
						for (size_t k = 0; k < IceBox.size(); ++k)
						{
							// ������ ã�Ҵٸ�
							if (IceBox[k]->pos[X] == nextPos[X] && IceBox[k]->pos[Y] == nextPos[Y])
							{
								// ������ �ϴ� ������ Ȯ��
								if (!IceBox[k]->m_Check && IceBox[k]->m_Ice == 0)
								{
									// �ش� ������ �湮�� ������ �ٲ��ְ� ���� Ž���� �������� ����
									CheckIce = IceBox[k];
									CheckIce->m_Check = true;
									dir = -1;
								}

								// �̹� �湮�� �����̶�� ������ ������ ǥ��
								else
								{
									++block;
								}

								break;
							}
						}
					}
				}

				// ����� ������ �� ���� ���̶�� ���� ���� ��
				if (block == 4)
				{
					++result;
					break;
				}
			}
		}

		// ������ �ƴϰų� Ž���� �̹� �ߴٸ�.
		else
		{
			continue;
		}

		// �湮�� ���� ������ �ٽ� �������� ���ư��� Ž���ϴ� ������ ���� , ,, 
	}

	std::cout << result;

	std::vector<Ice*>::iterator iter = IceBox.begin();
	std::vector<Ice*>::iterator iterEnd = IceBox.end();

	// �޸� ����
	for (; iter != iterEnd; ++iter)
	{
		delete (*iter);
	}


	int a = 0;
}

