package remote;
import static java.lang.Math.random;
public class TryRemoteControl {
    public static void main(String args[]) {
        RemoteControl remote = null;
        for(int i = 0 ; i<5 ; i++) {
            if(random()<0.5)
                remote = new TV(random()<0.5 ? "Sony" : "Hitachi",random()<0.5 ? 32 : 28);
            else
                remote = new VCR(random()<0.5 ? "Panasonic": "JVC");
         remote.powerOnOff(); 
         remote.channelUp(); 
         remote.volumeUp(10); 
      }
   }
}