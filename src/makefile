
all: server client

server: server.cpp socket.cpp wrap_zmq.cpp tree.cpp 
	g++ server.cpp socket.cpp wrap_zmq.cpp tree.cpp -o server -lpthread -lzmq
	
client: client.cpp socket.cpp wrap_zmq.cpp tree.cpp
	g++ client.cpp socket.cpp wrap_zmq.cpp tree.cpp -o client -lpthread -lzmq
