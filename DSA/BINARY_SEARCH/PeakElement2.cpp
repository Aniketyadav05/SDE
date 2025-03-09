#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find the row index with the maximum value in a given column
    int FindMax(vector<vector<int>> &mat, int n, int m, int col) {
        int maxValue = -1;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (mat[i][col] > maxValue) {
                maxValue = mat[i][col];
                index = i;
            }
        }
        return index;
    }

    // Function to find a peak element in a 2D grid
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int maxRowIndex = FindMax(mat, n, m, mid); // Get row index with max element in column mid

            // Get values of left and right elements
            int left = (mid - 1 >= 0) ? mat[maxRowIndex][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[maxRowIndex][mid + 1] : -1;

            // If the current element is a peak, return its index
            if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right) {
                return {maxRowIndex, mid};
            }
            // If left neighbor is greater, move left
            else if (mat[maxRowIndex][mid] < left) {
                high = mid - 1;
            }
            // Otherwise, move right
            else {
                low = mid + 1;
            }
        }

        return {-1, -1}; // Return -1 if no peak is found (should never reach here for a valid grid)
    }
};

// Main function to test findPeakGrid function
int main() {
    Solution sol; // Create an instance of Solution

    // Example input grid
    vector<vector<int>> mat = {
        {1, 4, 3},
        {6, 7, 8},
        {5, 9, 2}
    };

    // Call function to find peak
    vector<int> peak = sol.findPeakGrid(mat);

    // Print the result
    cout << "Peak element found at index: [" << peak[0] << ", " << peak[1] << "]" << endl;

    return 0; // Successful execution
}
