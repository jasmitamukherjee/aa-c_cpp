#include <iostream>
#include <limits.h>
#include <vector>

int minDistance(const std::vector<int>& dist, const std::vector<bool>& sptSet) {
    int min = INT_MAX, min_index;

    for (size_t v = 0; v < dist.size(); ++v)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(const std::vector<int>& dist) {
    int minCost = 0;
    std::cout << "Vertex Distance from Source\n";
    for (size_t i = 0; i < dist.size(); ++i) {
        std::cout << "\t" << i << "\t\t\t\t" << dist[i] << "\n";
        minCost += dist[i];
    }
    std::cout << "Minimum cost: " << minCost << "\n";
}

void dijkstra(const std::vector<std::vector<int>>& graph, int src) {
    int V = graph.size();
    std::vector<int> dist(V, INT_MAX);
    std::vector<bool> sptSet(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; ++v)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}

int main() {
    int V;
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;

    std::vector<std::vector<int>> graph(V, std::vector<int>(V));

    std::cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            std::cin >> graph[i][j];

    int src;
    std::cout << "Enter the source vertex: ";
    std::cin >> src;

    dijkstra(graph, src);

    return 0;
}


// Enter the number of vertices: 5
// Enter the adjacency matrix of the graph:
// 0 10 0 5 0
// 0 0 1 2 0
// 0 0 0 0 4
// 0 3 9 0 2
// 0 0 6 0 0