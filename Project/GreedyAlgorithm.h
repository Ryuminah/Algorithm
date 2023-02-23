#pragma once
#include <iostream>
#include "STLHeader.h"
using namespace std;
//21. 8.8 ���� 1
void Change();

//21.8.9 2�� ū ���� ��Ģ
void RulesOfBigNumber1();
void RulesOfBigNumber2();

//21.8.10 3�� ���� ī�� ����
void NumberCardGame1();
void NumberCardGame2();

//21.8.11 4�� 1�� �ɶ�����
void MakeOne();

//21.8.12 ���� 4796�� ķ��
void Camping();

//22.7.22 ���� 11399�� ATM
void ATM();

// ���α׷��ӽ� ū �� �����
std::string MakeBigNumber(std::string number, int k);

// ���α׷��ӽ� ���̽�ƽ
int JoyStick(std::string name);

// ���α׷��ӽ� ü����
int SweatSuit(int n, vector<int> lost, vector<int> reserve);

// 22.12.21 ���α׷��ӽ� �ܼ� ī�޶�
bool Compare(vector<int>& a, vector<int>& b);
int SpeedCamera(vector<vector<int>> routes);

// 22.12.22 ���α׷��ӽ� �� �����ϱ�
bool Comp(vector<int>& a, vector<int>& b);
int FindParent(int index);
int LinkIsland(int n,vector<vector<int>> costs);

// 22.12.26 ���� 1541�� �Ҿ���� ��ȣ
void MissingParentheses();

// 22.12.30 ���� 2212�� ����
void Sensor();
void Sensor1();

// 23.2.12 ���α׷��ӽ� : ������ ��ġ
int InstallBaseStation(int n, vector<int> stations, int w);