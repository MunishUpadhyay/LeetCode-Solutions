class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> lastLower;
        unordered_map<char, int> firstUpper;

        for(int i = 0; i < word.length(); i++) {
            if(islower(word[i])) {
                lastLower[word[i]] = i;
            }
            else if(isupper(word[i]) && firstUpper.find(word[i]) == firstUpper.end()) {
                firstUpper[word[i]] = i;
            }
        }

        int count = 0;

        for(auto it : lastLower) {
            char ch = it.first;

            if(firstUpper.find(toupper(ch)) != firstUpper.end() &&
               it.second < firstUpper[toupper(ch)]) {
                count++;
            }
        }

        return count;
    }
};