class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        //nums = [3,2,3,-3,1,0] target = 3. 
        //[[-3,0,3,3] = -3 + 0 + 3 + 3 => 3
        //[-3,1,2,3]] => 3

        //We need to return the quads where the sum of the quads should be equal to the target. 
        //And all the values of the quads should be distinctive : a != b !=c !=d

        //For the Brute force, we have can nested for loops running 4 times to grab all the 
        //values and inside the most inner loop, we can check if the sum of 4 values is 
        //equal to the target or not? If they are, then we would need to store those in the ans. 
        //TC: would be O(n ^ 4 + n log (quads)) as we will be using nested loops which will run from 1 to n
        //and sort the quads to make sure, we do not repeat any values again. 

        //Since we have to return a matrix vector. 
        vector<vector<int>> ans;
        int n = nums.size(); //Size of the array. 

        // The most optamized approach would be to use 2 pointers in this case. 

        // We can take the first value of the quad which is nums[a] using a for loop and second value b would be 
        // a + 1 to n. 

        //In order to use the 2 pointers approach, we would have to sort the array first. 

        sort(nums.begin(), nums.end()); // THis will give us nums : {-3, 0, 1, 2, 3, 3}; 
        //Now We can run the 2 pointers from 2index to last index. 

        for(int i = 0; i < n; i++){
            //Similarly, if the i is same as the previous value, we might find the same quads. 
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i + 1; j < n;){

                //Now we need to make our 2 pointers in order to travese over the rest of the array. 
                int p = j + 1, q = n -1;

                while(p < q){

                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];

                    //Now, we know that our target is equal to sum to find the quads. 
                    //We need to check how we are going to move our pointers. 

                    //if sum < target = > p++; We have to move the q--; element by 1. The next element would be 3 again. 
                    //THen we will find 2. The first quad will be when i = -3 j = 1, p = 2 and q = 3.

                    if(sum < target){
                        p++; 
                    }else if (sum > target){
                        q--;
                    }else{// In this case we will find our quads. which is target == sum
                        //We have to store the quads in the ans vector using a push_back function. 
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++; q--;
                        //Now, we need to make sure that we do not repeat any values as it is given in the question. 
                        //There might be some case when we can find the repeated quads if the values are repeating. 
                        while(p < q && nums[p] == nums[p - 1]) p++;
                    }
                }
                j++;
                while(j < n && nums[j] == nums[j -1]) j++;
            }
        }
        return ans;
    }
};