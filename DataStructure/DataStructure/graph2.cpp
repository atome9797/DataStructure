#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector<int> graph[1001];

int N, M, V;



//1. �湮 ���θ� �����ؾ� �Ѵ�.
bool isVisited[1001] = { false };

//2. DFS�� ����� ������ �����.
stack<int> st;//���ÿ��� ������ �湮�� ������ �����Ѵ�.

void test(int node)
{

	for (int nextNode : graph[node])
	{
		if (false == isVisited[nextNode])
		{
			st.push(nextNode);
			isVisited[nextNode] = true;

			int node2 = st.top();
			st.pop();
			cout << node2 << ' '; //stack�̶� 1 4 3 2���� 

			test(nextNode);
		}
	}
}

void dfs()
{
	st.push(V);//ù ��°�� �湮�� ����
	isVisited[V] = true;

	//3.���̻� �湮�� ������ ���������� �湮�Ѵ�.
	int node = st.top();
	test(node);
	
	while (st.empty() == false) //������ ����ִٸ� ��� ������ �湮�� ���̴�.
	{
		// 3-1. ������ �湮�Ѵ�.
		st.pop();
		cout << node << ' '; //stack�̶� 1 4 3 2���� 

		// 3-2. �������� �湮�� ������ ã�´�.
	}
}

void bfs()
{
	//1. �湮 ���θ� �����ؾ� �Ѵ�.
	bool isVisited[1001] = { false };

	//2. BFS�� ����� ť�� �����.
	queue<int> que;//ť���� ������ �湮�� ������ �����Ѵ�.

	que.push(V);//ù ��°�� �湮�� ����
	isVisited[V] = true;

	//3.���̻� �湮�� ������ ���������� �湮�Ѵ�.
	while (que.empty() == false) //������ ����ִٸ� ��� ������ �湮�� ���̴�.
	{
		// 3-1. ������ �湮�Ѵ�.
		int node = que.front();
		que.pop();
		cout << node << ' '; //stack�̶� 1 4 3 2���� 

		// 3-2. �������� �湮�� ������ ã�´�.
		for (int nextNode : graph[node])
		{
			if (false == isVisited[nextNode])// node -> nextNode �� �湮 �������� �湮
			{
				que.push(nextNode);
				isVisited[nextNode] = true;
			}
		}
	}
}

/*
	DFS, BFS

	1. �湮���θ� ������ ������ �����Ѵ�.
	=> ��? ��湮�� ���� ����

	2. DFS��� ������ �����,BFS��� ť�� �����Ѵ�.
	=> �����̳� ť�� ����Ǵ� �����ʹ� ������ �湮�� ����

	3. ���̻� �湮�� ������ ���������� �湮�Ѵ�.
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//1.�׷��� ����
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e); //������ �׷����� ���� �۾�
		graph[e].push_back(s); //������ �׷����� ���� �۾�
	}

	//2. ���� �������� �湮��Ű�� ���� ����
	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end()); //�� ���� vector�� ����� ���Ҹ� ������
	}

	//3. DFS
	dfs();

	cout << "\n";

	bfs();
}