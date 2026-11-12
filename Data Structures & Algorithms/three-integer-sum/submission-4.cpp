class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        //Using 2 pointers approach.

        //Sort the array to use the 2 pointers approach.
        sort(nums.begin(), nums.end());
        // nums = {-4, -1, -1, 0, 1, 2};
        

        //Using the the first loop, we will get our first value which is nums[i]
        for(int i = 0; i < n; i++){
            
            //Now we will make two pointers which will be j and k. 
            int j = i + 1, k = n -1;// j will the number after the i and k will be the last value. 
            //We know that j will be smallest and k will be largest among the numbers. 

            //Similarly, we have to make sure that if i repeats again, we would have to skip it. 
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            //now we would need to iterate over j and k to shift the values. i will automatically increment. 
            //Since we are going to move inwards from j to k.
            while(j < k){
                //Now we need to get the sum of all the three valuues to check when it is equal to 0. 

                int sum = nums[i] + nums[j] + nums[k];

                //Now, we would need to check how we will move the pointersl.
                //We will have three conditions to check one when the sum is greater than, smaller than and equal than. 

                //greater. 
                if(sum > 0){
                    //We know that when the sum is greater than 0, we would have to decrement the k which is the largest value to get a smaller value. 
                    k--;
                }
                //when it it smaller.
                else if(sum < 0){
                    j++;
                }
                //here we sum will be equal to 0. So, we would have to store our numbers in the vector ans. 
                else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;// we will still move the windows inwards when we find the ans as we do not want to repeat any triplets. 
                    //Now, we have to perform more optmaization to make sure that we do not repeat any values. 
                    // if nums = {-4, -1, 0, 0, 1, 1};
                    //Over here j can repeat by taking 0. In this case, lets assume when i = -1, j = 0, k = 1. Over here we will find our pair [-1, 0, 1]. Now j will increment and k will decrement. 
                    //But we will again get the same triplet : where i = -1, j =0, k = 1;
                    //In order to skip that, we have to make sure if we get any repeated values on k and j, we will need to skip those. 

                    while(j < k && nums[j] == nums[j - 1]) j++;
                    
                }
            } 
        }//for loop ends. 
        return ans;
    }
};
