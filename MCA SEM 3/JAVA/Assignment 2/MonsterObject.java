public class MonstersObject
{
    public static void main(String[] args)
    {
        int key;
        Monster[] m= new Monster[6];

        for(int i=0;i<6;i++)    //to create
        {
            key=(int) (3 * Math.random()) +1;   //to create random Monsters 

            switch(key)
            {
                case 1: //For Wolf
                    m[i]= new WareWolf(i);
                    break;
                case 2: //for Zombie
                    m[i]= new Zombie(i);
                    break;
                case 3: //for Vampire
                    m[i]= new Vampire(i);
            }
        }

        for(int i=0;i<6;i++)
        {
            m[i].display();
        }
    }
}
public class MonsterObject {
    
}
abstract class Monster
{
    String type;
    int id;

    Monster(String type)
    {
        this.type=type;
    }
    public void display()
    {
        System.out.println("-----");
        System.out.println("Monster id: "+ this.id);
        System.out.println("Monster type: "+ this.type);
    }
}

class WareWolf extends Monster
{
    WareWolf(int id)
    {
        super("WareWolf");
        this.id=id;
    }
}

class Zombie extends Monster
{
    Zombie(int id)
    {
        super("Zombie");
        this.id=id;
    }
}
class Vampire extends Monster
{
    Vampire(int id)
    {
        super("Vampire");
        this.id=id;
    }
}
