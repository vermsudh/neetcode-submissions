class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //brute force approach would be to get the sum of all the values using nested loops TC : O(n ^ 3 + n log (triplets)) as we are going to sort the arrays. 

        //Optamized approach. 

        int n = nums.size();
        vector<vector<int>> ans;

        //We would need to sort the array to use the 2 pointers approach to get the right pointers. 
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){

            //Now we would need to define the 2 pointers which are j and k. where j will be i+ 1 and k = n -1;
            int j = i + 1, k = n -1;
            
            //We need to make sure that i does not repeat as well once we are done finding the triplets. 
            //[[-1,-1,2],[-1,0,1]]

            if(i > 0 && nums[i] == nums[i -1]) continue;
            
            //loop to run over the 2 pointers. 
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum > 0){
                    k--;
                }else if (sum < 0){
                    j++;
                }else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    while(j < k && nums[j] == nums[j - 1] ) j++;//We do not need the repeated values 
                }
            }//2 poiner loop ends
        }// first for loop to obtain the first ith value. nums[i]

        return ans;
    }
};
