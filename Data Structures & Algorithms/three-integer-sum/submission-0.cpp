class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Using hashing 

        //We do not need a third loop as we can get the third value by 
        //a+ b + c = 0; a = -(b + c)

        int n = nums.size();
        set<vector<int>> uniqueTriplets;

        for(int i = 0; i < n; i++){
            int target = -nums[i];
            //now we need to create a set 
            set<int> s;

            for(int j = i +1; j < n; j++){
                int third = target - nums[j];

                if(s.find(third) != s.end()){
                    vector<int> trip = {nums[i], nums[j], third};
                    sort(trip.begin(), trip.end());
                    uniqueTriplets.insert(trip);
                }
                s.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
        return ans;



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
