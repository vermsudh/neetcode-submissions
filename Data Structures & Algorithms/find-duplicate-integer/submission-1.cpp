class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //1)Brute force approach of this question to traverse over the matrix twice with O(n^2)TC. 
        //2) Use a hashset with TC: O(n) and SC : O(n). 

        // unordered_set<int> s;

        // for(int i = 0; i < nums.size(); i++){
        //     if(s.find(nums[i]) != s.end()){
        //         return nums[i];
        //     }
        //     s.insert(nums[i]);
        // }

        //3) Solve this using slow fast pointer apprach with constant SC and TC : O(n)
        
        int slow = nums[0], fast = nums[0]; 

        do{
            slow = nums[slow];//THis is moving +1
            fast = nums[nums[fast]];  // This is moving + 2

        }while(slow != fast);

        slow = nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
