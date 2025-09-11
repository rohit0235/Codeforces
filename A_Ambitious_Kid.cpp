#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&a , int n ){
        
             int mini =INT_MAX;

             for(int i:a){
                 mini = min(mini, abs(i));
             }
             return mini;
          

}

int main (){
     
     

                
                        int n;
                        cin>>n;

                        vector<int>a(n,0);
                        for(int i=0;i<n;i++){
                             cin>>a[i];
                        }
                 
                         cout<<solve(a,n)<<endl;
         

     
}