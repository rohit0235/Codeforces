#include <iostream>
using namespace std;


int main (){
     
      int t ;
       cin>>t;
       
       while (t--){
         
           int a ,b,c;
           cin>>a>>b>>c;
                 
                  if (a>b) cout<<"First"<<endl;
                  if (a<b) cout<<"Second"<<endl;

                 
                 if (a==b){
                        if ((a+b+c)%2==0) cout<<"Second"<<endl;
                          else cout<<"First"<<endl;
                 }
        
       }
  
       
      
}