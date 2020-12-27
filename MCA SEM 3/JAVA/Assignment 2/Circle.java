public class Circle{
    public static void main(String[] args)
    {
        double x,y,r;
        int origin;
        CircleObj[] c= new CircleObj[10];

        for(int i=0;i<10;i++)
        {
            origin=(int) (2*  Math.random());
            r= (double) (10* Math.random())+1;

            if(origin==1)
                c[i]=new CircleObj(r);
            else
            {
                x= (double) (100* Math.random())+1;
                y= (double) (100* Math.random())+1;
                c[i] = new CircleObj(x,y,r);
            }
            
        }
        for(int i=0;i<10;i++)
        {
            c[i].display();
        }
    }
}
public class CircleObj
{
    double radius,cntx,cnty;

    CircleObj(double radius)
    {
        this.cntx=0;
        this.cnty=0;
        this.radius=radius;
    }

    CircleObj(double cntx,double cnty,double radius)
    {
        this.cntx=cntx;
        this.cnty=cnty;
        this.radius=radius;
    }

    private double area()
    {
        return (3.14*this.radius*this.radius);
    }

    public void display()
    {
         System.out.println("-------");
        System.out.println("Center: ("+this.cntx+", "+this.cnty+")");
        System.out.println("Radius: "+this.radius);
        System.out.println("Area: "+ this.area());
    }
}