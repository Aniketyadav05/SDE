#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int sumbyD(vector<int> arr, int div){
            int n = arr.size();
            int sum = 0;
            for(int i=0;i<n;i++){
                sum+=ceil(double(arr[i])/double(div));
            }
            return sum;
    
        }
        int smallestDivisor(vector<int>& nums, int threshold) {
            int n = nums.size();
            if (n > threshold) {
                return -1;
            }
            int left = 1, right = *max_element(nums.begin(), nums.end());
            
            while(left<=right){
                int mid = (left+right)/2;
                if(sumbyD(nums,mid)<=threshold){
                    right = mid -1;
                }
                else {
                    left = mid +1;
                }
            }
            return left;
        }
    };

int main(){
    solution ans;
    vector<int> nums = {44,22,33,11,1};
    int threshold = 5;
    int result = ans.smallestDivisor(nums, threshold);
    cout<< "smallest Divisor"<<result<<endl;
    return 0;
}