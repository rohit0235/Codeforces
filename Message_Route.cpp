#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;

     unordered_map<int, vector<int>> adj;
    // cout<<1<<endl;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    vector<int> dist(n + 1, -1);
    vector<int> parent(n + 1,0);
    dist[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        //  cout<<u<<endl;
        for (auto v : adj[u])
        {
            if (dist[v] == -1)
            {
                parent[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
 

    if (dist[n] == -1)
        cout << "IMPOSSIBLE";
    else
    {
           cout << dist[n]+1<<endl;
           vector<int>path;
           int current=n;
           while (current!=1){
                 path.push_back(current);
                 current=parent[current];
           }
           path.push_back(1);
           reverse(path.begin(),path.end());
           for(int i:path)cout<<i<<" ";

    }
}