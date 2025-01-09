class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int answer = 0;
        for(auto word : words) {
            if(isPrefix(pref, word))
                answer++;
        }
        return answer;
    }
private: 
    bool isPrefix(string pre, string str) {
        if(pre.size() > str.size())
            return false;
        for(int i = 0; i < pre.size(); i++) {
            if(pre[i] != str[i])
                return false;
        }
        return true;
    }
};