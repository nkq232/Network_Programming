//Nguyễn Khánh Quân 19020400
//Week5 client
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.ServerSocket;
import java.net.*;
import java.io.*;
import java.util.Scanner;
public class client{
	public static void main(String[] args) {
		final String serverHost = "localhost";

		Socket clientSocket = null;
		BufferedReader rd;
		BufferedWriter wt;

		try {
			clientSocket = new Socket(serverHost,8000);
			rd = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
			wt = new BufferedWriter(new OutputStreamWriter(clientSocket.getOutputStream()));
		} catch (UnknownHostException e) {
           System.err.println("Don't know about host " + serverHost);
           return;
       } catch (IOException e) {
           System.err.println("Couldn't get I/O for the connection to " + serverHost);
           return;
       }
       
       	try{
       		while(true){
	       Scanner in = new Scanner(System.in);
	       String message, response, username, userage;
	       System.out.print("Writing message: ");
	 	      message = in.nextLine();
	       wt.write(message);
	       wt.newLine();
	       wt.flush();
	       response = rd.readLine();
	       System.out.println("From server: " + response);
	       if (message.equals("USER INFO")) {
	       	System.out.print("Input your user name: ");
	       	username = in.nextLine();
	       	System.out.print("Input your user age: ");
	       	userage = in.nextLine();
        	String new_message = "{ “User name”: “" + username + "”, “User age”: “" + userage + "”}";
        	wt.write(new_message);
	       	wt.newLine();
	       	wt.flush();
	       	response = rd.readLine();
	       	System.out.println("From server: " + response);
	       }
	       if (message.equals("QUIT")) {
	       	
	       	rd.close();
        	wt.close();
        	clientSocket.close();
        	break;
	       	}
	    	}
    	} catch (UnknownHostException e) {
           System.err.println("Trying to connect to unknown host: " + e);
       } catch (IOException e) {
           System.err.println("IOException:  " + e);
       }
	}
}