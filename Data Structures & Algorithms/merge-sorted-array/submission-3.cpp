class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //this is one of the pattern that we have non-decreasing orders in 2 vecs

        int ind = m + n -1;
        int i = m - 1; //40 
        int j = n - 1; //2

        // there is one pattern that we can see is that the last
        //digits of nums1 and nums2 will be the largest in its vecs.

        while(i >= 0 && j >= 0){
            //first value of i would be 3 and j would be 1
            if(nums1[i] >= nums2[j]){
                nums1[ind] = nums1[i];
                ind--;
                i--;
            }else{
                nums1[ind] = nums2[j];
                ind--;
                j--;
            }
        }
        while(j >= 0){
            
        nums1[ind] = nums2[j];
        ind--;
        j--;
    
        }
    }
};