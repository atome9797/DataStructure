#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //���� �����̳� ����(Ŭ���� ���ø�)
    vector<int> vec;
    cout << boolalpha << vec.empty() << endl;
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;

    //����
    //push_back : ������ �� ���� ������ ����
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(2);
    //{3,4,2}

    //�ݺ���
    // begin() : �����̳��� ù ���Ҹ� ����Ű�� �ݺ���
    // end() : �����̳��� ������ ������ ������ ����Ű�� �ݺ���

    //�������������� :: ���
        //vector<int> Ŭ���� ���� �����ǵ� iterator Ŭ���� ���ø��� �����ͼ� ����Ѵ�.
        //vector<int> ���� �����̳ʴ� ������ �迭 �̹Ƿ� �ּҰ��� �Ҵ������ �ִ�.
    
        //���� �����̳��� int�� �ݺ���(������) ���� => ������ ���ҿ� ���� ����
        //iterator class �� �����Ϳ����� ������� => iterator class�� ������ �ּҸ� �޴´�.
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
    {
        cout << *iter << ",";
    }
    
    cout << endl;


    //{2, 4, 3}
    // rebegin() : �����̳��� ���������Ҹ� ����Ű�� �ݺ���
    // rend() : �����̳��� ù ������ ������ ����Ű�� �ݺ���
    for (vector<int>::reverse_iterator iter = vec.rbegin(); iter != vec.rend(); iter++)
    {
        cout << *iter << ",";
    }

    cout << endl;

    //insert : pos ������ �����͸� ���� �Ѵ�.
    vector<int>::iterator iter = vec.begin();
    ++iter; //2��° ���� 4

    iter = vec.insert(iter, 10); // vec : {3,10,4,2} , iter : &vec[1] (10)
    iter = vec.insert(iter, 3, 5); // vec : {3, 5, 5, 5,10 , 4, 2} , iter : &vec[1] (5)
    iter = vec.insert(iter, vec.begin() + 3, vec.end() - 1); //vec : {3,5, 10, 5, 5, 5 ,10, 4, 2} , iter : &vec[1] (5)

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
    {
        cout << *iter << ",";
    }

    cout << endl;

    //����
    //pop_back :�ǳ��� �ִ� �����͸� ����
    //vec : {3,5, 10, 5, 5, 5 ,10, 4, 2} 
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    //vec : {3,5, 10, 5, 5, 5}

    //erase : pos�� �ִ� �����͸� ����
    vec.erase(vec.begin());
    //vec : {5, 10, 5, 5, 5}
    vec.erase(vec.begin() + 1, vec.begin() + 3);
    //vec : {5, 5, 5, 5}

    //�б�
    cout << vec.front() << endl; //5
    cout << vec.back() << endl; //5
    cout << vec[2] << endl;//5

    //�˻� => �޼ҵ尡 �ƴ϶� �˰��� ���̺귯������ ã�ƺ��� �ִ�.

    //�ٸ� ����
    vector<int> vec2(5); //{0, 0, 0, 0, 0}
    vector<int> vec3(5, 10); //{10, 10, 10, 10, 10}


    return 0;
}