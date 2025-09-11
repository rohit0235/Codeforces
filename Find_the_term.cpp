#include <iostream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
const int MOD =1e9+7;

long long solve(vector<long long >&a, long long m){
          
     int n = a.size();
    //  cout<<1<<" ";
     int first = a[0];
     int second = a[1];
     vector<long long>dp(m+1,0);
     dp[0]=first;
     dp[1]=second;

     for(int i=2;i<m;i++){
            dp[i]=dp[i-2]-dp[i-1];   
     }


     return dp[m-1];

    // return 1;


               
}

int main (){
     
       long long t;
       cin>>t;
        cin.ignore();
       
       while (t--){
         
               string line;
               getline(cin,line);
                       
                long long  m ;
                cin>>m;
                if (t > 0) { 
                    cin.ignore(); 
                }

               int   num ;
               stringstream ss(line);
               vector<long long  >a;
               while (ss>>num){
                     a.push_back(num);
               }
        


            //    for(int i:a) cout<<i<<" ";
            //    cout<<endl;
               cout<<solve(a,m)<<endl;

       }
     
}