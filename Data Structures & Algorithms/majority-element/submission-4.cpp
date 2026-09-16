class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();
        //moore's voting algorithm

        int count = 0;
        int candidate = 0;
        for(int num : nums){
            if(count == 0){
                candidate = num;
            }
            if(candidate == num){
                count ++;
            }
            else{
                count --;
            }
        }
        return candidate;
        // //sorting approach
        // sort(nums.begin(), nums.end());

        // return nums[n/2];

        //brute force. Time complexity will be O(N^2)Space would be O(1)
        // int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     int count = 1;
        //     for(int j = i + 1; j < n; j++){
        //         if(nums[i] == nums[j]){
        //             count++;
        //         }
        //     }
        //     if(count > n/2){
        //         return nums[i];
        // }
        // }

    }
};