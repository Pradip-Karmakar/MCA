import java.util.*;
import java.util.stream.*;
public class Test2
{
public static void main(String args[])
{
//creating a list of integers
List<Integer> num = Arrays.asList(6,7,8,9);
//using map method
List<Integer> squares = num.stream().map(y -> y*y).
collect(Collectors.toList());
System.out.println(squares);
//creating a list of String
List<String> days =
Arrays.asList("Friday","Saturday","Sunday");
//filter method
List<String> res = days.stream().filter(s->s.startsWith("S")).
collect(Collectors.toList());
System.out.println(res);
//sorted method
List<String> display =
days.stream().sorted().collect(Collectors.toList());
System.out.println(display);
//creating a list of integers
List<Integer> number = Arrays.asList(6,9,5,7,1);
//collect method returns a set
Set<Integer> sqSet =
number.stream().map(y->y*y).collect(Collectors.toSet());
System.out.println(sqSet);
//forEach method
num.stream().map(y->y*y).forEach(x->System.out.println(x));
//reduce method
int even =
num.stream().filter(x->x%2==0).reduce(0,(result,i)-> result+i);
System.out.println(even);
}
}