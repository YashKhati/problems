import javax.imageio.stream.ImageOutputStreamImpl;
import java.util.Arrays;
import java.util.Scanner;
public class CountSort
{
    public  static void countSortAlgo(int[] arr,int mini,int maxi)
    {

        int range = maxi- mini+1;      // calculating range to declare freq array size

        int[] freq=new  int[range];

        for(int i=0;i<arr.length;i++)
        {
            freq[arr[i]-mini]++;
        }
        System.out.println("Frequency Sum Array : \n"+(Arrays.toString(freq)));
        // Converting Sum in Prefix Sum
        for(int i=1;i<freq.length;i++)
        {
            freq[i] = freq[i]+freq[i-1];
        }
        System.out.println("Prefix Sum Array : \n"+(Arrays.toString(freq)));
        int[] ans = new int[arr.length];
        for(int i= arr.length-1;i>=0 ;i--)
        {
            int val=arr[i];
            int pos = freq[val-mini];
            int indx = pos-1;
            ans[indx]=val;
            freq[val-mini]--;
        }
        System.out.println("Sorted Array : \n"+(Arrays.toString(ans)));
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.println("Enter Size of Array : ");
        n=sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter Array Elements ");
        for(int i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }
        int mini = Integer.MAX_VALUE;
        int maxi = Integer.MIN_VALUE;

        for(int i=0;i<n;i++)
        {
            maxi=Math.max(maxi,arr[i]);
            mini=Math.min(mini,arr[i]);
        }
        countSortAlgo(arr,mini,maxi);

    }
}
