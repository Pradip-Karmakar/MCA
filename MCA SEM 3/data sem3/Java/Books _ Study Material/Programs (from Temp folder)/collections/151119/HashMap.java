package Mcaiii;

//Java program to illustrate
//Java.util.HashMap
import java.util.HashMap;
import java.util.Map;
 
public class Hashmap1{
public static void main(String[] args){
HashMap<String, Integer> map = new HashMap<>();
print(map);
map.put("Ruju", 10);
map.put("Rizwan", 30);
map.put("Shrey", 20);
 
System.out.println("Size of map is" + map.size());
 
print(map);
if (map.containsKey("Ruju"))
{
Integer a = map.get("Ruju");
System.out.println("value for key \"Ruju\" is:- " + a);
}
 
map.clear();
print(map);
}
 
public static void print(Map<String, Integer> map){
if (map.isEmpty()){
System.out.println("map is empty");
}
else{
System.out.println(map);
}
}
}