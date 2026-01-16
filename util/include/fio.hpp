#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>

namespace ns::io {

	class Serializable {
		public:
			virtual bool serialize() = 0;
			virtual bool deserialize(nlohmann::json t_data) = 0;
			virtual nlohmann::json getSerialized() {
				return m_jsonData;
			};
		protected:
			nlohmann::json m_jsonData;
	};
		
	template<typename T>
	int load(T& t_obj, const std::string& t_filename) {
		std::ifstream file(t_filename, std::ios::binary);
		if(!file.is_open()) 
			return 1;
		std::vector<uint8_t> buffer((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
		nlohmann::json data = nlohmann::json::from_cbor(buffer);
		t_obj.deserialize(data);
		return 0;
	};

	template<typename T>
	int save(T& t_obj, const std::string& t_filename) {
		std::ofstream file(t_filename, std::ios::binary);
		if(file.is_open() && t_obj.serialize()) {
			nlohmann::json j = t_obj.getSerialized();
			std::vector<uint8_t> cbor = nlohmann::json::to_cbor(j);
			file.write(reinterpret_cast<const char*>(cbor.data()), cbor.size());
			file.close();
			return 0;
		}
		return 1;
	};

};
