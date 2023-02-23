#include "etc.h"

string MaxMin(string s)
{
    vector<int> numbers;
    string answer = "";

    string number = "";
    for (int i = 0; i < s.length(); ++i)
    {
        number += s[i];

        if (s[i] == ' ' || i == (s.length() - 1))
        {
            numbers.push_back(stoi(number));
            number.clear();
        }
    }

    sort(numbers.begin(), numbers.end());

    answer += to_string(numbers[0]);
    answer += ' ';
    answer += to_string(numbers[numbers.size() - 1]);

    return answer;
}

bool CheckLine(bool* arr, int findCount, string currentWord)
{
    bool result = false;
    int checkCount = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (arr[i])
        {
            ++checkCount;
        }
    }

    // �� �ٿ��� �ϳ��� ã��, �ܾ ���� ã�Ҵٸ�
    if (checkCount == 3 &&
        findCount == currentWord.length())
    {
        result = true;
    }

    return result;
}

vector<string> CardGame(vector<string> card, vector<string> word)
{
    vector<string> answer = {};

    // �� �ܾ�� vector�� ���� Ž���ؾ���.
    for (int i = 0; i < word.size(); ++i)
    {
        string strCard;
        // ī�带 �ϳ��� ���ڿ��� ��ȯ
        for (int i = 0; i < card.size(); ++i)
        {
            strCard += card[i];
        }

        string currentWord = word[i];
        int findCount = 0;
        bool checkLine[3] = { false };

        for (int j = 0; j < currentWord.length(); ++j)
        {
            char findChar = currentWord[j];
            int pos = strCard.find(findChar);

            // ���ڰ� �������� ���� ���
            if (pos == -1)
            {
                cout << findChar;
                break;
            }
            else
            {
                // ã���� ��� �ش� ���ڸ� �ҹ��ڷ� �ٲ���(ã�� ó��)
                strCard[pos] += 32;

                int line = pos / 8;
                checkLine[line] = true;
                ++findCount;
            }
        }

        if (CheckLine(checkLine, findCount, currentWord))
        {
            answer.push_back(currentWord);
        }
    }

    if (answer.size() == 0)
    {
        answer.push_back("-1");
    }

    return answer;

}

int MakeBtoA(string before, string after)
{
    int answer = 1;
    unordered_map<char, int> beforeTable;
    unordered_map<char, int> afterTable;

    // �ܾ ���
    for (int i = 0; i < before.length(); ++i)
    {
        // table�� ���� ���
        if (beforeTable.find(before[i]) == beforeTable.end())
            beforeTable[before[i]] = 1;
        else
            ++beforeTable[before[i]];

        if (afterTable.find(after[i]) == afterTable.end())
            afterTable[after[i]] = 1;
        else
            ++afterTable[after[i]];
    }


    //���ڿ��� ���ڰ� ������, ���� ������ ������ Ȯ��
    auto iter = afterTable.begin();
    auto iterEnd = afterTable.end();

    for (; iter != iterEnd; ++iter)
    {
        // ���ĺ��� �������� ���� ���
        if (beforeTable.find(iter->first) == beforeTable.end())
            return 0;

        // ���ĺ��� �����ϴ� ��� ö�� ������ Ȯ����
        else
        {
            if (beforeTable[iter->first] != iter->second)
                return 0;
        }
    }

    return answer;
}

string MorseSign(string letter)
{
    string answer = "";
    string morse = "'.-':'a','-...':'b','-.-.':'c','-..':'d','.':'e','..-.':'f','--.':'g','....':'h','..':'i','.---':'j','-.-':'k','.-..':'l','--':'m','-.':'n','---':'o','.--.':'p','--.-':'q','.-.':'r','...':'s','-':'t','..-':'u','...-':'v','.--':'w','-..-':'x','-.--':'y','--..':'z'";

    // Map�� ���� table����
    map<string, char> morseTable;
    string morseSign = "";
    for (int i = 0; i < morse.length(); ++i)
    {
        if (morse[i] == '.' || morse[i] == '-')
        {
            morseSign += morse[i];
        }

        // ���� �� ���
        else if (morse[i] >= 'a' && morse[i] <= 'z')
        {
            morseTable[morseSign] = morse[i];
            morseSign.clear();
        }
    }

    string morseLetter = "";
    for (int i = 0; i < letter.length(); ++i)
    {
        if (letter[i] != ' ')
        {
            morseLetter += letter[i];
        }

        else
        {
            answer += morseTable[morseLetter];
            morseLetter.clear();
        }
    }

    // ������ ö�ڴ� ����
    answer += morseTable[morseLetter];

    return answer;
}
