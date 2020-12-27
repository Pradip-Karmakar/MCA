class FixedQueue implements ICharQ{
    private char q[];
    private int putloc,getloc;

    
    public FixedQueue(int size)
    {
        q = new char[size];
        putloc = getloc = 0;
    }

  
    public void put(char ch)
    {
        if(putloc == q.length)
        {
            System.out.println("Alert : Queue is full");
            return;
        }
        q[putloc++] = ch;
    }


    public char get()
    {
        if(getloc == putloc)
        {
            System.out.println("Alert : Queue is empty");
            return (char) 0;
        }
        return q[getloc++];
    }
}

class CircularQueue implements ICharQ
{
    private char q[];
    private int putloc,getloc;

    public CircularQueue(int size)
    {
        q = new char[size+1];
        putloc = getloc = 0;
    }

    public void put(char ch)
    {
        if(putloc+1 == getloc | ((putloc == q.length-1) & (getloc == 0)))
        {
            System.out.println("Alert : Queue is full");
            return;
        }
        q[putloc++] = ch;
        if(putloc == q.length)
        {
            putloc = 0;
        }
    }

    public char get()
    {
        if(getloc == putloc)
        {
            System.out.println("Alert : Queue is empty");
            return (char) 0;
        }
        char ch = q[getloc++];
        if(getloc == q.length) getloc = 0;
        return ch;
    }
}

class DynQueue implements ICharQ
{
    private char q[];
    private int putloc,getloc;

    public DynQueue(int size)
    {
        q = new char[size];
        putloc = getloc = 0;
    }

    public void put(char ch)
    {
        if(putloc == q.length)
        {
            
            char t[] = new char[q.length * 2];
           
            for(int i=0; i < q.length; i++)
                t[i] = q[i];
            q = t;
        }
        q[putloc++] = ch;
    }

    public char get()
    {
        if(getloc == putloc)
        {
            System.out.println("Alert : Queue is empty");
            return (char) 0;
        }
        return q[getloc++];
    }
}

class IQDemo
{
    public static void main(String[] args)
    {
        FixedQueue fixedQueue = new FixedQueue(10);
        DynQueue dynQueue = new DynQueue(5);
        CircularQueue circularQueue = new CircularQueue(10);

        ICharQ iQ;
        char ch;
        int i;
        iQ = fixedQueue;
        
        for(i=0; i < 10;i++)
        {
            iQ.put((char) ('A' + i));
        }

  
        System.out.println("Contents of FixedQueue: ");
        for(i = 0; i < 10; i++)
        {
            ch = iQ.get();
            System.out.print(ch);
        }
        System.out.println();

        iQ = dynQueue;
        
        for(i=0; i < 10;i++)
        {
            iQ.put((char) ('Z' - i));
        }

     
        System.out.println("Contents of DynQueue: ");
        for(i = 0; i < 10; i++)
        {
            ch = iQ.get();
            System.out.print(ch);
        }
        System.out.println();

        iQ = circularQueue;
        
        for(i=0; i < 10;i++)
        {
            iQ.put((char) ('A' + i));
        }

       
        System.out.println("Contents of CircularQueue: ");
        for(i = 0; i < 10; i++)
        {
            ch = iQ.get();
            System.out.print(ch);
        }
        System.out.println();

       
        for(i=10; i < 20;i++)
        {
            iQ.put((char) ('A' + i));
        }

       
        System.out.println("Contents of CircularQueue: ");
        for(i = 0; i < 10; i++)
        {
            ch = iQ.get();
            System.out.print(ch);
        }
        System.out.println("\nStore and consume from circular queue");

      
        for(i = 0; i < 20; i++)
        {
            iQ.put((char) ('A' + i));
            ch = iQ.get();
            System.out.print(ch);
        }
    }
}
