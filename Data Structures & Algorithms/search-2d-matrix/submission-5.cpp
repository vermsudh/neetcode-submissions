class Solution {
public:
    //approach 2
    //find the right row where target can exists, then search in that row if target exists or not.

    bool searchRow(vector<vector<int>> mat, int target, int row){
        
        int n = mat[0].size();
        int start = 0, end = n -1;

        while(start <= end){
            int mid = start + (end - start)/ 2;

            if(target == mat[row][mid]){
                return true;
            }else if(target > mat[row][mid]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return false;
    }


    bool searchMatrix(vector<vector<int>> mat, int target){
        //lets try to solve this by ourself. 
        //first we need to find the right row. 
        //We are going to find that by doing Binary search only. 
        //lets assusme that our taget is 20. //Looking into Example 1.
        //we know that 20 exists on 3 row. 

        //Lets do binary search over the rows. 

        //We know that row in the matrix = mat.size(); and col = mat[0].size();
        //row : basically the mat.size();
        //vector<vector<int>> mat = {{}, {}, {}} = > 3
        //cols: would the elements of rows. 
        //Lets say we want to find how many elements exists in one row? mat[0].size(); Any row will 
        //give us the size of cols. 
        int m = mat.size(), n = mat[0].size();

        int startRow = 0, endRow = m - 1;
        while(startRow <= endRow){
            int midRow = startRow + (endRow - startRow)/2;

            if(target >= mat[midRow][0] && target <= mat[midRow][n-1]){
                //In this case, we have find the row, then we will do one BS to search through 
                //this row. 
                return searchRow(mat, target, midRow);
            }else if(target > mat[midRow][n-1]){
                //down -> right
                startRow = midRow + 1;
                //up - > left
            }else{
                endRow = midRow - 1; 
            }
        }
        return false;
    }
};
