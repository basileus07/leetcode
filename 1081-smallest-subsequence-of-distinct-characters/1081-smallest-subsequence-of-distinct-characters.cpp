class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0); 
        vector<bool> inStack(
            26, false);
        stack<char> st;

        for (char ch : s)
            freq[ch - 'a']++;

        for (char ch : s) {
            freq[ch - 'a']--;

            if (inStack[ch - 'a'])
                continue;

            while (!st.empty() && ch < st.top() && freq[st.top() - 'a'] > 0) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            inStack[ch - 'a'] = true;
        }

        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};