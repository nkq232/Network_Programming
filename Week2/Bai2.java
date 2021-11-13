// Nguyễn Khánh Quân 19020400 
// Bài 2
// Viết chương trình nhập tên file cần tạo mới và các chuỗi ký tự từ bàn phím cho đến khi nhập ký tự kết thúc (tự định nghĩa). 
// Lưu các chuỗi ký tự đã nhập vào file được tạo mới và xuất kích thước file ra màn hình.
import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.File;

public class Main {
    public static void main(String[]args){
        String fileOut;
        Scanner sc = new Scanner(System.in);
        System.out.println("Nhập tên file tạo mới (Nhập cả đuôi): ");
        fileOut = sc.nextLine();
        System.out.println("Nhập đến kí tự kết thúc '`' : ");
        String a;
        String output = "";
        boolean check = true;
        while(check) {
            a = sc.nextLine();
            for (int i = 0; i < a.length() ; i++) {
                if (a.charAt(i) == '`') {
                    check = false;
                    break;
                }
                output += a.charAt(i);
            }
        }
        try {
        File file = new File(fileOut);
        FileWriter fw = new FileWriter(fileOut);
        BufferedWriter bw = new BufferedWriter(fw);
        for(int b = 0; b < output.length(); b++)
        bw.write(output.charAt(b));
        bw.close();
        System.out.println("Độ dài file output: " + file.length());
    } catch (Exception e){
        System.out.println(e.getMessage());
    }

    }
}