class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        //2 pointers approach
        // nums = [0,0,1,2,0,5]
        int left = 0;
        int right = 0;

        while(right < n){

            if(nums[right] != 0 ){
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }

        // //brute force (nested loop)
        // for(int i = 0; i < n; i++){
        //     for(int j = i + 1; j < n; j++){
        //         if(nums[i] == 0){
        //             swap(nums[i], nums[j]);
        //         }
        //     }
        // }
    }
};