class Solution {
public:
    // void reveseArray(vector<int>& nums){
    //     int i = 0, j = nums.size() -1;
    //     while(i < j){
    //         swap(nums[i], nums[j]);
    //         i++;
    //         j--;
    //     }
    // }

    void nextPermutation(vector<int>& nums) {
        // nums = {1 , 2, 3, 6, 5, 4}
        //1) Find the pivot. It is a point from where the rest of the digits
        // are int descending order. 
        //Here we have 3 as the pivot. 
        int piv = -1, n = nums.size();
        for(int i = n - 2; i >=0; i--){//backwards loop
            if(nums[i] < nums[i + 1]){
                piv = i;
                break;
            }
        }
        //edge case : we might not have any pivot in the array. In that case we just 
        // have to return reversed array. 
        // For example : nums = {5,4,3,2,1}; No pivot it will become -1.
        if(piv == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        // 2) Now we need to swap the pivot with last digit to make it : 
        // nums = {1 , 2, 4, 6, 5, 3}
        for(int i = n - 1; i >= piv; i --){
            if(nums[piv] < nums[i]){
                swap(nums[piv], nums[i]);
                break;
            }
        }
        //3) Now we have successfully swapped the pivot with last digit. 
        // Now, we have to rever the rest of the numbers to get the final answer. 
        // which will be nums = {1 , 2, 4, 3, 5, 6}
        int i = piv + 1, j = n -1;
        while(i <= j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};