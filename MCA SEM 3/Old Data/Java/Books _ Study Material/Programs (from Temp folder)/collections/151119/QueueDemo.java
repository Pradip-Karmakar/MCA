import java.util.PriorityQueue;
 
public class QueueDemo{
 public static void main(String args[]){
	
	PriorityQueue<Integer> queue =new PriorityQueue<Integer>();  
		
		for (int i=10;i>0;i--) {
			queue.add(i);
		}
	
	//Queue (Front)10 9 8 7 6 5 4 3 2 1(Rear) 
	// but priority queue sorts the data for us , so
	//Queue (Front) 1 2 3 4 5 6 7 8 9 10 (Rear)  // sorted queue
	
	//two major operations peek and poll
	//peeking : head of queue
	//polling : Remove the head of queue
	
	System.out.println(queue.peek()); //head of queue
	queue.poll(); //removing the head
	System.out.println(queue.peek()); // new head of queue

	
	/*

	System.out.println("Queue size is : " + queue.size()); 
	System.out.println("Head of Queue is " + queue.peek()); //head of queue
	
	queue.poll(); //removing the head
	System.out.println("Queue size after poll is  : " + queue.size()); 
	
	
	System.out.println(queue.peek()); // new head of queue
	
	
	System.out.println(queue.peek()); // new head of queue

	
	*/


	
 }
 }
 