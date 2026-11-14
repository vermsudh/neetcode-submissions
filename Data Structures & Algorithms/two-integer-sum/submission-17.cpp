class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //Most optamzied approach would be to use hashing. 

        //We can use hashmaps which can solve this question in O(n) TC. 
        //We would have to use unordered_map.

        unordered_map<int, int> m;
        vector<int>ans;//we will store the ans here. 

        for(int i = 0; i < nums.size(); i++){
            //In this case, we know two things. The targets and the values of nums. 
            //We know that we will find automatically that one element in the array where the sum will be equal to target. 
            //.  i + j == target. //lets say we know about i and we laready know target, then we can find j == target - i.
            int first_element = nums[i];
            int second_element = target - first_element;
            //We would need to store the sum 

            if(m.find(second_element) != m.end()){
                return {m[second_element], i};
            }
            
            m[first_element] = i;
            
        }   

        return {};

        //More Optimal approach would be to use 2 pointers. THis will give us TC as n log n + O (n) which will be better than O (n ^ 2)

        //For this we would have to sort the nums first so that we have starting element the smallest and last element as the larget. 
        //We would need to preserve the original nums as after sorting, the indices will change.
        // sort(nums.begin(), nums.end());

        // int n = nums.size();
        // int start = 0, end = n - 1;
        // vector<int> ans;

        // while(start < end){
        //     int sum = nums[start] + nums[end];

        //     if(sum < target){
        //         start++;
        //     }
        //     else if(sum > target){
        //         end--;
        //     }
        //     else{
        //         ans.push_back(start);
        //         ans.push_back(end);
        //         start++;
        //         end--;
        //     }
        // }

        // return ans;


        // //We have to return the indices which is basically the index of the array elements where the sum is equal to the target.

        // //Brute force approach would be to use the nested loop to access two values. 
        // //Since we have to return a vector.
        // vector<int> ans;// We will store the ans in the vector. 
        // //Also we need to make sure that our i != j

        // //Therefore we cant retrun 5 , 5 in this case : [4,5,6], target = 10 [1, 1]
        // int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     //Now we need a second loop to have j element. 
        //     for(int j = i + 1; j < n; j++){
        //         //now we need to check if the sum of these elements are equal to target or not. 
        //         if(nums[i] + nums[j] == target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }

        // return ans;//return the vector. 
    }
};
