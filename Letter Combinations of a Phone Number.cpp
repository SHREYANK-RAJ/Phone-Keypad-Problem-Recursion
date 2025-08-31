class Solution {
public:
    void backtrack(int pos, string &current, const string &digits, 
                   const vector<string> &phoneMap, vector<string> &result) {
        // Base condition: if we used all digits
        if (pos == digits.size()) {
            result.push_back(current);
            return;
        }

        // Convert current digit to index (e.g., '2' → 2)
        int digitIndex = digits[pos] - '0';
        const string &letters = phoneMap[digitIndex];

        // Explore all possible letters for this digit
        for (char ch : letters) {
            current.push_back(ch);            // choose
            backtrack(pos + 1, current, digits, phoneMap, result); // explore
            current.pop_back();               // un-choose
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // Edge case: no digits → no combinations

        vector<string> phoneMap = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string current = "";
        backtrack(0, current, digits, phoneMap, result);
        return result;
    }
};
