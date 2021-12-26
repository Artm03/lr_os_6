#include <iostream>
#include <stdexcept>
#include "wrap_zmq.h"
#include "socket.h"

using namespace std;

Socket::Socket(void* context, SocketType new_socket_type, string new_endpoint) 
: socket_type(new_socket_type), endpoint(new_endpoint) {
    socket = create_zmq_socket(context, new_socket_type);
    switch (socket_type) {
        case SocketType::PUBLISHER:
            bind_zmq_socket(socket, new_endpoint);
            break;
        case SocketType::SUBSCRIBER:
            connect_zmq_socket(socket, new_endpoint);
            break;
        default:
            throw logic_error("Undefined connection type");
    }
}

Socket::~Socket() {
    try {
        switch(socket_type){
            case SocketType::PUBLISHER:
                cout << "unbind: " << endpoint << endl;
                unbind_zmq_socket(socket, endpoint);
                break;
            case SocketType::SUBSCRIBER:
                cout << "disconnect: " << endpoint << endl; 
                disconnect_zmq_socket(socket, endpoint);
                break;
        }
        close_zmq_socket(socket);
    } catch (exception& ex) {
        cout << "Socket wasn't closed: " << ex.what() << endl;
    }
}

void Socket::send(Message message) {
    if (socket_type == SocketType::PUBLISHER) {
        send_zmq_msg(socket, message);
    } else {
        throw logic_error("SUB socket can't send messages");
    }
}

Message Socket::receive() {
    if (socket_type == SocketType::SUBSCRIBER) {
        return get_zmq_msg(socket);
    } else {
        throw logic_error("PUB socket can't receive messages");
    }
}

void Socket::subscribe(string new_endpoint) {
    if (socket_type == SocketType::SUBSCRIBER) {
        connect_zmq_socket(socket, new_endpoint);
        endpoint = new_endpoint;
    } else {
        throw logic_error("Subscribe is only for SUB sockets");
    }
}

string Socket::get_endpoint() {
    return endpoint;
}

void*& Socket::get_socket(){
    return socket;
}
