#include <vector>
#include <algorithm>

#define ����� 0
#define ���缺 1
#define ������ 2
#define ���ǹ� 3
#define �̽��� 4

//true : ����, false : �񿬰�
bool graph[5][5];
std::vector<int>* graph3;


bool graph2[5][5];

//���� �ߴ��� �˷���? => ���� ��� ����
bool isAdjacent(int** graph, int v1, int v2)
{
	if (graph[v1][v2] || graph[v2][v1])
	{
		return true;
	}
	else
	{
		return false;
	}
}

//���� �ߴ��� �˷���? => ���� ����Ʈ ����
bool isAdjacent(std::vector<int>* graph, int v1, int v2)
{

	if (graph[v1].end() != std::find(graph[v1].begin(), graph[v1].end(), v2))
	{
		return true;
	}

	if (graph[v2].end() != std::find(graph[v2].begin(), graph[v2].end(), v1))
	{
		return true;
	}

	return false;
}


//���������� ���Ѵ�. => ���� ��� ����
int CountIndegree(int** graph, int vertex)
{
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		if (graph[i][vertex])
		{
			++count;
		}
	}

	return count;
}

//���������� ���Ѵ�. => ���� ����Ʈ ����
int CountIndegree(std::vector<int>* graph, int vertex)
{
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		//��ã���� end()����, ã���� ���� �ּ� ����
		if (graph[i].end() != std::find(graph[i].begin(), graph[i].end(), vertex)) //0->4, 1->4�� 2����
		{
			count++;
		}
	}

	return count;
}

int main()
{
	//�׷��� ���� : ���� ��� ����
	/*
		0 0 0 0 1
		0 0 1 1 1
		1 1 0 1 1
		0 1 1 0 1
		0 0 0 0 0
	*/
	graph2[�����][�̽���] = true;

	graph2[���缺][�̽���] = true;
	graph2[���缺][������] = true;
	graph2[���缺][���ǹ�] = true;
	
	graph2[������][�̽���] = true;
	graph2[������][���ǹ�] = true;
	graph2[������][���缺] = true;
	graph2[������][�����] = true;
	
	graph2[���ǹ�][�̽���] = true;
	graph2[���ǹ�][���缺] = true;
	graph2[���ǹ�][������] = true;


	//�׷��� ���� : ���� ����Ʈ ����
	/*
		[0] : {4} 
		[1] : {2,3,4} 
		[2] : {0,1,3,4} 
		[3] : {1,2,4} 
		[4] : {} 
	*/
	graph3[�����].push_back(�̽���);

	graph3[���缺].push_back(������);
	graph3[���缺].push_back(�̽���);
	graph3[���缺].push_back(���ǹ�);
	

}