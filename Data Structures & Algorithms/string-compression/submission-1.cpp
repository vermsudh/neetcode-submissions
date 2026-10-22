class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0; 

        for(int i = 0; i < n; i++){
            char ch = chars[i];
            int count = 0;

            while(i < n && chars[i] == ch){
                count++; i++;
            }

            if(count == 1){
                chars[idx++] = ch;
            }else{
                //We have to convert the digits into the strings and put them into the vec.
                //We are going to use a function called to_string. 
                chars[idx++] = ch;
                
                string str = to_string(count);
                for(char digit : str){
                    chars[idx] = digit;
                    idx++;
                }
            }
            i--;
        }
        chars.resize(idx);
        return idx;
    }
};