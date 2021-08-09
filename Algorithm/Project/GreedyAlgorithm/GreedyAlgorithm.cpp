#include "GreedyAlgorithm.h"
#include <vector>
#include <algorithm>

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

// ���� ������ ������ �̿��Ͽ� Ǯ��
void RulesOfBigNumber2()
{
    // ���� ���� ����^^//
}
