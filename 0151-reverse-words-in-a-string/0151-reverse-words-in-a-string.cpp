class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;

        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (!word.empty()) {
                reverse(word.begin(), word.end());
                words.push_back(word);
                word.clear();
            }
        }

        if (!word.empty()) {
            reverse(word.begin(), word.end());
            words.push_back(word);
        }

        string result;
        for (const string& w : words) {
            if (!result.empty()) result += ' ';
            result += w;
        }

        return result;
    }
};