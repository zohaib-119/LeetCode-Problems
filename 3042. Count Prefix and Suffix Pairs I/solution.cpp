class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int answer = 0;
        for(int i = 0; i < words.size(); i++) {
            for(int j = i+1; j < words.size(); j++) {
                if(isPrefixAndSuffix(words[i], words[j])) {
                    answer++;
                }
            }
        }
        return answer;
    }
private:
    bool isPrefixAndSuffix(string str1, string str2) {
        if(str1.size() > str2.size())
            return false;
        for(int i = 0; i < str1.size(); i++) {
            if(str1[i] == str2[i] && str1[str1.size()-1-i] == str2[str2.size()-1-i])
                continue;
            return false;
        }
        return true;
    }
};