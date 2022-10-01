import java.util.Arrays;

public class FirstAndLastPosition
{
    public static void main(String[] args)
    {
        int[] nums={5,7,7,8,8,10};
        int[] ans={-1,-1};
        int target=7;
        int fi=Occurrence(nums,target,true);
        int li=Occurrence(nums,target,false);
        ans[0]=fi;
        ans[1]=li;
        System.out.println(Arrays.toString(ans));
    }

        static  int Occurrence(int[] nums,int target,boolean firstIndex)
        {
            int ans=-1;
            int start=0;
            int end= nums.length-1;
            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(nums[mid]>target)
                {
                    end=mid-1;
                }
                else if(nums[mid]<target)
                {
                    start=mid+1;
                }
                else
                {
                    ans=mid;
                    if (firstIndex)
                    {
                        end=mid-1;
                    }
                    else
                    {
                        start=mid+1;
                    }
                }
            }
            return ans;
        }
}
