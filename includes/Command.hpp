/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuhamma <smuhamma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:40:10 by smuhamma          #+#    #+#             */
/*   Updated: 2024/01/19 16:00:30 by smuhamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

#include <string>
#include <iostream>
#include <vector>

class User;
class Channel;

class Command{
	private:
		std::string message;
		std::vector<User>::iterator user_it;
		std::vector<Channel>::iterator chan_it;
	public:
		Command(void);
		~Command(void);

		
		void part(std::string channel, User user);
		void kick(std::string channel, std::string user_kick, const std::vector<std::string>& splitmsg, User user);
		void invite(std::string user, std::string channel, User user_o);
		void notice(std::string reciever, const std::vector<std::string>& splitmsg, User user);
		void privmsg(std::string reciever, const std::vector<std::string>& splitmsg, User user);
		void mode(std::string channel, std::string mode, User user, std::string arg);
		void topic(std::string channel, std::string topic, User user);
		void join(std::string channel_s, std::string key_s, User user); 

		std::vector<std::string> ft_split(std::string str, char delimiter);
		std::vector<User>::iterator user_exist(std::string nick);
		std::vector<Channel>::iterator chan_exist(std::string channel);

};

#endif