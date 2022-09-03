#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
vector<int> NextLargestNumber(vector<int> nums1, vector<int> nums2)
{
    stack<int> st;
    unordered_map<int, int> mp;
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() < nums2[i])
        {
            st.pop();
        }
        int ans = st.empty() ? -1 : st.top();
        mp.insert({nums2[i], ans});
        st.push(nums2[i]);
    }
    vector<int> re;
    for (auto it : nums1)
    {
        re.push_back(mp[it]);
    }
    return re;
}
int main()
{
    vector<int> nums1{4, 1, 2};
    vector<int> nums2{1, 3, 4, 2};
    vector<int> ans;
    ans = NextLargestNumber(nums1, nums2);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}
