class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Using 2 pointers approach. 

        int n = nums.size();

        //sorting the nums array first. 
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){// This loop will traverse over the nums.

            int j = i + 1, k = n - 1;

            if(i > 0 && nums[i] == nums[i - 1]) continue;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum > 0){
                    k--;
                }else if (sum < 0){
                    j++;
                }else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    k--; j++;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                }
            }
        }
        return ans;


        //Using hashing 

        //We do not need a third loop as we can get the third value by 
        //a+ b + c = 0; a = -(b + c)

        // int n = nums.size();
        // set<vector<int>> uniqueTriplets;

        // for(int i = 0; i < n; i++){
        //     int target = -nums[i];
        //     //now we need to create a set 
        //     set<int> s;

        //     for(int j = i +1; j < n; j++){
        //         int third = target - nums[j];

        //         if(s.find(third) != s.end()){
        //             vector<int> trip = {nums[i], nums[j], third};
        //             sort(trip.begin(), trip.end());
        //             uniqueTriplets.insert(trip);
        //         }
        //         s.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
        // return ans;



        //Brute force approach with TC : O(n ^ 3 * O(log(triplets)))
        // int n = nums.size();
        // set<vector<int>> s;
        // vector<vector<int>> ans;

        // for(int i = 0; i < n; i ++){
        //     for(int j = i + 1; j < n; j++){ 
        //         for(int k = j + 1; k < n; k++){
        //             if(nums[i] + nums[j] + nums[k] == 0){
        //                 vector<int> triplets = {nums[i], nums[j], nums[k]};

        //                 sort(triplets.begin(), triplets.end());

        //                 if(s.find(triplets) == s.end()){
        //                     s.insert(triplets);
        //                     ans.push_back(triplets);
        //                 }
        //             }
        //         }
        //     }
        // }
        // return ans;
    }
};
