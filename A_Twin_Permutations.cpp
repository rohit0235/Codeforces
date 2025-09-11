#include <bits/stdc++.h>
using namespace std;


int main (){
          int t;
         cin>>t;

         while (t--){
                
                        int n;
                        cin>>n;

                        vector<int>a(n,0);
                        for(int i=0;i<n;i++){
                             cin>>a[i];
                        }
                        
                       vector<int> ans(n,0);
                       for(int i = 0;i<n;i++){
                        ans[i] = n+1-a[i];
                       }

                       for(int i : ans){
                        cout<<i<<" ";
                       }
                       cout<<endl;


                  
         }


     
}