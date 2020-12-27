import java.util.*;
class HashsetExample{
 public static void main(String args[]){
  
 HashSet&amp;amp;amp;lt;String&amp;amp;amp;gt; al=new HashSet(); // creating hashSet
 al.add("Ashish");                 // adding elements
 al.add("Vivek");
 al.add("Kruti");
 Iterator&amp;amp;amp;lt;String&amp;amp;amp;gt; itr=al.iterator();
 while(itr.hasNext()){
 System.out.println(itr.next());
 }
 }
 }