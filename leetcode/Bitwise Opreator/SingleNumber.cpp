#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> ar = {4, 1, 2, 1, 2};
    int ans = 0;
    for (int i = 0; i < ar.size(); i++)
    {
        ans ^= ar[i];   // A XOR B XOR A = B
    }
    cout << "Answer : " << ans;
    return 0;
}
