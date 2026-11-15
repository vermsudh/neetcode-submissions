class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        //Lets try to solve this question using most optamized approach. 

        //We will use 2 pointers approach for this. 

        vector<vector<int>> ans;

        //Lets sort the nums first in order to the do implement 2 pointers. 

        sort(nums.begin(), nums.end()); //O (n log n)
        // nums = [-4, -1, -1, 0, 1, 2]
        //Now the nums is sorted. 

        int n = nums.size();

        for(int i = 0; i < n; i++){
            //This loop will give us nums[i] 

            //now we would have to use 2 pointers inside this. 

            // Since the elements should be distictive.
            int j = i + 1, k = n - 1;
            //We have to make sure that we do not repeat any values. 
            // lets we have [-4,, -1, -1, 0, 1, 2] // THe possible ans would be [-1, 0 1] ans [-1, 0, 1] where -1 is at 1 and 2 both.
            //In order to skip that, we would need a condition if nums[i] == previous element[nums[i - 1]], then skip it. 

            if(i > 0 && nums[i] == nums[i - 1]) continue;
            // j and k is our pointers which will run from 0 
            while(j < k){
                
                int sum = nums[i] + nums[j] + nums[k];

                //Now we would need to check how to move the pointers. 

                if(sum >0){ // if the sum is coming greater then we would have to decrese the bigger element which is k
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{ // when the sum == 0, we will find our trips. 
                    ans.push_back({nums[i], nums[j], nums[k]});
                    k--; j++;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                    //Similarly for that J, we would have to make sure that we do take any num that is already repeating. 
                }  
            }
            
        }

        return ans;

        




        // We have to return nums[i], nums[j], nums[k] such that the sum of them is equal to 0.
        //return rempty vector if there is not solution. 
        //Also, we have been given that all the digits should be distintive which means 
        //nums[i] != nums[j] != nums[k]

        //Lets create a vector. 
        // vector<vector<int>> ans;
        // //We would need a set to store the unique triplets.
        // set<vector<int>>s;


        //Brute force approach of this solution would be to solve it using nestest for loops which 
        //can give us TLE as the loops will be running O (n ^ 3  * log (trips)). 
        // int n = nums.size();// this is storing the size of the nums. 
        // for(int i = 0; i <n; i++){
        //     for(int j = i + 1; j < n; j++){// j can't be initlized at 0 as we need distintive digits. 
        //         for(int k = j + 1; k < n; k++){
        //             int sum = nums[i] + nums[j] + nums[k];

        //             vector<int> trip = {nums[i] + nums[j] + nums[k]};

        //             //Lets sort the vector so that we do not get repeated trips like {-1, 0, 1} and {1, 0, -1}
        //             sort(trip.begin(), trip.end());//THis will be constant only as we are moving sorting only three values.  
                    
        //             if(sum == 0){
        //                 if(s.find(trip) == s.end()){
        //                     s.insert(trip);
        //                     ans.push_back(trip);
        //                 }       
        //             }
        //         }
        //     }
        // }
        // return ans;
    }
};
