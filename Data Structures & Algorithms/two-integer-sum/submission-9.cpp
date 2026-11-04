class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //We are going to solve this question using hashsets. 

        unordered_map<int, int> s;

        for(int i = 0; i < nums.size(); i++){
            //We have the target and we are going to assume our every value in the nums to be first value. 
            //We can say that second = target - first. We know if we find the right pair which are equal, then 
            // we will be able to find our ans. 
            int first = nums[i];
            int second = target - nums[i]; 

            if(s.find(second) != s.end()){
                return {s[second], i};
            }   
            
            s[first] = i;
        }
        return {};
    }
};
