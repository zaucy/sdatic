#include <string>
#include <bitset>
#include <cstring>
#include <iostream>

#include "sdatic.h"

#ifdef USE_CXX11_REGEX
#include <regex>
namespace ns_regex = std;
#else
#include <boost/regex.hpp>
namespace ns_regex = boost;
#endif//USE_CXX11_REGEX

static sdatic::variable sdatic_null(SDATIC::TYPE::NULLTYPE, 0, nullptr);
static std::shared_ptr<sdatic::variable> sdatic_nullptr(&sdatic_null);

static sdatic::variable sdcParseLiteral(std::string src) {
	using namespace ns_regex;
	using namespace regex_constants;

	smatch m;
	if(regex_match(src, m, regex("\\\"(.*?)\\\"", ECMAScript | nosubs))) {
		std::string value =  m.str().substr(1, m.str().length()-2);
		char* val =  new char[value.length()];
		value.copy(val, value.length());

		return sdatic::variable(SDATIC::TYPE::U8STRING, 1, val);
	} else
	if(regex_match(src, m, regex("\\d+", ECMAScript | nosubs))) {
		// integer
	} else
	if(regex_match(src, m, regex("\\d+\\.\\d*", ECMAScript | nosubs))) {
		// float
	}

	return sdatic_null;
}

static sdatic::varmap sdcParseEnclosure(std::string) {

}

static sdatic::variable sdcParseValue(std::string src) {

}

sdatic::variable::variable(SDATIC::TYPE type, std::size_t count, char* value) {
	this->type = type;
	this->count = count;
	this->value = value;
}

sdatic::varmap sdatic::parse(std::string src) {
	sdatic::varmap m;
	m.insert({"", sdatic_nullptr});

	using namespace ns_regex;
	using namespace regex_constants;

	smatch sm;
	if(regex_search(src, sm, regex("\\w"))) {

	}

	return m;
}

float sdatic::variable::get_float32() {

	return *reinterpret_cast<float*>(value);
}

double sdatic::variable::get_float64() {

	return *reinterpret_cast<double*>(value);
}

uint8_t sdatic::variable::get_uint8() {

	return *reinterpret_cast<uint8_t*>(value);
}

uint16_t sdatic::variable::get_uint16() {

	return *reinterpret_cast<uint16_t*>(value);
}

uint32_t sdatic::variable::get_uint32() {

	return *reinterpret_cast<uint32_t*>(value);
}

int8_t sdatic::variable::get_int8() {

	return *reinterpret_cast<int8_t*>(value);
}

int16_t sdatic::variable::get_int16() {

	return *reinterpret_cast<int16_t*>(value);
}

int32_t sdatic::variable::get_int32() {

	return *reinterpret_cast<int32_t*>(value);
}

const char* sdatic::variable::get_u8char() {
	return value;
}

char16_t sdatic::variable::get_u16char() {
	return *reinterpret_cast<char16_t*>(value);
}

char32_t sdatic::variable::get_u32char() {
	return *reinterpret_cast<char32_t*>(value);
}

const char* sdatic::variable::get_u8string() {
	return value;
}

const char16_t* sdatic::variable::get_u16string() {
	return reinterpret_cast<char16_t*>(value);
}

const char32_t* sdatic::variable::get_u32string() {
	return reinterpret_cast<char32_t*>(value);
}
