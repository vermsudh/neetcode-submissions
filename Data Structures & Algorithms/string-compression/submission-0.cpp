class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;
        //travers over the vector of strings.
        for(int i = 0; i < n; i++){
            char ch = chars[i];
            int count = 0;

            while(i < n && chars[i] == ch){
                count++; i++;
            }//this will count the repeated characters. 
//Now, we need to put a condition. If count = 1, retrun the ch. Otherewise need to conver the count into the string. 
            if(count == 1){
                chars[idx] = ch;
                idx++;
            }
            else{
//if count is greater than 1, in that case we have to conver the count into string. 
//For example : we have count = 12,then conver this into string using to_string() function "1", "2"
                chars[idx] = ch;
                idx++;
                string str = to_string(count);
                for(char digit : str){
                    chars[idx] = digit;
                    idx++;
                }
            }
         i--;//This is quite important to place the char and numeric values at their right place.   
        }
    chars.resize(idx);
    return idx;   
    }
};