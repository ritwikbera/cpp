#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge
{
	int src, dest;
};

class Graph{
public:
	vector<vector<int>> adjList;

	Graph(vector<Edge> const &edges, int N)
	{
		adjList.resize(N);

		for (auto &edge: edges)
		{
			adjList[edge.src].push_back(edge.dest);
			adjList[edge.dest].push_back(edge.src);
		}
	}
};

void recursiveBFS(Graph const &graph, queue<int> &q, vector<bool> &discovered)
{
	if(q.empty())
		return;

	int v = q.front();
	q.pop();
	cout << v << " ";

	for(int u : graph.adjList[v])
	{
		if(!discovered[u])
		{
			discovered[u] = true;
			q.push(u);
		}
	}

	recursiveBFS(graph, q, discovered);

}

int main()
{
	vector<Edge> edges = {
		{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
		{5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
	};

	int N = 15;

	Graph graph(edges, N);
	vector<bool> discovered(N, false);

	queue<int> q;

	for (int i = 0; i < N; i++){
		if (discovered[i] == false)
		{
			discovered[i] = true;
			q.push(i);
			recursiveBFS(graph, q, discovered);
		}
	}
}