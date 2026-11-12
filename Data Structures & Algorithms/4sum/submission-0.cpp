class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        //Using 2 pointer approach.

        //We have four numbers : i, j, p , q
        //We have to make sure that the sum of these three numbers should be equal to the target value. 
        //if it is equal, we will find our quads. 

        //Since we need to return a matrix vector. 
        vector<vector<int>> ans;

        int n = nums.size();//Size of the nums. 

        //SInce we are going to use 2 pointers appoach, we will need sort the array first. 

        sort(nums.begin(), nums.end());// [-3, 0, 1, 2, 3, 3]; target = 3

        //Lets make the first value which is i.

        for(int i = 0; i < n; i++){
            //We have nums[i] as the first value. 

            //Now we would need to make sure that we do not repeat any values if i is -3 and we have already founnd our
            // quad with i = -3. and assume if the next value is -3 as well, In that case, we will need to move on.
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            //Now, we will need another loop for j. and we will p and q as pointers which will move inwards. 
            for(int j = i + 1; j < n;){//J should be initlized by i + 1.

                //Now, lets make the two pointers p and q. 
                int p = j + 1, q = n -1;
                
                //Now we have all the 4 values. i, j, p, q 

                //We need to iterate over those 2 pointers now. 
                while(p < q){//2 pointers loop. running from 1 to 3
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];
                    //We are taking long long as int can be a smaller and if we have bigger int values, 
                    //then it is can exceed the limits of int. 

                    //Now, we will need to check three conditions. 
                    //when sum is greater than, smaller than and equal to the target. 
                    if(sum < target){// if sum is greater than target. 
                        //We will need to bigger values for p
                        p++;
                    }else if(sum > target){
                        //When sum is greater than target.
                        //We will need to decrease q to obtain smaller value. 
                        q--;
                    }else{//when sum and target are equal. 
                        //If they are equal, in that case we would need to add that to ans.

                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;q--;//We still have to move inwards when we find the right pair. 
                        
                        //Now we have to make sure that p should not repeat. 
                        while(p < q && nums[p] == nums[p -1]) p++;
                    }
                }
                j++;
                //Now, we have to make sure that we do not repeat any values. 
                while(j < n && nums[j] == nums[j - 1 ]) j++;

            }//2nd inner loop

        }//1st outer loop

        return ans;// We will return the ans as we agoing to store all the possible quads. 
    }
};