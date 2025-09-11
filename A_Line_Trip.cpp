

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&a , int n , int x){
        

    int maxdiff = a[0];

    for(int i=1;i<n;i++){
        maxdiff = max(maxdiff , a[i]-a[i-1]);
    }

    return max(maxdiff,2*(x-a[n-1]));


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
                      
                        cout<<solve(a,n,x)<<endl;
              
         }
     
}