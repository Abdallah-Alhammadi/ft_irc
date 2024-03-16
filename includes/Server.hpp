/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:40:16 by smuhamma          #+#    #+#             */
/*   Updated: 2024/01/26 16:11:09 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include "User_Commands.hpp"
#include "Channel.hpp"
#include "Utils.hpp"
#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <fcntl.h>
#include <cerrno>
#include <iomanip>
#include <signal.h>
#include <stdint.h>
#include <unistd.h>

#define MAX_PORT UINT16_MAX
#define MAX_HOST_NAME 512
#define MAX_BUFFER 1024


class Channel;
class User;
class Server
{
private:
	Server(void);

public:
	static const int MAX_CLIENTS = FD_SETSIZE;
	static const int BUFFER_SIZE = MAX_BUFFER;
	static std::string _password;
	static std::string _hostName;
	static std::string bufferStr;
	static int sd;
	static int _port;
	static int valread;
	static int max_sd;
	static int addrlen;
	static int newSocket;
	static int curIndex;
	static int serverSocket;
	static char c_buffer[MAX_BUFFER];
	static char c_hostName[MAX_HOST_NAME];
	static fd_set readfds;
	static struct sockaddr_in address;
	static std::vector<int> _fds;
	static std::vector<User> _users;
	static std::vector<Channel> _channels;
	static void run(void);
	static void openSocket(void);
	static void acceptConnection(void);
	static std::string getPassword(void);
	static void clientMessages(void);
	
	class ServerException : public std::exception
	{
		private:
			std::string _msg;
		public:
			ServerException(std::string msg) : _msg(msg) {}
			virtual ~ServerException() throw() {}
			virtual const char *what() const throw() { return _msg.c_str(); }
	};
};

#endif