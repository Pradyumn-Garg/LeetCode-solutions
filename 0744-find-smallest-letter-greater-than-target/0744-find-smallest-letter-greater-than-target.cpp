class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(auto i=0;i<letters.size();i++){
            if(int(letters[i])>int(target)){
                return letters[i];
            }
        }
        return letters[0];
    }
};