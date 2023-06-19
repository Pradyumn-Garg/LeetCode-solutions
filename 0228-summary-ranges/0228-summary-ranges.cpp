class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0){
            return ans;
        }
        string str;
        long long st=nums[0],curr=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]==curr){
                curr++;
                continue;
            }
            else{
                if(st==nums[i-1]){
                    str="";
                    str+=to_string(st);
                    ans.push_back(str);
                    st=nums[i];
                    curr=st+1;
                }
                else{
                    str="";
                    str+=to_string(st);
                    str+="->";
                    str+=to_string(nums[i-1]);
                    ans.push_back(str);
                    st=nums[i];
                    curr=st+1;
                }
            }
        }
        if(st==curr-1){
            ans.push_back(to_string(st));
        }
        else{
            str="";
            str+=to_string(st);
            str+="->";
            str+=to_string(curr-1);
            ans.push_back(str);
        }
        return ans;
    }
};