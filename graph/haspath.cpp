#include <iostream>

using namespace std;

int main () {
    int v, e;
    cin >> v >> e;
    int** edges = new int* [v];
    for (int i = 0; i < v; i++) {
        edges[i] = new int [v];
        for (int j = 0; j < v; j++) edges[i][j] = 0;
    }

    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges [f][s] = 1;
        edges [s][f] = 1;
    }

    int one, two;
    cin >> one >> two;

    if (DFS()) cout << "true";
    else cout << "false";
}