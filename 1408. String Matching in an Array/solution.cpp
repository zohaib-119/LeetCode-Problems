class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> answer;
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words.size(); j++) {
                if(i == j)
                    continue;
                if(isSubstring(words[i], words[j])) {
                    answer.push_back(words[i]);
                    break;
                }
            }
        }
        return answer;
    }
private: 
    bool isSubstring(string a, string b){
        if(a.size() > b.size())
            return false;
        int startMatch = 0;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()){
            if(a[i] == b[j]) {
                i++;
                j++;
            }
            else {
                ++startMatch;
                j = startMatch;
                i = 0;
            }
        }
        if(i == a.size()){
            return true;
        }
        return false;
    }
};