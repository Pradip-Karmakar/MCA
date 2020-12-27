
public class MSD {
    public static void main(String[] args)
    {
        int[] numbers = {34, 21, 56, 89, 12};
        int count = 0;
        int max = numbers[0];
        int total = 0;
        System.out.print("Numbers In Array : ");
        while(count < 5)
        {
            if( numbers[count] > max && count > 0)
                max = numbers[count];
                
            total += numbers[count];
            System.out.print(numbers[count++] + " ");
        }
        System.out.println("\nMax Element In Array : " + max);
        System.out.println("Total of Elements In Array : " + total);
    }
}
