class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        int missingNum, repeatingNum;
        int actualSum = 0, expectedSum = 0;
        unordered_set<int> s;
        int n = grid.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                actualSum += grid[i][j];

                if(s.find(grid[i][j]) != s.end()){

                    repeatingNum = grid[i][j];

                    ans.push_back(repeatingNum);
                }
                s.insert(grid[i][j]);
            }
        }
        //We have found the repeating number using sets, now in order to the find out the missing number, we would have to do follow this formula. 

        expectedSum = (n * n) * (n * n + 1) / 2;
        missingNum = expectedSum + repeatingNum - actualSum;

        ans.push_back(missingNum);

        return ans;
    }
};