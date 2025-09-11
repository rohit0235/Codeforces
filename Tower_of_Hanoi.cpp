#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
vector<pair<int,int>>ans;
void towero(int n, int a, int b, int c){   
               

    if (n == 0) {
        return;
    }
    towero(n - 1, a, c, b);
    ans.push_back({a,b});
    // cout <<  a<<" "<<b<<" "<< endl;
    towero(n - 1, c, b, a);
      
}

int main (){
       
         int n;
         cin>>n;

         towero(n,1,3,2);
          cout<<ans.size()<<endl;
         for(auto i:ans){
             cout<<i.first<<" "<<i.second<<endl;
         }
           

         



}