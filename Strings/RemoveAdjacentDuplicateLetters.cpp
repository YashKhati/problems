
// Solution using Stack
//TC = O(N)
// SC = O(N)

class Solution {
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        for(auto itr : s)
        {
            if(st.empty())
            {
                st.push(itr);
                continue;
            }
            if(st.top()==itr)
            {
                st.pop();
            }
            else
            {
                st.push(itr);
            }
        }
        string ans;
        while(!st.empty())
        {
            ans +=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// Solution using Itterative approach
//TC = O(N)
// SC = O(1)

class Solution {
public:
  string removeDuplicates(string s) {
        int i = 0, n = s.length();
        for (int j = 0; j < n; ++j, ++i) {
            s[i] = s[j];
            if (i > 0 && s[i - 1] == s[i]) // count = 2
                i -= 2;
        }
        return s.substr(0, i);
    }
};
