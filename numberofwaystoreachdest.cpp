#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>>path;
    set<vector<int>>st;
    void countways (int V , vector<vector<int>>&adj,int u,vector<int>&curr,vector<bool>&visited){
                 curr.push_back(u);    
                 visited[u] = true;
            if(u==V-1){    
                if (!st.count(curr)){
                          path.push_back(curr);
                          st.insert(curr);
                }
            
                 return ;
            }  
            if (curr.size()==V){
                 return ;
            }
   
   
         
            for(auto v:adj[u]){
                  if (!visited[v]){
                        countways(V , adj , v , curr,visited);
                        curr.pop_back();
                          visited[v] =false;
                  }
    
            }
            
    }
    
   
    int countPaths(int V, vector<vector<int>>& edges) {
          // sabhi taraf se sabhi
           vector<vector<int>>adj(V);
           for(auto i:edges){
                 int u = i[0];
                 int v = i[1];
                 adj[u].push_back(v);
                 adj[v].push_back(u);
           }
           vector<int>curr;
           vector<bool>visited(V,false);
              countways(V,adj,  0, curr,visited);
            //   for(auto i:path){
            //         for(auto j:i){
            //              cout<<j<<"  ";
            //         }
            //         cout<<endl;
            //   }
            //   cout<<endl;
            map<pair<int,int>, int>mp;
            map<pair<int,int>, int>mp2;
            
            for(auto i:edges){
                   int u = i[0];
                 int v = i[1];
                 int t = i[2];
                 pair<int,int>k = {u,v};
                 if (!mp.count(k)){
                       mp[k]=t;
                 }
                 else{
                     if (t==mp[k]){
                          mp2[k]++;
                     }
                      mp[k]=min(mp[k],t);
                 }
                
            }
   
            int mini = INT_MAX;
     
            // for(int i=0;i<path.size();i++){ 
            
            //       for(int j=1;j<path[i].size();j++){
            //         cout<<path[i][j]<<"  ";
            //       }
            //       cout<<endl;
             
            // }        
     
            for(int i=0;i<path.size();i++){ 
                 int ans = 0;
                  for(int j=1;j<path[i].size();j++){
                      cout<<path[i][j]<<" ";
                          int first = path[i][j-1];
                          int second = path[i][j];
                          pair<int,int>k = {first , second};
                          pair<int,int>k2 = {second , first};
                          if (mp.count(k)){
                                                      ans+=mp[k];
                          }
                          else{
                                                   ans+=mp[k2];
                          }
                          

                  }
                  cout<<endl;
                  cout<<ans<<endl;
                 
                  mini = min(mini ,ans);
            }        
            // cout<<mini;
            int count = 0;
            for(int i=0;i<path.size();i++){ 
                 int ans = 0;
                  for(int j=1;j<path[i].size();j++){
                                  int first = path[i][j-1];
                          int second = path[i][j];
                          pair<int,int>k = {first , second};
                          pair<int,int>k2 = {second , first};
                          if (mp.count(k)){
                                                      ans+=mp[k];
                          }
                          else{
                                                   ans+=mp[k2];
                          }
                  }
                                  
                    if (ans == mini) {
                          count++;
                    }
            }
  

                return count;
    }
};

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int V;
  if (!(cin >> V)) return 0;
  int E;
  cin >> E;
  vector<vector<int>> edges;
  edges.reserve(E);
  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  Solution sol;
  int result = sol.countPaths(V, edges);
  cout << result << '\n';
  return 0;
}
 