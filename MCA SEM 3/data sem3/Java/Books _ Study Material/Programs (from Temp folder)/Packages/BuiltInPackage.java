package mcaiii;
import java.util.ArrayList;
 
class BuiltInPackage{
 
    public static void main(String[] args) {
 
        ArrayList<Integer> myList = new ArrayList<Integer>(3);
 
        myList.add(3);
        myList.add(2);
        myList.add(1);
 
        System.out.println("The elements of list are: " + myList);
    }
}

/* The ArrayList class belongs to java.util package. 
To use it, we have to import the package using the import statement. 
The first line of the code import java.util.ArrayList imports the java.util package 
and uses ArrayList class which is present in the sub package util. */