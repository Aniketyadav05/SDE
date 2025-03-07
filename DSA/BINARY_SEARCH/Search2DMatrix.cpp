#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int search(vector<vector<int>> arr, int i, int target) {
        int left = 0, right = arr[i].size() - 1;

        
        if (!arr[i].empty() && target >= arr[i][left] && target <= arr[i][right]) {
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (arr[i][mid] < target) {
                    left = mid + 1;
                } 
                else if (arr[i][mid] == target) {
                    cout << "Found at row: " << i << ", column: " << mid << endl;
                    return 1; 
                } 
                else {
                    right = mid - 1;
                }
            }
        } 
        else {
            return -1; 
        }

        return -1; 
    }

    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            int ans = search(matrix, i, target);
            if (ans == 1) {
                return true; 
            }
        }
        return false; 
    }
};

int main() {
    Solution sol; 

    
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 16; 

    
    bool result = sol.searchMatrix(matrix, target);

    
    if (result) {
        cout << "Target " << target << " found in the matrix!" << endl;
    } else {
        cout << "Target " << target << " not found in the matrix!" << endl;
    }

    return 0;
}
