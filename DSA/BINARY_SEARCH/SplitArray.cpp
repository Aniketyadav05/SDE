#include <iostream>
#include <vector>
#include <algorithm> // For max_element
#include <numeric>   // For accumulate

using namespace std;

class Solution {
public:
    // Function to count how many partitions are needed for a given max subarray sum
    int CalcPartitions(vector<int> nums, int mid) {
        int partitions = 1;  // Start with one partition
        int subarraySum = 0; // Track the sum of the current subarray
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (subarraySum + nums[i] <= mid) {
                subarraySum += nums[i]; // Add element to the current subarray
            } else {
                partitions++;       // Start a new partition
                subarraySum = nums[i]; // Assign the current element as the new subarray sum
            }
        }
        return partitions;
    }

    // Function to find the minimum largest sum of k subarrays
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int left = *max_element(nums.begin(), nums.end()); // Minimum possible value (largest element)
        int right = accumulate(nums.begin(), nums.end(), 0); // Maximum possible value (sum of all elements)

        // Binary search to find the optimal max subarray sum
        while (left <= right) {
            int mid = (left + right) / 2;
            if (CalcPartitions(nums, mid) > k) {
                left = mid + 1; // Increase min sum value
            } else {
                right = mid - 1; // Try a smaller max sum
            }
        }
        return left; // The smallest possible max subarray sum
    }
};

int main() {
    Solution sol;

    // Example input: Array and number of partitions
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    // Calling the function and printing the result
    int result = sol.splitArray(nums, k);
    cout << "Minimum largest sum of " << k << " subarrays: " << result << endl;

    return 0;
}
