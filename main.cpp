/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:38:49 by smuhamma          #+#    #+#             */
/*   Updated: 2024/01/26 16:10:53 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Server.hpp"

int main(int argc, char *argv[])
{
	if (argc == 3) {

		int port_num = std::atoi(argv[1]);
		std::string	port(argv[1]), password(argv[2]);
		if (port.empty() || password.empty() || port_num > MAX_PORT \
			|| port.length() > 5 || port.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cerr << "Error: invalid arguments !" << std::endl;
			return 1;
		}

		signal( SIGINT, Utils::signalHandler );
	    signal( SIGQUIT, Utils::signalHandler );
		
		try
		{
			Server::_port = port_num;
			Server::_password = password;
			Server::openSocket();
			Server::run();
		} catch(const std::exception& e) {
			std::cerr << "Exception: " << e.what()  << '\n';
		}
	}
	else
	{
		std::cerr << "Usage: ./ircserv [port] [PASS]" << std::endl;
		return (1);
	}
	
	return 0;
}