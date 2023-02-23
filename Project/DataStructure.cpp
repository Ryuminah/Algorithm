#include "DataStructure.h"

void TalkMiddle()
{
    int N;
    cin >> N;

    vector<int> v;
    int number;
    for (int i = 0; i < N; ++i)
    {
        cin >> number;
        v.push_back(number);
    }

    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;

    for (int i = 0; i < N; ++i)
    {
        // �ִ� ���� ũ��� �׻� �ּ� ���� ���ų� 1��ŭ �� Ŀ�� ��
        if (maxQ.size() > minQ.size())
        {
            minQ.push(v[i]);
        }
        else
        {
            maxQ.push(v[i]);
        }

        // �ּ� ���� ��� ���Ҵ� �ִ� ���� ��� ���Һ��� �׻� ���ų� Ŀ����
        if (!maxQ.empty() && !minQ.empty())
        {
            if (minQ.top() < maxQ.top())
            {
                int maxTemp = maxQ.top();
                int minTemp = minQ.top();

                maxQ.pop();
                maxQ.push(minTemp);

                minQ.pop();
                minQ.push(maxTemp);
            }
        }

        cout << maxQ.top() << '\n';
    }
}

vector<int> DoublePriorityQueue(vector<string> operations)
{
    priority_queue<int> q;
    vector<int> answer;

    for (int i = 0; i < 2; ++i)
    {
        answer.push_back(0);
    }

    for (int i = 0; i < operations.size(); ++i)
    {
        string str = operations[i];;
        if (str.find("I") != string::npos)
        {
            string sCut = str.substr(str.find(' ') + 1);
            int number = stoi(sCut);
            q.push(number);
        }

        else
        {
            if (q.empty())
                continue;

            else
            {
                if (str.find("D 1") != string::npos)
                {
                    q.pop();
                }

                else
                {
                    priority_queue<int> tempQ;
                    while (q.size() != 1)
                    {
                        tempQ.push(q.top());
                        q.pop();
                    }

                    q.swap(tempQ);
                }
            }
        }


    }

    if (!q.empty())
    {
        answer[0] = q.top();
        q.pop();

        while (q.size() != 1)
        {
            q.pop();
        }

        answer[1] = q.top();
    }

    for (int i = 0; i < 2; ++i)
    {
        cout << answer[i] << ' ';
    }

    return answer;
}

vector<int> DoublePriorityQueue2(vector<string> operations)
{
    vector<int> answer;
    multiset<int> table;

    for (int i = 0; i < 2; ++i)
        answer.push_back(0);

    for (int i = 0; i < operations.size(); ++i)
    {
        string str = operations[i];

        if (str.find("I") != string::npos)
        {
            string sCut = str.substr(str.find(' ') + 1);
            int number = stoi(sCut);
            table.insert(number);
        }

        else if (str.find("D 1") != string::npos)
        {
            if (table.size() != 0)
                table.erase(--table.end());
        }

        else
        {
            if (table.size() != 0)
                table.erase(table.begin());
        }
    }

    if (table.size() != 0)
    {
        answer[0] = *(--table.end());
        answer[1] = *(table.begin());
    }

    return answer;
}

bool Compare(pair<int, int>& a, pair<int, int>& b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> BestAlbum(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    map<string, int> playsTable;             // ��� Ƚ�� ���
    map<string, vector<int>> musicTable;    // ���� ��ȣ ���

    for (int i = 0; i < genres.size(); ++i)
    {
        // ��� Ƚ���� ���
        playsTable[genres[i]] += plays[i];

        if (musicTable.find(genres[i]) == musicTable.end())
        {
            vector<int> v;
            v.push_back(i);
            musicTable.insert({ genres[i], v });
        }

        else
            musicTable[genres[i]].push_back(i);
    }

    map<int, string, greater<int>> playsCount;
    for (auto iter : playsTable)
    {
        playsCount.insert({ iter.second, iter.first });
    }

    // ��� Ƚ���� ���� �帣 �� ���� ��ȣ�� ���� ������ ����
    for (auto iter : playsCount)
    {
        string name = iter.second;
        vector<int> v = musicTable[name];

        // ��� Ƚ���� �������� �ٽ� �������ش�
        vector<pair<int, int>> vPlay;
        for (int i = 0; i < v.size(); ++i)
        {
            pair<int, int> value(plays[v[i]], v[i]);
            vPlay.push_back(value);
        }

        sort(vPlay.begin(), vPlay.end(), Compare);
        for (int i = 0; i < vPlay.size(); ++i)
        {
            if (i == 2)
                break;

            answer.push_back(vPlay[i].second);
        }
    }

    return answer;
}

bool CheckIdMatch(string a, string b)
{
    if (a.size() != b.size()) return false;

    for (int i = 0; i < a.size(); i++) {
        if (b[i] == '*') continue;
        if (a[i] != b[i]) return false;
    }

    return true;
}

// �ٸ��� ��ø�Ǵ� ����� ���� ���Ͽ� �����غ��ƾ� ��
int BannedUser(vector<string> user_id, vector<string> banned_id)
{
    set<vector<string> > s;
    sort(user_id.begin(), user_id.end());//permutation�� ���� ����

    vector<int> v;
    for (int i = 0; i < user_id.size(); i++)
    {
        v.push_back(0);
    }
    for (int i = 0; i < banned_id.size(); i++)
    {
        v[i] += 1;
    } // n P r

    do {
        vector<string> tmp;
        for (int i = 0; i < user_id.size(); i++)
        {
            if (v[i] == 1) 
            {
                if (CheckIdMatch(user_id[i], banned_id[i])) 
                {
                    tmp.push_back(user_id[i]);
                }
            }
        }

        sort(tmp.begin(), tmp.end());

        if (tmp.size() == banned_id.size())
        {
            s.insert(tmp);
        }

    } 
    while (next_permutation(user_id.begin(), user_id.end()));
    //������ ������ ��ȸ�ϸ� user_id, banned_id�� Ȯ���Ѵ�. ��ġ�ϸ� tmp �迭�� �߰��Ѵ�.
    //���İ� set�� ���� �ߺ��� �����ϰ� ���̰� ���ǿ� ������ insert

    return s.size();
}
