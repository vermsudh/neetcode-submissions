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
        int freq[26] = {0};
        for(int i = 0; i < s1.length();i++){
            freq[s1[i] - 'a']++;
        }
        
        
        for(int i=0; i < s2.length(); i++){
            int windFreq[26] = {0};
            int windSize = s1.length();
            int windIdx = 0, idx = i;

            while(windIdx < windSize && idx < s2.length()){
                windFreq[s2[idx] - 'a']++;
                idx++; windIdx++;
            }
            if(isFreqSame(freq, windFreq)){
                return true;
            }
        }
        return false;
    }
};
