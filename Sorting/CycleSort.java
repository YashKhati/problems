import java.util.Arrays;
import java.util.Scanner;

public class CyclicSort
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int range;
        System.out.println("Enter Range of Number : ");
        range = sc.nextInt();
        int[] ar = new int[range];
        System.out.println("Enter Elements of array : ");
        for(int i=0;i<range;i++)
        {
            ar[i]=sc.nextInt();
        }
        CycleSort(ar);
        System.out.println("After sorting : ");
        System.out.println(Arrays.toString(ar));
    }
    static void  CycleSort(int[] ar)
    {
        int i=0;
        while (i< ar.length)
        {
            int correct_indx=ar[i]-1;
            if(ar[correct_indx]!=ar[i])
            {
                swap(ar,i,correct_indx);
            }
            else
            {
                i++;
            }
        }
    }
    static  void swap(int[] arr,int first,int second)
    {
        int temp = arr[first];
        arr[first]=arr[second];
        arr[second]=temp;
    }
}
