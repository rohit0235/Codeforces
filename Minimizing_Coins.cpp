#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

long long solve(vector<long long >& s , long long b,   vector<long long >&dp){
     
       if (b==0) return 0;
       if (b<0) return INT_MAX;
      
        long long mini =INT_MAX;
       for(long long  i=0;i<s.size();i++){
           
             long long st = 1+solve(s, b-s[i],dp);
              mini = min( mini,st);
       }
            
       return dp[b]=mini;
      
     
}
int main (){
     
         long long a, b;
         cin>>a>>b;
         vector<long long >dp(b+1,LLONG_MAX);
         vector<long long >s(a,0);
         for(long long  i=0;i<a;i++) cin>>s[i];

         dp[0]=0;
         

         for(int i=1;i<=b;i++){
             
              for(long long coin:s){
                    if (i-coin>=0 && dp[i-coin]!=LLONG_MAX){
                             dp[i]= min(dp[i], dp[i-coin]+1);
                    }
              }
         }

         if (dp[b]==LLONG_MAX) cout<<-1;
         else cout<<dp[b];


       
        //  cout<< solve(s,b,dp);  
        


                    
}