package bookpackext;
import bookpack.*;

class UseBook {
    public static void main(String args[])
    {
        Books book[] = new Books[5];
        book[0] = new Books("Java: A Beginner's Guide","Schildt",2014);

        book[1] = new Books("Java: The Complete Reference","Schildt",2014);

        book[2] = new Books("The Art of Java","Schildt and Holmes",2003);

        book[3] = new Books("Red Storm Raising","Clancy",1986);

        book[4] = new Books("On The Road","Kerouac",1955);

        for(int index = 0; index < book.length;index++) book[index].show();
    }
}