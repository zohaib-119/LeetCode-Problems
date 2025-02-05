class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int firstIndex, mismatches = 0;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i]) {
                if(mismatches == 0) {
                    firstIndex = i;
                }
                else if(mismatches == 1) {
                    if(s1[i] != s2[firstIndex] || s2[i] != s1[firstIndex]) {
                        return false;
                    }
                }
                else {
                    return false;
                }
                mismatches++;
            }
        }
        if(mismatches == 1)
            return false;
        return true;
    }
};