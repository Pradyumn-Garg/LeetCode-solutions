class Solution {
public:
    int minMaxDifference(int num) {
        string a = to_string(num);
        int ans;
        char first='-';
        int i=0;
        while(i<a.length()){
            if(a[i]!='9'&&first=='-'){
                first=a[i];
            }
            if(a[i]==first){
                a[i]='9';
            }
            i++;
        }
        ans=stoi(a);
        a = to_string(num);
        i=0;
        first=a[0];
        while(i<a.length()){
            if(a[i]==first){
                a[i]='0';
            }
            i++;
        }
        ans=ans-stoi(a);
        return ans;
    }
};