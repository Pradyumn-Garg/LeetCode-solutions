class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector <long long> pairs;
        for(int i=0;i<n-1;i++){
            pairs.push_back(weights[i]+weights[i+1]);
        }
        sort(pairs.begin(),pairs.end());
        long long max=weights[0]+weights[n-1],min=max;
        for(int i=0;i<k-1;i++){
            min+=pairs[i];
        }
        int temp=pairs.size();
        for(int i=temp-1;i>temp-k;i--){
            max+=pairs[i];
        }
        return max-min;
    }
};