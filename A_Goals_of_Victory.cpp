#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&a , int n ){
        
             int sum =0;

             for(int i:a){
                 sum = sum  + ( -1*i);
             }
             return sum;
          

}

int main (){
     
     
         int t;
         cin>>t;

         while (t--){
                
                        int n;
                        cin>>n;

                        vector<int>a(n-1,0);
                        for(int i=0;i<n-1;i++){
                             cin>>a[i];
                        }
                 
                         cout<<solve(a,n)<<endl;
         }

     
}