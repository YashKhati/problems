class Solution {
public:
     bool isPalindrome(string str, int startIndex, int lastIndex){
        while(startIndex <= lastIndex){
            if(str[startIndex] != str[lastIndex])
                return false;
            startIndex++;
            lastIndex--;
        }
        return true;
    }
    void solution(int index, vector<string>& ds, vector<vector<string>>& output, string str){
        if(index == str.length()){
            output.push_back(ds);
            return;
        }
        for(int i = index; i < str.length(); i++){
            if(isPalindrome(str, index, i)){
                ds.push_back(str.substr(index, i - index + 1));
                solution(i+1, ds, output, str);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
        vector<string> ds;
        solution(0, ds, output, s);
        return output;
    }
    
};
