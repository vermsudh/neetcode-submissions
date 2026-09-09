class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        //edge case, if we have only one element. 
        if(n == 1){
            return nums[0];
        }
        int start = 0, end = n - 1;
        
        while(start <= end){
            int mid = start + (end - start)/2;

            // edge case
            if(mid == 0 && nums[0] != nums[1]){return nums[mid];}
            if(mid == n - 1 && nums[n-1] != nums[n-1]){return nums[mid];}

            if(nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]){
                return nums[mid];
            }
            if(mid % 2 == 0){// even elements on both sides
                if(nums[mid - 1] == nums[mid]){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }else{
                if(nums[mid] != nums[mid + 1]){
                    start = mid + 1;
                }
                else{
                    end = mid -1;
                }
            }
        }
        return -1;
    }
};