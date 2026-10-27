class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;

        // Scan from right to left so words are collected in reverse order.
        for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                // Characters are collected backward, so reverse this word later.
                word += s[i];
            } else if (!word.empty()) {
                // A space ends a word. Empty words are ignored, so extra spaces are skipped.
                reverse(word.begin(), word.end());
                words.push_back(word);
                word.clear();
            }
        }

        // Add the first word: the scan may end before finding a space before it.
        if (!word.empty()) {
            reverse(word.begin(), word.end());
            words.push_back(word);
        }

        string result;

        // Join words with one space, without adding spaces at the beginning or end.
        for (const string& w : words) {
            if (!result.empty()) result += ' ';
            result += w;
        }

        return result;
    }
};