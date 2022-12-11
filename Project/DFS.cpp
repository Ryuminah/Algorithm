#include "DFS.h"
#include "STLheader.h"

using namespace std;

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

void CheckNetwork(bool* visited, int currentDepth, std::vector<std::vector<int>>& computers)
{
	visited[currentDepth] = true;

	for (int i = currentDepth, j = 0; j < computers.size(); ++j)
	{
		if (i == j)
		{
			continue; 
		}

		if (!visited[j] && computers[i][j])
		{
			CheckNetwork(visited,j,computers);
		}
	}
}

int Network(int n, std::vector<std::vector<int>> computers)
{
	bool visited[200] = { false };
	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		// �湮�� ���� ���� ����� (������ ������ ���)
		if (!visited[i])
		{
			++answer;

			// ����� ��Ʈ��ũ�� ��ȸ
			CheckNetwork(visited, i, computers);
		}
	}
		return answer;
}

void CalculateNumber(std::vector<int> numbers, int target, int index, int totalSum, int& answer)
{
	if (index == numbers.size() - 1)
	{
		if (totalSum == target)
		{
			++answer;
		}

		return;
	}

	CalculateNumber(numbers, target, index + 1, numbers[index + 1] + totalSum, answer);
	CalculateNumber(numbers, target, index + 1, -numbers[index + 1] + totalSum, answer);
}

int TargetNumber(std::vector<int> numbers, int target)
{
	int i = 0;
	int answer = 0;

	CalculateNumber(numbers, target, i, numbers[0], answer);
	CalculateNumber(numbers, target, i, -numbers[0], answer);

	return answer;
}


bool visit[100][100] = { false };


void MakeArea(std::vector<vector<char>> grid, int indexX, int indexY, char color, bool isRedGreen)
{
	visit[indexY][indexX] = true;

	// 4���� Ž��
	int dirX[] = { 1,0,-1,0 };
	int dirY[] = { 0,1, 0,-1 };

	for (int i = 0; i < 4; ++i)
	{
		int nextX = indexX + dirX[i];
		int nextY = indexY + dirY[i];

		// ���簡 ������ �����̰�
		if (nextX >= 0 && nextY >= 0 && 
			nextX < grid.size() && nextY < grid.size() &&
			!visit[nextY][nextX])
		{
			if (!isRedGreen)
			{
				// ���� �����̶�� ������ ����
				if (color == grid[nextY][nextX])
				{
					MakeArea(grid, nextX, nextY, color);
				}
			}

			// ���� ������ ���
			else
			{ 
				// color�� B�� �ƴ� ���
				if (color == 'B')
				{
					if ('B' != grid[nextY][nextX])
					{
						continue;
					}
				} 
					
				else
				{
					if ('B' == grid[nextY][nextX])
					{
						continue;
					}
				}

				MakeArea(grid, nextX, nextY, color, true);
			}
		}
	}
}

void RedGreenColorWeakness()
{
	int result = 0;
	int redGreenResult = 0;

	int N;
	vector<vector<char>> grid;

	// Input
	cin >> N;
	grid.resize(N);

	for (int i = 0; i < N; ++i)
	{
		string line;
		cin >> line;

		for (int j = 0; j < line.length(); ++j)
		{
			char color = line[j];
			grid[i].push_back(color);
		}
	}


	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			// ������ ������ ���� ���
			if (!visit[y][x])
			{
				MakeArea(grid, x, y, grid[y][x]);
				++result;
			}
		}
	}

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			visit[y][x] = false;
		}
	}

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			// ������ ������ ���� ���
			if (!visit[y][x])
			{
				MakeArea(grid, x, y, grid[y][x],true);
				++redGreenResult;
			}
		}
	}


	cout << result << ' ' << redGreenResult;
}

