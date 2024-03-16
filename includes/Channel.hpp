/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:11:05 by abalhamm          #+#    #+#             */
/*   Updated: 2024/01/26 16:11:06 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

# define OP_ERR_M "Permission Denied- You're not an operator of the channel.\n"
# define NO_USR_M " :No such nickname\n"
# define NO_CHAN_M " :No such channel.\n"
# define MODE_ERR_M " :is unknown mode char to me.\n"
# define NOT_CHAN_USR " :Cannot send to channel.\n"
# define NO_KEY_M " :Cannot join channel (+k).\n"
# define NO_INV_M " :Cannot join channel (+i).\n"
# define YES_USR_M " :is already on channel\n"
# define INVALID_CHAN "Error: Invalid Channel Name. Channel name starts with \'#\' or \'&\'\n"
# define INVALID_CHAN_NAME "Error: Invalid Channel Name. Channel should have more than one character\n"
# define CHAN_FULL "  :Cannot join channel (+l)\n"
# define NOT_USER_M "  :You're not on that channel\n"

class User;

class Channel{
	private:
		int user_limit;
		std::string topic;
		std::string pass;
		std::map<char, int> mode;
		Channel(void); //default
	public:
	
	std::string name;
	std::vector<User> operators;
	std::vector<User> invites;
	std::vector<User> users;
	std::string message;
	std::vector<User>::iterator it_i;
	std::vector<User>::iterator it_o;
	std::vector<User>::iterator it_u;
	Channel(std::string str_n, std::string str_p);
	~Channel(void);

	void setPass(std::string str);
	void setUserLimit(int num); 
	void setMode(char m, char sign);
	void setTopic(std::string str);

	int getUserLimit(void); 
	std::string getPass(void);
	std::string getTopic(void);
	std::vector<User> getUsers(void);
	std::string getName(void) const;
	std::vector<User> getOperators(void);
	std::map<char, int> getMode(void);
	
	int isOperator(User user);
	int isMode(char m);
	int isInvited(User user);
	int isUser(User user);
	
	int user_len(void);
	void addUser(User new_user);
	std::vector<User>::iterator user_in_chan(int fd);
	void exec_mode(std::string mode, User &user, std::string arg);
	std::vector<User>::iterator inv_in_chan(int fd);
	std::vector<User>::iterator op_in_chan(int fd);
	void kickUser(std::string user_kick, const std::vector<std::string>& splitmsg, User user);
	
};
# endif
