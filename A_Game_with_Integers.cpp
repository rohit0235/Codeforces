

#include <bits/stdc++.h>
using namespace std;

bool solve( int n){
        return n%3==0;
}

int main (){
     
     
         int t;
         cin>>t;

         while (t--){
                
                        int n;
                        cin>>n;
                  
                        if (!solve(n)){
                             cout<<"First"<<endl;
                        }
                        else{
                             cout<<"Second"<<endl;
                        }
              
         }
     
}