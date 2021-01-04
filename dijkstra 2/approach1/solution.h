/*
    Time complexity: O(V^2)
    Space complexity: O(V^2)

    Where ‘V’ is the number of vertices in a graph.
*/

// Finds the vertex with minimum distance
int minDistance(vector<int> distance, vector<bool> visited, int vertices) {
    int min = INT_MAX, minVertex;
    for (int v = 0; v < vertices; v++) {
        if (visited[v] == false && distance[v] <= min) {
            min = distance[v];
            minVertex = v;
        }
    }
    return minVertex;
}
vector<int> dijkstraHelper(vector<vector<int>> &matrix, int vertices, int source) {
    vector<int> distance(vertices, INT_MAX);
    vector<bool> visited(vertices, false);
    // Distance of source to itself is 0.
    distance[source] = 0;
    for (int i = 0; i < vertices - 1; i++) {
        int u = minDistance(distance, visited, vertices);
        // Mark the current vertex as visied.
        visited[u] = true;
        // Update the distances of the adjacent nodes.
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && matrix[u][v] && distance[u] != INT_MAX && distance[u] + matrix[u][v] < distance[v]) {
                distance[v] = distance[u] + matrix[u][v];
            }
        }
    }
    return distance;
}
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<vector<int>> matrix(vertices, vector<int>(vertices, 0));
    // Create an adjacency matrix from the given input.F
    for (int i = 0; i < vec.size(); i++) {
        matrix[vec[i][0]][vec[i][1]] = vec[i][2];
        matrix[vec[i][1]][vec[i][0]] = vec[i][2];
    }
    return dijkstraHelper(matrix, vertices, source);
}
