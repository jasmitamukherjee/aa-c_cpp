#include <iostream>
#include <map>
#include <list>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;

    // Function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}

void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

// Driver code
int main()
{
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    // Create a graph
    Graph g;

    // Add edges to the graph
    cout << "Enter the edges (in the format 'v w'):\n";
    for (int i = 0; i < edges; ++i) {
        int v, w;
        cin >> v >> w;
        g.addEdge(v, w);
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    // Function call
    cout << "Depth First Traversal:\n";
    g.DFS(startVertex);

    return 0;
}

// Enter the number of vertices: 4
// Enter the number of edges: 5
// Enter the edges (in the format 'v w'):
// 0 1
// 0 2
// 1 2
// 2 0
// 2 3
// Enter the starting vertex for DFS: 2