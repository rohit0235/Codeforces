#include <bits/stdc++.h>
using namespace std;

typedef long long ll ;
int main() {
     
	 ll n;
	cin>>n;
	 vector<ll>s(n,0);
	 for(int i=0;i<n;i++){
cin>>s[i];
	 }

	 ll q;
	 cin>>q;
  
    for(ll i =1;i<n;i++){
		 s[i]^=s[i-1];
		//  cout<<s[i]<<" "<<endl;
	}
	 while (q--){
		 
		   ll l;ll r;
		   cin>>l>>r;
           ll xo= 0;
		//    for(int j=l-1;j<r;j++){
			// brute force
		// 	     xo^=s[j];
		//    }
		  if (l == 1) {
			xo = s[r - 1];
		} else {
			xo = s[r - 1] ^ s[l - 2];
		}

		     if(xo==0)cout<<"Ferb"<<endl;
		    else if(xo!=0)cout<<"Phineas"<<endl;
	 }
	
}

// is this possible if 3 5
// 
