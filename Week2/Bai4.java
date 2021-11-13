// Nguyễn Khánh Quân 19020400 
// Bài 4
// Viết chương trình đọc dữ liệu từ một file ảnh và lưu dữ liệu đó sang một file khác.
import java.io.*;
import java.util.Scanner;
 
public class Main {
    public static void main(String args[]) throws Exception {
        System.out.println("Nhập tên file (Nhập đuôi): ");
    	Scanner sc = new Scanner(System.in);
    	String fileIn = sc.nextLine();
    	String result = "result.";
    	int po = 0;
    	for(int i = fileIn.length() - 1; i >= 0; i--){
    		if (fileIn.charAt(i) == '.') {
    			po = i + 1;
    			break;
    		}
    	}
    	for(int i = po; i < fileIn.length(); i++){
    		result += fileIn.charAt(i);
    	}
        try (
            InputStream inputStream = new FileInputStream(fileIn);
            OutputStream outputStream = new FileOutputStream(result);
        ) {
 
            int bRead;
 
            while ((bRead = inputStream.read()) != -1) {
                outputStream.write(bRead);
            }
 
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
