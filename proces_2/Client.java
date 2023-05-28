import java.util.*;
import org.apache.xmlrpc.*;
import java.util.Scanner;
import java.io.*;
import java.net.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;



public class Client {

	public static void main (String [] args) {
	

	while(true){
	
	int 	port = 1234;
	String 	host = "127.0.0.1";
    
    int port_sock = 12345;
	String host_sock = "192.168.0.18";
	
	ServerSocket serverSocket;
	Socket connection = null;
	DataInputStream in;
	InputStream inputStream;
    String message = "";
    
    Vector params = new Vector();
		
            try{
			// utworzenie nowego gniazda
			serverSocket = new ServerSocket( port_sock, 5 );
			
			// akceptacja polaczenia
			connection = serverSocket.accept();
			
			// wyswietlenie informacji o polaczenii
			System.out.println("Address: " + connection.getInetAddress() + " Port: " + connection.getPort() );
			
			// Otworz strumien wejściowy do odczytu danych wyslanych przez klienta (proces 1)
            BufferedReader input = new BufferedReader(new InputStreamReader(connection.getInputStream()));
            // Odczytaj dane przeslane przez klienta
            message = input.readLine();
            System.out.println("Przekazywana wiadomosc: " + message);

			serverSocket.close();		
            
			
		}
		catch(IOException ioException){
			ioException.printStackTrace();
		}
		
		try {
            XmlRpcClient server = new XmlRpcClient( "http://"+host+":"+port+"/RPC2" ); 
			String zmiennaWejsciowa = message;

				params.addElement(zmiennaWejsciowa);

				Object result = server.execute( "sample.add", params );
				
				params.clear();
			
        }
        catch( Exception exception ){
			System.err.println( "Client: " + exception );
		}
				
    }
	}
}