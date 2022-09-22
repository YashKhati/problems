int max(int a,int b)
    {
        if(a>b)
        {
            return a;
        }
        return b;
    }
    int trap(vector<int>& height)
    {
        int water=0;
        for(int i=1;i<height.size()-1;i++)
        {
            int left=height[i];
            for(int j=0;j<i;j++)
            {
                left=max(left,height[j]);
            }
            int right=height[i];
            for(int j=i+1;j<height.size();j++)
            {
                right=max(right,height[j]);
            }
            water=water+(min(left,right)-height[i]);
        }
        return water;
    }
