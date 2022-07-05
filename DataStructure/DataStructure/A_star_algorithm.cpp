#include <iostream>
#include <queue>
#include <vector>

#define START_X 9
#define START_Y 9
#define END_X   2
#define END_Y   2

#define INF 1e9

using namespace std;

//가중치 아님 맵임 => 그리고 모든 거리가 같기 때문에 가중치는 없다.
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
    return abs(a.X - b.X) + abs(a.Y - b.Y);//abs 절댓값 반환
}

void astar(Pos start, Pos end)
{
    vector<vector<int>> f;
    for (int i = 0; i < 10; ++i)
        f.emplace_back(10, INF); //10by10
    f[start.Y][start.X] = 0;

    Pos path[10][10];
    path[start.Y][start.X] = start;//시작 지점 2,4를 구조체 x,y값에 넣어줌
    //클래스 이므로 할당 가능하다. 복사할당연산자 실행됨

    priority_queue<pair<int, Pos>> pq;
    pq.emplace(0, start);

    //상하좌우 대각선 포함
    int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int dg[] = { 10, 14, 10, 14, 10, 14, 10, 14 };
    //1: 1.4 비율인데 소수점 쓰기싫어서 10곱해줌
    //0이 있으면 좌우로만 움직이니까 총 길이 10을 쓰고
    //0이 없으면 x,y 둘다 움직이니까 대각선 총길이 14씀

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

            //nf : 출발지점에서 목적지까지의 총 cost 합, 가중치
            //dg : g는 대각선으로 10*10배열의 경우 대각선의 길이는 14.14...임 => 그래서 14로 정하심
            //h : 현재 노드에서 목적지까지의 총 cost 합, 가중치

            //(1,1) (10,10) 일때 h는 18반환(절댓값)
            int nf = dg[i] + (h({ nx, ny }, end) * 10); //dg는 비율때문에 10곱해졌으므로 h도 곱해줌


            if (f[ny][nx] > nf)
            {
                f[ny][nx] = nf;

                path[ny][nx] = pos;

                pq.emplace(-f[ny][nx], Pos{ nx, ny });
            }
        }
    }

    //하위에서 상위로 이동하게 해야함
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
