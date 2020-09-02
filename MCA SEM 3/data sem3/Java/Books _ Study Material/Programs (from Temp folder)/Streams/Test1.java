import java.util.stream.*;
public class Test1 {
public static void main(String[] args){
Stream.iterate(1, element->element+1)
.filter(element->element%4==0)
.limit(6)
.forEach(System.out::println);
}
}