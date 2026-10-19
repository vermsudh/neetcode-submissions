class Solution {
public:

    bool alphaNumeric(char ch){
        if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        //first lets, just detect which character is alphanumeric or which are not. Created a function. 
        //alphaNumeric will find us the valid characters and also keep the spaces in mind. 

        // Now, we need 2 pointers in order to traverse over the string with O(n) TC. 
        int left = 0, right = s.length() - 1;
        while(left < right){
            if(!alphaNumeric(s[left])){
                left++;
                continue;
            }
            if(!alphaNumeric(s[right])){
                right--;
                continue;
            }//this will skip the characters which are not alphanumerics.
            //All is left is to compare. Since we have to compare the lowercase, we will convert everything to lowercase. 

            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
