#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to search for a target in a sorted matrix
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();    // Number of rows
        int m = matrix[0].size(); // Number of columns
        int row = 0, col = m - 1; // Start from the top-right corner

        // Traverse the matrix using binary search logic
        while (row < n && col >= 0) {
            if (matrix[row][col] == target) 
                return true; // Target found
            else if (matrix[row][col] < target) 
                row++; // Move down if target is greater
            else 
                col--; // Move left if target is smaller
        }
        return false; // Target not found
    }
};

// Main function to test searchMatrix function
int main() {
    Solution sol; // Create an instance of Solution

    // Example input matrix
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int target = 9; // Target value to search

    // Call searchMatrix function
    bool result = sol.searchMatrix(matrix, target);

    // Print result
    if (result) {
        cout << "Target " << target << " found in the matrix!" << endl;
    } else {
        cout << "Target " << target << " not found in the matrix!" << endl;
    }

    return 0; // Program executed successfully
}
