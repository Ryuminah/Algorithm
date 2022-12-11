#pragma once
#include <vector>

// Depth First Search

//21. 8.22 DFS example
void DFS();

//21.8.25 ���� 3 ����� ����Ա�
bool CheckIceBox(int _x, int _y, int _n, int _m, int _Graph[][1000]);		// DFS
void FreezingDrinks();

// 22.11.6 ���α׷��ӽ� ��Ʈ��ũ
void CheckNetwork(bool* visited,int currentDepth, std::vector<std::vector<int>>& computers);
int Network(int n, std::vector<std::vector<int>> computers);

// 22.12.8 ���α׷��ӽ� Ÿ�ٳѹ�
void CalculateNumber(std::vector<int> numbers, int target, int index, int totalSum, int& answer);
int TargetNumber(std::vector<int> numbers, int target);

//22.12.10 ���� 10026�� ���ϻ���
void MakeArea(std::vector<std::vector<char>>& grid, int indexX, int indexY, char color, bool isRedGreen = false);
void RedGreenColorWeakness();

void MakeArea2(std::vector<std::vector<char>>& grid, int indexX, int indexY);
void RedGreenColorWeakness2();

//22.12.11 ���� �� �ִܰŸ�
int ShortestDistanceInGameMap(std::vector<std::vector<int>> maps);