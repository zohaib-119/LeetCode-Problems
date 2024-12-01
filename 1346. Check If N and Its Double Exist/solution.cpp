class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<double> set;
        for(int i = 0; i < arr.size(); i++){
            if(set.find(arr[i]/2.0) == set.end() && set.find(2.0* arr[i]) == set.end() ){
                set.insert(arr[i]);
            } else{
                return true;
            }
        }
        return false;
    }
};