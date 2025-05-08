#include <iostream>
#include <climits>
#include<map>
using namespace std;

class Graph {
    map<string,int>cityIndex;
    string cities[10];
    int a[10][10], b[10][10];
    int n;

public:
    Graph(int x) {
    	n=x;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                a[i][j] = INT_MAX;
                b[i][j] = 0;
            }
        }
    }

    void input() {
        cout << "Enter the names of "<<n<<"cities :\n";
        for (int i = 0; i < n; i++) {
            cin >> cities[i];
            cityIndex[cities[i]]=i;
        }

        cout << "Enter the adjacency matrix weights (Enter -1 for no edge):\n";
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                cout << "Enter the weight of the edge (" << cities[i] << " -> " << cities[j] << "): ";
                cin >> a[i][j];

                if (a[i][j] == -1)
                    a[i][j] = a[j][i]= INT_MAX;
                else 
                    a[j][i] = a[i][j];
            }
            a[i][i] = 0;
        }
    }

    void prims() {
        int visited[10] = {0}, from[10], dist[10];
        int sum = 0;

        for (int i = 0; i < n; i++) {
            dist[i] = a[0][i];
            from[i] = 0;
        }

        visited[0] = 1;
        int edges = 0;

        while (edges <n-1) {
            int min = INT_MAX, u = -1, v = -1;

            for (int i = 0; i < n; i++) {
                if (!visited[i] && dist[i] < min) {
                    min = dist[i];
                    v = i;
                    u = from[v];
                }
            }

            if (u == -1 || v == -1) {
                cout << "\nGraph is disconnected. Minimum spanning tree cannot be formed.\n";
                return;
            }

            b[u][v] = b[v][u] = min;
            sum+=min;
            visited[v] = 1;
            edges++;

            for (int i = 0; i < 10; i++) {
                if (!visited[i] && a[i][v] < dist[i]) {
                    dist[i] = a[i][v];
                    from[i] = v;
                }
            }

        }

        cout << "\nThe sum of the minimum spanning tree is: " << sum << endl;
    }

    void display() {
        cout << "\nMinimum Spanning Tree Adjacency Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j] == 0)
                    cout<<" - ";
                else
                    cout << b[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    int n;

    cout << "Enter the number of cities: ";
    cin >> n;

    if (n > 10) {
        cout << "Error: Maximum number of cities is 10.\n";
        return 1;
    }
    Graph g(n);
    g.input();
    g.prims();
    g.display();

    return 0;
}

