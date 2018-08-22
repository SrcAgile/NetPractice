import socket

UDP_IP = "127.0.0.2"
UDP_PORT = 9999
MESSAGE = "HI WHAT'S UP"

#Construct udp socket
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

sock.sendto(MESSAGE,(UDP_IP,UDP_PORT))
