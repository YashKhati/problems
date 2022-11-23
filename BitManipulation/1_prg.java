import java.util.Scanner;

public class Prg1
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int num;
        System.out.print("Enter a number : ");
        num = sc.nextInt();
        System.out.println(num +" in Binary : "+Integer.toBinaryString(num)); //

        // To turn on 3 on bit of number
        int maskON = 1;
        maskON=(maskON<<2);
        System.out.println("maskOn in Binary : "+Integer.toBinaryString(maskON));
        System.out.println(num | maskON);
        System.out.println(Integer.toBinaryString(num | maskON));


        // To turn off 3 on bit of number
        System.out.print("Enter a number : ");
        num = sc.nextInt();
        System.out.println(num +" in Binary : "+Integer.toBinaryString(num));
        int maskOff = 1;
        maskOff=~(maskOff<<1);
        System.out.println("maskOff in Binary : "+Integer.toBinaryString(maskOff));
        System.out.println(num & maskOff);
        System.out.println(Integer.toBinaryString(num & maskOff));

        // To toggle ith bit of number
        System.out.print("Enter a number : ");
        num = sc.nextInt();
        System.out.println(num +" in Binary : "+Integer.toBinaryString(num));
        int Toggle = 1;
        Toggle=(Toggle<<2);
        System.out.println("toggle in Binary : "+Integer.toBinaryString(Toggle));
        System.out.println(num ^ Toggle);
        System.out.println(Integer.toBinaryString(num ^ Toggle));

    }
}
