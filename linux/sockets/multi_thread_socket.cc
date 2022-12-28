// Server side C/C++ program to demonstrate Socket
// programming

/* Hello, Welcome to Socket Programming.
 *
 * In this example, We will write server code to accept multiple client connections at a time.
 *
 * For Every new connection, Server creates new dedicated thread to service the request, 
 * and main thread will be used to accept new connections.
 *
 * Instead of threads, we can also use dedicated linux process using fork() for serving the request.
 *
 */

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include <list>

#define PORT 8080

void read_data(int sock_fd, const std::string &payload) {
    char buffer[1024] = { 0 };
    read(sock_fd, buffer, 1024);
    printf("%s\n", buffer);
    send(sock_fd, payload.c_str(), payload.length(), 0);

    //closing the connected socket
    close(sock_fd);
}

int main(int argc, char const* argv[])
{
	int server_fd; //new_socket;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
        int no_of_connections = 3;
        std::string hello = "Hello from server";
        std::list<std::thread> tlist;

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port 8080
	if (setsockopt(server_fd, SOL_SOCKET,
				SO_REUSEADDR | SO_REUSEPORT, &opt,
				sizeof(opt))) {
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr*)&address,
			sizeof(address))
		< 0) {
            perror("bind failed");
            exit(EXIT_FAILURE);
	}

	if (listen(server_fd, no_of_connections) < 0) {
            perror("listen");
            exit(EXIT_FAILURE);
	}

        int conn_id = 1;
        std::string msg;
        while(true) {
            std::cout << "Waiting for new connection" << std::endl;
            int new_socket;
            if ((new_socket
	            = accept(server_fd, (struct sockaddr*)&address,
		        (socklen_t*)&addrlen))
                           < 0) {
		perror("accept");
		exit(EXIT_FAILURE);
            }
            msg = "Data from Connection " + std::to_string(conn_id);
            std::thread t1(read_data, new_socket, msg);
            tlist.push_back(std::move(t1));
            conn_id += 1;
        }

	// closing the listening socket
	shutdown(server_fd, SHUT_RDWR);
	return 0;
}

