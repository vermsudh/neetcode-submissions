class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //We can solve this question using brute force, whwere we will have to take 4 nested loops which will give us TC: O (n ^ 4).
        //A better approach would be, we can bring the TC to O(n ^ 3) by using hashing as we can get the last element since we know the target and the other three element
        
        
        //Most Optmaized approach. We will need to use 2 pointers to get 2 elements and we can take 2 elements using nested for loops. 

        //Since we have to use 2 pointers approach, we need to make sure that our data is sorted. 

        sort(nums.begin(), nums.end());
        //[3,2,3,-3,1,0] -> [-3, 0, 1, 2, 3, 3]
        int n = nums.size();// this will store the size of the vector 

        //We are going to store our ans in a matrix.
        vector<vector<int>> ans;

        //Our first nums[i] would be our first value.
        for(int i = 0; i < n; i++){//We will obtain nums[i] which is our first element. 
            //We have to look out for edge cases : assume we have this vector [-3, -3, 0, 0, 2, 3, 3]. 
            //In this case, we can have two ans [[-3,0,3,3], [-3,0,3,3]]// Since we have to avoid the duplication. We would need need to ignore the -3 and continue
            //if our previous - value is same. IN this case : nums[i] and nums[i -1] are same. 
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i + 1; j < n;){//This will give us second element. 

                //Now we can find 2 more elements p and q using 2 pointers approach. 
                
                int p = j + 1;//This will be the third value 
                int q = n - 1;//This will be the last value

                while(p < q){
                    //We have to make sure that we take long long as our sum as bigger int can exceed the range when we add them, so the sum needs to be in long.
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];

                    if(sum < target){ //1st iteration will be sum = -3 + 0 + 1 + 3 = > 1 and target = 3 We need to increment p as we need bigger values and since 
                    //we have sorted the data already, we will find bigger values as we increment p
                        p++; 
                    }
                    else if(sum > target){
                        q--;
                    }
                    else{ // when our sum would be equal to target. 
                        //In this case, we will have to store our ans in the matrix.
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;q--;

                        //Similarly we have to make sure that we do not get duplicated value for p.
                        while(p < q && nums[p] == nums[p - 1])p++;//We will have to ignore p if they are similar. 
                        //Assume : [-3, 0, 1, 2, 3, 3, 3]
                    }
                }

                //SImilarly for j, we need to make sure that we do not repeat the value. 
                j++;// The reason we need to increment j after this while loop is because we need to grab all the 4 values and then check if the previous j and next j 
                //values are matching or not? 
                while(j < n && nums[j] == nums[j - 1]) j++;
            }
        }

        //At last, we return the ans. 
        return ans;
    }
};