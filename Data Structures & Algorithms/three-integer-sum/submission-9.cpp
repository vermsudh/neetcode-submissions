class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        //Since we have to store the ans in the vector. 
        vector<vector<int>> ans;

        //Optimal Approach. 

        //We would need to use 2 pointers approach to find our two values. 
        //We can grab the first value using for loop traversal. 

        //Since we are using 2 pointers approach, we woudl need to make sure that the data is being sorted. 
        sort(nums.begin(), nums.end()); //as we need the data in a ascending order. 
        // [-1,0,1,2,-1,-4] => [-4, -1, -1, 0, 1, 2]

        for(int i = 0; i< n; i++){

            //We have to take one edge case. When i can get repeated values. The ans can also get duplicated and we need distinctive triplets.
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i -1]) continue; 
            //We have nums[i] already now. 
            //Now we have to use 2 pointers approach to find out nums[j] and nums[k];
            //We are going to initlize our pointers. 
            //We need to take j as i + 1 as we have already taken the 0 index as nums[i] and the nums[j] should always be after the nums[i].
            //Since we can't take any duplicated value. 
            int j = i + 1, k = nums.size() - 1;
            

            while(j < k){
                //We are going to have three conditions. When the sum of all three elements are equal to 0, less than and more than. 

                int sum = nums[i] + nums[j] + nums[k]; 

                if(sum > 0){//if sum is greater. We know that we can need to a smaller value. Now, we know if we increase j won't help as we need to decrease the value. 
                            //So we are going to decrease the largest value in the nums which is at last after sorting the data.  
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{//when we have the 
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                }
                //Edge Case:
                //We have to make sure that we do not take duplicated value. 
                 
            }
            
        }

        return ans;

        //Better approach in this case, that we do not have to run another loop to find nums[k]. 
        //SInce we know nums[i] and nums[j] and target = 0. We can find nums[k] = -nums[i] - nums[j] 
        //We can find this using hashing like we do in 2 SUM problem. We would need to check if nums[k] exists in the vector. If it does, then we have the ans.
        //TC: O(n^2)

        //We have to find find three values in the nums vector where the sum of them could be equal to 0.
        //Brute force approach TC : O (n^ 3)
        //We would need to run 3 loops in order to find the and put a if statement to find the ans. 

        // int n = nums.size();
        // //Since we have to store the ans in the vector. 
        // vector<int> ans;
        // for(int i = 0; i< n; i++){
        //     for(int j= i+1; j <n; j++){
        //         for(int k = j + 1; j <n; k++){
        //             if(nums[i] + nums[j] + nums[k] == 0){
        //                 //Since we have to store multiple ans. We would need to sort the ans and keep storing all the values
        //                 //until we are done iterating over the entire loop. 
        //                 ans.push_back(nums[i]);
        //                 ans.push_back(nums[j]);
        //                 ans.push_back(nums[k]);
        //             }
        //         }
        //     }
        // }
        // return ans; // We will return the ans if we have stores all the right values. 
    }
};
