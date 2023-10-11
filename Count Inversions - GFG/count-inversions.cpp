//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.

    long long merge(long long arr[], long long s,long long mid,long long e){
        vector<long long> v;
        long long first=s,sec=mid+1;
        long long ans=0;
        while(first<=mid&&sec<=e){
            if(arr[first]>arr[sec]){
                ans+=mid-first+1;
                v.push_back(arr[sec]);
                sec++;
            }
            else{
                v.push_back(arr[first]);
                first++;
            }
        }
        while(first<=mid){
            v.push_back(arr[first]);
            first++;
        }
        while(sec<=e){
            v.push_back(arr[sec]);
            sec++;
        }
        for(auto i:v){
            arr[s]=i;
            s++;
        }
        return ans;
    }
    
    long long mergesort(long long arr[], long long s,long long e){
        if(s<e){
            long long ans=0;
            long long mid=(s+e)/2;
            ans+=mergesort(arr,s,mid);
            ans+=mergesort(arr,mid+1,e);
            ans+=merge(arr,s,mid,e);
            return ans;
        }
        return 0;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        return mergesort(arr,0,N-1);
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends