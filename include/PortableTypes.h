#ifndef PORTABLE_TYPES_H
#define PORTABLE_TYPES_H

/* SunOS / gcc / 32 bits systems */
#ifdef __sun

	#include <limits.h>
	#include <inttypes.h>

	/* Basic types */

	typedef unsigned char          uint8;
	typedef unsigned short int     uint16;
	typedef unsigned long int      uint32;
	typedef unsigned long long int uint64;

	typedef   signed char          sint8;
	typedef   signed short int     sint16;
	typedef   signed long int      sint32;
	typedef   signed long long int sint64;

	/* Limits */

	#define UINT8_MIN  0
	#define UINT16_MIN 0
	#define UINT32_MIN 0
	#define UINT64_MIN 0

#if 0
	/* already defined in stdint.h */
	#define UINT8_MAX  UCHAR_MAX
	#define UINT16_MAX USHRT_MAX
	#define UINT32_MAX ULONG_MAX
	#define UINT64_MAX ULLONG_MAX
#endif

	#define SINT8_MIN  INT8_MIN
	#define SINT16_MIN INT16_MIN
	#define SINT32_MIN INT32_MIN
	#define SINT64_MIN INT64_MIN

	#define SINT8_MAX  INT8_MAX
	#define SINT16_MAX INT16_MAX
	#define SINT32_MAX INT32_MAX
	#define SINT64_MAX INT64_MAX

	/* Constant builders */

#if 0
	/* already defined in stdint.h */
	#define UINT8_C(c)  UINT8_C(c)
	#define UINT16_C(c) UINT16_C(c)
	#define UINT32_C(c) UINT32_C(c)
	#define UINT64_C(c) UINT64_C(c)
#endif

	#define SINT8_C(c)  INT8_C(c)
	#define SINT16_C(c) INT16_C(c)
	#define SINT32_C(c) INT32_C(c)
	#define SINT64_C(c) INT64_C(c)

	/* C printf format strings */

	#define STRING_CFORMAT(f)  "%" f "s"

	#define POINTER_CFORMAT(f)  "0x%" f "p"

	#define INT8_CFORMAT(f)   "%" f "d"
	#define INT16_CFORMAT(f)  "%" f "hd"
	#define INT32_CFORMAT(f)  "%" f "ld"
	#define INT64_CFORMAT(f)  "%" f "lld"
	#define INT_CFORMAT(f)    "%" f "d"

	#define UINT8_CFORMAT(f)  "%" f "u"
	#define UINT16_CFORMAT(f) "%" f "hu"
	#define UINT32_CFORMAT(f) "%" f "lu"
	#define UINT64_CFORMAT(f) "%" f "llu"
	#define UINT_CFORMAT(f)   "%" f "u"

	#define SINT8_CFORMAT(f)  "%+" f "d"
	#define SINT16_CFORMAT(f) "%+" f "hd"
	#define SINT32_CFORMAT(f) "%+" f "ld"
	#define SINT64_CFORMAT(f) "%+" f "lld"
	#define SINT_CFORMAT(f)   "%+" f "d"

	#define XINT8_CFORMAT(f)  "0x%" f "x"
	#define XINT16_CFORMAT(f) "0x%" f "hx"
	#define XINT32_CFORMAT(f) "0x%" f "lx"
	#define XINT64_CFORMAT(f) "0x%" f "llx"
	#define XINT_CFORMAT(f)   "0x%" f "x"

	#define OINT8_CFORMAT(f)  "0%" f "o"
	#define OINT16_CFORMAT(f) "0%" f "ho"
	#define OINT32_CFORMAT(f) "0%" f "lo"
	#define OINT64_CFORMAT(f) "0%" f "llo"
	#define OINT_CFORMAT(f)   "0%" f "o"

#endif

/* Linux / gcc / 32 bits systems */
#ifdef __linux

	#if !defined(__STDC_CONSTANT_MACROS)
	#define __STDC_CONSTANT_MACROS 1
	#endif

	#if !defined(__STDC_LIMIT_MACROS)
	#define __STDC_LIMIT_MACROS 1
	#endif

	#include <limits.h>
	#include <stdint.h>

	/* Basic types */

	typedef unsigned char          uint8;
	typedef unsigned short int     uint16;
	typedef unsigned long int      uint32;
	typedef unsigned long long int uint64;
	typedef unsigned int           uint;

	typedef   signed char          sint8;
	typedef   signed short int     sint16;
	typedef   signed long int      sint32;
	typedef   signed long long int sint64;
	typedef   signed int           sint;

	/* Limits */

	#define UINT8_MIN  0
	#define UINT16_MIN 0
	#define UINT32_MIN 0
	#define UINT64_MIN 0

#if 0
	/* already defined in stdint.h */
	#define UINT8_MAX  UCHAR_MAX
	#define UINT16_MAX USHRT_MAX
	#define UINT32_MAX ULONG_MAX
	#define UINT64_MAX ULLONG_MAX
#endif

	#define SINT8_MIN  INT8_MIN
	#define SINT16_MIN INT16_MIN
	#define SINT32_MIN INT32_MIN
	#define SINT64_MIN INT64_MIN

	#define SINT8_MAX  INT8_MAX
	#define SINT16_MAX INT16_MAX
	#define SINT32_MAX INT32_MAX
	#define SINT64_MAX INT64_MAX

	/* Constant builders */

#if 0
	/* already defined in stdint.h */
	#define UINT8_C(c)  UINT8_C(c)
	#define UINT16_C(c) UINT16_C(c)
	#define UINT32_C(c) UINT32_C(c)
	#define UINT64_C(c) UINT64_C(c)
#endif

	#define SINT8_C(c)  INT8_C(c)
	#define SINT16_C(c) INT16_C(c)
	#define SINT32_C(c) INT32_C(c)
	#define SINT64_C(c) INT64_C(c)

	/* C printf format strings */

	#define STRING_CFORMAT(f)  "%" f "s"

	#define POINTER_CFORMAT(f)  "%" f "p"

	#define INT8_CFORMAT(f)   "%" f "d"
	#define INT16_CFORMAT(f)  "%" f "hd"
	#define INT32_CFORMAT(f)  "%" f "ld"
	#define INT64_CFORMAT(f)  "%" f "lld"
	#define INT_CFORMAT(f)    "%" f "d"

	#define UINT8_CFORMAT(f)  "%" f "u"
	#define UINT16_CFORMAT(f) "%" f "hu"
	#define UINT32_CFORMAT(f) "%" f "lu"
	#define UINT64_CFORMAT(f) "%" f "llu"
	#define UINT_CFORMAT(f)   "%" f "u"

	#define SINT8_CFORMAT(f)  "%+" f "d"
	#define SINT16_CFORMAT(f) "%+" f "hd"
	#define SINT32_CFORMAT(f) "%+" f "ld"
	#define SINT64_CFORMAT(f) "%+" f "lld"
	#define SINT_CFORMAT(f)   "%+" f "d"

	#define XINT8_CFORMAT(f)  "0x%" f "x"
	#define XINT16_CFORMAT(f) "0x%" f "hx"
	#define XINT32_CFORMAT(f) "0x%" f "lx"
	#define XINT64_CFORMAT(f) "0x%" f "llx"
	#define XINT_CFORMAT(f)   "0x%" f "x"

	#define OINT8_CFORMAT(f)  "0%" f "o"
	#define OINT16_CFORMAT(f) "0%" f "ho"
	#define OINT32_CFORMAT(f) "0%" f "lo"
	#define OINT64_CFORMAT(f) "0%" f "llo"
	#define OINT_CFORMAT(f)   "0%" f "o"

#endif

/* Windows / Visual C++ 6.0 / 32 bits systems */
#ifdef WIN32

	#include <limits.h>

	/* Basic types */

	typedef unsigned __int8  uint8;
	typedef unsigned __int16 uint16;
	typedef unsigned __int32 uint32;
	typedef unsigned __int64 uint64;

	typedef   signed __int8  sint8;
	typedef   signed __int16 sint16;
	typedef   signed __int32 sint32;
	typedef   signed __int64 sint64;

	/* Limits */

	#define UINT8_MIN  0
	#define UINT16_MIN 0
	#define UINT32_MIN 0
	#define UINT64_MIN 0

	#define UINT8_MAX  UCHAR_MAX
	#define UINT16_MAX USHRT_MAX
	#define UINT32_MAX ULONG_MAX
	#define UINT64_MAX 18446744073709551615

	#define SINT8_MIN  SCHAR_MIN
	#define SINT16_MIN SHRT_MIN
	#define SINT32_MIN LONG_MIN
	#define SINT64_MIN (-9223372036854775807-1)

	#define SINT8_MAX  SCHAR_MAX
	#define SINT16_MAX SHRT_MAX
	#define SINT32_MAX LONG_MAX
	#define SINT64_MAX (9223372036854775807)

	/* Constant builders */

	#define UINT8_C(c)  ((uint8 )(c))
	#define UINT16_C(c) ((uint16)(c))
	#define UINT32_C(c) ((uint32)(c))
	#define UINT64_C(c) ((uint64)(c))

	#define SINT8_C(c)  ((sint8 )(c))
	#define SINT16_C(c) ((sint16)(c))
	#define SINT32_C(c) ((sint32)(c))
	#define SINT64_C(c) ((sint64)(c))

	/* C printf format strings */

	#define STRING_CFORMAT(f)  "%" f "s"

	#define POINTER_CFORMAT(f)  "0x%" f "x"

	#define INT8_CFORMAT(f)   "%" f "d"
	#define INT16_CFORMAT(f)  "%" f "hd"
	#define INT32_CFORMAT(f)  "%" f "ld"
	#define INT64_CFORMAT(f)  "%" f "I64d"
	#define INT_CFORMAT(f)    "%" f "d"

	#define UINT8_CFORMAT(f)  "%" f "u"
	#define UINT16_CFORMAT(f) "%" f "hu"
	#define UINT32_CFORMAT(f) "%" f "lu"
	#define UINT64_CFORMAT(f) "%" f "I64u"
	#define UINT_CFORMAT(f)   "%" f "u"

	#define SINT8_CFORMAT(f)  "%+" f "d"
	#define SINT16_CFORMAT(f) "%+" f "hd"
	#define SINT32_CFORMAT(f) "%+" f "ld"
	#define SINT64_CFORMAT(f) "%+" f "I64d"
	#define SINT_CFORMAT(f)   "%+" f "d"

	#define XINT8_CFORMAT(f)  "0x%" f "x"
	#define XINT16_CFORMAT(f) "0x%" f "hx"
	#define XINT32_CFORMAT(f) "0x%" f "lx"
	#define XINT64_CFORMAT(f) "0x%" f "I64x"
	#define XINT_CFORMAT(f)   "0x%" f "x"

	#define OINT8_CFORMAT(f)  "0%" f "o"
	#define OINT16_CFORMAT(f) "0%" f "ho"
	#define OINT32_CFORMAT(f) "0%" f "lo"
	#define OINT64_CFORMAT(f) "0%" f "I64o"
	#define OINT_CFORMAT(f)   "0%" f "o"

#endif

#endif
