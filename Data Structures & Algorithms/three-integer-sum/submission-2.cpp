class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Most Optimal Solution is using the 2 pointers approach. 
        //Lets sort the array first of all. 
        sort(nums.begin(), nums.end());
        //sorted array : {-4, -1, -1, 0, 1, 2};

        int n = nums.size();
        vector<vector<int>> ans;// we will need to store our solution which is [[-1,-1,2],[-1,0,1]]

        for(int i = 0; i < n; i++){
            //We have one number already which is nums[i]. 
            int j = i + 1, k = n - 1;

            //since the triplets should be distinctive. We have to make sure that 
            if(i > 0 && nums[i] == nums[i - 1]) continue;//if i = -1. We will make a triplet already with [-1, -1, 2]. We have to make sure that we do not repeat this triplet. So if -1 == -1 in the next triplet, then we have to skip taking i = -1 and start with a new number to obtain distintive triplets. 

            while(j < k){//running this loop until j is greater than k. 
                int sum = nums[i] + nums[j] + nums[k];

                if(sum > 0){
                    k--;
                }else if(sum < 0){
                    j++;
                }else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    k--; j++;
                    while(j < k && nums[j] == nums[j - 1]) j++;//similary just assume we have an array : {-4, -1, 0, 0, 1, 2} We have found the one triplet already which is {-1, 0, 1}. Now we, in next iteration i = 0 and j = 0. We cant have j as 0 again as we need distinctive triplets. so we would have to skip this j by going to next value until we have a unique value. 
                    
                }
            }
        }
        
        return ans;
    }
};
