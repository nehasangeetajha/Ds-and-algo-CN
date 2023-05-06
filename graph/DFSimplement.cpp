#include <iostream>
#include <queue>

using namespace std;

void printDFS (int** edges, int n, int sv, bool* visited) {
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++) {
        if(i == sv) continue;

        if (edges[sv][i] == 1) {
            if (visited[i]) continue;
            printDFS(edges, n, i, visited);
        }
    }
}

void printBFS (int** edges, int n, int sv) {
    queue<int> pendingVertex;

    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited [i] = false;
    }

    visited[sv] = true;

    pendingVertex.push (sv);
    while (!pendingVertex.empty()) {
        int current = pendingVertex.front();
        pendingVertex.pop();
        cout << current << endl;
        
        for (int i = 0; i < n ; i++) {
            if (current == i) continue;
            if (edges[current][i] == 1 && !(visited[i])) {
                pendingVertex.push(i);
                visited[i] = true;
            }
        }

    }
}

int main() {
    int n, e;
    cout << "enter the number of vertices ";
    cin >> n;
    cout <<"\nenter the number of edges ";
    cin >> e;
    cout << endl;

    int** edges = new int* [n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) edges[i][j] = 0;
    }

    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) visited[i] = false;
    
    printDFS (edges, n, 0, visited);

    printBFS (edges, n, 0);

    delete[] visited;
    
    for (int i = 0; i < n; i++) {
        delete [] edges[i];
    }

    return 0;
}