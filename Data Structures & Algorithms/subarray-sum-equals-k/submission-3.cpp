class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int ps = 0, count = 0;
        unordered_map<int, int> m;
        m[0] = 1;

        for(int i = 0; i < nums.size(); i ++){

            ps += nums[i];
            int remove = ps - k;
            count = count + m[remove];
            m[ps]++;
        } 

        return count;
        
    }
};