

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&a , int n ){
        
      return a[0]==1;



}

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
                      
                     if (solve(a,n)){
                            cout<<"YES"<<endl;
                     }
                     else{
                             cout<<"NO"<<endl;
                     }
         }
     
}