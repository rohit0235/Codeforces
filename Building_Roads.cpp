#include <bits/stdc++.h>
using namespace std;

// so this function is for find
int find(int a, vector<int> &parent)
{

      if (parent[a] == a)
            return a;
      return parent[a] = find(parent[a], parent);
}

// so this is for unite
void unite(int a, int b, vector<int> &parent)
{

      int root_a = find(a, parent);
      int root_b = find(b, parent);
      if (root_a != root_b)
      {
            parent[root_a] = root_b;
      }
}
int main()
{
      int m, n;
      cin >> n >> m;

      // 1 - 2
      // 3 - 4
      vector<int> parent(n + 1, 0);
      for (int i = 1; i <= n; i++)
      {
            parent[i] = i;
      }
      while (m--)
      {
            int u, v;
            cin >> u >> v;
            unite(u, v, parent);
      }

      vector<int> representatives;
      for (int i = 1; i <= n; i++)
      {
            if (parent[i] == i)
            {
                  representatives.push_back(i);
            }
      }

      int ans = representatives.size() - 1;
      cout << ans << endl;
      if (ans > 0)
      {

            for (size_t i = 1; i < representatives.size(); ++i)
            {
                  std::cout << representatives[0] << " " << representatives[i] << std::endl;
            }
      }

      return 0;
}