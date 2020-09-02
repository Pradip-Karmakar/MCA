import java.util.ArrayList;
 class Student{
	int rollno;
	String name;
}

public class ListDemo{
 public static void main(String args[]){
	// List1 will add only string elements
	ArrayList<String> list1=new ArrayList<String>();  // creating array list //here we are type specific
	
	//any type of object
	ArrayList list2=new ArrayList();  // creating array list //here any type of data
	
	Student s1=new Student();
	s1.rollno=12;
	s1.name="Krishna";
	
	//Add data to list
	list1.add("Ankita-2");                  // adding elements    
	list1.add("Faizan");
	list1.add("Antra");
	list1.add("Aqueed");
	
	
	list2.add("Ankita-2");                  // adding elements    
	list2.add(10);
	list2.add(4.2);
	list2.add(s1);
	
	//Print reference to list
		System.out.println("List1 is " + list1);
		
		System.out.println("List2 is " + list2);

			System.out.println("Student name is " + s1.name);

	
	//Get the elements from list 
	// String name=list1.get(2);
	// System.out.println("Name is " + name);
	
	//Now fetching element from List 2
	// Object o=list2.get(2);
	// System.out.println("O is " + o);
	
	
	//update elements in list 
	// list1.set(2,"test");
	// System.out.println("List1 " + list1);
	
	//remove item from list
	//list1.remove(2);
	// System.out.println("List1 after delete is" + list1);
	
	//list1.clear //it removes all elements
	
	/* There are methods which provide us features of searching and sorting */
	
	// if (list1.contains("Antra")){
	// System.out.println("Antra is in the list");
	// }
	
	//itearating with enhanced for loop
	// System.out.println("For loop ----------");
	// for (String str : list1){
		// System.out.println(str);
	// }
		// System.out.println("*********");
	
	// /* You can also use basic for loop , wherein you can use the size method e.g for (int i=0;i<list1.size();i++) print list1.get(i); */
	
	
	//api iterator we have already done
	// /* Iterator itr=al.iterator();      //iterator method gives us reference of the array list, 
	// iterator gives the element one by one in the sequence, if you dont write in loop write next as many times, You can also use remove method 
	// in iterator to remove item from list*/
	
	//while(itr.hasNext()){
	//System.out.println(itr.next());
	
	// while(itr.hasNext()){
		// String str=itr.hasNext();
		// System.out.println(str);
		// if (str.equals("Antra")){
			// itr.remove();
		// }
	// }
	// System.out.println("*****");
	
	// System.out.println("List after iteration" + list1);
	
 }
 }
 //}