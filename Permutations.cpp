#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main (){
       
         int n;
         cin>>n;
          vector<int>ans;
          if (n==1) cout<<1<<endl;
          else if(n<=3) cout<<"NO SOLUTION"<<endl;
      
          else{
                
                  int i =2;
                   while (i<=n){
                     
                       ans.push_back(i);
                       i+=2;
                   }
                  i =1;
                   while (i<=n){
                     
                       ans.push_back(i);
                       i+=2;
                   }
               
          }

          for(int i :ans) cout<<i<<" ";



}