class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()){
            return 0;
        }
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;

        for(char ch1 : s){
            s_map[ch1]++;
        }
        for(char ch2 : t){
            t_map[ch2]++;
        }

        if(s_map == t_map){
            return true;
        }
        else{
            return false;
        }

    }
};
