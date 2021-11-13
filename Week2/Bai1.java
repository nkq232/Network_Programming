// Nguyễn Khánh Quân 19020400 
// Bài 1
// Viết chương trình nhập chuỗi ký tự từ bàn phím và xuất ra số ký tự là chữ cái, số ký tự là số và số ký tự là các ký hiệu.
import java.util.Scanner;
public class Main {
	public static void main(String[]args){
		int letter = 0;
		int number = 0;
		int symbol = 0;
		String a;
		Scanner sc = new Scanner(System.in);
		a = sc.nextLine();
		for (int i=0; i<a.length(); i++) {
			if ( (65 <= a.charAt(i) && a.charAt(i) <= 90) || (a.charAt(i) >= 97 && a.charAt(i) <= 122) )
		{
			/* code */
			letter++;

		} else if (a.charAt(i) <= 57 && a.charAt(i) >= 48)
		{
			/* code */
			number ++;
		} else {
			symbol ++;
		}
		}
		System.out.println("Chữ cái: " + letter + "   Số: " + number + "   Kí hiệu:  " + symbol);
	}
}