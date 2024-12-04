class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        while(j < str2.size() && i < str1.size()){
            if(str1[i] == str2[j] || (str1[i]+1) == str2[j] || (str1[i] == 'z' && str2[j] == 'a')) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        if(j == str2.size()){
            return true;
        }
        return false;
    }
};