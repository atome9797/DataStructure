#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<int> solution(vector<int> answers) {

    //많이 맞춘 정답자
    vector<int> answer;

    vector<int> answer_count = { 0, 0, 0 };

    //수포자 3명임
    //패턴 2번 반복됨
    vector<int> answer1 = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5}; //5개씩 반복
    vector<int> answer2 = { 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5 }; //8개씩 반복
    vector<int> answer3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }; // 10개씩 반복

    int count = 0;
    for (vector<int>::iterator iter = answers.begin(); iter != answers.end(); iter++)
    {
        int answer1_pattern = count % 5;//0 ~ 4
        int answer2_pattern = count % 8;//0 ~ 7
        int answer3_pattern = count % 10;//0 ~ 9

        if (*iter == answer1[answer1_pattern])
        {
            answer_count[0] += 1;
        }

        if (*iter == answer2[answer2_pattern])
        {
            answer_count[1] += 1;
        }

        if (*iter == answer3[answer3_pattern])
        {
            answer_count[2] += 1;
        }

        count++;
    }
    
    //3중 큰 값으로 세팅
    int max_count = max(answer_count[0], max(answer_count[1], answer_count[2]));

    for (int i = 0; i < 3; i++)
    {
        if (max_count == answer_count[i])
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}


int main() {
    vector<int> answers = { 1 ,2,3,4,5};
    vector<int> result = solution(answers);
    //iter는 반복자이고 iter반복자는 result의 시작주소를 가진다.
    for (vector<int>::iterator iter = result.begin(); iter != result.end(); iter++)
    {
        cout << *iter << ",";
    }

    return 0;
}