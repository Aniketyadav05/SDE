// First approach 

#include <iostream>
#include <vector>
#include <algorithm> // For sorting

using namespace std;

class Solution {
public:
    // Function to find the median of two sorted arrays
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        double ans = 0;

        // Merge nums2 into nums1
        for (int i = 0; i < n2; i++) {
            nums1.push_back(nums2[i]); // Append each element of nums2 to nums1
        }

        // Sort the merged array
        sort(nums1.begin(), nums1.end());

        int n1 = nums1.size(); // Get new size
        int mid = n1 / 2; // Find the middle index

        // If the merged array has even length, return the average of the two middle elements
        if (n1 % 2 == 0) {
            ans = (double)(nums1[mid] + nums1[mid - 1]) / 2;
        }
        // If odd, return the middle element
        else {
            ans = nums1[mid];
        }

        return ans; // Return median
    }
};

int main() {
    Solution sol;

    // Example input: Two sorted arrays
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    // Calling the function and printing the median
    double median = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;

    return 0;
}

// OPTIMIZED APPROACH
