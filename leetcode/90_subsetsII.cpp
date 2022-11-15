class Solution {
public:
    void  UniqueSubsets(vector<int> nums,vector<vector<int>> &ans,vector<int> &ds,int i)
    {
        ans.push_back(ds);
         for(int j=i;j<nums.size();j++)
        {
            if(j!=i && nums[j]==nums[j-1])
            {
                continue;
            }
            ds.push_back(nums[j]);
            UniqueSubsets(nums,ans,ds,j+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        UniqueSubsets(nums,ans,ds,0);
        return ans;
    }
};
