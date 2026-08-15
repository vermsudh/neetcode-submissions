class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0; // first we will initlize the ans with 0
        for(int val : nums){ // Then we run a loop in the   vector
            ans ^= val; 
           // This iteration will be 3 ^ 3 ^ 2 = 2 becasue
           //XOR of 3 ^ 3 is 0 and 0 ^ 2 = 2
        }
        return ans;
    }
};
