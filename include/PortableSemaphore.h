#ifndef PORTABLE_SEMAPHORE_H
#define PORTABLE_SEMAPHORE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Windows / Visual C++ 6.0 / 32 bits systems */
#if defined( WIN32 )

	#include <windows.h>

	typedef HANDLE PTBL_Semaphore;

	#define PTBL_SEMAPHORE_OPEN( _ptbl_semaphore_, _ptbl_initial_value_ ) \
		( ( ( *( _ptbl_semaphore_ ) ) = CreateSemaphore( NULL, _ptbl_initial_value_, 0x7FFFFFFF, NULL ) ) != NULL )

	#define PTBL_SEMAPHORE_WAIT( _ptbl_semaphore_ ) \
		( WaitForSingleObject( *( _ptbl_semaphore_ ), INFINITE ) == WAIT_OBJECT_0 )

	#define PTBL_SEMAPHORE_TRYWAIT( _ptbl_semaphore_ ) \
		( WaitForSingleObject( *( _ptbl_semaphore_ ), 0 ) == WAIT_OBJECT_0 )

	#define PTBL_SEMAPHORE_POST( _ptbl_semaphore_ ) \
		ReleaseSemaphore( *( _ptbl_semaphore_ ), 1, NULL )

	#define PTBL_SEMAPHORE_CLOSE( _ptbl_semaphore_ ) \
		CloseHandle( *( _ptbl_semaphore_ ) )

/* SunOS / gcc / 32 bits systems */
#elif defined( __sun )

	#include <synch.h>

	typedef sema_t PTBL_Semaphore;

	#define PTBL_SEMAPHORE_OPEN( _ptbl_semaphore_, _ptbl_initial_value_ ) \
		( sema_init( _ptbl_semaphore_, _ptbl_initial_value_, USYNC_PROCESS, NULL ) != -1 )

	#define PTBL_SEMAPHORE_WAIT( _ptbl_semaphore_ ) \
		( sema_wait( _ptbl_semaphore_ ) != -1 )

	#define PTBL_SEMAPHORE_POST( _ptbl_semaphore_ ) \
		( sema_post( _ptbl_semaphore_ ) != -1 )

	#define PTBL_SEMAPHORE_CLOSE( _ptbl_semaphore_ ) \
		sema_destroy( _ptbl_semaphore_ )

/* Linux / gcc / 32 bits systems */
#elif defined( __linux )

	#include <semaphore.h>

	typedef sem_t PTBL_Semaphore;

	#define PTBL_SEMAPHORE_OPEN( _ptbl_semaphore_, _ptbl_initial_value_ ) \
		( sem_init( _ptbl_semaphore_, 0, _ptbl_initial_value_ ) == 0 )

	#define PTBL_SEMAPHORE_WAIT( _ptbl_semaphore_ ) \
		( sem_wait( _ptbl_semaphore_ ) == 0 )

	#define PTBL_SEMAPHORE_TRYWAIT( _ptbl_semaphore_ ) \
		( sem_trywait( _ptbl_semaphore_ ) == 0 )

	#define PTBL_SEMAPHORE_POST( _ptbl_semaphore_ ) \
		( sem_post( _ptbl_semaphore_ ) == 0 )

	#define PTBL_SEMAPHORE_CLOSE( _ptbl_semaphore_ ) \
		sem_destroy( _ptbl_semaphore_ )

#else

	#error PORTABLE_SEMAPHORE_H

#endif

#ifdef __cplusplus
}
#endif

#endif
