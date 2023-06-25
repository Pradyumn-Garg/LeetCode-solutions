class Solution {
public:
    int rec(vector <int> &locations,int curr, int finish, int fuel, vector<vector<int>> &dp){
        if(fuel<0){
            return 0;
        }
        if(dp[curr][fuel]!=-1){
            return dp[curr][fuel];
        }
        
        int sum = curr == finish ? 1 : 0;

        for(int i=0;i<locations.size();i++){
            if(i!=curr){
                sum=(sum+rec(locations,i,finish,fuel-abs(locations[i]-locations[curr]),dp))%1000000007;
            }
        }
        return dp[curr][fuel]=sum;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        vector <vector<int>> dp(n,vector<int>(fuel+1,-1));
        return rec(locations, start, finish, fuel, dp);
    }
};