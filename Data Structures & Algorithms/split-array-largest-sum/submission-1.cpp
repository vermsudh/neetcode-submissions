class Solution {
public:

    bool checkMid(vector<int>& nums, int k, int mid){
        int student = 1, pages = 0;
        
        for(int i = 0; i < nums.size(); i++ ){
            if(nums[i] > mid){
                return false;
            }
            if(pages + nums[i] <= mid){
                pages += nums[i];
            }
            else{
                student++;
                pages = nums[i];
            }
        }
        if(student <= k){
            return true;
        }else{
            return false;
        }
    }

    //arr = [1, 4, 2], k = 1
    int splitArray(vector<int>& nums, int k) {
        int start = 0, sum = 0, ans = -1;

        for(int i = 0; i < nums.size(); i++){sum += nums[i];}
        int end = sum;

        while(start <= end){

            int mid = start + (end - start)/2;

            if(checkMid(nums, k, mid) == true){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};