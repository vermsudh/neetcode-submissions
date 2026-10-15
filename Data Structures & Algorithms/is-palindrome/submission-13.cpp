class Solution {
public:

    //1) we need to identify which char are not alphanumeric. 
    // range of alphanumeric : (A-Z, a-z) and (0-9)
    //since it is given in the question that we have to conver the string to
    //lowercase in order to get the final palindromic string. 
    // Therefore, we do not have to mention the range of uppercase. 
    // We can just simply use tolower() function to check the range. 
    
    bool isAlpNum(char ch){
        if((ch >= '0'&& ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
            return true;
        }
        return false;
    }
    //2) Now we know how to check if any char is aplha numeric or not? 
    // Now we would have to skip those char which are not aplphanumeric or not. 
    
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        // this step will skip those characters which are not aplhanumeric. 
        while(left < right){
            if(!isAlpNum(s[left])){
                left++; continue;
            }
            if(!isAlpNum(s[right])){
                right--; continue;
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
