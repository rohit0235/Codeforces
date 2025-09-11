
#include  <iostream>
#include  <vector>
using namespace std;


bool ispos(long long a , long long b , long long c , long long d){
                    
 
      
      
}
int main (){
     
                    long long t;
               cin>>t;

               while (t--){
                 
                        long long  a , b,c,d;
                           
                        
                        cin>>a>>b>>c>>d;

                        if (b>d) cout<<-1<<endl;

                        else {
                               
                                 int maxtime = d-b;
                                 a=a+maxtime;
                                 if (a<c){
                                    cout<<-1<<endl;
                      
                                 }
                                   else  {
                                         maxtime +=abs(c-a);
                                 
                                         cout<<maxtime<<endl;
                                   } 
                        }
            
                   

               }
               
               // -2 -1 1 1
               // 


               // a b c d
               // a b  -> c,d

               // a,b +1 ,+1
               // a- -1 

            //    -1 0  -1 2
            //     0 1  , 1 2 , 0 2 , -1 2  

            //  0 0 4 5
            // 5 5 
            // 4 5

}