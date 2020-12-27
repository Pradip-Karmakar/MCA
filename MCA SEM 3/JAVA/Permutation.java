import java.io.*;

public class Permutation {
    public static void main(String[] args) throws IOException {
        String str = "the fat cat";
        String[] words = str.split("[ ]");

        FileWriter writer = new FileWriter("permutations.txt");

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    String data = words[i] + words[j] + words[k] + "\n";
                    writer.write(data);
                }
            }
        }

        writer.close();

        BufferedReader reader = new BufferedReader(new FileReader("permutations.txt"));

        while ((str = reader.readLine()) != null)
            System.out.println(str);

        reader.close();

    }
}
