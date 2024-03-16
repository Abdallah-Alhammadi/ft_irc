/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User_Commands.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:40:24 by smuhamma          #+#    #+#             */
/*   Updated: 2024/01/26 16:11:22 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <stdlib.h>
#include "Command.hpp"
#include <vector>
#include <algorithm>
#include <string>
#include "Utils.hpp"
#include <cstring>

#define JOIN "JOIN"
#define PART "PART"
#define KICK "KICK"
#define NOTICE "NOTICE"
#define INVITE "INVITE"
#define PRIVMSG "PRIVMSG"
#define TOPIC "TOPIC"
#define WHOIS "WHOIS"
#define PING "PING"
#define MODE "MODE"
#define PONG "TOPIC"
#define UNKNOWN_CMD "421"
#define ERR_NICKCOLLISION "436"
#define WRONG_PASS_CODE "464"
#define PRIVMSG_EMPTY "412"
#define NICKNAME_IN_USE "433"
#define ERR_NOSUCHCHANNEL "403"
#define ERR_CANNOTSENDTOCHAN "404"
#define ERR_NOSUCHNICK "401"
#define TOO_MANY_ARGS "461"
#define ERR_NOTREGISTERED "451"
#define ERR_TOOMANYCHANNELS "405"
#define ERR_NOTONCHANNEL "442"
#define ERR_INVITEONLYCHAN "473"
#define ERR_UNKNOWNMODE "472"
#define ERR_CHANOPRIVSNEEDED "482"
#define ERR_BADCHANNELKEY "475"
#define ERR_UNKNOWNCOMMAND "421"
#define ERR_CHANNELISFULL "471"
#define ERR_ALREADYREGISTRED "462"
#define ERR_NEEDMOREPARAMS "461"
#define ERR_INVALIDKEY "525"
#define ERR_USERONCHANNEL "443"


class User {
   public:
    User(int fd, int id);
    ~User();

    std::string input;

    int _fd;
    int _id;
	int pass_issue;
	int alr_reg;
    bool isAuth;
    bool isOperator;
	bool change_flag;
	bool is_registered;
    std::string userName;
    std::string nickName;
	std::string pass;
	std::vector<std::string> _cmd;

    void userErase(User &user);
    bool	parse_cmd(std::string str);
    void execute(std::string cmd, User *it);
    friend std::ostream& operator<<(std::ostream& os, const User& user);
    bool operator==(const User& other) const {
        return (this->_fd == other._fd);
    }
	int	authorise(User *user, std::string cmd);
    void change_user(User *user, std::vector<std::string> splitmsg);
	void	user_cmds(User *user, std::vector<std::string> splitmsg);
	bool	user_options(User *user, std::vector<std::string> splitmsg);

};

void noticeCommand(const std::vector<std::string>& splitmsg, Command& cmd, User* user);
void joinCommand(const std::vector<std::string>& splitmsg, Command& cmd, User* user);
void inviteCommand(const std::vector<std::string>& splitmsg, Command& cmd, User* user);
void kickCommand(const std::vector<std::string>& splitmsg, Command& cmd, User* user);
void privMsgCommand(const std::vector<std::string>& splitmsg, Command& cmd, User* user);
void topicCommand(const std::vector<std::string>& splitmsg, Command& cmd, User* user);
void whoisCommand(const std::vector<std::string>& splitmsg, Command& cmd, User* user);
void sendErrorMessage(int fd, const std::string& message, const std::string& key);
void partCommand(const std::vector<std::string>& splitmsg, Command& cmd, User* user);
void modeCommand(const std::vector<std::string>& splitmsg, Command& cmd, User* user);

#endif

