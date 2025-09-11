#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main (){
       
         long long n;
         cin>>n;
          
         while (n--){

            long long a,b;
            cin>>a>>b;
            if (a==0 && b==0) cout<<"YES"<<endl;
            else if (a==0 || b==0) cout<<"NO"<<endl;
            else if ((max(a,b)/2)>min(a,b)) cout<<"NO"<<endl;
          else  if ((a+b)%3==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
                 
         }

   

}