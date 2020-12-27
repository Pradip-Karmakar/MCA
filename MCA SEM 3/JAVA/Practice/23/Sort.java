public class Sort {
    public static void main(String args[]) {
      
      String text = "Lorem Ipsum is simply dummy text of the printing and typesetting industry " +
                    "It is a long established fact that a reader will be distracted by the readable content of a page when looking at its layout ";
    
      int count = 0;	                     
      boolean isWord = false;             
      for (int i = 0 ; i<text.length() ; i++) {
        if(isWord) {                      
          if(Character.isLetter(text.charAt(i)) || text.charAt(i) == '\'')
            continue;                     
          else                                                        
            isWord = false;                
        }
        else if(Character.isLetter(text.charAt(i))) {
                                           
            count++;                      
            isWord = true;                
        }
      }        
  
      
      String[] words = new String[count];
  
    
      int start = 0;                                      
      int wordIndex = 0;                                                                     
      isWord = false;                                      
      for (int i = 0 ; i<text.length() ; i++) {
        if(!isWord) {                                      
          if(Character.isLetter(text.charAt(i))) {         
            start = i;                                    
            isWord = true;                                 
          }
        }
        else {                                             
          if(Character.isLetter(text.charAt(i)) || text.charAt(i) == '\'')
            continue;                                      
          else {                                           
            isWord = false;                                
            words[wordIndex++] = text.substring(start,i); 
          }
        }          
      }
      
      if(wordIndex < words.length)
        words[wordIndex] = text.substring(start);
  

      String temp = null;                        
      boolean exchange = true;                     
      while(exchange) {
        exchange = false;                          
        for(int i = 1 ; i<words.length ; i++) {    
            if(words[i-1].compareTo(words[i])>0) {  
                temp = words[i];                     
                words[i] = words[i-1];
                words[i-1] = temp;
                exchange = true;                
            }
        }
      }
  
      for(String word : words) {
        System.out.println(word);
      }
      
    }
  }
  
  