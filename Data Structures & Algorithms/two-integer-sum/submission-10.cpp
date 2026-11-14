class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //We have to return the indices which is basically the index of the array elements where the sum is equal to the target.

        //Brute force approach would be to use the nested loop to access two values. 
        //Since we have to return a vector.
        vector<int> ans;// We will store the ans in the vector. 
        //Also we need to make sure that our i != j

        //Therefore we cant retrun 5 , 5 in this case : [4,5,6], target = 10 [1, 1]
        int n = nums.size();
        for(int i = 0; i < n; i++){
            //Now we need a second loop to have j element. 
            for(int j = i + 1; j < n; j++){
                //now we need to check if the sum of these elements are equal to target or not. 
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }

        return ans;//return the vector. 
    }
};
