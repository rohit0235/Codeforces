#include <bits/stdc++.h>
using namespace std;


int main (){
     int t;
         cin>>t;

         while (t--){
                
                        int n;
                        cin>>n;

                        vector<int>a(n,0);
                        for(int i=0;i<n-1;i++){
                             cin>>a[i];
                        }

                        vector<int>ans;
                        ans.push_back(a[0]);
                        for(int i=1;i<n;i++){
                              ans.push_back(a[i]);
                              ans.push_back(a[i]+1);
                        }
                         cout<<ans.size()<<endl;
                        for(int i:ans){
                              cout<<i<<" ";
                        }
                        cout<<endl;
                 
         }


     
}