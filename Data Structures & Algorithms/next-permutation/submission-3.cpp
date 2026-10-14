class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // arr ={1,2,3} {1,3,2} {2,1,3} {2,3,1} {3,1,2} 3{3,2,1}
        
        // next lexicographically arr would be arr = {1, 3, 2}
        // We need to return this. 
        //{1 , 2, 3, 5, 4} => {1, 2, 4, 3 , 5, 6} =>

        //1)approach would be to find the pivot. 

        int piv = -1, n = nums.size();
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                piv = i;
                break;
            }
        }   
        //edge case would be if there is no pivot. In that case, we just have to
        //reverse the array. 

        if(piv == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        //2) Next Step would be to swap the piv with the last digit.  
        for(int i = n -1; i >=piv ; i--){
            if(nums[piv] < nums[i]){
                swap(nums[piv], nums[i]);
                break;
            }
        }
        //3) reverse the rest of the array from pivot to last digit. 
        int i = piv + 1, j = n -1;
        while(i <=j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
         
    }
};