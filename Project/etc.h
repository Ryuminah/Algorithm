#pragma once
#include "STLHeader.h"
using namespace std;

// 22.12.21 ���α׷��ӽ� : �ִ񰪰� �ּڰ�
string MaxMin(string s);

bool CheckLine(bool* arr, int findCount, string currentWord);
vector<string> CardGame(vector<string> card, vector<string> word);


#pragma region ���ڿ�
// 23.1.8 ���α׷��ӽ� : A�� B�����
int MakeBtoA(string before, string after);

// 23.1.9 ���α׷��ӽ� : �𽺺�ȣ(1)
string MorseSign(string letter);
#pragma endregion

