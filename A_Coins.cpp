
#include  <iostream>
#include  <vector>
using namespace std;

int main (){
     
                    long long t;
               cin>>t;

               while (t--){
                 
                        long long  n , k;
                        
                        
                        cin>>n>>k;


                        if (n%k==0 || n%2==0 ){
                             cout<<"YES"<<endl;
                        }
                        else if (n<k){
                              cout<<"NO"<<endl;
                        }
                        else{
                               
                               if (k%2==0) cout<<"NO"<<endl;
                               else cout<<"YES"<<endl;
                              
                        }

               }
      
}