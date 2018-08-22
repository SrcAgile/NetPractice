import socket

UDP_IP = "127.0.0.2"
UDP_PORT = 9999

sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

#BIND SOCKET
sock.bind((UDP_IP,UDP_PORT))

while True:
	data,addr = sock.recvfrom(1024)
	print "[Recieve Message]", data
