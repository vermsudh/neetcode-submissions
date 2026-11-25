class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        //Optmaized solution would be to use 2 pointers approach which can solve this question using only one loop. 

        int i = 0, j = heights.size() - 1;
        int maxArea = 0;

        while(i < j){
            int ht = min(heights[i], heights[j]);
            int width = j - i;
            int currentArea = ht * width;

            if(heights[i] < heights[j]){
                i++;
            }else{
                j--;
            }

            maxArea = max(currentArea, maxArea);
            
        }
        return maxArea;

        //We can solve this question with brute force approach where we can grab the two elements using two nested loop. 

        //We have height vector

        //We need to return the max area that can be covered. From the picture, we know what the max area coveres by the vector
        //would be 7 and 6 values located at 1 and 6. 

        // We would need to calculate the area for that, we know that the hight would be the element. 
        // and width would be the indices from 0 to 6 from the example. 
        // int n = heights.size();
        //Brute force aproach with the time complexity O(n ^ 2) 
        //This will give us TLE. 

        // int maxArea = 0;
        
        // for(int i = 0; i < n; i++){
        //     // We will have the width from 0 to 6. 
        //     //In order to calculate the area
        //     for(int j = i + 1; j < n; j++){
        //         int ht = min(heights[i], heights[j]);
        //         int width = j - i;
        //         int currentArea = width * ht;

        //         maxArea = max(currentArea, maxArea);
        //     }
        // }
        // return maxArea;
    }
};
