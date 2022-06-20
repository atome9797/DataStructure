#include <forward_list> // std::forward_list�� ���� ���� ���
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    std::forward_list<int> flist;

    // ����
    flist.push_front(1); // push_front() : �� �տ� �����Ѵ�.
    // flist{ 1 }
    flist.insert_after(flist.begin(), 2); // insert_after(pos, value) : pos �ڿ� value�� �����Ѵ�.
    // flist{ 1, 2 }
    flist.push_front(3); // flist { 3, 1, 2 }

    // �ݺ���
    std::forward_list<int>::iterator iter;
    //������ �����ϰ� �ϱ����� ���� ��� �����
    iter = flist.before_begin();
    // [ ]->[3]->[1]->[2]->[ ]
    //  ��
    iter = flist.begin();
    // [ ]->[3]->[1]->[2]->[ ]
    //       ��
    iter = flist.end();
    // [ ]->[3]->[1]->[2]->[ ]
    //                      ��

    // ����
    flist.pop_front(); // pop_front() : ù ��° ���Ҹ� �����Ѵ�.
    // flist{ 1, 2 };
    flist.erase_after(flist.begin()); // erase_after(pos) : pos ���� ���Ҹ� �����Ѵ�.
    // flist{ 1 }
    flist.clear(); // clear() : �����̳ʸ� ���� ����.
    // flist{ }

    // ũ��
    if (flist.empty()) // empty() : ������� Ȯ���Ѵ�.
    {
        std::cout << "flist�� �����.\n";
    }
    // ����! �ٸ� �����̳ʿ� �ٸ��� size()�� ����

    // �Ʒ�ó�� �ʱ�ȭ ����
    std::forward_list<int> flist2 = { 1, 2, 3, 4, 5 };

    // �б�
    std::cout << "flist2.front() : " << flist2.front() << "\n"; // front() : ù ��° ���Ҹ� ��ȯ�Ѵ�.

    // �� : �ٸ� �����̳ʿ� ���������� == / != / > / >= / < / <= ����
    flist = flist2;
    if (flist == flist2)
    {
        std::cout << "flist�� flist2�� ����.\n";
    }

    for (auto element : flist)
    {
        cout << element << endl;
    }

    // C++17���ʹ� ���� Ÿ���� ���� �ʾƵ� �˾Ƽ� �߷��Ѵ�.
    std::forward_list flist3 = { 1, 2, 3, 4, 5 };
    

    //�ݺ��� ��
    for (forward_list<int>::iterator iter = flist3.begin(); iter != flist3.end(); iter++)
    {
        cout << *iter << endl;
    }

    std::forward_list<int> flist4 = { 1,3,4,2,5 };
    flist4.sort();
    for (forward_list<int>::iterator iter = flist4.begin(); iter != flist4.end(); iter++)
    {
        cout << *iter;
    }


    return 0;
}