//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> st;  
  

    for (int i = 0; i < a.size(); i++) {
      	st.insert(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
      	st.insert(b[i]);
    }
    vector<int> res;                            
  
  	for(auto it: st){
      	res.push_back(it);
  	}
    return res.size();
    }


//{ Driver Code Starts.

int main() {
    vector<int> a = { 1, 4, 3, 2, 6, 5 };
    vector<int> b = { 1, 6,7};
    cout<<findUnion(a , b)<<endl;
  

    return 0;
}
// } Driver Code Ends