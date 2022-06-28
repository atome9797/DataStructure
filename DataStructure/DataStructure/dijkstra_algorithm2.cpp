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
    //distance �迭 �����
    vector<int> dist(7);
    
    //ù ������ 0�̸� 0���� ���� �����͸� �̾Ƽ� ������ 
    for (int i = 0; i < 7; i++)
    {
        dist[i] = graph[start][i];
    }

    vector<bool> isVisited(7);
    isVisited[start] = true;
    st.push_back(start);

    //��� ������ ���� �ִ� ��θ� ã��������
    for (int i = 0; i < 7 - 1; i++)
    {
        int next = 0; //�ε���
        int minDist = INF; //��

        for (int node = 0; node < 7; node++)
        {
            if (isVisited[node])
            {
                continue;
            }

            //�ּڰ��� ����
            if (minDist > dist[node])
            {
                next = node; //�ε��� 4
                minDist = dist[node]; //��
            }
        }
        

        //dist�࿡ �ִ� �����Ϳ��� �ּ� �Ÿ����� ������ �ε����� ������ ������


        //�湮 ǥ�� => �湮�� ������ �ּ� �Ÿ����� ������
        isVisited[next] = true; //�ּҰŸ����� ������ true�� ����
        st.push_back(next);

        for (int node = 0; node < 7; node++)
        {
            //0 ������ ���� ������ 
            //next : 4
            //graph[4][node] : 3 + 0 �� ���ŵ� => 0�������� 4������ ���� 1�������� ���°� 0�������� 1�������� ���°ź��� ������ 0 -> (node -1)������ �ִܰŸ��� �ι� ���� ��ģ���� �ȴ�.
            // 0 -> 1�� 5�� ���ŵ� 7 > 3 + 2�� 5�� ���� 
            dist[node] = min(dist[node], dist[next] + graph[next][node]);
        }
    }

    return dist;
}


vector<int> GetShortestPath2(int start)
{
    //distance �迭 �����
    //�߰ߵ������� ������ ��� INF�̴�.
    vector<int> dist(7, INF);

    //���� ������ �Ÿ��� 0�̴�.
    dist[start] = 0;

    //�켱���� ť�� �̿��Ѵ�. => ��� �����߿��� ���� ū���� top�� �����ɼ��ֵ��� ��
    priority_queue<pair<int, int>> pq;
    //���� ������ �־��ش�.
    pq.emplace(0, start);

    //dist �� ��簪�� ã�� ������
    while (false == pq.empty())
    {
        //dist�߿��� ���� �ּҰ��� ������ ������ �̾Ƴ���.
        int w = -pq.top().first;
        int v = pq.top().second;
        pq.pop();

        //���ſ� �߰��� �ִ� ��ο� ���� �ִ� ��θ� ���Ѵ�.
        //���ſ� �߰��� �ִ� ��ΰ� �� ũ�ٸ� ����� �ʿ䰡 ����.
        if (dist[v] < w)
        {
            continue;
        }

        //�ش� ������ �̿�������, �ִܰŸ��� ã���� �ִ��� üũ�Ѵ�.
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

    // path[i]�� i �������� ���� ���� ���ľ� �ϴ� �����̴�.
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

        //�� ������ �ִ� �Ÿ��� �������ش�.
        for (int node = 0; node < 7; ++node)
        {
            if (dist[node] > w + graph[v][node])
            {
                dist[node] = w + graph[v][node];

                // �ش� node�� ���� ���ؼ��� v�� ���ľ� �Ѵ�.
                path[node] = v; //0�������� 4�������� ���� node = 4�� �ǰ� v�� 0�̵ȴ�. 

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

    // Ȥ�� ���ÿ� �־ ������� ����� ���� �ִ�.
}


int main()
{
    auto vec1 = GetShortestPath(0);
    std::cout << "0���� �� index���������� �ִܰŸ� : [";
    for (int i : vec1)
    {
        std::cout << i << ' ';
    }
    std::cout << "]\n";

    cout << "�ش� ���� ������� �ش� ���������� �ִܰŸ��� ����" << endl;
    for (vector<int>::iterator iter = st.begin(); iter != st.end(); iter++)
    {
        cout << *iter << " ";
    }

    pair<int, int> test = make_pair(1,2);
    cout << "��� : " <<  test.first << "  " << test.second << endl;


    auto vec2 = GetShortestPath2(0);
    std::cout << "0���� �� index���������� �ִܰŸ� : [";
    for (int i : vec2)
    {
        std::cout << i << ' ';
    }
    std::cout << "]\n";

    auto vec3 = GetShortestPath2(0);
    std::cout << "0���� �� index���������� �ִܰŸ� : [";
    for (int i : vec3)
    {
        std::cout << i << ' ';
    }
    std::cout << "]\n";

    PrintPath(0, 2);

}