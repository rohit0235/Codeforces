#include  <iostream>
#include  <vector>
using namespace std;

int solve(vector<int>&a , int n){
     
           int maxi =0;
           int curr= 0;
           for(int i=0;i<n;i++){
                    if (a[i]==1)  curr=0;
                    else curr +=1;

                    maxi = max(maxi , curr);
               
           }

           return maxi ;
 
     
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


                cout<<solve(a,n)<<endl;
              
         }    
 
      
}