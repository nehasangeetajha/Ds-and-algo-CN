#include <iostream>
#include <queue>
using namespace std;

void printBFS (int** edges, int n, int sv) {
    queue<int> pendingVertex;

    bool* visited = new bool[n];

    for (int i = 0; i < n; i++) {
        visited [i] = false;
    }

    pendingVertex.push(sv);
    visited[sv] = true;
    while (!pendingVertex.empty()) {
        int currentVertex = pendingVertex.front();
        pendingVertex.pop();
        cout << currentVertex << endl;
        for (int i = 0; i < n; i++) {
            if (i == currentVertex) continue;
            if (edges[currentVertex][i] == 1 && !(visited[i])) {
                pendingVertex.push(i);
                visited[i] = true;
            }
        }
    }
    delete [] visited;
}

void printDFS (int** edges, int n , int sv, bool* visited) {
    cout << sv << endl;
    visited[sv] = true;

    for (int i = 0; i < n; i++) {
        if (sv == i) continue;

        if (edges[sv][i] == 1) {
            if (visited[i]) continue;
            
            printDFS (edges, n, i, visited);
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

    queue<int> q;

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

    printBFS (edges, n, 0);

    printDFS (edges, n, 0, visited);

    delete [] visited;
}