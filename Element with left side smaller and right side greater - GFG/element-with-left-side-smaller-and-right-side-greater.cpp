//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int arr[], int n) {
    vector<int> left;
    vector<int> right;
    int temp=INT_MAX;
    for(int i=n-1;i>=0;i--){
        right.push_back(temp=min(temp,arr[i]));
    }
    temp=INT_MIN;
    for(int i=0;i<n;i++){
        left.push_back(temp=max(temp,arr[i]));
    }
    for(int i=1;i<n-1;i++){
        if(left[i-1]<=arr[i]&&right[n-i-2]>=arr[i]){
            return arr[i];
        }
    }
    return -1;
}