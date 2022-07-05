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
    // ��ŸƮ �������� ���� �ش� ������ �Ÿ��� �迭�� �־��� 
    // ��ŸƮ ������ 0�϶� dist�� 0���� �Ÿ�, 1���� �Ÿ�, 2���� �Ÿ�, 3���� �Ÿ�...���� �迭 ���Ե�


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
            //�Ÿ��� node 1���� �Ÿ��� 7�ε�, next 3�̰� 0���� 3���� �Ÿ� + 3���� 7���� �Ÿ��� 7���� ������ ���� �Ÿ��� ��������
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

    //���� ������ �Ÿ��� 0�̴�. �ڱ� �ڽ��̱� ����!
    dist[start] = 0;

    //�켱���� ť�� �̿��Ѵ�. => ��� �����߿��� ���� ū���� top�� �����ɼ��ֵ��� ��
    priority_queue<pair<int, int>> pq;
    //���� ������ �־��ش�. //  dist[start] = 0�� ���� ����
    pq.emplace(0, start);

    //dist �� ��簪�� ã�� ������
    while (false == pq.empty())
    {
        //dist�߿��� ���� �ּҰ��� ������ ������ �̾Ƴ���.
        int w = -pq.top().first; //7
        //priority_queue���� ū������ �����ϱ� ������, 0���� �����ϱ� ���� -�ٿ���
        int v = pq.top().second; //1
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
            //���⼭ W�� ����  dist[next]�� ����. �Ÿ� ����
            if (dist[node] > w + graph[v][node])
            {
                dist[node] = w + graph[v][node]; //���� ������ 0�̸� ù���� �״�� dist�Ÿ��� ��
                pq.emplace(-dist[node], node); //�ش� ���� �Ÿ��� �������� 0~7���� ��
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
    
    //outPath = path; �� ����
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