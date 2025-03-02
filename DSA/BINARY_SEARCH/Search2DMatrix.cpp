#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to perform binary search on row i of the matrix
    int search(vector<vector<int>> arr, int i, int target) {
        int left = 0, right = arr[i].size() - 1;

        // Ensure the row is not empty and target is within the row's range
        if (!arr[i].empty() && target >= arr[i][left] && target <= arr[i][right]) {
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (arr[i][mid] < target) {
                    left = mid + 1;
                } 
                else if (arr[i][mid] == target) {
                    cout << "Found at row: " << i << ", column: " << mid << endl;
                    return 1; // Target found
                } 
                else {
                    right = mid - 1;
                }
            }
        } 
        else {
            return -1; // Target is not in this row
        }

        return -1; // Target not found
    }

    // Function to search for the target in the matrix row by row
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            int ans = search(matrix, i, target);
            if (ans == 1) {
                return true; // Target found in one of the rows
            }
        }
        return false; // Target not found in any row
    }
};

// Main function to test the searchMatrix function
int main() {
    Solution sol; // Create an instance of the Solution class

    // Example input matrix
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 16; // Target value to search

    // Call the searchMatrix function and store the result
    bool result = sol.searchMatrix(matrix, target);

    // Print the result
    if (result) {
        cout << "Target " << target << " found in the matrix!" << endl;
    } else {
        cout << "Target " << target << " not found in the matrix!" << endl;
    }

    return 0;
}
