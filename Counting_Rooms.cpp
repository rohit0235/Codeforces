#include <bits/stdc++.h>
using namespace std;
int n, m;
bool solve(int x , int y,vector<vector<char>>&s){
        
        if (x<0 || y<0 || x>=n || y>=m || s[x][y]=='#') return false;
        
        return true;
     
}
void dfs(vector<vector<bool>>&visited, int x , int y ,    vector<vector<char>>&s){
      
      visited[x][y] =true;
      vector<int>a= {0,-1,1,0};
      vector<int>b= {1,0,0,-1};

      for(int i=0;i<4;i++){
              
                 int newx = x+a[i];
                 int newy = y+b[i];
                if (solve(newx, newy, s)){ 
                          if (!visited[newx][newy]){
                              dfs(visited, newx, newy,s);
                          }
                }
             
      }
         
}
int main (){
     
       
       cin>>n>>m;
       
       vector<vector<char>>s(n,vector<char>(m,' '));

       for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
             cin>>s[i][j];
          }
       }
       
       vector<vector<bool>>visited(n,vector<bool>(m,false));
       int count =0;
       for(int i=0;i<n;i++){
         
             for(int j=0;j<m;j++){
                //   cout<<visited[i][j]<<" "<<s[i][j]<<endl;
                  if (!visited[i][j] && s[i][j]=='.'){ 
                         count++;
                         dfs(visited,i,j,s);
                   
                        
                  }
             }
       }

       cout<<count<<endl;
}