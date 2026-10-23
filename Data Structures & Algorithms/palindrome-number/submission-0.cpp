class Solution {
public:
    int reverseNumber(int n){
        //First we will revese the number. 

        int revNum = 0;
        
        //lets say we have n = 1223221. 
        // in order to reverse this, we will get the last digit. and multiply it with 10 and add the digit to get the revNum and we will keep on doing this until we have no numbers left. 


        while(n != 0){  
            int digit = n % 10;
            //edge case : if n gets out of range of int, then we need to return 0

            if(revNum > INT_MAX / 10 || revNum < INT_MIN /10){return 0;}

            revNum = revNum * 10 + digit;

            //take out the last digit from the num
            n = n / 10;
            
        }
        return revNum;
    }

    bool isPalindrome(int n) {
        //to check if the number is palindrome or not, we will simply compare the revese number
        //with the original n. If they match, we return true, otherwise false.

        //edge case : we know that -ve number is not palindromic. 
        if(n < 0){
            return false;
        }    

        int revNum = reverseNumber(n);

        return n == revNum;
    }
};