class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //We know that nums[i] != nums[j]

        //We are going to use hashmaps to store the sum and its 
        // indices. 

        unordered_map<int, int>m;

        //We know two value nums[i] and the target. 
        //We would just need to find the second value which is nums[j].
        // Nums[j] = target - nums[i]

        for(int i = 0; i < nums.size(); i++){
            int first = nums[i];
            int second = target - first;

            //We are going to store the the nums element to check if we have 
            //second value in the map or not. 

            if(m.find(second) != m.end()){
                //If the second value exist. then we would have simply return it. 
                return {m[second] , i};
            }
            m[first] = i; // this is to store the nums[i] in the map.
      
        }
        return {}; // if no pair exist where the sum == target. 
        
    }
};
