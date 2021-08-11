#include "GreedyAlgorithm.h"
#include <algorithm>
#include <vector>

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
        int min = 10000;

        for (int x = 0; x < N; ++x)
        {
            // ���� ���ڰ� ���� �ּڰ����� �۴ٸ� ��ü
            if (Card[x][y] < min)
            {
                min = Card[x][y];
            }
        }

        MinNumbers.push_back(min);
    }

    // ���� �� ��ŭ ũ�� ��
    for (int i = 0; i < N; ++i)
    {
        if (MinNumbers[i] > Result)
        {
            Result = MinNumbers[i];
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



