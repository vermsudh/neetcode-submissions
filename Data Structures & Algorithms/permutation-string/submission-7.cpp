class Solution {
public:

    //We need another function to return true if freq matches the windFreq
    bool isFreqSame(int freq1[], int freq2[]){
        for(int i = 0; i < 26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        // a permutation is basically a rearraging of the words. 
        //we need to check if s1 characters permutation exists in s2 -> true, if not -> false

        //We have been given that the characters in s1 and s2 are in lowercase characters only which is between 'a' to 'z'.
        
        //In this case, we can solve this question by sliding window. We cna make windows in s2 of length s1 to check. 
        // 1st) We are going to place abc into an array with its value. So, we know that we will have only 26 characters. We are going to make array of 26 size where each chracter will have its index value
        // starting from 0 to 25. We will initlize the value of those arrays as 0 at first. If we traverse over s1, and find 'a', then we will incremnet its count to 1. This will give us the frequency of each character in the array. At last we are just going to compare the freq of s1 array and freq of windows in s2 to check if permutation exist or not. 
        // 2nd) window = 'lec' 

        int freq[26] = {0};
        
        for(int i = 0; i < s1.length(); i++){
            //In order to calculate the index value of any character. We know that 'a' should be stored at 0 index, b should be on 1.
            //Therefore, if we subtract ASCII values of any character with 'a' which is 97, that should give us the index. 
            int index = s1[i] - 'a';
            freq[index]++;
        }

        //Now, we need window Frequency on S2. 
        
        //We would need an index that will help us to store the value of characters in the freq array. 
        
        for(int i = 0; i < s2.length(); i++){    
            int windFreq[26] = {0};        
            int windSize = s1.length();
            int windIdx = 0, idx = i;
            while(windIdx < windSize &&  idx < s2.length()){
                windFreq[s2[idx] - 'a']++;
                windIdx++; idx++;
            }
            if(isFreqSame(freq, windFreq)){
                return true;
            }
        
        }
        return false;
    }
};
