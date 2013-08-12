#ifndef SDATIC_HEADER
#define SDATIC_HEADER

#include <cstdint>
#include <memory>
#include <map>

namespace SDATIC {
	enum TYPE {
		NULLTYPE  = 0,
		UINT8     = 01,
		UINT16    = 02,
		UINT32    = 03,
		UINT64    = 04,

		INT8      = 11,
		INT16     = 12,
		INT32     = 13,
		INT64     = 14,

		FLOAT16   = 22,
		FLOAT32   = 23,
		FLOAT64   = 24,

		U8CHAR    = 31,
		U8STRING  = 41,
		U16CHAR   = 32,
		U16STRING = 42,
		U32CHAR   = 33,
		U32STRING = 43
	};
}

namespace sdatic {
	class variable;

	typedef std::map<std::string, std::shared_ptr<variable>> varmap;

	class variable {
	public:
		variable(SDATIC::TYPE, std::size_t count, char* value);
		SDATIC::TYPE type;
		std::size_t count;
		char* value;

		// ??? get_float16();
		float get_float32();
		double get_float64();

		uint8_t get_uint8();
		uint16_t get_uint16();
		uint32_t get_uint32();

		int8_t get_int8();
		int16_t get_int16();
		int32_t get_int32();

		const char* get_u8char();
		char16_t get_u16char();
		char32_t get_u32char();

		// All strings are NULL terminated
		const char* get_u8string();
		const char16_t* get_u16string();
		const char32_t* get_u32string();
	};

	varmap parse(std::string src);
}

#endif//SDATIC_HEADER
