public class MountainArrayFind
{
    public static void main(String[] args)
    {
        int[] MtArr={-1,0,2,4,5,3,1};
        int target=1;
        int indx=FindElementIndex(MtArr,target);
        System.out.println("Index : "+indx);
    }
    static int FindElementIndex(int[] MtArr,int target)
    {
        int peak=PeakElement(MtArr);

        int firstHalf=OrderAgnosticBS(MtArr,target,0,peak);
        if(firstHalf!=-1)
            return  firstHalf;
        return  OrderAgnosticBS(MtArr,target,peak+1, MtArr.length-1);
    }
    static int OrderAgnosticBS(int[] ar,int target,int start,int end)
    {
        boolean isAsc=ar[start]<ar[end];

        while (start<=end)
        {
            int mid=start+(end-start)/2;
            if(ar[mid]==target)
            {
                return mid;
            }
            if(isAsc)
            {
                if(target<ar[mid])
                {
                    end=mid-1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                if(target>ar[mid])
                {
                    end=mid-1;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }
        return -1;
    }
    static int PeakElement(int[] MtArr)
    {
        int start=0;
        int end=MtArr.length-1;
        while (start<end)
        {
            int mid=start+(end-start)/2;
            if(MtArr[mid]>MtArr[mid+1])
            {
                end=mid;
            }
            else
            {
                start=mid+1;
            }
        }
        return  start;
    }
}
