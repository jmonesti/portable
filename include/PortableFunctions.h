#ifndef PORTABLE_FUNCTIONS_H
#define PORTABLE_FUNCTIONS_H

#include <string.h>

/* SunOS / gcc / 32 bits systems */
#ifdef __sun

#endif

/* Linux / gcc / 32 bits systems */
#ifdef __linux

	#include <sys/types.h>
	#include <sys/stat.h>
	#include <unistd.h>

#endif

/* Windows / Visual C++ 6.0 for 32 bits systems */
#ifdef WIN32

	#include <stdio.h>
	#include <io.h>
	#include <direct.h>
	#include <process.h>
	#include <sys/stat.h>

	#define sleep( x )       Sleep( 1000 * (x) )

	#define strcasecmp       _stricmp
	#define strncasecmp      _strnicmp

	#define vsnprintf        _vsnprintf
	#define snprintf         _snprintf
	#define strdup           _strdup

	#define stat             _stat

	#define S_ISDIR( mode )  ( ( (mode) & S_IFMT ) == S_IFDIR )

	#define strtoll          _strtoui64
	#define strtoull         _strtoui64

	#define strtok_r         strtok_s

	#define isatty           _isatty
	#define fileno           _fileno

	#define getcwd           _getcwd

	#define mkdir( a, b )    _mkdir( (a) )

	#define popen            _popen
	#define pclose           _pclose

	#define getpid           _getpid

	#define localtime_r(a,b) memcpy(b, localtime((a)), sizeof(struct tm))

	#define gettimeofday( tv, tz ) \
	{ \
	    FILETIME ft; \
	    __int64 tmpres = 0; \
	    /* TIME_ZONE_INFORMATION tz_winapi; */ \
	    /* int rez = 0; */ \
	    const __int64 DELTA_EPOCH_IN_MICROSECS = 11644473600000000; \
	    \
	    ZeroMemory (&ft, sizeof (ft)); \
	    /* ZeroMemory (&tz_winapi, sizeof (tz_winapi)); */ \
	    \
	    GetSystemTimeAsFileTime (&ft); \
	    \
	    tmpres = ft.dwHighDateTime; \
	    tmpres <<= 32; \
	    tmpres |= ft.dwLowDateTime; \
	    \
	    /*converting file time to unix epoch */ \
	    tmpres /= 10;			/* convert into microseconds */ \
	    tmpres -= DELTA_EPOCH_IN_MICROSECS; \
	    (tv)->tv_sec = (__int32) (tmpres * 0.000001); \
	    (tv)->tv_usec = (tmpres % 1000000); \
	    \
	    /*_tzset(),don't work properly, so we use GetTimeZoneInformation */ \
	    /* rez = GetTimeZoneInformation (&tz_winapi); */ \
	    /* tz->tz_dsttime = (rez == 2) ? true : false; */ \
	    /* tz->tz_minuteswest = tz_winapi.Bias + ((rez == 2) ? tz_winapi.DaylightBias : 0); */ \
	    \
	    /* return 0; */ \
	}

#endif

#endif

