#include <iostream>
#include <vector>
using namespace std;

int main (){
        
       int n;
       cin>>n;

       while (n--){
              
                int t;
                cin>>t;

                vector<int>s(t,0);
                for(int i=0;i<t;i++){
                     
                       cin>>s[i];
                }

                // 6 7 1 5 4 3 2
                //  2 1 7 3 4 5 6
                // 
                vector<int>ans;
                for(int i:s){
                     ans.push_back(t+1-i);
                }
                for(int i:ans){
                     cout<<i<<" ";
                }
                cout<<endl;


                   
       }
     
}