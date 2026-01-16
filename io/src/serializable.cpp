#include <io/serializable.hpp>

namespace nd::io {
	nlohmann::json& Serializable::getSerialized() {
		return m_jsonData;
	};
	
	const nlohmann::json& Serializable::getSerialized() const {
		return m_jsonData;
	};
} // namespace nd::io
