/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuhamma <smuhamma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:40:32 by smuhamma          #+#    #+#             */
/*   Updated: 2024/01/26 16:14:19 by smuhamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class User;

namespace Utils {

	User &find(int fd);
	void closeThis(User &user);
	void signalHandler(int signum);
    std::string to_string(int value);
	std::string trim(std::string &str);
	std::vector<std::string> split(const std::string str);
}

#endif