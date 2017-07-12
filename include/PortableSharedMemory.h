#ifndef PORTABLE_SHAREDMEMORY_H
#define PORTABLE_SHAREDMEMORY_H

#include <assert.h>

/* Windows / Visual C++ 6.0 / 32 bits systems */
#if defined( WIN32 )

	#include <process.h>
	#include <windows.h>

	#define IPC_PRIVATE 0

	typedef HANDLE PTBL_SharedMemoryHandle;

	#define PTBL_SHARED_MEMORY_OPEN( _ptbl_shm_, _ptbl_shm_key_, _ptbl_shm_size ) \
		( ( ( _ptbl_shm_ = CreateFileMapping( ( HANDLE )0xFFFFFFFF, NULL, PAGE_READWRITE, 0, _ptbl_shm_size, _itoa( _ptbl_shm_key_, NULL, 10 ) ) ) != NULL ) && ( GetLastError( ) != ERROR_ALREADY_EXISTS ) )

	#define PTBL_SHARED_MEMORY_GET( _ptbl_shm_, _ptbl_shm_key_, _ptbl_shm_size ) \
		( ( _ptbl_shm_ = OpenFileMapping( FILE_MAP_WRITE, false, _itoa( _ptbl_shm_key_, NULL, 10 ) ) ) != NULL )

	#define PTBL_SHARED_MEMORY_ATTACH( _ptbl_shm_address_, _ptbl_shm_type_, _ptbl_shm_ ) \
		( ( _ptbl_shm_address_ = ( _ptbl_shm_type_ ) MapViewOfFile( _ptbl_shm_, FILE_MAP_WRITE, 0, 0, 0 ) ) != NULL )

	#define PTBL_SHARED_MEMORY_CLOSE( _ptbl_shm_address_, _ptbl_shm_ ) \
		( UnmapViewOfFile( _ptbl_shm_address_ ) && CloseHandle( _ptbl_shm_ ) )

/* SunOS / gcc / 32 bits systems */
/* Linux / gcc / 32 bits systems */
#elif defined( __sun ) || defined( __linux )

	#include <sys/types.h>
	#include <sys/ipc.h>
	#include <sys/shm.h>

	#include <stdio.h>
	#include <stdlib.h>
	#include <errno.h>

	typedef int PTBL_SharedMemoryHandle;

	#define PTBL_SHARED_MEMORY_OPEN( _ptbl_shm_, _ptbl_shm_key_, _ptbl_shm_size ) \
		( ( _ptbl_shm_ = shmget( _ptbl_shm_key_, _ptbl_shm_size, 0600 | IPC_CREAT | IPC_EXCL ) ) != -1 )

	#define PTBL_SHARED_MEMORY_GET( _ptbl_shm_, _ptbl_shm_key_, _ptbl_shm_size ) \
		( ( _ptbl_shm_ = shmget( _ptbl_shm_key_, _ptbl_shm_size, 0600 | IPC_CREAT ) ) != -1 )

	#define PTBL_SHARED_MEMORY_ATTACH( _ptbl_shm_address_, _ptbl_shm_type_, _ptbl_shm_ ) \
		( ( _ptbl_shm_address_ = ( _ptbl_shm_type_ ) shmat( _ptbl_shm_, NULL, 0600 ) ) != NULL )

	#define PTBL_SHARED_MEMORY_CLOSE( _ptbl_shm_address_, _ptbl_shm_ ) \
		( shmctl( _ptbl_shm_, IPC_RMID, NULL ) != -1 )

#else

	#error PORTABLE_SHAREDMEMORY_H

#endif

#endif
