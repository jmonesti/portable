#ifndef PORTABLE_THREAD_H
#define PORTABLE_THREAD_H

/* SunOS / gcc / 32 bits systems */
#if defined( __sun )

	#include <pthread.h>

	typedef pthread_attr_t PTBL_ThreadAttributes;

	typedef pthread_t      PTBL_ThreadHandle;

	#define PTBL_THREAD_ATTRIBUTES_OPEN( _ptbl_thread_attributes_ ) \
	    pthread_attr_init( _ptbl_thread_attributes_ )

	#define PTBL_THREAD_ATTRIBUTES_CLOSE( _ptbl_thread_attributes_ ) \
	    pthread_attr_destroy( _ptbl_thread_attributes_ )

	#define PTBL_THREAD_CREATE( _ptbl_thread_, _ptbl_thread_attributes_, _ptbl_thread_function_, _ptbl_thread_arguments_ ) \
	    ( pthread_create( _ptbl_thread_, _ptbl_thread_attributes_, _ptbl_thread_function_, ( void * )_ptbl_thread_arguments_ ) == 0 )

	#define PTBL_THREAD_EXIT( _ptbl_thread_exit_code_ ) \
	    pthread_exit( ( void * )_ptbl_thread_exit_code_ )

	#define PTBL_THREAD_JOIN( _ptbl_thread_ ) \
	    pthread_join( * ( _ptbl_thread_ ), NULL )

/* Linux / gcc / 32 bits systems */
#elif defined( __linux )

	#include <pthread.h>

	typedef pthread_attr_t PTBL_ThreadAttributes;

	typedef pthread_t      PTBL_ThreadHandle;

	#define PTBL_THREAD_ATTRIBUTES_OPEN( _ptbl_thread_attributes_ ) \
	    pthread_attr_init( _ptbl_thread_attributes_ )

	#define PTBL_THREAD_ATTRIBUTES_CLOSE( _ptbl_thread_attributes_ ) \
	    pthread_attr_destroy( _ptbl_thread_attributes_ )

	#define PTBL_THREAD_CREATE( _ptbl_thread_, _ptbl_thread_attributes_, _ptbl_thread_function_, _ptbl_thread_arguments_ ) \
	    ( pthread_create( _ptbl_thread_, _ptbl_thread_attributes_, _ptbl_thread_function_, ( void * )_ptbl_thread_arguments_ ) == 0 )

	#define PTBL_THREAD_EXIT( _ptbl_thread_exit_code_ ) \
	    pthread_exit( ( void * )_ptbl_thread_exit_code_ )

	#define PTBL_THREAD_JOIN( _ptbl_thread_ ) \
	    pthread_join( * ( _ptbl_thread_ ), NULL )

/* Windows / Visual C++ 6.0 / 32 bits systems */
#elif defined( WIN32 )

	#include <process.h>
	#include <windows.h>

	typedef SECURITY_ATTRIBUTES PTBL_ThreadAttributes;

	typedef struct PTBL_Thread { DWORD id; HANDLE handle; } PTBL_ThreadHandle;

	#define PTBL_THREAD_ATTRIBUTES_OPEN( _ptbl_thread_attributes_ ) \
	( \
	    ( _ptbl_thread_attributes_->nLength = sizeof( SECURITY_ATTRIBUTES ) ) \
	    && ( _ptbl_thread_attributes_->bInheritHandle = true ) \
	    && ! ( _ptbl_thread_attributes_->lpSecurityDescriptor = NULL ) \
	)

	#define PTBL_THREAD_ATTRIBUTES_CLOSE( _ptbl_thread_attributes_ )

	#define PTBL_THREAD_CREATE( _ptbl_thread_, _ptbl_thread_attributes_, _ptbl_thread_function_, _ptbl_thread_arguments_ ) \
	    ( ( ( (_ptbl_thread_)->handle ) = CreateThread( _ptbl_thread_attributes_, 0, ( LPTHREAD_START_ROUTINE )_ptbl_thread_function_, ( LPVOID )_ptbl_thread_arguments_, 0, &( (_ptbl_thread_)->id ) ) ) != NULL )

	#define PTBL_THREAD_EXIT( _ptbl_thread_exit_code_ ) \
	    ExitThread( _ptbl_thread_exit_code_ )
      
	#define PTBL_THREAD_JOIN( _ptbl_thread_ ) \
	( \
	    WaitForSingleObject( (_ptbl_thread_)->handle, INFINITE ) \
	    && CloseHandle( (_ptbl_thread_)->handle ) \
	) 

#else

	#error PORTABLE_THREAD_H

#endif

#endif
