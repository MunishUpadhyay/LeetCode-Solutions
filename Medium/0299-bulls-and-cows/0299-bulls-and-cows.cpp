class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();

        string result = "";
        int val1 = 0;
        for(int i = 0; i < n; i++) {
            if(secret[i] == guess[i]) {
                val1++;
            } 
        }

        result += to_string(val1);
        result += 'A';

        unordered_map<char, int> mpp1;
        for(char c : secret) {
            mpp1[c]++;
        }

        unordered_map<char, int> mpp2;
        for(char c : guess) {
            mpp2[c]++;
        }

        int val2 = 0;
        for(auto &it : mpp1) {
            if(mpp2.count(it.first))
                val2 += min(it.second, mpp2[it.first]);
        }

        val2 -= val1;
        result += to_string(val2);
        result += 'B';

        return result;
    }
};