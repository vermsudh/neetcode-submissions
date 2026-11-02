class Solution {
public:

    bool isFreqSame(int freq1[], int freq2[]){
        //Since we have lowercase only, we will run a loop from 0 to 26. 
        for(int i = 0; i < 26; i++){
            if(freq1[i] != freq2[i]){
                return false;
                break;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        //We have been given that both the strings has lowercase characters which means.
        //we will have characters from 'a' to 'z' which is from 97. 

        //One way to solve this question would be using a sliding window. 

        //We can store the characters of s1 in the array and the characters of the window which is equal to the length of s2. We can store the frequency of the chacters. For starters, We can store freq in the array. We can get the index of 26 characters by subtracting any character with 'a' which has a ASCII value of 97. 

        int freq[26] = {0};
        for(int i = 0; i < s1.length(); i++){
            int index = s1[i] - 'a';
            freq[index]++;
        }
        
        //Now we have stored the frequency and the index value of s1, now we would have to split the s2 into windows which should be equal to the length of s1. 

        for(int i; i < s2.length(); i++){

            int windFreq[26] = {0};
            int windSize = s1.length();
            int windIdx = 0, idx = i;
            while(windIdx < windSize && idx < s2.length()){
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
