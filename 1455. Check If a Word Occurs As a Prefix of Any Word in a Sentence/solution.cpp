class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 1;
        int i = 0;
        while(i < sentence.size()) {
            if(isPrefix(sentence.substr(i), searchWord)){
                return index;
            }
            index++;
            while(i < sentence.size() && !(sentence[i] == ' ')) {
                i++;
            }
            i++;
        }
        return -1;
    }
private:
    bool isPrefix(string str, string pre) {
        if(str.size() < pre.size()){
            return false;
        }
        for(int i = 0; i < pre.size(); i++){
            if(str[i] != pre[i]){
                return false;
            }
        }
        return true;
    }
};