#ifndef PORTABLE_MUTEX_H
#define PORTABLE_MUTEX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Windows / Visual C++ 6.0 / 32 bits systems */
#if defined( WIN32 )

	#include <windows.h>

	typedef HANDLE PTBL_Mutex;

	#define PTBL_MUTEX_OPEN(   _ptbl_mutex_ ) \
		( ( ( *_ptbl_mutex_ ) = CreateMutex( NULL, false, NULL ) ) != NULL )

	#define PTBL_MUTEX_LOCK(   _ptbl_mutex_ ) \
		( WaitForSingleObject( _ptbl_mutex_, INFINITE ) == WAIT_OBJECT_0 )

	#define PTBL_MUTEX_UNLOCK( _ptbl_mutex_ ) \
		ReleaseMutex( _ptbl_mutex_ )

	#define PTBL_MUTEX_CLOSE(  _ptbl_mutex_ ) \
		CloseHandle( *( _ptbl_mutex_ ) )

/* SunOS / gcc / 32 bits systems */
#elif defined( __sun )

	#error PORTABLE_MUTEX_H

/* Linux / gcc / 32 bits systems */
#elif defined( __linux )

	#include <pthread.h>

	typedef pthread_mutex_t PTBL_Mutex;

	#define PTBL_MUTEX_OPEN(   _ptbl_mutex_ ) \
		( pthread_mutex_init( _ptbl_mutex_, NULL ) == 0 )

	#define PTBL_MUTEX_LOCK(   _ptbl_mutex_ ) \
		( pthread_mutex_lock( _ptbl_mutex_ ) == 0 )

	#define PTBL_MUTEX_UNLOCK( _ptbl_mutex_ ) \
		( pthread_mutex_unlock( _ptbl_mutex_ ) == 0 )

	#define PTBL_MUTEX_CLOSE(  _ptbl_mutex_ ) \
		pthread_mutex_destroy( _ptbl_mutex_ )

#else

	#error PORTABLE_MUTEX_H

#endif

#ifdef __cplusplus
}
#endif

#endif
