//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



    void sort012(vector<int>& nums) {
        // code here
        int cnt0 = 0, cnt1=0,cnt2 = 0;
        for(int i =0; i< nums.size();i++){
            if(nums[i]==0) cnt0++;
            else if(nums[i] == 1) cnt1++;
            else cnt2++;
        }
        for(int i =0;i<cnt0;i++) nums[i]=0;
        for(int i =cnt0;i<cnt0 + cnt1;i++) nums[i]=1;
        for(int i =cnt0+cnt1;i<nums.size();i++) nums[i]=2;
        
    }


//{ Driver Code Starts.
int main() {
    vector<int> nums = {2,0,2,1,1,0};
    sort012(nums);
    for(int i = 0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}

// } Driver Code Ends