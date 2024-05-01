#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
class Graph {
public:
    int V, E; // Number of vertices and edges
    vector<Edge> edges; // Array of edges

    // Constructor
    Graph(int V, int E) : V(V), E(E) {
        edges.resize(E);
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight, int index) {
        edges[index].src = src;
        edges[index].dest = dest;
        edges[index].weight = weight;
    }

    // Function to find the subset of an element
    int find(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    // Function to perform union of two subsets
    void Union(vector<int>& parent, int x, int y) {
        int xroot = find(parent, x);
        int yroot = find(parent, y);
        parent[xroot] = yroot;
    }

    // Function to find Minimum Spanning Tree using Kruskal's algorithm
    void kruskalMST();
};

// Comparison function to sort edges by weight
bool compare(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Function to find Minimum Spanning Tree using Kruskal's algorithm
void Graph::kruskalMST() {
    vector<Edge> result(V - 1); // Array to store the MST edges
    int e = 0; // Index variable for result array
    int i = 0; // Index variable for sorted edges array

    // Sort all the edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), compare);

    // Create a vector to store parent of each vertex
    vector<int> parent(V, -1);

    // Loop until MST has V-1 edges
    while (e < V - 1 && i < E) {
        Edge next_edge = edges[i++];

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        // If including this edge does not cause cycle, include it in result and increment the index
        if (x != y) {
            result[e++] = next_edge;
            Union(parent, x, y);
        }
    }

    // Print the edges of MST
    cout << "Edges of MST are:" << endl;
    for (int j = 0; j < e; ++j)
        cout << result[j].src << " - " << result[j].dest << " : " << result[j].weight << endl;
}

// Driver code
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V, E);

    cout << "Enter the edges (src dest weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight, i);
    }

    g.kruskalMST();

    return 0;
}

// Enter the number of vertices: 9
// Enter the number of edges: 14
// Enter the edges (src dest weight):
// 0 1 4
// 0 7 8
// 1 2 8
// 1 7 11
// 2 3 7
// 2 8 2
// 2 5 4
// 3 4 9
// 3 5 14
// 4 5 10
// 5 6 2
// 6 7 1
// 6 8 6
// 7 8 7
