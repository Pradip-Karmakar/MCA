import java.util.*;
import java.util.stream.Collectors;
class Instrument{
int num;
String name;
float price;
public Instrument(int num, String name, float price) {
this.num = num;
this.name = name;
this.price = price;
}
}
public class Test {
public static void main(String[] args) {
List<Instrument> instrumentsList = new ArrayList<Instrument>();
//Adding Products
instrumentsList.add(new Instrument(1,"Guitar",15000f));
instrumentsList.add(new Instrument(2,"Piano",18000f));
instrumentsList.add(new Instrument(3,"Flute",15000f));
instrumentsList.add(new Instrument(4,"Drums",48000f));
instrumentsList.add(new Instrument(5," Ukulele",32000f));
List<Float> InstrumentPriceList2 =instrumentsList.stream()
.filter(p -> p.price > 30000)// filtering data
.map(p->p.price)//fetching price
.collect(Collectors.toList()); // collecting as list
System.out.println(InstrumentPriceList2);
}
}