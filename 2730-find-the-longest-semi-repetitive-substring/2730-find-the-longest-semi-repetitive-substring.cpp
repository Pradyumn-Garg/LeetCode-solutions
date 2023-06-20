class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int start=0,flag=0,ans=0,pair=0;
        for(auto i=0;i<s.length()-1;i++){
            if(flag==0&&s[i]==s[i+1]){
                pair=i+1;
                flag=1;
            }
            else if(flag==1&&s[i]==s[i+1]){
                if(i-start+1>ans){
                    ans=i-start+1;
                }
                start=pair;
                pair=i+1;
            }
        }
        if(s.length()-start>ans){
            ans=s.length()-start;
        }
        return ans;
    }
};