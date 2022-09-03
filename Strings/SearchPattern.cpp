#include <iostream>
#include <vector>
using namespace std;
void pi_table(string patt, vector<int> &lps)
{
    int i = 1;
    int len = 0;
    while (i < patt.length())
    {
        if (patt[i] == patt[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}
bool KMP_Search(string patt, string text, vector<int> lps)
{
    if (patt.length() == 0)
    {
        return false;
    }
    int i = 0, j = 0;
    while (i < text.length())
    {
        if (text[i] == patt[j])
        {
            i++;
            j++;
            if (j == patt.length())
            {
                j = lps[j - 1];
                return true;
            }
        }
        else
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }
    return false;
}
int main()
{
    string text, patt;
    cout << "Enter text : ";
    getline(cin, text);
    cout << "Enter pattern  : ";
    getline(cin, patt);

    int t_len = text.length(), pat_len = patt.length();

    cout << "text length " << t_len << endl;
    cout << "pattern length " << pat_len << endl;
    vector<int> lps(pat_len, 0);
    pi_table(patt, lps);
    if (KMP_Search(patt, text, lps))
    {
        cout << "Pattern exist ";
    }
    else
    {
        cout << "Pattern does not exist ";
    }
}
