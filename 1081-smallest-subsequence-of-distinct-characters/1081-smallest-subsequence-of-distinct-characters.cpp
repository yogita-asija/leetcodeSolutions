class Solution {
public:
    string smallestSubsequence(string s) {
        
        vector<int> freq(26,0);

        for (char c:s){
            freq[c - 'a'] ++;
        }
        vector<bool> used(26,0);

        string st;

        for (char c:s){
            freq[c - 'a']--;

            if(used[c-'a'])
            continue;

            while(!st.empty() && st.back() >c && freq[st.back() - 'a'] > 0){
                used[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(c);
            used[c - 'a'] = true;
        }
        return st;
    }
};