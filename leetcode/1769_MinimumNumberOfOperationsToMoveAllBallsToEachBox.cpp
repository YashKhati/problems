class Solution {
public:
    vector<int> minOperations(string boxes)
    {
        vector<int> ans(boxes.size(),0);
        int behind=0;
        int ahead=0;
        for(int i=0;i<boxes.size();i++)
        {
             if(boxes[i]=='1')
             {
                ahead++;
                ans[0] += i;
             }
        }
        if(boxes[0]=='1')
        {
            ahead--;
            behind++;
        }
        for(int i=1;i<boxes.size();i++)
        {
            ans[i] += ans[i-1]+behind-ahead;
            if(boxes[i]=='1')
            {
                behind++;
                ahead--;
            }
        }
        return ans;   
    }
};
