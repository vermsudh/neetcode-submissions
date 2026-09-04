class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {


        //most optimized approach using hashset

        unordered_set<int> seen;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            seen.insert(nums[i]);
        }
        if(nums.size() == seen.size()){
                return false;
        }else{
            return true;
        }

        // //sorted vector
        // int n = nums.size();
        // sort(nums.begin(), nums.end());

        // for(int i = 0; i < n - 1; i++){
        //     if(nums[i] == nums[i + 1]){
        //         return true;
        //     }
        // }
        // return false;

        //brute force
        // int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     for(int j = i + 1; j < n; j++){
        //         if(nums[i] == nums[j]){
        //             return true;
        //         }
        //     }
        // }
        // return false;
    }
};