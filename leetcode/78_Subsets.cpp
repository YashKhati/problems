// Recurssive Approach

class Solution {
public:
    void calcSubsets(vector<int> nums,vector<vector<int>> &ans,vector<int> &ds,int i)
    {
        if(i==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        calcSubsets(nums,ans,ds,i+1);
        ds.pop_back();
        calcSubsets(nums,ans,ds,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        calcSubsets(nums,ans,ds,0);
        return ans;
    }
};


// Itterative approach

class Solution {
    public List<List<Integer>> subsets(int[] nums) 
    {
        List<List<Integer>> ans = new ArrayList();   // power set or ans list
        ans.add(new ArrayList());   // adding empty subset to answer list    
        
        for(int num : nums)
        {
            int n = ans.size();      // current size of ans list
            for(int j = 0;j<n;j++)
            {
                List<Integer> temp =new ArrayList(ans.get(j));      // getting element from ans list and adding it to temperoary list
              
                temp.add(num);      // Adding element to the list 
               
                ans.add(temp);  // adding  resulting temperoary list in ans list 
            }
        }
        return ans;
    }
}
