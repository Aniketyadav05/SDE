#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find the k-th missing positive number
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0, right = n - 1;

        // Binary search to find the position where k-th missing number fits
        while (left <= right) {
            int mid = (left + right) / 2;
            int missingNum = arr[mid] - (mid + 1); // Count of missing numbers before arr[mid]

            if (missingNum < k) {
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }
        
        // The k-th missing number is found at (k + right + 1)
        return k + right + 1;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> arr = {2, 3, 4, 7, 11}; 
    int k = 5;

    // Calling the function and printing the result
    int result = sol.findKthPositive(arr, k);
    cout << "The " << k << "-th missing positive number is: " << result << endl;

    return 0;
}
