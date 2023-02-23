#pragma once
#include "STLHeader.h"
using namespace std;

// 21. 8.24 BFS example
void BFS();

// 21.8.31 ���� 4�� �̷� Ż��
void EscapeTheMaze();

// 21.12.3 14248�� ���� ����
void JumpJump();

// 22.12.14 ���α׷��ӽ� ���� �� �ִܰŸ�;
int ShortestDistanceInGameMap(vector<vector<int> > maps);

// 22.12.17 ���α׷��ӽ� �ܾ� ��ȯ
bool CanChange(string src, string dest);
int ChangeWords(string begin, string target, vector<string> words);

// 22.12.27 ���� 14502�� ������
struct Pos
{
	int x, y;

	Pos() : x(0),y(0) {}
	Pos(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

// �迭�� ���� �������� �� ��, ���������� ���޵ȴ�.
void Virus(int mapCopy[][8]);
void MakeWall(int count);

void Virus();
void Laboratory();

// 23.1.26 ���� 2993�� : �̳׶�
void Mineral();
void CheckCluster(Pos pos);
