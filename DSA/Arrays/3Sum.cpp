#include <iostream>
#include <vector>
#include <algorithm> // For sort()

using namespace std;

class Solution {
public:
    // Function to find unique triplets that sum to zero
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Iterate through the array
        for (int i = 0; i < n; i++) {
            // Skip duplicate elements for the first number
            if (i != 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = n - 1;

            // Step 3: Two-pointer approach to find pairs that sum to -nums[i]
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++; // Increase left pointer to get a larger sum
                } else if (sum > 0) {
                    k--; // Decrease right pointer to get a smaller sum
                } else {
                    // Found a valid triplet
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip duplicate elements for second and third numbers
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};

// Main function to test threeSum function
int main() {
    Solution sol; // Create an instance of Solution

    // Example input array
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    // Call threeSum function
    vector<vector<int>> result = sol.threeSum(nums);

    // Print the result
    cout << "Unique triplets that sum to zero:\n";
    for (const auto& triplet : result) {
        cout << "[ ";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0; // Successful execution
}
