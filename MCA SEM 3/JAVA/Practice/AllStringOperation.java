public class AllStringOperation {
    public static void main(String args[]){
        String str1 = "when it comes to web programming, java is #1.";
        String str2 = new String(str1);
        String str3 = "java strings are powerful.";
        int result,idx;
        char ch;

        System.out.println("length of str1 : "+str1.length());

        //display str1,one char at a time.
        for(int i=0; i<str1.length();i++)
            System.out.print(str1.charAt(i));

        System.out.println();

        if(str1.equals(str2))
            System.out.println("str1 equals str2");
        else
            System.out.println("str1 does not equal str2");

        if(str1.equals(str3))  
            System.out.println("str1 equals str3");
        else
            System.out.println("str1 does not equal str3");
            
        result = str1.compareTo(str3);
        if(result == 0)
            System.out.println("str1 and str3 are equal");
        else if(result<0)
            System.out.println("str1 is less than str3");
        else
            System.out.println("str1 is greater than str3");
        
        idx = str2.indexOf("one");
        System.out.println("index of first occurence of one : "+idx);
        idx = str2.lastIndexOf("one");		 
        System.out.println("index of last occurence of one : "+idx);  
    }
}
