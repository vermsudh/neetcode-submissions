class Solution {
public:
    int maxArea(vector<int>& heights) {
        //how to calculate the width? 
        // the right pointer - left pointer. 
        
        //2 pointer approach.

        int left = 0; //index
        int right = heights.size() -1; // index
        int maxWater = 0; // ans

        while(left < right){
            int width = right - left;
            int height = min(heights[left],heights[right]);
            int currentWater = width * height;
            maxWater = max(maxWater, currentWater);

            if(heights[left] < heights[right]){
                left ++;
            }
            else{
                right--;
            }
        }
        // brute force
        // int maxWater = 0;
        // for(int i = 0; i< heights.size(); i++){
        //     for(int j = i +1; j < heights.size(); j++){
        //         int width = j - i;
        //         int height = min(heights[i], heights[j]);
        //         int currentWater = width * height;
        //         maxWater = max(maxWater, currentWater);
        //     }
        // }
        return maxWater;
    }
};
