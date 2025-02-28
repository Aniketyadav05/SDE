#include <iostream>
#include <vector>
#include <algorithm> // For sorting

using namespace std;

class Solution {
public:
    // Function to check if we can place 'm' cows with at least 'mid' distance apart
    bool canPlaceCows(vector<int> arr, int mid, int m) {
        int n = arr.size();
        int countCows = 1; // First cow placed at the first position
        int lastPlaced = arr[0];

        for (int i = 1; i < n; i++) { // Start from the second position
            if (arr[i] - lastPlaced >= mid) { // Check if we can place a cow here
                countCows++;
                lastPlaced = arr[i]; // Update last placed cow position
            }
            if (countCows >= m) { // If we placed all cows successfully
                return true;
            }
        }
        return false;
    }

    // Function to find the largest minimum distance for placing 'm' cows
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end()); // Sort stall positions
        
        int left = 1, right = position[n-1] - position[0]; // Minimum & maximum possible distances
        int bestDist = 0;

        // Binary search to find the optimal largest minimum distance
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canPlaceCows(position, mid, m)) {
                bestDist = mid; // Update best distance
                left = mid + 1; // Try to maximize distance
            } else {
                right = mid - 1; // Reduce the search range
            }
        }
        return bestDist;
    }
};

int main() {
    Solution sol;

    // Example input: Stall positions and number of cows
    vector<int> position = {1, 2, 8, 4, 9};
    int m = 3;

    // Calling the function and printing the result
    int result = sol.maxDistance(position, m);
    cout << "Largest minimum distance to place " << m << " cows: " << result << endl;

    return 0;
}
