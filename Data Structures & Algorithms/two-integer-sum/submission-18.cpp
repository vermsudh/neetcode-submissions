class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> m;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            int first_element = nums[i];

            int second_element = target - first_element;

            if(m.find(second_element) != m.end()){
                return {m[second_element], i};
            }

            m[first_element] = i;
        }
        
        return {};
        //better approach TC : O(n log n)

        //1) Sort the array. 

        // sort(nums.begin(), nums.end());

        // int start = 0, end = nums.size() - 1;
        // vector<int>ans;

        // while(end > start){
        //     if(nums[start] + nums[end] > target){
        //         end --;
        //     }
        //     else if(nums[start] + nums[end] < target){
        //         start++;
        //     }else{
        //         ans.push_back(start);
        //         ans.push_back(end);
        //         break;
        //     }
        // } 
        // return ans;
        // //brute force approach with TC : O(n ^ 2) ans SC will be O(n)
        // int n = nums.size();
        // vector<int> ans;
        // for(int i = 0; i < n; i++){
        //     for(int j = i + 1; j < n; j++){
        //         if(nums[i] + nums[j] == target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        // return ans;
    }
};
