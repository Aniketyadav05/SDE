#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to generate a specific row of Pascal's Triangle
    vector<int> generator(int row) {
        long long ans = 1; // First element is always 1
        vector<int> ansRow;
        ansRow.push_back(1); // First element of the row

        // Generate the elements of the row using nCr formula
        for (int col = 1; col < row; col++) {
            ans = ans * (row - col); // Multiply by (n - r)
            ans = ans / col;          // Divide by r
            ansRow.push_back(ans);    // Store the value
        }
        return ansRow;
    }

    // Function to generate Pascal's Triangle up to numRows
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer; // Stores Pascal's Triangle
        for (int i = 1; i <= numRows; i++) {
            answer.push_back(generator(i)); // Generate each row
        }
        return answer;
    }
};

// Main function to test the Pascal's Triangle generator
int main() {
    Solution sol;
    int numRows = 5; // Example input

    // Generate Pascal's Triangle
    vector<vector<int>> result = sol.generate(numRows);

    // Print Pascal's Triangle
    cout << "Pascal's Triangle with " << numRows << " rows:" << endl;
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
