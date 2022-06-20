#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int> solution(vector<int> answers) {

    //���� ���� ������
    vector<int> answer;

    vector<int> answer_count = { 0, 0, 0 };

    //������ 3����
    //���� 2�� �ݺ���
    vector<int> answer1 = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5}; //5���� �ݺ�
    vector<int> answer2 = { 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5 }; //8���� �ݺ�
    vector<int> answer3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }; // 10���� �ݺ�

    static const int solution[3][10] = {
        { 1, 2, 3, 4, 5},
        { 2, 1, 2, 3, 2, 4, 2, 5},
        { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    static const int patternSize[3] = { 5,8,10 };

    int count = 0;
    for (vector<int>::iterator iter = answers.begin(); iter != answers.end(); iter++)
    {
        
        if (*iter == solution[0][count % patternSize[0]])
        {
            answer_count[0] += 1;
        }

        if (*iter == solution[1][count % patternSize[1]])
        {
            answer_count[1] += 1;
        }

        if (*iter == solution[2][count % patternSize[2]])
        {
            answer_count[2] += 1;
        }

        count++;
    }
    
    //3�� ū ������ ����
    int max_count = max(answer_count[0], max(answer_count[1], answer_count[2]));

    for (int i = 0; i < 3; i++)
    {
        if (max_count == answer_count[i])
        {
            answer.push_back(i + 1);
        }
    }

    sort(answer.begin(), answer.end());


    return answer;
}


int main() {
    vector<int> answers = { 1 ,2,3,4,5};
    vector<int> result = solution(answers);
    //iter�� �ݺ����̰� iter�ݺ��ڴ� result�� �����ּҸ� ������.
    for (vector<int>::iterator iter = result.begin(); iter != result.end(); iter++)
    {
        cout << *iter << ",";
    }

    return 0;
}