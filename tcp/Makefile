all:server client
server:socket_server.o
	g++ -g -o socket_server socket_server.o
client:socket_client.o
	g++ -g -o socket_client socket_client.o
socket_server.o:socket_server.cpp
	g++ -g -c socket_server.cpp
socket_client.o:socket_client.cpp
	g++ -g -c socket_client.cpp
clean:all
	rm *.o socket_server socket_client
