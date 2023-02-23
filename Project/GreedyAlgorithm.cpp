#include "GreedyAlgorithm.h"

using namespace std;
//21. 8.8 ���� 1
void Change()
{
    int n = 0;
    int coinCount = 0;

    std::cin >> n;

    int coins[4] = { 500,100,50,10 };

    for (int i = 0; i < 4; ++i)
    {
        int coin = coins[i];
        coinCount += n / coin;
        n %= coin;
    }
    std::cout << coinCount;
}

//21.8.9 2�� ū ���� ��Ģ
void RulesOfBigNumber1()
{
    int N = 0;
    int M = 0;
    int K = 0;
    int Result = 0;

    std::cin >> N;
    std::cin >> M;
    std::cin >> K;

    // �Է°� ��ŭ �迭�� ũ�⸦ 
    std::vector<int> arr;
    arr.reserve(N);
    
    for (int i = 0; i < N; ++i)
    {
        int input = 0;
        std::cin >> input;
        arr.push_back(input);
    }
    
    // ���ڰ� �������� Ƚ����ŭ �ݺ��� ����
    int CountCheck = K;

    for (int i = 0; i < M; ++i)
    {
        // ���� ū �� ���ڸ� ��Ƴ��� ����
        int firstBigNum = 0;
        int secondBigNum = 0;

        // ���� ū �� ���� ���� ����
        for (int j = 0; j < N; ++j)
        {
            // �迭�� ���� �ε����� ����Ǿ��ִ� ������ ũ�ٸ�
            if (arr[j] >= firstBigNum)
            {
                // �� ���� ����.
                secondBigNum = arr[j];

                // ���� ���� �ִ񰪺��� �� ũ�ٸ�,
                if (secondBigNum >= firstBigNum)
                {
                    // ���� ū ���� ��ü���ش�.
                    secondBigNum = firstBigNum;
                    firstBigNum = arr[j];
                }
            }
        }
        
        // �ݺ��� �� �ִ� ������ Ƚ���� ������ ������ ��
        if (CountCheck == 0)
        {
            Result += secondBigNum;
            CountCheck = 3;
        }

        else
        {
            Result += firstBigNum;
            --CountCheck;
        }
    }

    std::cout << Result;
}

void RulesOfBigNumber2()    // ������ �̿��� Ǯ�� ���
{
    int N = 0;
    int M = 0;
    int K = 0;
    int Result = 0;

    std::cin >> N;
    std::cin >> M;
    std::cin >> K;

    // �Է°� ��ŭ �迭�� ũ�⸦ ����
    std::vector<int> arr;
    arr.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        int input = 0;
        std::cin >> input;
        arr.push_back(input);
    }

    // stl�� �̿��� ����
    std::sort(arr.begin(), arr.end(), std::greater<int>());

    // ���� ū ���� �ι�°�� ū ��
    int first = arr[0];
    int second = arr[1];

    // ������ �ݺ��Ǵ� Ƚ���� ���� ��, �̸� ���Ͽ� ���� ū ���� �����ϴ� ���� ����.
    int firstCount = (M / (K + 1)) * K;

    // �������� �����Ѵٸ�, ������ ��ŭ ū ���� �ݺ��� ��.
    firstCount += M % (K + 1);
    int secondCount = M - firstCount;

    Result = (first * firstCount) + (second * secondCount);

    std::cout << Result;
}

//21.8.10 3�� ���� ī�� ����
void NumberCardGame1()
{
    int N = 0;
    int M = 0;
    int Result = 0;

    std::cin >> N;
    std::cin >> M;

    // 2���� �迭 ���� (N����ŭ ��, 0���� �ʱ�ȭ�� M�� ��ŭ�� ���� ���� vector�� �����ϰڴ�)
    std::vector<std::vector<int>> Card(N, std::vector<int>(M,0));
    
    // ī�� �Է¹ޱ�
    for (int y = 0; y < M; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            int Number = 0;
            std::cin >> Card[x][y];
        }
    }

    std::vector<int> MinNumbers;

    for (int y = 0; y < M; ++y)
    {
        int min = 10001;

        for (int x = 0; x < N; ++x)
        {
            // ���� ���ڰ� ���� �ּڰ����� �۴ٸ� ��ü
            if (Card[x][y] < min)
            {
                min = Card[x][y];
            }
        }
        
        if (min > Result)
        {
            Result = min;
        }
    }

    std::cout << Result << std::endl;
}

void NumberCardGame2()
{
    int N = 0;
    int M = 0;
    int Result = 0;

    std::cin >> N;
    std::cin >> M;
 
    // ī�� �Է¹ޱ�
    for (int y = 0; y < M; ++y)
    {
        int min = 10001;

        for (int x = 0; x < N; ++x)
        {
            int Number = 0;
            std::cin >> Number;

            // �� �ٿ��� ���� ū ���� ���ϱ�.
            if (min > Number)
            {
                min = Number;
            }
        }

        // ���� �� �߿��� ū �� ã��
        if (min > Result)
        {
            Result = min;
        }
    }

    std::cout << Result << std::endl;

}

//21.8.11 4�� 1�� �ɶ�����
void MakeOne()
{
    int N = 0;
    int K = 0;
    int Count = 0;

    std::cin >> N >> K;

    // N�� 1�� �� �� ���� while ��
    while (N != 1)
    {
        // ���� �������� ���� ��쿡�� 1�� ����
        if (N % K != 0)
        {
            N -= 1;
        }

        // ������ ��쿡�� �׻� �������� �Ѵ�.
        else
        {
            N /= K;
        }

        ++Count;
    }

    std::cout << Count << std::endl;
}

//21.8.12 ���� 4796�� ķ��
void Camping()
{
    int InputCheck = 0;

    while (true)
    {
        int L, P, V;

        std::cin >> L >> P >> V;
        ++InputCheck;

        if (L == 0 && P == 0 && V == 0)
        {
            break;
        }

        int Result = L * (V / P);
        int  remainder = V % P;

        if (L > remainder)
        {
            Result += remainder;
        }

        else
        {
            Result += L;
        }

        std::cout << "Case " << InputCheck << ": " << Result << std::endl;
    }
}

void ATM()
{
    // Input
    int N = 0;
    std::cin >> N;

    std::vector<int> P;
    P.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        int time = 0;
        std::cin >> time;
        P.push_back(time);
    }

    // �迭�� ������������ ����
    std::sort(P.begin(), P.end());

    int result = 0;
    int finalResult = 0;

    for (int i = 0; i < N; ++i)
    {
        int currentTime = P[i] + result;
        result = currentTime;

        finalResult += result;
    }

    // Output
    std::cout << finalResult;
}

std::string MakeBigNumber(std::string number, int k)
{
    string answer = "";

    int index = -1;
    for (int i = 0; i < number.size() - k; ++i)
    {
        char maxValue = ' ';
        for (int j = index + 1; j <= k + i; j++)
        {
            if (maxValue < number[j])
            {
                maxValue = number[j];
                index = j;
            }
        }
        answer += maxValue;
    }

    return answer;
}

int JoyStick(std::string name)
{
    int answer = 0;
    int n = name.length();

    // ���̽�ƽ�� �� �������θ� �������� ��
    int moveOneDirection = n - 1;

    for (int i = 0; i < n; i++)
    {
        if (name[i] - 'A' < 14)
        {
            answer += name[i] - 'A';
        }

        else
        {
            answer += 'Z' - name[i] + 1;
        }


        int index = i + 1;

        while (index < n &&
            name[index] == 'A')
        {
            ++index;
        }

        moveOneDirection = min(moveOneDirection, (i + n - index) + min(i, n - index));
    }

    answer += moveOneDirection;
    return answer;
}

int SweatSuit(int n, vector<int> lost, vector<int> reserve)
{
    int answer = n;

    // Ȯ���ϰ� ������ �� �ִ� ����� table�� ���.

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    unordered_map<int, bool> reserveTable;

    for (int i = 0; i < reserve.size(); ++i)
    {
        reserveTable[reserve[i]] = true;
    }

    for (int i = 0; i < lost.size(); ++i)
    {
        auto iter = reserveTable.find(lost[i]);

        // �������� ���� ���� ��Ȳ�̶��
        if (iter != reserveTable.end())
        {
            reserveTable.erase(iter->first);
            lost[i] = -1;
        }
    }


    for (int i = 0; i < lost.size(); ++i)
    {
        // �Ҿ�������� ������ �־ �Ⱥ����� �Ǵ� ��
        if (lost[i] == -1)
        {
            continue;
        }

        // ������ ã�ƺ� �� 
        auto iter = reserveTable.find(lost[i] - 1);

        // �����ȴٸ� �������� Ȯ��
        if (iter == reserveTable.end())
        {
            iter = reserveTable.find(lost[i] + 1);
        }

        // �ᱹ ������ ��
        if (iter == reserveTable.end())
        {
            --answer;
        }

        // ���ȴٸ� ������ �� �ִ� Table���� ���������
        else
        {
            reserveTable.erase(iter->first);
        }
    }

    return answer;
}

bool Compare(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}

int SpeedCamera(vector<vector<int>> routes)
{
    // �������� ������ �ٽ��� ����
    int answer = 0;
    int camera = -300001;

    sort(routes.begin(), routes.end(), Compare);

    for (int i = 0; i < routes.size(); ++i)
    {
        if (routes[i][0] > camera)
        {
            ++answer;
            camera = routes[i][1];
        }
    }


    return answer;
}


int island[101] = { 0 };
bool Comp(vector<int>& v1, vector<int>& v2)
{
    return v1[2] < v2[2];
}

int FindParent(int index)
{
    if (island[index] == index) { return index; }
    return island[index] = FindParent(island[index]);
}

int LinkIsland(int n, vector<vector<int>> costs)
{
    int answer = 0;
    int bridge = 0;

    for (int i = 0; i < n; ++i)
    {
        island[i] = i;
    }

    // �������� ����
    sort(costs.begin(), costs.end(), Comp);

    for (int i = 0; i < costs.size(); ++i)
    {
        int startParent = FindParent(costs[i][0]);
        int endParent = FindParent(costs[i][1]);
        int cost = costs[i][2];

        // �θ� �ٸ��� �Ǽ�
        if (startParent != endParent)
        {
            island[endParent] = startParent;
            answer += cost;
            ++bridge;
        }

        if (bridge == n - 1)
        {
            break;
        }
    }

    return answer;
}

void MissingParentheses()
{
    int answer = 0;
    string expression;
    cin >> expression;

    string number;
    int currentNumber;
    bool isMinus = false;

    // ��ȣ�� ���ڸ� �и��ؼ� ����
    for (int i = 0; i <= expression.size(); ++i)
    {
        // ��ȣ �� ���
        if (expression[i] == '-' || expression[i] == '+' ||
            i == expression.size())
        {
            currentNumber = stoi(number);
            number.clear();

            // ������ ��ȣ�� ���� ����� �޸���
            if (isMinus)
            {
                answer -= currentNumber;
            }

            else
            {
                answer += currentNumber;
            }


            isMinus = expression[i] == '-' ? true : isMinus;
        }

        // ������ ���
        else
        {
            number += expression[i];
        }

    }

    cout << answer;
}

void Sensor()
{
    int answer = 0;
    int N, K;
    cin >> N >> K;

    vector<int> vSensor;
    for (int i = 0; i < N; ++i)
    {
        int pos;
        cin >> pos;
        vSensor.push_back(pos);
    }

    sort(vSensor.begin(), vSensor.end());


    vector<int> vDistance;
    for (int i = 1; i < N; ++i)
    {
        vDistance.push_back(vSensor[i] - vSensor[i - 1]);
    }

    sort(vDistance.begin(), vDistance.end());

    if (N >= K)
    {
        answer = accumulate(vDistance.begin(), vDistance.begin() + (N - K), 0);
    }

    cout << answer;
}

void Sensor1()
{
    int N, K, answer = { 0 };
	int sensor[10001] = { 0 };

	cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		cin >> sensor[i];
	}

	sort(sensor, sensor + N);

	vector<int> vDistance;
	// ������ ������ �Ÿ��� �� ������ �����Ƿ�
	for (int i = 1; i < N; ++i)
	{
		vDistance.push_back(sensor[i] - sensor[i - 1]);
	}

	// |--���߱�--| ����� |----���߱�----| �� ������ ���� ū �κ��� �����ϰ� ���ϸ� �ȴ�.
	// ���� ������������ ������ �� �� k-1������ ������� ���Ѵ�
	sort(vDistance.begin(), vDistance.end(), greater<int>());

	// K-1�� ��ŭ ������� ����� ������ K-1�� ��ȸ
	for (int i = K-1; i < vDistance.size(); ++i)
	{
		answer += vDistance[i];
	}

	cout << answer;

}

int InstallBaseStation(int n, vector<int> stations, int w)
{
    int answer = 0;
    int index = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (index < stations.size() && i >= stations[index] - w)
        {
            i = stations[index] + w;
            ++index;
        }
        else
        {
            ++answer;
            i += w * 2;
        }
    }

    return answer;
}



