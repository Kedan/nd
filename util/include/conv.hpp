#pragma once

#include <string>
#include <charconv>
#include <optional>
#include <system_error>
#include <stdexcept>

namespace ns::util {

	template<typename T>
	std::optional<T> numopt(const std::string& s) {
		T v{};
		auto [ptr, ec] = std::from_chars(s.data(), s.data()+s.size(), v);
		if(ec == std::errc() && ptr == s.data() + s.size()) {
			return v;
		}
		return std::nullopt;
	}

	template<typename T>
	T strtonum(const std::string& s) {
		T v{};	
		auto [ptr, ec] = std::from_chars(s.data(), s.data()+s.size(), v);
		if(!(ec == std::errc() && ptr == s.data() + s.size())) {
			throw std::invalid_argument("nudny::util::conv::num() Invalid, non-numeric parameter. Lame.");
		}
		return v;
	}

};
