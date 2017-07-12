#ifndef PORTABLE_DLL_H
#define PORTABLE_DLL_H

#ifdef __cplusplus
extern "C" {
#endif

/* SunOS / gcc / 32 bits systems */
/* Linux / gcc / 32 bits systems */
#if defined( __sun ) || defined( __linux )

	#include <dlfcn.h>

	typedef void * PTBL_DllHandle;

	#define PTBL_DLL_OPEN( _ptbl_dll_handle_, _ptbl_name_ ) \
	    ( ( _ptbl_dll_handle_ ) = dlopen( _ptbl_name_, RTLD_LAZY ) )

	#define PTBL_DLL_GET_SYMBOL( _ptbl_dll_handle_, _ptbl_pointer_, _ptbl_name_ ) \
	    ( ( _ptbl_pointer_ ) = dlsym( _ptbl_dll_handle_, _ptbl_name_ ) )

	#define PTBL_DLL_GET_TYPED_SYMBOL( _ptbl_dll_handle_, _ptbl_pointer_, _ptbl_name_, _ptbl_type_ ) \
	    ( ( _ptbl_pointer_ ) = ( _ptbl_type_ )dlsym( _ptbl_dll_handle_, _ptbl_name_ ) )

	#define PTBL_DLL_CLOSE( _ptbl_dll_handle_ ) \
	    dlclose( _ptbl_dll_handle_ )
	
	#define PTBL_DLL_GET_ERROR( _ptbl_msg_ ) \
	    ( ( _ptbl_msg_ ) = dlerror( ) )

/* Windows / Visual C++ 6.0 / 32 bits systems */
#elif defined( WIN32 )

	#include <windows.h>

	typedef HINSTANCE PTBL_DllHandle;

	static char dll_error_message[1024];

	#define PTBL_DLL_OPEN( _ptbl_dll_handle_, _ptbl_name_ ) \
	    ( ( _ptbl_dll_handle_ ) = LoadLibrary( _ptbl_name_ ) )

	#define PTBL_DLL_GET_SYMBOL( _ptbl_dll_handle_, _ptbl_pointer_, _ptbl_name_ ) \
	    ( ( _ptbl_pointer_ ) = GetProcAddress( _ptbl_dll_handle_, _ptbl_name_ ) )

	#define PTBL_DLL_GET_TYPED_SYMBOL( _ptbl_dll_handle_, _ptbl_pointer_, _ptbl_name_, _ptbl_type_ ) \
	    ( ( _ptbl_pointer_ ) = ( _ptbl_type_ )GetProcAddress( _ptbl_dll_handle_, _ptbl_name_ ) )

	#define PTBL_DLL_CLOSE( _ptbl_dll_handle_ ) \
	    ( ! FreeLibrary( _ptbl_dll_handle_ ) )

	#define PTBL_DLL_GET_ERROR( _ptbl_msg_ ) { \
	    FormatMessage( FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError( ), MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ), ( LPTSTR )dll_error_message, 128, NULL ); \
	    ( _ptbl_msg_ ) = dll_error_message; \
	}

#else

	#error PORTABLE_DLL_H

#endif

#ifdef __cplusplus
}
#endif

#endif
