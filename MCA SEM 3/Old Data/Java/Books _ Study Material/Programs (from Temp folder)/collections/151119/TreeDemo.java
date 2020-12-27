import java.util.TreeSet;
import java.util.Iterator;

class TreeDemo{
 public static void main(String args[]){
  TreeSet<String> set=new TreeSet<String>(); // Data is unordered, but alphbetically sorted 
  
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
		set.remove("Akhil");
		System.out.println("Set after remove is:" +set);
		
		if(set.contains("")){
			System.out.println("is in the list");
		}
	//you can also fetch set size by set.size();
 }
 }