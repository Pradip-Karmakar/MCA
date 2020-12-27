package remote;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class TV implements RemoteControl {

    public TV(String make, int screensize) {
        this.make = make;
        this.screensize = screensize;
    }

    public boolean powerOnOff() {
        power = !power;
        System.out.println(make + " "+ screensize + " inch TV power "+ (power ? "on.":"off."));
        return power;
    }

    public int volumeUp(int increment) {
        if(!power)
            return 0; 
    
        volume += increment;
        volume = min(volume, MAX_VOLUME);
        System.out.println(make + " "+ screensize + " inch TV volume level: "+ volume);
        return volume;
    }

    public int volumeDown(int decrement) {
        if(!power) 
            return 0; 
    
        volume -= decrement;
        volume = max(volume, MIN_VOLUME);
        System.out.println(make + " "+ screensize + " inch TV volume level: " + volume);
        return volume;
    }
    public void mute() {
        if(!power) 
           return; 

        volume = MIN_VOLUME;
        System.out.println(make + " "+ screensize + " inch TV volume level: "+ volume);
    }

    public int setChannel(int newChannel) {
        if(!power)  
            return 0; 
   
        if(newChannel>=MIN_CHANNEL && newChannel<=MAX_CHANNEL)
            channel = newChannel;

        System.out.println(make + " "+ screensize + " inch TV tuned to channel: "+ channel);
        return channel;
    }

    public int channelUp() {
        if(!power) 
            return 0; 

        channel = channel<MAX_CHANNEL ? ++channel : MIN_CHANNEL;
        System.out.println(make + " "+ screensize + " inch TV tuned to channel: "+ channel);
        return channel;
    }

    public int channelDown() {
        if(!power) 
            return 0; 
    
        channel = channel>MIN_CHANNEL ? --channel : MAX_CHANNEL;
        System.out.println(make + " "+ screensize + " inch TV tuned to channel: "+ channel);
        return channel;
    }
    private String make = null;
    private int screensize = 0;
    private boolean power = false;
    private int MIN_VOLUME = 0;
    private int MAX_VOLUME = 100;
    private int volume = MIN_VOLUME;
    private int MIN_CHANNEL = 0;
    private int MAX_CHANNEL = 999;
    private int channel = 0;
}