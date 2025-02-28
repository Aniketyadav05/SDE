#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For accumulate function

using namespace std;

class Solution {
public:
    // Function to calculate the number of days required to ship with given capacity
    int findDays(vector<int> arr, int cap) {
        int days = 1; // Start with one day
        int load = 0; // Current load of the ship
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            // If adding the current weight exceeds capacity, start a new day
            if ((load + arr[i]) > cap) {
                days += 1; // Increment days
                load = arr[i]; // Start new load with current weight
            } else {
                load += arr[i]; // Add weight to current day's load
            }
        }
        return days;
    }

    // Function to find the minimum capacity needed to ship within the given days
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()); // Minimum capacity needed
        int right = accumulate(weights.begin(), weights.end(), 0); // Maximum possible capacity
        
        // Binary search to find the optimal ship capacity
        while (left <= right) {
            int mid = (left + right) / 2;
            if (findDays(weights, mid) <= days) {
                right = mid - 1; // Try a smaller capacity
            } else {
                left = mid + 1; // Increase capacity
            }
        }
        return left;
    }
};

int main() {
    Solution sol;
    
    // Example input: weights of packages and required number of days
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    // Calling the function and printing the result
    int result = sol.shipWithinDays(weights, days);
    cout << "Minimum capacity required to ship within " << days << " days: " << result << endl;

    return 0;
}
