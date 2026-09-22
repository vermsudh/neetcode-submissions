class Solution {
public:
    void reverseString(vector<char>& s) {
        //brute force 

        vector<char> reverseString; 

        for(int i = s.size() - 1; i >= 0; i-- ){
            reverseString.push_back(s[i]);
        }
        s = reverseString;
    }
};