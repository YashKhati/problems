public class MountainArrayPeak
{
    public static void main(String[] args)
    {
     int[] MtArr={1,4,6,9,12,13,11,10,4,3,0};
     int indx=PeakElement(MtArr);
        System.out.println("Peak Element : "+MtArr[indx]);
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
