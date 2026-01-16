#pragma once
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>

namespace ns::util {

	class Parser {
		public:
			Parser() = default;
			Parser(int t_argc, char* t_argv[]) {
				parse(t_argc, t_argv);
			}	
			~Parser() = default;

			void parse(int t_argc, char* t_argv[]) {
				for(int i=1; i<t_argc; i++) {
					std::string arg = t_argv[i];
					if(arg.rfind("--")==0 && i + 1 < t_argc) {
						std::string key = arg.substr(2);
						std::string val = t_argv[++i];
						m_data[key] = val;
					} else {
						m_data["positional"].push_back(t_argv[i]);
					}
				}
			}
			
			std::string get(const std::string& t_key) {
				return m_data[t_key];
			}

			std::string get(int idx) {
				return m_data["positional"][idx];
			}

			nlohmann::json getJson() const { 
				return m_data;
			}

			nlohmann::json get(void) const {
				return getJson();
			}

			bool exist(const std::string& key) const {
				return m_data.contains(key);
			}

			bool exist(int idx) const {
				return m_data["positional"].size() < idx;
			}
		protected:
			nlohmann::json m_data;
	};

};
