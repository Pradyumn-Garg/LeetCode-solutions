class Solution {
public:
    int solve(vector<int>& locations, int currCity, int finish, int remainingFuel,
              vector<vector<int>>& memo) {
        if (remainingFuel < 0) {
            return 0;
        }
        if (memo[currCity][remainingFuel] != -1) {
            return memo[currCity][remainingFuel];
        }

        int ans = currCity == finish ? 1 : 0;
        for (int nextCity = 0; nextCity < locations.size(); nextCity++) {
            if (nextCity != currCity) {
                ans = (ans + solve(locations, nextCity, finish,
                                   remainingFuel - abs(locations[currCity] - locations[nextCity]),
                                   memo)) % 1000000007;
            }
        }

        return memo[currCity][remainingFuel] = ans;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> memo(n, vector<int>(fuel + 1, -1));

        return solve(locations, start, finish, fuel, memo);
    }
};
// class Solution {
// public:
//     int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
//         vector <vector<int>> dp(fuel+1,vector<int>(locations.size()+1,-1));
//         return rec(locations, start, finish, fuel, dp);
//     }
//     int rec(vector <int> locations,int curr, int finish, int fuel, vector<vector<int>> &dp){
//         if(fuel==0){
//             if(curr==finish){
//                 return 1;
//             }
//             return 0;
//         }
//         if(dp[fuel][curr]!=-1){
//             return dp[fuel][curr];
//         }
//         int sum=0;
//         for(int i=0;i<locations.size();i++){
//             if(i==curr){
//                 continue; 
//             }
//             if(fuel-abs(locations[i]-locations[curr])>=0){
//                 sum=(sum+rec(locations,i,finish,fuel-abs(locations[i]-locations[curr]),dp))%1000000007;
//             }
//         }
//         if(curr==finish){
//             sum+=1;
//         }
//         return dp[fuel][curr]=sum;
//     }
// };