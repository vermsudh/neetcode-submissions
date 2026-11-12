class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //Brute force approach of this question would be to use nested loops. 
        //We would have to access the values using nested loops. 

        //nums : {9, 4, 20, 3, 10, 5}, target = 33;

        int n = nums.size(), count = 0;

        for(int i = 0; i < n; i++){
            int sum = 0; 
            for(int j = i; j < n; j++){
                sum += nums[j];

                if(sum == k){
                    count++;
                }
            }
        }
        return count;
    }
};