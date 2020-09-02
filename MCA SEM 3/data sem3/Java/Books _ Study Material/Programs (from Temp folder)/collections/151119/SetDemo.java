import java.util.HashSet;
import java.util.Iterator;

class SetDemo{
 public static void main(String args[]){
  HashSet<String> set=new HashSet<String>(); // creating hashSet
  
  //Here data is not added as in indexin approach
  // we get hashcodes for elements which are beint added
		set.add("Parth");                 // adding elements
		set.add("Yash");
		set.add("Akhil");
		set.add("Parth");                 
		set.add("Sachin");
		set.add("Supan");
		set.add("Parth");
		
		System.out.println("Set is :" +set);
		
		Iterator<String> itr=set.iterator();
		while(itr.hasNext()){
			String str=itr.next();
			System.out.println(str);
			//hashing technique will not allow us indexing so we use iterator
		}
	}
 }