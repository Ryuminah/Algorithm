#include "Queue.h"

std::vector<int> DevelopFeature(std::vector<int> progresses, std::vector<int> speeds)
{
    std::queue<int> qDurations;
    std::vector<int> answer;

    // ������ ����� ��ŭ �ɸ����� ���.
    for (int i = 0; i < progresses.size(); ++i)
    {
        int remainAmount = 100 - progresses[i];
        int duration = remainAmount / speeds[i];

        // ������������ ������ �Ϸ� ��
        if ((remainAmount % speeds[i]) != 0)
        {
            duration += 1;
        }

        qDurations.push(duration);
    }

    int day = 1;

    // while �ѹ� �� �Ϸ�
    while (qDurations.size() != 0)
    {
        int endCount = 0;
        --qDurations.front();

        CheckProgress(endCount, day, qDurations);

        if (endCount > 0)
        {
            answer.push_back(endCount);
        }

        ++day;
    }

    return answer;
}

void CheckProgress(int& endCount, int day, std::queue<int>& q)
{
    // ���� ó��
    if (q.size() == 0)
    {
        return;
    }

    // ���� �����ٸ�, �ش� ��¥�� ����� �ٸ� ���� ������ ����
    if (q.front() <= 0)
    {
        q.pop();
        q.front() -= day;
        ++endCount;

        CheckProgress(endCount, day, q);
    }
}
