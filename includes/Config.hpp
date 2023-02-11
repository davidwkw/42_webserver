#ifndef __CONFIG_HPP__
#define __CONFIG_HPP__

#include <fstream>
#include <iostream>
#include <exception>
#include <vector>
#include <set>
#include "Server.hpp"
#include <webserv.hpp>
#include <sstream>

class Config
{
	private:
		// probably replace std::string with ServerConfig class
		// std::vector<Server>	server_configs;

		// Server stuff
		// listen
		// server_name
		// error_page
		// client_max_body_size

		static const std::set<std::string>	directives; 
		std::string							_path;
		std::map<int, Server>				servers;

		Config(void);
		bool _open_file(const std::string &filename, std::ifstream& file);
		void _cache_stream(std::ifstream& file, std::stringstream &cached_stream);
		void _remove_comments(std::stringstream &cached_stream);
		void _parse_server_conf(std::stringstream &cached_stream);

	public:
		~Config(void);
		Config(const Config &ref);
		Config &operator=(const Config &ref);
		Config(const std::string &filename);

		const std::string &path(void) const;

		class UnableToOpenPath : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif
