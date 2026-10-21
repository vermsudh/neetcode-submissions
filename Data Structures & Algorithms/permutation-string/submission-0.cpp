class Solution {
public:

    bool isFreqSame(int freq1[], int freq2[]){
        for(int i = 0; i < 26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true; 
    }

    bool checkInclusion(string s1, string s2) {
// Firstly, we need to check what characters we have in s1. 
//The num of characters and the fequency of the characters will be same. 
// First thing first, store the characters of s1. Since we have lowercase, range : 'a' to 'z' : arr[26].
// But if we had more characters like special characters, lowercase and numbers. In that case, we would use unordered_map. map<char, int>

        int freq[26] = {0};

        for(int i = 0; i < s1.length(); i++){// this will help to calculate the index. 
            int idx = s1[i] - 'a';
            freq[idx]++;
        }// we have stored the frequency of s1 which is s1 ="ab". freq of a -> 1, freq of b -> 1 

        //2) Search the S1 permutation in S2 using window based approach

        int windSize = s1.length();

        for(int i = 0; i < s2.length(); i++){
            int windIdx = 0, idx = i;
            int windFreq[26] = {0};

            while(windIdx < windSize && idx < s2.length()){
                windFreq[s2[idx] - 'a']++;
                windIdx++; idx++;
            }// This will track one window frequency on s2.

            if(isFreqSame(freq, windFreq)){// check if the freq of s1 is same as the window freq of s2? 
                return true;
            }
        }
        return false;
    }
};
