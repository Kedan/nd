#pragma once
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>

namespace nd::util {

	class CliParser {
		public:
			CliParser() = default;
			CliParser(int t_argc, char* t_argv[]);
			~CliParser() = default;

			void parse(int t_argc, char* t_argv[]);	
			std::string get(const std::string& t_key) const;
			std::string get(int idx) const;
			const nlohmann::json& getJson() const;
			const nlohmann::json& get(void) const;
			bool exist(const std::string& key) const;
			bool exist(int idx) const;
			std::string operator()(const std::string& t_key) const;
			std::string operator()(int t_index) const;
		protected:
			nlohmann::json m_data;
	}; // class CliParser
	
	class Commander {
		public:
			void setCli(const std::shared_ptr<CliParser>& t_cli);
			void setCli(const CliParser& t_cli);
			const std::shared_ptr<CliParser>& cli(void) const;
			std::string cli(const std::string&) const;
			std::string cli(int i) const;
		protected:
			void check() const;
			std::shared_ptr<CliParser> m_cli;
	}; // class Commander

}; // namespace nd::util
