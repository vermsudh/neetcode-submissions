class Solution {
public:
    int maxArea(vector<int>& heights) {

        //2pointer approach
        int n = heights.size();
        int right = n-1;
        int left = 0;
        int maxWater = 0;

        while(left < right){
            int width = right - left;
            int height = min(heights[left], heights[right]);
            int currentWater = width * height;

            maxWater = max(currentWater, maxWater);

            if(heights[left] > heights[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return maxWater;

        // //Brute force
        // int n = heights.size();
        // int maxWater = 0;
        // for(int i = 0; i < n; i++){
        //     for(int j = 1; j < n; j++){
        //         int width = j-i;
        //         int height = min(heights[j], heights[i]);
        //         int currentWater = width * height;

        //         maxWater = max(currentWater, maxWater); 
        //     }
        // }
        // return maxWater;
    }
};
