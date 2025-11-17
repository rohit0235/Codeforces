#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int num;
	cin >> num;   
	vector<int>nums(num,0);
	for(int i=0;i<num;i++) cin>>nums[i];
	// find the max length of subarray with 1 zero 
   bool zero = false;
   int l =0;
   int z= 0;
   int maxi =0;
    int n = nums.size();
    for(int r=0;r<num;r++){
		  
		   if (nums[r]==0){
			 z++;
			 zero = true;
		   }
		   while (z>1){
			    if (nums[l]==0){
					 z--;
				}
				l++;
		   }
           maxi  = max(maxi , r-l+1);
	}
	 int t =0;
	for(int i:nums){
		 if (i==1) t++;
	}
	if (t>=maxi){
		 cout<<maxi;
	}
	else{
		 cout<<maxi-1;
	}

}