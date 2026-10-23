class Solution {
public:
    int countPrimes(int n) {
        //lets assume of the numbers from 2 to n are prime numbers. 
         vector<bool> isPrime (n+1, true);// this vector has all the values stored as true.
        int count = 0; //since we have to return the count. 
        for(int i = 2; i < n; i++){
            //now we need to assume every number is prime numbers. 
            if(isPrime[i]){// we have put a condition to count the prime numbers. 
                count++;
            }
            //so far all the numbers are prime numbers but we need to check which are not.
            //For that, we are going to find the multiples of each numbers and check if they are 
            //prime numbers or not. 
            //for getting the prime numbers : we know if we need to find the multiple of any number: we would need to multiply it with 2. 
            for(int j = i * 2; j < n; j +=i ){
                isPrime[j] = false;
            }
        }
        return count;
    }
};