class Solution {
public:
    int longestValidParentheses(string s) {
        stack <int> stack;
        int curr=0,ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                stack.push(0);
            }
            else{
                if(!stack.empty()){
                    if(stack.top()==0){
                        curr=2;
                        stack.pop();
                        while(!stack.empty()&&stack.top()!=0){
                            curr+=stack.top();
                            stack.pop();
                        }
                        ans=max(curr,ans);
                        stack.push(curr);
                        continue;
                    }
                    else{
                        curr=stack.top();
                        stack.pop(); 
                        if(!stack.empty()&&stack.top()==0){
                            stack.pop();
                            curr+=2;
                            while(!stack.empty()&&stack.top()!=0){
                                curr+=stack.top();
                                stack.pop();
                            }
                            ans=max(curr,ans);
                            stack.push(curr);
                            continue;
                        }
                        else{
                            curr=0;
                        }
                    }
                }
            }
        }
        return ans;
    }
};