CFLAGS = -O2 -Wall
LDFLAGS = -s
CC = gcc
LD = ld
MAKE = make

CLIENT_CFLAGS=`xmlrpc-c-config  libwww-client --cflags`
CLIENT_LDFLAGS=`xmlrpc-c-config libwww-client --libs`

SERVER_CFLAGS=`xmlrpc-c-config  abyss-server --cflags`
SERVER_LDFLAGS=`xmlrpc-c-config abyss-server --libs`

all: server client

#server: server.c
#	$(CC) $(CFLAGS) -c $<
#	$(CC) $(LDFLAGS) $< -o $@

client: client.c
	$(CC) $(CLIENT_CFLAGS)	$(CFLAGS)  -c $<
	$(CC) $(CLIENT_LDFLAGS)	$(LDFLAGS) $< -o $@

server: server.c
	$(CC) $(SERVER_CFLAGS)	$(CFLAGS)  -c $<
	$(CC) $(SERVER_LDFLAGS)	$(LDFLAGS) $< -o $@

clean:
	rm -f client server *.o 

