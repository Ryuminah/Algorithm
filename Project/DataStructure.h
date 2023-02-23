#pragma once
#include "STLHeader.h"

#pragma region  Stack/Queue
// 22.1.3 ȭ ���� 1655�� ����� ���ؿ�
void TalkMiddle();

vector<int> DoublePriorityQueue(vector<string> operations);
vector<int> DoublePriorityQueue2(vector<string> operations);

#pragma endregion

#pragma region Hash
bool Compare(pair<int, int>& a, pair<int, int>& b);
vector<int> BestAlbum(vector<string> genres, vector<int> plays);

// ���α׷��ӽ� : �ҷ� �����
bool CheckIdMatch(string a, string b);
int BannedUser(vector<string> user_id, vector<string> banned_id);
#pragma endregion


