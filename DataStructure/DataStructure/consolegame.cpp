#include <iostream>
#include <vector>
#include <windows.h>
#include <queue>
#include <stack>

#define mapSize 10
#define INF 1e9//10억
char map[mapSize][mapSize];
using namespace std;

stack <pair<int,int>> stack1;

int random()
{
	srand(time(NULL));
	
	int random= rand() % 10;
	return random;
}

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
		return (X == other.X) && (Y == other.Y);
	}
	bool operator!=(const Pos& other) const
	{
		return !(* this == other);
	}
};

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

			if (!(map[ny][nx] == ' ' || map[ny][nx] == 'E'))
			{
				continue;
			}

			//nf : 출발지점에서 목적지까지의 총 cost 합, 가중치
			//dg : g는 대각선으로 10*10배열의 경우 대각선의 길이는 14.14...임 => 그래서 14로 정하심
			//h : 현재 노드에서 목적지까지의 총 cost 합, 가중치

			//(1,1) (10,10) 일때 h는 18반환(절댓값)
			int nf = dg[i] + h({ nx, ny }, end); //dg는 비율때문에 10곱해졌으므로 h도 곱해줌


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
		pair<int, int> pair1 = { curr.X, curr.Y };
		stack1.push(pair1);
		curr = path[curr.Y][curr.X];
	}
}
int main()
{

	//탈출게임 만들기

	//1. 맵을 만든다.
	//2. 사람 좌표로 쓸 x,y 값을 지정한다.
	int playerX = 0;
	int playerY = 0;
	int ranX = 0;
	int ranY = 0;

	ranX = random();
	ranY = random();

	while (ranX == 0 && ranY == 0)
	{
		ranX = random();
		ranY = random();
	}

	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
		{
			map[i][j] = ' ';
		}
	}

	map[playerX][playerY] = 'P';
	map[ranX][ranY] = 'E';


	astar({ playerX ,playerY }, { ranX ,ranY });

	while (1)
	{

		Sleep(50);

		system("cls");
		
		for (int i = 0; i < mapSize; i++)
		{
			for (int j = 0; j < mapSize; j++)
			{
				map[i][j] = ' ';
			}
		}

		map[playerX][playerY] = 'P';
		map[ranX][ranY] = 'E';

		
		for (int i = 0; i < mapSize; i++)
		{
			for (int j = 0; j < mapSize; j++)
			{
				cout << map[i][j];
			}
			cout << "\n";
		}

		if (playerX == ranX && playerY == ranY)
		{
			ranX = random();
			ranY = random();

			while (ranX == 0 && ranY == 0)
			{
				ranX = random();
				ranY = random();
			}

			for (int i = 0; i < mapSize; i++)
			{
				for (int j = 0; j < mapSize; j++)
				{
					map[i][j] = ' ';
				}
			}

			map[playerX][playerY] = 'P';
			map[ranX][ranY] = 'E';

			astar({ playerX ,playerY }, { ranX ,ranY });

			continue;
		}


		playerX = stack1.top().first;
		playerY = stack1.top().second;
		stack1.pop();
	}
	


	return 0;
}