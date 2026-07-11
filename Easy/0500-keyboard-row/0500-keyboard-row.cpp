class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        unordered_map<char,int> mpp;

        string s1 = "qwertyuiop", s2 = "asdfghjkl", s3 = "asdfghjkl";

        for(char &ch : s1) mpp[tolower(ch)] = 1;
        for(char &ch : s2) mpp[tolower(ch)] = 2;
        for(char &ch : s3) mpp[tolower(ch)] = 3;

        for(string &s:words) {
            int row = mpp[tolower(s[0])];
            bool flag = true;

            for(char &ch : s) {
                if(mpp[tolower(ch)] != row){
                    flag = false;
                    break;
                }
            }
            if(flag) result.push_back(s);
        }

        return result;       
    }
};