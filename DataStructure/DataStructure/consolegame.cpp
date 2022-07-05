#include <iostream>
#include <vector>
#include <windows.h>
#include <queue>
#include <stack>

#define mapSize 10
#define INF 1e9//10��
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

			if (!(map[ny][nx] == ' ' || map[ny][nx] == 'E'))
			{
				continue;
			}

			//nf : ����������� ������������ �� cost ��, ����ġ
			//dg : g�� �밢������ 10*10�迭�� ��� �밢���� ���̴� 14.14...�� => �׷��� 14�� ���Ͻ�
			//h : ���� ��忡�� ������������ �� cost ��, ����ġ

			//(1,1) (10,10) �϶� h�� 18��ȯ(����)
			int nf = dg[i] + h({ nx, ny }, end); //dg�� ���������� 10���������Ƿ� h�� ������


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
		pair<int, int> pair1 = { curr.X, curr.Y };
		stack1.push(pair1);
		curr = path[curr.Y][curr.X];
	}
}
int main()
{

	//Ż����� �����

	//1. ���� �����.
	//2. ��� ��ǥ�� �� x,y ���� �����Ѵ�.
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