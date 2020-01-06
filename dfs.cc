#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Edge {
	int src, dest;
};

class Graph
{
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

void DFS(Graph const &graph, int v, vector<bool> &discovered)
{
	discovered[v] = true;
	cout << v << " ";
	for (int u : graph.adjList[v])
	{
		if(!discovered[u])
			DFS(graph, u, discovered);
	}
}

void iterativeDFS(Graph const &graph, int v, vector<bool> &discovered)
{
	stack<int> stack;
	stack.push(v);

	while(!stack.empty())
	{
		v = stack.top();
		stack.pop();

		if(discovered[v])
			continue;

		discovered[v] = true;
		cout << v << " ";

		for (auto it = graph.adjList[v].rbegin(); 
			it != graph.adjList[v].rend(); ++it)
		{
			int u = *it;
			if(!discovered[u])
				stack.push(u);
		}

	}
}


int main()
{
	vector<Edge> edges = {
		{1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4}, {3, 5},
		{8, 9}, {8, 12}, {9, 10}, {9, 11}
	};

	int N = 13;
	Graph graph(edges, N);
	vector<bool> discovered(N);

	// Do DFS traversal from all undiscovered nodes to
	// cover all unconnected components of graph

	for (int i = 0; i < N; i++)
		if (discovered[i] == false)
		{
			// DFS(graph, i, discovered);
			iterativeDFS(graph, i, discovered);
			cout << "\n" << endl;
		}

	return 0;
}