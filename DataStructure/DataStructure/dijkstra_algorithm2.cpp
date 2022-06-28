#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int graph[7][7] =
{
    {   0,   7, INF, INF,   3,  10, INF },
    {   7,   0,   4,  10,   2,   6, INF },
    { INF,   4,   0,   2, INF, INF, INF },
    { INF,  10,   2,   0,  11,   9,   4 },
    {   3,   2, INF,  11,   0, INF,   5 },
    {  10,   6, INF,   9, INF,   0, INF },
    { INF, INF, INF,   4,   5, INF,   0 }
};

vector<int> st;

vector<int> GetShortestPath(int start)
{
    //distance 배열 만들기
    vector<int> dist(7);
    
    //첫 시작이 0이면 0열의 행의 데이터를 뽑아서 저장함 
    for (int i = 0; i < 7; i++)
    {
        dist[i] = graph[start][i];
    }

    vector<bool> isVisited(7);
    isVisited[start] = true;
    st.push_back(start);

    //모든 정점에 대한 최단 경로를 찾을때까지
    for (int i = 0; i < 7 - 1; i++)
    {
        int next = 0; //인덱스
        int minDist = INF; //값

        for (int node = 0; node < 7; node++)
        {
            if (isVisited[node])
            {
                continue;
            }

            //최솟값을 담음
            if (minDist > dist[node])
            {
                next = node; //인덱스 4
                minDist = dist[node]; //값
            }
        }
        

        //dist행에 있는 데이터에서 최소 거리값을 가지는 인덱스즉 정점을 가져옴


        //방문 표시 => 방문한 정점은 최소 거리임을 보장함
        isVisited[next] = true; //최소거리값의 정점을 true로 만듬
        st.push_back(next);

        for (int node = 0; node < 7; node++)
        {
            //0 정점의 행의 데이터 
            //next : 4
            //graph[4][node] : 3 + 0 만 갱신됨 => 0정점에서 4정점을 거쳐 1정점으로 가는게 0정점에서 1정점으로 가는거보다 빠르면 0 -> (node -1)까지의 최단거리는 두번 정점 거친값이 된다.
            // 0 -> 1은 5로 갱신됨 7 > 3 + 2라서 5로 갱신 
            dist[node] = min(dist[node], dist[next] + graph[next][node]);
        }
    }

    return dist;
}


vector<int> GetShortestPath2(int start)
{
    //distance 배열 만들기
    //발견되지않은 정점은 모두 INF이다.
    vector<int> dist(7, INF);

    //시작 정점은 거리가 0이다.
    dist[start] = 0;

    //우선순위 큐를 이용한다. => 모든 원소중에서 가장 큰값이 top에 유지될수있도록 함
    priority_queue<pair<int, int>> pq;
    //시작 정점을 넣어준다.
    pq.emplace(0, start);

    //dist 의 모든값을 찾을 때까지
    while (false == pq.empty())
    {
        //dist중에서 가장 최소값을 가지는 정점을 뽑아낸다.
        int w = -pq.top().first;
        int v = pq.top().second;
        pq.pop();

        //과거에 발견한 최단 경로와 현재 최단 경로를 비교한다.
        //과거에 발견한 최단 경로가 더 크다면 계산할 필요가 없다.
        if (dist[v] < w)
        {
            continue;
        }

        //해당 정점을 이용했을때, 최단거리를 찾을수 있는지 체크한다.
        for (int node = 0; node < 7; node++)
        {
            if (dist[node] > w + graph[v][node])
            {
                dist[node] = w + graph[v][node];
                pq.emplace(-dist[node], node);
            }
        }
    }

    return dist;
}

std::vector<int> GetShortestPathWithPath(int start, vector<int>& outPath)
{
    vector<int> dist(7, INF);
    dist[start] = 0;

    // path[i]는 i 정점으로 가기 위해 거쳐야 하는 정점이다.
    vector<int> path(7, INF);
    path[start] = start;

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, start);

    while (false == pq.empty())
    {
        int w = -pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (dist[v] < w)
        {
            continue;
        }

        //각 정점의 최단 거리로 갱신해준다.
        for (int node = 0; node < 7; ++node)
        {
            if (dist[node] > w + graph[v][node])
            {
                dist[node] = w + graph[v][node];

                // 해당 node로 가기 위해서는 v를 거쳐야 한다.
                path[node] = v; //0정점에서 4정점까지 갈때 node = 4이 되고 v가 0이된다. 

                pq.emplace(-dist[node], node);
            }
        }
    }

    outPath = std::move(path);

    return dist;
}

void PrintPath(int start, int end)
{
    vector<int> path;
    GetShortestPathWithPath(start, path);

    int curr = end;
    while (curr != start)
    {
        printf("%d <- ", curr);
        curr = path[curr];
    }
    printf("%d", curr);

    // 혹은 스택에 넣어서 순서대로 출력할 수도 있다.
}


int main()
{
    auto vec1 = GetShortestPath(0);
    std::cout << "0에서 각 index정점까지의 최단거리 : [";
    for (int i : vec1)
    {
        std::cout << i << ' ';
    }
    std::cout << "]\n";

    cout << "해당 스택 순서대로 해당 정점까지의 최단거리를 구함" << endl;
    for (vector<int>::iterator iter = st.begin(); iter != st.end(); iter++)
    {
        cout << *iter << " ";
    }

    pair<int, int> test = make_pair(1,2);
    cout << "페어 : " <<  test.first << "  " << test.second << endl;


    auto vec2 = GetShortestPath2(0);
    std::cout << "0에서 각 index정점까지의 최단거리 : [";
    for (int i : vec2)
    {
        std::cout << i << ' ';
    }
    std::cout << "]\n";

    auto vec3 = GetShortestPath2(0);
    std::cout << "0에서 각 index정점까지의 최단거리 : [";
    for (int i : vec3)
    {
        std::cout << i << ' ';
    }
    std::cout << "]\n";

    PrintPath(0, 2);

}