#include <iostream>
#include <vector>
#include <algorithm> // For sorting

using namespace std;

class Solution {
public:
    // Function to check if we can place 'm' cows with at least 'mid' distance apart
    bool PlaceKrSkte(vector<int> arr, int mid, int m) {
        int n = arr.size();
        int cntCows = 1; // Place the first cow in the first stall
        int last = arr[0]; // Track the last placed cow's position

        for(int i = 0; i < n; i++) {
            // If the gap between the current stall and last placed cow is at least 'mid', place a cow here
            if(arr[i] - last >= mid) {
                cntCows++; // Place a cow
                last = arr[i]; // Update last placed cow position
            }
            // If all cows are placed successfully, return true
            if(cntCows >= m) {
                return true;
            }
        }
        return false; // If we couldn't place all cows, return false
    }

    // Function to find the largest minimum distance between cows
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end()); // Sort the stalls to make placing cows easier
        
        int left = 1, right = position[n-1] - position[0]; // Possible distance range

        // Binary search to find the maximum minimum distance
        while(left <= right) {
            int mid = (left + right) / 2;
            
            // Check if it's possible to place all cows with at least 'mid' distance
            if(PlaceKrSkte(position, mid, m)) {
                left = mid + 1; // Try for a bigger distance
            }
            else {
                right = mid - 1; // Reduce the distance
            }
        }
        return right; // The largest possible minimum distance
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
