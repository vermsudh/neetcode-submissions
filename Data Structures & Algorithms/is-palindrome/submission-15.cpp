class Solution {
public:

    //1)lowercase in order to see the changes. 
    //2) we need to inlcude only alphanumeric characters which are (A-Z, a-z) and 0-9
    //3) once we have filter out all everything, 
    //Brute force approach on this question would be to use nested loop. 
    // that can run from forward and the inner loop can run from backward. 
    // TC: O(n ^ 2) if we use nested loop. 
    //Now, in order to optamize the code, we can use 2 pointers to bring the TC: O(n)

    bool isAlphaNum(char ch){
        if((ch >= '0' && ch <= '9') || towlower(ch) >= 'a'&& tolower(ch) <='z'){
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while(left < right){
            if(!isAlphaNum(s[left])){
                left++;
                continue;
            }
            if(!isAlphaNum(s[right])){
                right--;
                continue;
            }
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
