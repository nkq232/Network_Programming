// Nguyễn Khánh Quân 19020400 
// Bài 3
// Viết chương trình đọc dữ liệu từ một file text và lưu các ký tự là chữ cái sang một file khác.
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Scanner;
 
public class Main {
    public static void main(String args[]) throws Exception {
        System.out.println("Nhập tên file (Nhập đuôi): ");
    	Scanner sc = new Scanner(System.in);
    	String fileIn = sc.nextLine();
        FileReader fr = new FileReader(fileIn);
        BufferedReader br = new BufferedReader(fr);

        String input = "";
        int i;
        while ((i = br.read()) != -1) {
        	if ((65 <= i && i <=90) || (i >= 97 && i <= 122)) {
        		input += (char) i;
        	}
        }
        br.close();
        fr.close();

        FileWriter fw = new FileWriter("result.txt");
        BufferedWriter bw = new BufferedWriter(fw);
        for(int a = 0; a < input.length(); a++)
		bw.write(input.charAt(a));
		bw.close();
    }
}