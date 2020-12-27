public class StringSwitch {
    public static void main(String args[]){
        String command = "connect";
        
        switch(command){
            case "connect" :
                System.out.println("connecting");
                break;
            case "cancel" :
                System.out.println("canceling");
                break;
            case "disconnect" :
                System.out.println("disconnecting");
                break;
            default :
                System.out.println("command error");
                break;
        }
    }
}
