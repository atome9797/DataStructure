#include <iostream>
#include <queue>
#include <vector>

#define START_X 9
#define START_Y 9
#define END_X   2
#define END_Y   2

#define INF 1e9

using namespace std;

//����ġ �ƴ� ���� => �׸��� ��� �Ÿ��� ���� ������ ����ġ�� ����.
int map[10][10] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 2, 0, 0, 3, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

struct Pos
{
    int X;
    int Y;

    bool operator<(const Pos& other) const
    {
        return (X < other.X) && (Y < other.Y);
    }
    bool operator==(const Pos& other) const
    {
        return X == other.X && Y == other.Y;
    }
    bool operator!=(const Pos& other) const
    {
        return !(*this == other);
    }
};

void PrintMap()
{
    for (int r = 0; r < 10; ++r)
    {
        for (int c = 0; c < 10; ++c)
        {
            if (map[r][c] == 0)
                cout << " ";
            else if (map[r][c] == 1)
                cout << "S";
            else if (map[r][c] == 2)
                cout << "B";
            else if (map[r][c] == 3)
                cout << "E";
            else if (map[r][c] == 4)
                cout << "P";
        }
        cout << endl;
    }
}

int h(Pos a, Pos b)
{
    return abs(a.X - b.X) + abs(a.Y - b.Y);//abs ���� ��ȯ
}

void astar(Pos start, Pos end)
{
    vector<vector<int>> f;
    for (int i = 0; i < 10; ++i)
        f.emplace_back(10, INF); //10by10
    f[start.Y][start.X] = 0;

    Pos path[10][10];
    path[start.Y][start.X] = start;//���� ���� 2,4�� ����ü x,y���� �־���
    //Ŭ���� �̹Ƿ� �Ҵ� �����ϴ�. �����Ҵ翬���� �����

    priority_queue<pair<int, Pos>> pq;
    pq.emplace(0, start);

    //�����¿� �밢�� ����
    int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int dg[] = { 10, 14, 10, 14, 10, 14, 10, 14 };
    //1: 1.4 �����ε� �Ҽ��� ����Ⱦ 10������
    //0�� ������ �¿�θ� �����̴ϱ� �� ���� 10�� ����
    //0�� ������ x,y �Ѵ� �����̴ϱ� �밢�� �ѱ��� 14��

    while (false == pq.empty())
    {
        int w = -pq.top().first;
        Pos pos = pq.top().second;
        pq.pop();

        if (f[pos.Y][pos.X] < w)
        {
            continue;
        }

        if (pos == end)
        {
            break;
        }

        for (int i = 0; i < 8; ++i)
        {
            int ny = dy[i] + pos.Y;
            int nx = dx[i] + pos.X;

            if (ny < 0 || ny >= 10 || nx < 0 || nx >= 10)
            {
                continue;
            }

            if (!(map[ny][nx] == 0 || map[ny][nx] == 3))
            {
                continue;
            }

            //nf : ����������� ������������ �� cost ��, ����ġ
            //dg : g�� �밢������ 10*10�迭�� ��� �밢���� ���̴� 14.14...�� => �׷��� 14�� ���Ͻ�
            //h : ���� ��忡�� ������������ �� cost ��, ����ġ

            //(1,1) (10,10) �϶� h�� 18��ȯ(����)
            int nf = dg[i] + (h({ nx, ny }, end) * 10); //dg�� ���������� 10���������Ƿ� h�� ������


            if (f[ny][nx] > nf)
            {
                f[ny][nx] = nf;

                path[ny][nx] = pos;

                pq.emplace(-f[ny][nx], Pos{ nx, ny });
            }
        }
    }

    //�������� ������ �̵��ϰ� �ؾ���
    Pos curr = end;
    while (curr != start)
    {
        map[curr.Y][curr.X] = 4;

        curr = path[curr.Y][curr.X];
    }


}

int main()
{
    PrintMap();

    puts("");

    astar({ START_X, START_Y }, { END_X, END_Y });

    PrintMap();

}
