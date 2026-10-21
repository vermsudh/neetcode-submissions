class Solution {
public:
    //We need one function to compare the frequency of s1 and windows of s2. 
    bool isFreqSame(int freq1[], int freq2[]){
        for(int i = 0; i < 26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        //we have been give that the string is only lowercase : 'a' to 'z' freq[26] ={0}
        //Next we have to see if the s1 permutation lies in s2 anywhere or not. 
        //if exists -> return true; // notfound -> return false; 

        // The best approach in this case would be to use sliding window approach. 
        // In order to find the permutation of any string. We can note down its freq of each    characters which will let us find the reordered string in s2.  
        
        //Lets find the frequency of each characters in s1 first and also find its index value.
        //To find the index value : we would need to subtract the current i with 'a' which will get converted into ASCII value and give the us the index. 
// So it a is appearing twice : then a is at index of 0 and has a value of 2. 
        int freq[26] = {0};
        for(int i = 0; i < s1.length(); i++){
            int index = s1[i] - 'a';//this gets the index.
            freq[index]++;
        }

        //now, we have to traverse over the s2 and make windows to search if s1 exists. 
        for(int i = 0; i < s2.length(); i++){
//First we need to initlize what should be the window Size in which we have to compare. It should be s1 length as we need to search s1 in s2. 
            int windFreq[26] = {0};
            int windSize = s1.length();
            int windIndex = 0, idx = i; 
//Now we would have to use another loop to access the window. 
// Firstly, we need to make sure that windIndex should be 
// Secondly, the index which is i be less than s2.length to traverse over the string. 
            while(windIndex < windSize && idx < s2.length()){
                windFreq[s2[idx] - 'a']++;
                windIndex++; idx++;
            }

            if(isFreqSame(freq, windFreq)){
                return true;
            }
        }
        return false;
    }
};


