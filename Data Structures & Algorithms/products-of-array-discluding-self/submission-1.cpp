class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n,1);
        vector <int> suffix(n,1);
        vector <int> prefix(n,1);

        //prefix
        
        for(int i = 1; i < n; i++){
            prefix[0] = 1;
            prefix[i] = prefix[i - 1] * nums[i -1];
        }

        //suffix
        for(int i = n - 2; i >= 0; i--){
            suffix[0] = 1;
            suffix[i] = suffix[i + 1] * nums [i + 1];
        }

        //ans -> suffix * prefix
        for(int i = 0; i < n; i++){
            ans[i] = suffix[i] * prefix[i];
        }

        // for(int i = 0; i < n; i++){
        //     int products = 1;
        //     for(int j = 0; j < n; j++){
        //         if(nums[i] != nums[j]){
        //             products *= nums[j];
        //         }
        //     }
        //     ans.push_back(products);
        // }
        // return ans;
        return ans;
    }
    
};
