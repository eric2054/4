#include <iostream>
#include <queue>
using namespace std;

void BFS(int i)
{
    queue<int> q;
    bool visited[100] = {false};
    int n, e;
    cin >> n >> e;
    int adj[100][100] = {0};
    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }
    q.push(i);
    visited[i] = true;
    while (!q.empty())
    {
        int v = q.front();
        cout << v << " ";
        q.pop();
        for (int j = 1; j <= n; j++)
        {
            if (adj[v][j] == 1 && visited[j] == false)
            {
                q.push(j);
                visited[j] = true;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int i;
    cin >> i;
    BFS(i);	
}
