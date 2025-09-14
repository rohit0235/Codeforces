
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
int solve(vector<vector<char>>&imp, long long i , long long j, long long n, vector<vector<long long>>&dp){
        if (i==n-1 && j==n-1) return 1;
        if (i>=n || j>=n ) return 0;
        if (imp[i][j]=='*') return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        long long a = solve(imp, i+1,j,n,dp)%mod;
        long long b = solve(imp, i,j+1,n,dp)%mod;
        // cout<<a<<" "<<b<<endl;

        return dp[i][j]=(a+b)%mod;
      
}

int main(){
     
      long long n;
      cin>>n;

      vector<vector<char>>imp(n,vector<char>(n,'.'));

      for(long long i=0;i<n;i++){
            
            for(long long j=0;j<n;j++){
                 cin>>imp[i][j];
            }
      }
      vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
      if (imp[n-1][n-1]=='*' || imp[0][0]=='*') cout<<0;
      else  cout<< solve(imp, 0,0,n,dp);
      



}

