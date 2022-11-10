/*

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:
      0 <= i <= s.length - 2
      s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

*/
class Solution {
public:
    string makeGood(string s) 
    {
        // Initialize 'end = 0' since the good string is empty.
        int end = 0;
        for (int cur = 0; cur < s.size(); ++cur) {
            // If s[cur] makes a pair with the last character s[end - 1] in good string,
            // remove s[end - 1] by decrementing 'end' by 1. 
            // Otherwise, add s[cur] to the good string by overwritting s[end] by s[cur].
            if (end > 0 && abs(s[cur] - s[end - 1]) == 32)
                end--;
            else {
                s[end] = s[cur];
                end++;
            }
        }
        
        // Once the iteration ends, the string before 'end' is the good string.
        return s.substr(0, end); 
    }
};
