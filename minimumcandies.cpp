#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main (){
       
        int n;
        cin>>n;
        vector<int>s(n,0);
        for(int i=0;i<n;i++)
        cin>>s[i]; 

        vector<int>ans(n,1);

        for(int i=0;i<n-1;i++){
                
                if (s[i]>s[i+1]){
                      ans[i] = ans[i]+1;
                }
               
        }

        for(int i=n-2;i>=0;i--){
                
                if (s[i]>s[i+1]){
                      ans[i] = max(ans[i],ans[i]+1);
                }
               
        }
       cout<< accumulate(ans.begin(),ans.end(),0);


     
}