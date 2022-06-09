#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {

    srand(time(NULL));
    //많이 맞춘 정답자
    vector<int> answer;

    vector<int> answer_count = { 0, 0, 0 };

    //수포자 3명임
    vector<int> answer1;
    vector<int> answer2;
    vector<int> answer3;

    //answers사이즈 만큼만 랜덤 얻으면됨
    for (int i = 0; i < answers.size(); i++)
    {
        answer1.push_back(rand() % 5 + 1);
        answer2.push_back(rand() % 5 + 1);
        answer3.push_back(rand() % 5 + 1);
    }

    vector<int>::iterator iter = answers.begin();
    vector<int>::iterator iter_answer1 = answer1.begin();
    vector<int>::iterator iter_answer2 = answer2.begin();
    vector<int>::iterator iter_answer3 = answer3.begin();
    
    
    while (iter != answers.end())
    {
        if (*iter == *iter_answer1) {
            answer_count[0] += 1;
        }else if (*iter == *iter_answer2) {
            answer_count[1] += 1;
        }else if (*iter == *iter_answer3) {
            answer_count[2] += 1;
        }

        iter++;
        iter_answer1++;
        iter_answer2++;
        iter_answer3++;
    }




    answer.push_back(1);

    if (answer_count[0] == answer_count[1])
    {
        answer.push_back(2);
    }
    if (answer_count[0] < answer_count[1])
    {
        answer.pop_back();
        answer.push_back(2);
    }
    if (answer_count[0] <= answer_count[1] && answer_count[1] == answer_count[2])
    {
        answer.push_back(3);
    }
    if (answer_count[0] <= answer_count[1] && answer_count[1] < answer_count[2])
    {
        answer.pop_back();
        answer.push_back(3);
    }





    return answer;
}


int main() {
    vector<int> answers = { 1 ,2,3,4,5};
    vector<int> result = solution(answers);
    for (vector<int>::iterator iter = result.begin(); iter != result.end(); iter++)
    {
        cout << *iter << ",";
    }

    return 0;
}