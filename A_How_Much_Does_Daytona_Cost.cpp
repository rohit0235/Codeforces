#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&a , int x ){
  
        if (find(a.begin(),a.end(),x)!=a.end()){
             return 1;
        }
        else{
             return false;
        }

}

int main (){
     
     
         int t;
         cin>>t;

         while (t--){
                
                        int n,x;
                        cin>>n>>x;

                        vector<int>a(n,0);
                        for(int i=0;i<n;i++){
                             cin>>a[i];
                        }
                      
                     if (solve(a,x)){
                            cout<<"YES"<<endl;
                     }
                     else{
                             cout<<"NO"<<endl;
                     }
         }
     
}