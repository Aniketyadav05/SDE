#include <iostream>
#include <vector>
#include <climits> // For INT_MIN

using namespace std;

class Solution {
public:
    // Function to find elements that appear more than ⌊n/3⌋ times in an array
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0; // Counters for two potential majority elements
        int el1 = INT_MIN, el2 = INT_MIN; // Two candidate elements initialized to minimum integer value

        // Step 1: Find two potential majority elements using Boyer-Moore Voting Algorithm
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && nums[i] != el2) {
                cnt1 = 1;
                el1 = nums[i];
            } else if (cnt2 == 0 && nums[i] != el1) {
                cnt2 = 1;
                el2 = nums[i];
            } else if (nums[i] == el1) {
                cnt1++;
            } else if (nums[i] == el2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        // Step 2: Verify if these elements actually appear more than ⌊n/3⌋ times
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) {
                cnt1++;
            }
            if (nums[i] == el2) {
                cnt2++;
            }
        }

        vector<int> answer;
        int threshold = n / 3; // An element must appear more than ⌊n/3⌋ times

        // Check if candidates meet the condition
        if (cnt1 > threshold) {
            answer.push_back(el1);
        }
        if (cnt2 > threshold) {
            answer.push_back(el2);
        }
        return answer;
    }
};

// Main function to test the majorityElement function
int main() {
    Solution sol; // Create an instance of the Solution class

    // Example input array
    vector<int> nums = {3, 2, 3, 2, 2, 1, 1, 1, 3};

    // Call the majorityElement function and store the result
    vector<int> result = sol.majorityElement(nums);

    // Print the majority elements found
    cout << "Majority Elements (appearing more than ⌊n/3⌋ times): ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
