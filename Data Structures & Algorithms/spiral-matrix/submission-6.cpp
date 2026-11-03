class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        //We have to provide a vector in return with a print of the matrix movinbg in a sprial foramt. 
        //For that, We would need a loop to print the elements of the matrices. 

        //We can break down this problem into some parts. 
        //We can try to print the boundaries of the first layer and then move inwards. 

        //Let me write the loops to print the boundaries. 

        //For this we have to map the first and the last element of the matrix. 

        //we know that that row of the matrix is and the col is 
        int row = mat.size(), col = mat[0].size();
        //We will have the starting row and col as srow and scol = 0; and ending row as r - 1 and c - 1;
        int srow = 0, scol = 0, erow = row - 1, ecol = col - 1;
        vector<int> ans;

        //now we have to repeat these steps until we are done printing all of them. We have to make sure that we move the inside the spiral matrix once we are done printing the 
        // boundaries. 

        //For example, we have to print 5 now. 
        //We know that we would have to increment srow and scol and decrement the erow and ecol. 

        while(srow <= erow && scol <= ecol){//We have to run this loop until srow == erow and scol == ecol to print all the possible values. 

            //We will print 4 boundaries which is top, right, bottom, left. 
            //top which is a col. 
            for(int i = scol; i <= ecol; i++){
                ans.push_back(mat[srow][i]);// this will print 1, 2, 3
            }
            //right.   Now we print the right side. 
            for(int j = srow + 1; j <= erow; j++){// we have icremented srow with 1 as we have already printed the last digit in col which is first element in the row on the right side. 
                ans.push_back(mat[j][ecol]);// since this is the last col, we are printing the lastcol and all the elements of this row which is 6 and 9
            }
            //bottom
            //Since we have to print 8, 7. We are running backwards which means we are have to move the for loop backwards. 
            for(int i = ecol - 1; i >= scol; i--){
                //There will be corner cases that we have to keep in mind for. 
                // We have to make sure that we do not print boundaries again. 
                //Lets say we have a matrix of 3 X 5. 
                //mat ={{1, 2, 3, 4, 5 }
                //      {6, 7, 8, 9, 10},
                //      {11,12,13,14,15}}// 
                //We will print {1, 2, 3, 4, 5, 10, 15, 14, 13, 12, 11, 6, 7, 8, 8}
                //If you notice that our 

                if(srow == erow){
                    break;
                }
                ans.push_back(mat[erow][i]);

            } 
            //Now we have to print the left side which is 4 as we have already printed 1 and 7, we have to make sure that we do not repeat anything. 
            //left
            for(int j = erow - 1; j >= srow + 1; j--){
                
                if(scol == ecol){
                    break;
                }
                ans.push_back(mat[j][scol]);
            }

            srow++; erow--;
            scol++; ecol--;
        }

        return ans;//this will have all the possible values. 
    }
};
