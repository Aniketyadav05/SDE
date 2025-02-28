#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& arr) {
        int n = arr.size()-1;
        int k =0;
        while(k<n){
        swap(arr[n], arr[k]);
        k++;
        n--;
        }
        k =1;
        n = arr.size()-1;
        while(k<n){
            swap(arr[n], arr[k]);
            k++;
            n--;
        }
    } 

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    rotate(arr);
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}