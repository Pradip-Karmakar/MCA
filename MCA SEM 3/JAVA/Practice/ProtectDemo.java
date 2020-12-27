package bookpackext;

class ExtBook extends bookpack.Books{
    private String publisher;
    public ExtBook(String t,String a, int d,String p)
    {
        super(t,a,d);
        publisher = p;
    }

    public void show()
    {
        super.show();
        System.out.println(publisher);
        System.out.println();
    }

    public String getPublisher() { return publisher; }
    public void setPublisher(String p) { publisher = p; }

    public String getTitle() { return title; }
    public void setTitle(String t) { title = t; }

    public String getAuthor() { return author; }
    public void setAuthor(String a) { author = a; }

    public int getPubDate() { return pubDate; }
    public void setTitle(int d) { pubDate = d; }

}

class ProtectDemo
{
    public static void main(String[] args)
    {
        ExtBook books[] = new ExtBook[5];
        books[0] = new ExtBook("Java: A Beginner's Guide","Schildt",2014,"McGrew-Hill Professional");

        books[1] = new ExtBook("Java: The Complete Reference","Schildt",2014,"McGrew-Hill Professional");

        books[2] = new ExtBook("The Art of Java","Schildt and Holmes",2003,"McGrew-Hill Professional");

        books[3] = new ExtBook("Red Storm Raising","Clancy",1986,"Putham");

        books[4] = new ExtBook("On The Road","Kerouac",1955,"Viking");

        for(int index = 0; index < books.length; index++)
        {
            books[index].show();
        }

        System.out.println("Showing all books by schildt.");
        for(int index=0;index<books.length;index++)
        {
            if(books[index].getAuthor() == "Schildt")
            {
                System.out.println(books[index].getTitle());
            }
            //books[index].title = "test title"; error by accessing protected
        }
    }
}