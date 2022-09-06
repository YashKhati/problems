#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;
int LongestSubString(string text)
{
    unordered_map<char, int> mp;
    int r = 0, l = 0, len = 0;
    while (r < text.size())
    {
        if (mp.find(text[r]) != mp.end())
        {
            l = max(mp[text[r]] + 1, l);
        }
        mp[text[r]] = r;
        len = max(len, r - l + 1);
        r++;
    }
    return len;
}
int main()
{
    string text;
    cout << "Enter text : ";
    getline(cin, text);
    int sz = 0;
    sz = LongestSubString(text);
    cout << "length of longest substring : " << sz;
}
