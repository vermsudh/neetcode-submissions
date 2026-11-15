class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // We will move to the most optmaized approach on this.

        //We would have to use 2 pointers approach to pick up 2 values so that
        //we do not have to use 2 extra for loops to do the same job. 

        //nums[a] + nums[b] + nums[c] + nums[d] == target 
        // It has been given that a != b != c != d. Every element should be distinctive. 

        //Lets grab the first element which is a. 
        int n = nums.size();
        //Lets creates a matrix vector to store our ans. 

        vector<vector<int>> ans;
        
        //Since we are going to 2 pointers approach, we would have to make sure that we use sorted elements. 
        sort(nums.begin(), nums.end()); // O (n log n);
        // [-3, 0, 1, 2, 3, 3]

        for(int a = 0; a < n; a++){
            //Since, it has been given a should not repeat. Just is case if we have any example where we have 
            // assume we have :  [-3, -3, 0, 1, 2, 3, 3]. THen we will have to make sure we do not get repeated ans with same i value -3. 
            //[-3, 0, 3, 3] and [[-3, 0, 3, 3]] where i is at 0 and 1 both. 
            //In this case, we would have to make sure that we have to skip the values if the current i value is == to previous i value. 

            if(a > 0 && nums[a] == nums[a - 1]) continue;

            for(int b = a + 1; b < n; ){// We are taking a + 1 as we do not want the first element which is a. 
                //Now, we would need our 2 pointers c and d. 

                int c = b + 1, d = n -1; // c is going to be after b as we need distinctive values. 

                while(c < d){
                    //We would have to assign sum as long, just in case if we have bigger int values for a, b, c, d 
                    long long sum = (long long)nums[a] + (long long)nums[b] + (long long)nums[c] + (long long)nums[d];

                    //Nowe we would need to check how the pointers should move. 

                    if(sum > target){// if the sum is getting bigger than target
                        d--;
                    }   
                    else if(sum < target){
                        c++;
                    }
                    else{ //sum is equal to the target. In this case, we will find our quads. 
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++; d--;
                        //Similarly We would have to make sure that we do not repeat c value. 

                        while(c < d && nums[c] == nums[c - 1]) c++;
                    }
                    
                }
                //Similarly as i, we need to make sure that we do not repeaat b as well. 

                //We will only increment b when it is done search the right c and d. 
                b++; 

                while(b < n && nums[b] == nums[b - 1])b++;
            }
        }

        //At last, we will return our ans. 

        return ans;
    }
};