#include <iostream>
#include <vector>

using namespace std;

int main() {
    Solution sol; // Create an instance of the Solution class

    // Example 2D matrix (sorted row-wise)
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 16; // Target value to search for

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
