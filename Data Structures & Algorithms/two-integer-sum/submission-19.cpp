class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //In this approach, we will use hashing to solve this question. 

        // First of all, lets write what we know. 
        //We need two elements where the sum == target and they should be unique. i != j 

        //Since we know two values. when we iterate with a help of a loop. We will get element i.
        //We know that nums[i] + nums[j] == target 
        //Now, we would just have to find the other value and check if it is present in the array or not. 
        //if it is, then we would have to return the indices of the values. 

        //We can store the nums[i] and index in a hashmap to check if the values are present in the map or not? 
        //nums [] == {2, 5, 5, 11} , target == 10

        //We would have to return [1, 2]. we have to return a vector.

        //lets travese over the array.
        
        //lets create a hashmap, where we are going to check if our second exist in the hashmaps or not. 
        //We have to store our nums[i] and the index. {nums[i], i}

        unordered_map<int, int> m;

        for(int i = 0; i < nums.size(); i++){
            int first_element = nums[i];

            //we know that first_element + second_element == target. 
            // second_element == target - first_element 

            int second_element = target - first_element;

            if(m.find(second_element) != m.end()){//We will check if our second element is present in the maps or not. 
            //if it is not, then we are going to simply store the first_element and its index in the maps. 
            //if we are able to find our second_element in the maps, then we are simply going to return the indices. 
                return { m[second_element], i};
            }
            m[first_element] = i;// This will store {2, 0}, {5, 1}, {5, 1}
        }

        return {};// if we are unable to find the ans, then we would have to return an empty vector. 
    }
};
