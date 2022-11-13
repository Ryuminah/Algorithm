#include "Implementation.h"
#include "STLheader.h"

using namespace std;

//21. 8.13 ���� 4-1 �����¿�
void UpDownLeftRight()
{
	std::vector<char> plans;

	struct Pos
	{
		int x;
		int y;

		Pos& operator+= (const Pos& _other)
		{
			this->x += _other.x;
			this->y += _other.y;

			return *this;
		}
	};

	
	Pos currentPos = {1, 1};
	int N;
	char Dir;
	std::cin >> N;
	
	// �Է��� �޴� ����
	while (std::cin >> Dir)
	{
		plans.push_back(Dir);
		if (std::cin.get() == '\n')
		{
			break;
		}

	}

	for (size_t i = 0; i < plans.size(); ++i)
	{
		Pos nextPos = currentPos;

		switch (plans[i])
		{
		case 'L':
			nextPos += {0, -1};
			break;

		case 'R':
			nextPos += {0, +1};
			break;

		case 'D':
			nextPos += {+1, 0};
			break;

		case 'U':
			nextPos += {-1, 0};;
			break;

		default:
			break;
		}

		if (nextPos.x <1 || nextPos.y < 1 || nextPos.x > N || nextPos.y > N)
		{
			continue;
		}

		else
		{
			currentPos = nextPos;
		}
	}

	std::cout << currentPos.x << " " << currentPos.y;
	
}

void Time()
{
	int N = 0;
	int Count = 0;

	// �ð��� �Է¹ޱ�
	std::cin >> N;


	for (int h = 0; h <= N; ++h)
	{
		for (int m = 0; m < 60; ++m)
		{
			for (int s = 0; s < 60; ++s)
			{
				if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
				{
					++Count;
				}
			}
		}
	}
	
	std::cout << Count;
}

void RoyalNight()
{
	enum Pos {X, Y};

	int CurrentPos[2] = { 0, 0 };
	int Count = 0;

	char KnightPos[] = "a1";
	std::cin >> KnightPos;

	// ��ġ�� ���
	for (int i = 0; i < sizeof(KnightPos); ++i)
	{
		if (0 == KnightPos[i])
		{
			break;
		}

		CurrentPos[i] = KnightPos[i];
	}
	
	// 8���� ������ üũ
	for (int i = 0; i < 8; ++i)
	{
		int NextPos[2] = { 0,0 };
		NextPos[X] = CurrentPos[X];
		NextPos[Y] = CurrentPos[Y];

		switch (i)
		{
		case 0:
			NextPos[X] += 2;
			NextPos[Y] += 1;
			break;
		case 1:
			NextPos[X] += 2;
			NextPos[Y] -= 1;
			break;

		case 2:
			NextPos[X] -= 2;
			NextPos[Y] += 1;
			break;

		case 3:
			NextPos[X] -= 2;
			NextPos[Y] += 1;
			break;

		case 4:
			NextPos[X] += 1;
			NextPos[Y] -= 2;
			break;

		case 5:
			NextPos[X] -= 1;
			NextPos[Y] -= 2;
			break;

		case 6:
			NextPos[X] += 1;
			NextPos[Y] += 2;
			break;

		case 7:
			NextPos[X] -= 1;
			NextPos[Y] += 2;
			break;

		}

		// ���� �Ѿ��ٸ� Count�� ���� ����
		if (NextPos[X] <'a' || NextPos[X] > 'h'||
			NextPos[Y] < '1' || NextPos[Y] > '8')
		{
			continue;
		}

		else
		{
			++Count;
		}
	}
	
	std::cout << Count;

}

void GameDevelopment()
{
	enum Direction {NORTH, EAST, SOUTH, WEST};
	enum Pos { X, Y, Dir };

	int N = 0;		// ����
	int M = 0;		// ����
	

	// ���� ũ�� �Է�
	std::cin >> N >> M;

	// X, Y, ����
	int player[3] = { 1,1,NORTH };

	// ĳ������ ��ġ
	std::cout << '1' << ' ' << '1' << ' ' << '0' << std::endl;
	std::vector<char> Width;
	std::vector<std::vector<char>> Map(M, std::vector<char>(N, '1'));

	Map[1][1] = '0';
	Map[1][2] = '0';
	Map[2][2] = '0';

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cout << Map[i][j] << ' ';
		}
		std::cout << '\n';
	}


	int canMoveCheck = 0;
	int Count = 1;

	while (true)
	{
		// ���� ��ǥ�� �̹� ���� ��
		Map[1][1] = '1';

		// �� ����
		int playerNextPos[3];

		for (int i = 0; i < 3; ++i)
		{
			playerNextPos[i] = player[i];

		}

		if (player[Dir] == WEST)
		{
			player[Dir] = NORTH;
		}

		// 1�ܰ� ���� (���� ����)
		++player[Dir];

		// 2�ܰ� ���� (���⿡ ���� �ε��� Ȯ��)
		switch (player[Dir])
		{
			
		case NORTH:
			playerNextPos[Y] -= 1;
			playerNextPos[Dir] = NORTH;
			break;
		case EAST:
			playerNextPos[X] += 1;
			playerNextPos[Dir] = EAST;
			break;

		case SOUTH:
			playerNextPos[Y] += 1;
			playerNextPos[Dir] = SOUTH;
			break;

		case WEST:
			playerNextPos[X] -= 1;
			playerNextPos[Dir] = WEST;
			break;

		default:
			break;
		}

		// ���� ������ �� �� �ִ� ���̶��
		if (Map[playerNextPos[X]][playerNextPos[Y]] == '0')
		{
			// ���ٰ� ǥ��
			Map[playerNextPos[X]][playerNextPos[Y]] = '1';
			canMoveCheck = 0;
		}

		// �� �� ���� ���̶��
		else
		{
			// ���� ������ �̹� ���� ĭ�̶�� ȸ���� ����
			++canMoveCheck;
			player[Dir] = playerNextPos[Dir];

			// �� ���� �� ���� ��Ȳ�� ��� �������� �̵�
			if (canMoveCheck == 4)
			{
				switch (player[Dir])
				{

				case NORTH:
					playerNextPos[Y] += 1;
					break;
				case EAST:
					playerNextPos[X] -= 1;
					break;

				case SOUTH:
					playerNextPos[Y] -= 1;
					break;

				case WEST:
					playerNextPos[X] += 1;
					break;

				default:
					break;
				}

				// �̶� �̵��ؾ��� ���� �ٴ��� ���
				if (Map[playerNextPos[X]][playerNextPos[Y]] == '1')
				{
					break;
				}
			}

			// ��� ���� ��찡 �ƴ϶�� ȸ���� ����
			else
			{
				continue;
			}
		}

		// �̵�
		player[X] = playerNextPos[X];
		player[Y] = playerNextPos[Y];
		player[Dir] = playerNextPos[Dir];
		++Count;

	}

	std::cout << Count;
}

void Message()
{
	int p = 0;
	int w = 0;
	int result = 0;
	char inputString[1000];

	// �Է�
	std::cin >> p >> w;
	std::cin.ignore();
	std::cin.getline(inputString, 1001);

	std::map<char, int> allText;
	allText['A'] = 1;
	allText['B'] = 2;
	allText['C'] = 3;

	allText['D'] = 1;
	allText['E'] = 2;
	allText['F'] = 3;

	allText['G'] = 1;
	allText['J'] = 2;
	allText['I'] = 3;

	allText['J'] = 1;
	allText['K'] = 2;
	allText['L'] = 3;

	allText['M'] = 1;
	allText['N'] = 2;
	allText['O'] = 3;

	allText['P'] = 1;
	allText['Q'] = 2;
	allText['R'] = 3;
	allText['S'] = 4;


	allText['T'] = 1;
	allText['U'] = 2;
	allText['V'] = 3;

	allText['W'] = 1;
	allText['X'] = 2;
	allText['Y'] = 3;
	allText['Z'] = 4;

	allText[' '] = 1;

	std::map<char, int> sameText;

	int count = 1;
	int group = 1;

	for (int i = 0; i < 26; ++i)
	{
		char Text = 'A' + i;

		if (count <=3)
		{
			// ������ 4��° ������ ���
			if (Text == 'R' || Text == 'Y')
			{
				count = 3;
				sameText[Text] = group;
				continue;
			}

			sameText[Text] = group;
			++count;
		}

		else
		{
			// ���� ���ڿ��� �ٲ�� ��Ȳ
			count = 2;
			++group;
			sameText[Text] = group;
		}
	}

	sameText[' '] = 0;

	int i = 0;
	while (0 != inputString[i])
	{
		// ù ���ڴ� ������.
		if (i == 0)
		{
			result += allText[inputString[i]] * p;
			char prevString = inputString[i];
			++i;
			continue;
		}

		char prevString = inputString[i - 1];

		// ���� ���ڰ� �����
		if (' ' == inputString[i])
		{
			result += (allText[inputString[i]] * p);
		}

		// �ƴ� ���
		else
		{
			// ���ð��� üũ���� �ʾƵ� �Ǵ��� Ȯ��
			if (sameText[inputString[i]] != sameText[prevString] || ' ' == sameText[prevString])
			{
				result += (allText[inputString[i]] * p);
			}

			// ���� �׷쿡 �����ִٸ�
			else
			{
				result += w + (allText[inputString[i]] * p);
			}
		}

		++i; 

	}

	std::cout << result;

}

void MinMax()
{
	int count;
	std::cin >> count;

	int input;
	int min = 1000001;
	int max = -1000001;

	for (int i = 0; i < count; ++i)
	{
		std::cin >> input;

		if (input > max)
		{
			max = input;
		}

		if (input < min)
		{
			min = input;
		}
	}

	std::cout << min << ' ' << max;
}

void CountWord()
{
	std::string sentence;
	std::getline(std::cin, sentence);

	int wordCount = 0;
	char prevWord = ' ';

	for (size_t i = 0; i < sentence.length(); ++i)
	{	
		// ���� �ܾ ������ ��� 
		if (' ' == prevWord &&
			' ' != sentence[i])
		{
			++wordCount;
		}

		prevWord = sentence[i];
	}

	std::cout << wordCount;
}

std::vector<int> Tuple(std::string s)
{
	vector<int> answer;

	string number;
	map<string, int> tuple;

	// ���ڸ� �����鼭
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '{')
		{
			continue;
		}

		else if (s[i] == ',' || s[i] == '}')
		{
			// �̹� �����ϴ� �������� Ȯ��
			if (number.size() != 0)
			{
				auto iter = tuple.find(number);

				if (iter == tuple.end())
				{
					//tuple.insert({ number, 1 });
					tuple.insert(std::pair<string, int>(number, 1));

				}

				else
				{
					iter->second++;
				}

				number.clear();
			}
		}

		// ������ ���
		else
		{
			number += s[i];
		}
	}


	map<int, string, greater<int>> sortTuple;

	for (auto iter = tuple.begin(); iter != tuple.end(); ++iter)
	{
		sortTuple.insert({ iter->second,iter->first });
	}

	for (auto iter = sortTuple.begin(); iter != sortTuple.end(); ++iter)
	{
		answer.push_back(stoi(iter->second));
	}

	return answer;

}

int LeastCommonMultiple(std::vector<int> arr)
{
	int answer = 0;

	sort(arr.begin(), arr.end());

	int rest = 0;

	if (arr.size() == 1)
	{
		return arr[0];
	}

	answer = arr[0];

	for (int i = 1; i < arr.size(); ++i)
	{
		int current = arr[i];

		// ���� ���� ����� ���
		int bigger = max(answer, current);
		int divide = min(answer, current);
		int remainder = bigger % divide;

		// ����� ���
		if (remainder == 0)
		{
			answer = bigger;
		}

		else
		{
			int total = current;
			while ((total % answer) != 0)
			{
				total += current;
			}

			answer = total;
		}
	}

	return answer;
}
