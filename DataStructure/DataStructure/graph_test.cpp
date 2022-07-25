#include <iostream>
#include <stdio.h>
#include <vector>
struct Edge
{
	int Vertex;
	int Weight;
	Edge(int v, int w) : Vertex(v), Weight(w) { }
};
int main()
{

	std::vector<Edge>graph2[7];
	graph2[0].emplace_back(1,1);

	Edge edge2(0, 1);
	graph2[1].push_back(edge2);
	Edge edge3(2, 2);
	graph2[1].push_back(edge3);
	Edge edge4(3, 2);
	graph2[1].push_back(edge4);
	Edge edge5(1, 2);
	graph2[2].push_back(edge5);
	Edge edge6(5, 6);
	graph2[2].push_back(edge6);
	Edge edge7(6, 3);
	graph2[2].push_back(edge7);
	Edge edge8(1, 2);
	graph2[3].push_back(edge8);
	Edge edge9(4, 1);
	graph2[3].push_back(edge9);
	Edge edge10(5, 4);
	graph2[3].push_back(edge10);
	Edge edge11(3, 1);
	graph2[4].push_back(edge11);
	Edge edge12(3, 4);
	graph2[5].push_back(edge12);
	Edge edge13(2, 6);
	graph2[5].push_back(edge13);
	Edge edge14(2, 3);
	graph2[6].push_back(edge14);

	graph2[1].push_back({ 5,1 });
	graph2[1].push_back({ 6,2 });
	graph2[1].push_back({ 7,4 });

	std::cout << graph2[1][1].Vertex;
	std::cout << graph2[1][1].Weight;
}
