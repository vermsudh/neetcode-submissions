class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //optimal solution would be to use hashing which is maps along with preSum approach.

        int preSum = 0, count = 0; 

        unordered_map<int, int>m;

        m[0] = 1; //We are storing the first value in the map as (0, 1) as need to store the initlize value which is 0 when nothing is added. 


        for(int i = 0; i < nums.size(); i++){
            preSum += nums[i];
            int remove = preSum - k;
            count += m[remove];
            m[preSum]++; 
        }

        return count;
        //Brute force approach of this question would be to use nested loops. 
        //We would have to access the values using nested loops. 

        //nums : {9, 4, 20, 3, 10, 5}, target = 33;

        // int n = nums.size(), count = 0;

        // for(int i = 0; i < n; i++){
        //     int sum = 0; 
        //     for(int j = i; j < n; j++){
        //         sum += nums[j];

        //         if(sum == k){
        //             count++;
        //         }
        //     }
        // }
        // return count;
    }
};