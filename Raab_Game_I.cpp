#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
         
           int n,a,b;
           cin>>n>>a>>b;
         if(a+b>n){
             cout<<"NO"<<endl;
         } 
         else{
           int i=0;
           int j=n-1;
                 int rem = abs(n-a-b);
           vector<int>a1;
           vector<int>b1;
           while (a--){
                   a1.push_back(j);
                   b1.push_back(i);
                   i++;
                   j--;

           }
           while (b--){
                   a1.push_back(i);
                   b1.push_back(j);
                   i++;
                   j--;

           }

     
           while (i<=j && rem--){
                a1.push_back(i);
                b1.push_back(i);
                i++;
           }
           cout<<rem;
           cout<<"YES"<<endl;
           for(int i:a1) cout<<i<<" ";
           cout<<endl;
           for(int i:b1) cout<<i<<" ";
             cout<<endl;
        }
         
    }
    return 0;
}