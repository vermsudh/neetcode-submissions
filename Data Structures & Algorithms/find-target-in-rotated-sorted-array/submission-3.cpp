class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() -1;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target){
                return mid;
            }

            // To check if left side of the array is sorted from mid point.
            if(nums[start] <= nums[mid]){// this will check if mid is greater than     first value, then this is sorted otherwise the right is sorted

                if(nums[start] <= target && target <= nums[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }

            }
            else{// right
                if(nums[mid] <= target && target <= nums[end]){
                    start = mid + 1;
                }else{
                    end = end - 1;
                }
            }
        }
        return -1;
    }
};
