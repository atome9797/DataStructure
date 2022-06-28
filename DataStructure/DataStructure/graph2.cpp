#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector<int> graph[1001];

int N, M, V;


void dfs()
{
	//1. 방문 여부를 저장해야 한다.
	bool isVisited[1001] = { false };

	//2. DFS에 사용할 스택을 만든다.
	stack<int> st;//스택에는 앞으로 방문할 정점을 저장한다.

	st.push(V);//첫 번째로 방문할 정점
	//isVisited[V] = true;

	//3.더이상 방문할 정점이 없을때까지 방문한다.
	while (st.empty() == false) //스택이 비어있다면 모든 정점을 방문한 것이다.
	{
		// 3-1. 정점을 방문한다.
		int node = st.top();
		st.pop();
		if (false == isVisited[node])
		{
			isVisited[node] = true;
			cout << node << ' '; //stack이라 1 4 3 2나옴 
		}

		// 3-2. 다음으로 방문할 정점을 찾는다.
		for (int nextNode : graph[node])
		{
			if (false == isVisited[nextNode])// node -> nextNode 에 방문 안했으면 방문
			{
				st.push(nextNode);
				//isVisited[nextNode] = true;
				//break;
			}
		}
	}
}

void bfs()
{
	//1. 방문 여부를 저장해야 한다.
	bool isVisited[1001] = { false };

	//2. BFS에 사용할 큐을 만든다.
	queue<int> que;//큐에는 앞으로 방문할 정점을 저장한다.

	que.push(V);//첫 번째로 방문할 정점
	isVisited[V] = true;

	//3.더이상 방문할 정점이 없을때까지 방문한다.
	while (que.empty() == false) //스택이 비어있다면 모든 정점을 방문한 것이다.
	{
		// 3-1. 정점을 방문한다.
		int node = que.front();
		que.pop();
		cout << node << ' '; //stack이라 1 4 3 2나옴 

		// 3-2. 다음으로 방문할 정점을 찾는다.
		for (int nextNode : graph[node])
		{
			if (false == isVisited[nextNode])// node -> nextNode 에 방문 안했으면 방문
			{
				que.push(nextNode);
				isVisited[nextNode] = true;
			}
		}
	}
}

/*
	DFS, BFS

	1. 방문여부를 저장할 변수를 생성한다.
	=> 왜? 재방문을 막기 위해

	2. DFS라면 스택을 만들고,BFS라면 큐를 생성한다.
	=> 스택이나 큐에 저장되는 데이터는 다음에 방문할 정점

	3. 더이상 방문할 정점이 없을때까지 방문한다.
*/

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//1.그래프 구성
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	//2. 작은 정점부터 방문시키기 위해 정렬
	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].rbegin(), graph[i].rend());
	}

	//3. DFS
	dfs();

	cout << "\n";

	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	bfs();
}