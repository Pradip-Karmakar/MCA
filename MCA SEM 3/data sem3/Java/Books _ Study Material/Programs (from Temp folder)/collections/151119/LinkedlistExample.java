import java.util.*; 

public class LinkedlistExample{ 
    public static void main(String args[]){
        LinkedList<String> al=new LinkedList<String>();// creating linked list 
        al.add("Ankita"); // adding elements 
        al.add("Ankita"); 
        al.add("Faizan"); 
        Iterator<String> itr = al.iterator();
        while(itr.hasNext()){ 
            System.out.println(itr.next());
        }
    }
}