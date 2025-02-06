class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> pairProducts;

        int totalNumberOfTuples = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                pairProducts.push_back(nums[i] * nums[j]);
            }
        } 
        
        sort(pairProducts.begin(), pairProducts.end());

        int lastProductSeen = -1;
        int sameProductCount = 0;

        for(int i = 0; i < pairProducts.size(); i++) {
            if (pairProducts[i] == lastProductSeen) {
                sameProductCount++;
            }
            else {
                int pairsOfEqualProduct = (sameProductCount - 1) * sameProductCount / 2;

                totalNumberOfTuples += 8 * pairsOfEqualProduct;

                lastProductSeen = pairProducts[i];
                sameProductCount = 1;
            }
        }
        // to handle last product group
        int pairsOfEqualProduct = (sameProductCount - 1) * sameProductCount / 2;
        totalNumberOfTuples += 8 * pairsOfEqualProduct;

        return totalNumberOfTuples;
    }
};