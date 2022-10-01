public class SmallestChar
{
    public static void main(String[] args)
    {
        char[] arr={'c','f','j'};
        char target='j';
        char ans=nextGreatestLetter(arr,target);
        System.out.println(ans);
    }
    static char nextGreatestLetter(char[] ar, char target) {
        int start = 0;
        int end = ar.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (target < ar[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ar[start%ar.length];
    }
}
