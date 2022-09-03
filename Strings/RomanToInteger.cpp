#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int romanToInteger(string str)
{
    unordered_map<char, int> ump;
    int sum = 0;
    ump['I'] = 1;
    ump['V'] = 5;
    ump['X'] = 10;
    ump['L'] = 50;
    ump['C'] = 100;
    ump['D'] = 500;
    ump['M'] = 1000;
    for (int i = 0; i < str.size(); i++)
    {
        if (ump[str[i]] < ump[str[i + 1]])
        {
            sum += ump[str[i + 1]] - ump[str[i]];
            i++;
        }
        else
        {
            sum += ump[str[i]];
        }
    }
    return sum;
}
int main()
{
    string str;
    cout << "Enter the Expression : ";
    getline(cin, str);
    int ans = romanToInteger(str);
    cout << str << " = " << ans;
}
