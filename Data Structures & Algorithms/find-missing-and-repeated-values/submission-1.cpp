class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    //We have to find two values in this grid. 
    //One if the repeated value which is 9 in example 2. 
    //For that we can run a nested loop and find the repeated value using a hashset as sets have a unique property of not repeating any number, if we find any number which is repeating, we would be able to find it using hasset in constant time.    
        int n = grid.size();
        int repeatedNum, missingNum; 
        int expectedSum = 0, actualSum = 0;

        unordered_set<int> s;
        //Since we have to return a vector
        vector<int> ans;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                actualSum += grid[i][j];
                if(s.find(grid[i][j]) != s.end()){
                    repeatedNum = grid[i][j];
                    ans.push_back(repeatedNum);
                }
                s.insert(grid[i][j]);
            }
        }

        //now we have to return the missing value which is 5 in this case. 
        //For this we would need to solve this part using arithmetic progression. 

        //We know that one number is repeating which is 9. 
        //In order to find the sum from 1 to 9 would be sum += grid[i][j]. 
        //We can take this as actualSum

        //We know that expexted Sum of any number from 1 to n would be (n^2)*(n^2 + 1)/2
        
        //Now, The formula for deriving the missing number would be = expectedSum + repeatedNum - actualSum
        
        expectedSum = (n * n) * (n * n + 1)/2;
        missingNum = expectedSum + repeatedNum - actualSum;
        ans.push_back(missingNum);
        
        return ans;
    }
};