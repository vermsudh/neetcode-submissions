class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0; 
        int right = s.length() - 1;

        // To ignore the spaces, we can run a loop for left and right. 
        // inside our while loop. We can't just write it from one side as 
        // left will be running till it is not bigger than right. 

        while(left < right){

            while(left < s.length() && !isalnum(s[left])){
                left++;
            }
            while(right > 0 && !isalnum(s[right])){
                right--;
            }
            if(left >= right){
                return true;
            }

            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
};
