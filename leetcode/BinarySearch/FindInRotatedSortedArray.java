public class RotatedSortedArray {
    public static void main(String[] args) {
        int[] arr = {6, 7, 8, 0, 1, 2, 3, 4};
        System.out.println( search(arr,2));
    }

    static int search(int[] nums, int target)
    {
        int pivot=SearchPivot(nums);
        if(pivot==-1)
            return  binarySearch(nums,target,0,nums.length-1);
        if(nums[pivot]==target)
            return pivot;
        if(target>=nums[0])
            return binarySearch(nums,target,0,pivot-1);

        return binarySearch(nums,target,pivot+1,nums.length-1);
    }
    static  int binarySearch(int[] ar,int target,int start,int end )
    {
        while (start<=end)
        {
            int mid=start+(end-start)/2;
            if(ar[mid]==target)
            {
                return mid;
            }
            else if(target<ar[mid])
            {
                end=mid-1;
            }
            else if (target>ar[mid])
            {
                start = mid + 1;
            }
        }
        return -1;
    }
    static int SearchPivot(int[] ar)
    {
        int start=0;
    int end=ar.length - 1;
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        if(mid<end && ar[mid]>ar[mid+1])
        {
            return mid;
        }
        if(mid > start&& ar[mid]<ar[mid-1])
        {
            return  mid-1;
        }
        if(ar[mid]<=ar[start])
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return -1;
}
}
