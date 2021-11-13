//Nguyễn Khánh Quân 19020400
//Week 5 server
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.ServerSocket;

public class server {
	public static void main(String[] args) {
		ServerSocket listener = null;
		String line;
		BufferedReader rd;
		BufferedWriter wt;
		Socket serverSocket = null;

		try {
			listener = new ServerSocket(8000);
		} catch (IOException e){
			System.out.println(e);
			System.exit(1);
		}
		
	

	try {
		System.out.println("Waiting for client .");
		
		serverSocket = listener.accept();
		System.out.println("Client connect !");
		rd = new BufferedReader(new InputStreamReader(serverSocket.getInputStream()));
		wt = new BufferedWriter(new OutputStreamWriter(serverSocket.getOutputStream()));

		while(true) {
			String input;
			String output;
			input = rd.readLine();
			System.out.println("From client: " + input);
			if (input.equals("HELO Server"))
		{
			/* code */
			output= "200 Hello Client";
			wt.write(output);
			wt.newLine();
			wt.flush();
			System.out.println("Sending to client: 200 Hello Client\n");
		}
			if (input.equals("USER INFO"))
		{
			/* code */
			output= "210 OK";
			wt.write(output);
			wt.newLine();
			wt.flush();
			System.out.println("Sending to client: 210 OK");
			String username = "";
			String userage = "";
			input = rd.readLine();
			int count1 = 0;
			int count2 = 0;
			for (int i = 0; i < input.length(); i++) {
				if (input.charAt(i) == '“') {
					count1 ++;
				}
				if (input.charAt(i) == '”') {
					count2 ++;
				}
				if (count1 == 2 && count2 == 1) {
					username += input.charAt(i);
				}
				if (count1 == 4 && count2 == 3) {
					userage += input.charAt(i);
				}
				if (count2 == 4) {
					break;
				}
			}
			
			username = username.substring(1);
			userage = userage.substring(1);

			System.out.println("From Client: " + input);
			int check = 0;
			for (int i = 0; i < username.length(); i++)
			{
				/* code */
				if (!((username.charAt(i) >= 'A' && username.charAt(i) <= 'Z') || (username.charAt(i) >= 'a' && username.charAt(i) <= 'z')))
				{
					/* code */
					if (username.charAt(i) == '\0' || username.charAt(i) == '\n')
					{
						/* code */
						continue;
					}
					check++;
					break;
				}
			}
			if (check == 0) {
				for (int i = 0; i < userage.length(); ++i)
			{
				/* code */
				if (!(userage.charAt(i) >= '0' && userage.charAt(i) <= '9'))
				{
					/* code */
					if (userage.charAt(i) == '\0' || userage.charAt(i) == '\n')
					{
						/* code */
						continue;
					}
					check++;
					break;
				}
			}
			}
			if (check == 0)
			{
				/* code */
				output = "211 User Info OK";
				wt.write(output);
				wt.newLine();
				wt.flush();
				System.out.println("Sending to client: 211 User Info OK");
			} else {
				output = "400 User Info Error";
				wt.write(output);
				wt.newLine();
				wt.flush();
				System.out.println("Sending to client: 400 User Info Error");
			}
		}
			if (input.equals("QUIT"))
		{
			/* code */
			output= "500 bye";
			wt.write(output);
			wt.newLine();
			wt.flush();
			System.out.println("Sending to client: 500 bye");
			break;
		}
		}
	} catch (IOException e) {
           System.out.println(e);
           e.printStackTrace();
       }
       System.out.println("Server stopped!");
  }
}