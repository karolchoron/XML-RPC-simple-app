#!/usr/bin/php

<?php
	$host = "192.168.0.18";
	$port = 12345;
	
	while(1){
	
	# utworzenie gniazda od razu podlaczonego do serwera
	if( ! ( $client = stream_socket_client( "tcp://$host:$port", $errno, $errstr, 5 ) ) ){
		print "stream_socket_client(): $errstr\n";
		exit(1);
	}
	
	$msg = "";
	
	print "Wpisz wiadomosc: ";
        $msg=rtrim(fgets(STDIN), "\n");
        fwrite($client, $msg);
    
		
	# zamkniecie gniazda
	fclose($client);
	//wstrzymuje kod na 1 sec, tak aby serwer (proces 2 java) zdazyl na nowo otworzyc gniazdo
	sleep(1);
	}
?>
