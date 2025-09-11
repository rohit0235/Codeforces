#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main (){
       
         long long n;
         cin>>n;

          for(int i=1;i<=n;i++){
                 if (i==1) cout<<0<<endl;

                 else{
                          
                      long long first = (1LL*(i*i)*(i*i-1))/2;

                      long long numberofside = (4*i-4)*(i-2)*1LL;

                      cout<<first-numberofside<<endl;
                      

                      
                 }
             
         }

}