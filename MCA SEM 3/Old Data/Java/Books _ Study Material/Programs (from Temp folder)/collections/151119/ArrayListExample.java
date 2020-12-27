import java.util.*;
 class ArrayListExample{
 public static void main(String args[]){
  
	ArrayList al=new ArrayList();  // creating array list
	al.add("Ankita-2");                // adding elements    
	al.add("Faizan");
	Iterator itr=al.iterator();
	while(itr.hasNext()){
	System.out.println(itr.next());
 }
 }
 }