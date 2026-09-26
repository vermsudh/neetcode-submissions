class Solution {
public:
    // arr = {2,1,3,4}
    bool checkMid(vector<int>& nums, int n, int mid){
        int pages = 0, student = 1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > mid){
                return false;
            }
            if(pages + nums[i] <= mid){
                pages+=nums[i];
            }else{
                student++;
                pages = nums[i];
            }
        }
        if(student <= n){
            return true;
        }else{
            return false;
        }


    }

    int splitArray(vector<int>& nums, int n) {
        int start = 0, sum = 0, ans = -1;

        for(int i = 0; i < nums.size(); i++){sum += nums[i];}
        int end = sum;
        
        while(start <= end){

            int mid = start + (end - start)/2;

            if(checkMid(nums, n, mid) == true){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};