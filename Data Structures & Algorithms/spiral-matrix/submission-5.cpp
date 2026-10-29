class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        //We will try to print the boundaries and move inwards. 
        //We have to make sure that we do not repeat any number again. 
        
        //First of all we would need to find out the number of cols and rows of the matrix. 

        int m = mat.size();//this will give us the number of rows. 
        int n = mat[0].size();// this will give us the number of cols. 

        //Since we have to return the ans in the vector. 
        vector<int> ans; //we are going to store all the answers in this vector. 

        //Now we have to find the corners to to be able to traverse and find out the 
        //starting point and ending points of the matrix. 
        int srow = 0, scol = 0, erow = m -1, ecol = n - 1;

        //Now we need one more loop to keep on iterating over the matrix and move inwards. 
        while(srow <= erow && scol <= ecol){
            //First I will write the for loops to print all the boundaries. 

            //Top Cols
            for(int i = scol; i <= ecol; i++ ){
                ans.push_back(mat[srow][i]);
            }
            //Right (Rows)
            for(int j = srow + 1; j <= erow; j++)//do not repeat the element, since we have already printed the col element, we have to make sure that we start out row from index 1. 
            {
                ans.push_back(mat[j][ecol]);
            }
            //Bottom Cols // run a backwards loop from 8 to 9. Since we have already printed 9 in the right loop. We have to skip this. 
            for(int i = ecol - 1; i >= scol; i--){
                //Now, we would have to take take care of one of edge case where we have to not print the values again when we have odd number of cols and rows. 
                //We have a matrix of 3 row and 5 cols. We will have 3 elements to print. Where the srow==eroww and ecol == scol.
                //We have to make sure that we do not print those values again. In that case, we would like to break from the loop. 
                //We can put a if condition to check if they are equal, then break from the loop. 
                if(srow == erow){
                    break;
                }
                ans.push_back(mat[erow][i]);
            }
            //Left (Rows)//Now we have to make sure that we do not print 1 and 7 again, so we have to increate the srow + 1 and erow - 1
            for(int j = erow - 1; j >= srow + 1; j--){
                if(scol == ecol){
                    break;
                }
                ans.push_back(mat[j][scol]);
            }
            srow++; scol++;
            erow--; ecol--;
        }        
        return ans;// at last we are going to return the vectors with the printing values. 
    }
    
};
