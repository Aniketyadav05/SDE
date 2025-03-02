#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find the index of the first occurrence of '1' in a row using Binary Search
    int last(vector<vector<int>> &arr, int i) {
        int number = -1;
        int n = arr[i].size();
        int left = 0, right = n - 1; // Fix: right should be n - 1 (not arr[i].size())

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[i][mid] == 1) {
                number = mid;  // Store index of first '1' found
                right = mid - 1; // Search in the left half for the first '1'
            } else {
                left = mid + 1; // Move to the right half
            }
        }

        // If '1' is found, return count of 1s in the row (from index 'number' to end)
        return (number >= 0) ? (n - number) : 0;
    }

    // Function to find the row with the maximum number of 1s
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int answer = 0;  // Maximum count of 1s
        int ind = -1;    // Index of row with maximum 1s

        for (int i = 0; i < n; i++) {
            int noOf = last(arr, i); // Count 1s in the current row using binary search
            if (answer < noOf) {
                answer = noOf; // Update max count
                ind = i; // Update row index
            }
        }
        return ind; // Return the row index with maximum 1s
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    
    // Example input: Binary matrix
    vector<vector<int>> arr = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1}
    };

    // Calling the function and printing the result
    int rowIndex = sol.rowWithMax1s(arr);
    cout << "Row with maximum 1s: " << rowIndex << endl;

    return 0;
}
