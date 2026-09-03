class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n,1);

        // vector <int> suffix(n,1);
        // vector <int> prefix(n,1);
        // we need to optimized this code more in order to bring the 
        //space complexity to O(1)

        //Now, we do not have to create a seperate array for suffix and
        //prefix. We can just get the product of these two directly 
        // into the ans vector.

        for(int i = 1; i < n; i++){
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int suffix = 1;
        for(int i = n - 2; i >= 0; i--){
            suffix *= nums[i + 1];
            ans[i] *= suffix;
        }
        return ans;


        // Time and space complexity in this case would be O(n)
        // //prefix
        // for(int i = 1; i < n; i++){
        //     prefix[0] = 1;
        //     prefix[i] = prefix[i - 1] * nums[i -1];
        // }

        // //suffix
        // for(int i = n - 2; i >= 0; i--){
        //     suffix[0] = 1;
        //     suffix[i] = suffix[i + 1] * nums [i + 1];
        // }

        // //ans -> suffix * prefix
        // for(int i = 0; i < n; i++){
        //     ans[i] = suffix[i] * prefix[i];
        // }

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
        
    }
    
};
