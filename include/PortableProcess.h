#ifndef PORTABLE_PROCESS_H
#define PORTABLE_PROCESS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Windows / Visual C++ 6.0 / 32 bits systems */
#if defined( WIN32 )

	typedef HANDLE PTBL_ProcessHandle;

	#define PTBL_PROCESS_KILL( _ptbl_process_handle ) \
		TerminateProcess( _ptbl_process_handle, 0 )

	#define PTBL_PROCESS_COMMAND( _ptbl_process_handle, _ptbl_process_command, _ptbl_process_arguments ) \
		( ( _ptbl_process_handle = PTBL_Process( _ptbl_process_command, _ptbl_process_arguments ) ) != -1 )

	extern PTBL_ProcessHandle PTBL_Process( char * command, char ** arguments );

/* SunOS / gcc / 32 bits systems */
#elif defined( __sun )

	#include <sys/types.h>
	#include <unistd.h>
	#include <signal.h>

	#include <stdio.h>
	#include <stdlib.h>
	#include <errno.h>
	#include <string.h>

	typedef int PTBL_ProcessHandle;

	#define PTBL_PROCESS_KILL( _ptbl_process_handle ) \
		kill( _ptbl_process_handle, SIGKILL )

	#define PTBL_PROCESS_COMMAND( _ptbl_process_handle, _ptbl_process_command, _ptbl_process_arguments ) \
		( ( _ptbl_process_handle = PTBL_Process( _ptbl_process_command, _ptbl_process_arguments ) ) != -1 )

	extern PTBL_ProcessHandle PTBL_Process( char * command, char ** arguments );

/* Linux / gcc / 32 bits systems */
#elif defined( __linux )

	#include <sys/types.h>
	#include <unistd.h>
	#include <signal.h>

	#include <stdio.h>
	#include <stdlib.h>
	#include <errno.h>
	#include <string.h>

	typedef int PTBL_ProcessHandle;

	#define PTBL_PROCESS_KILL( _ptbl_process_handle ) \
		kill( _ptbl_process_handle, SIGKILL )

	#define PTBL_PROCESS_COMMAND( _ptbl_process_handle, _ptbl_process_command, _ptbl_process_arguments ) \
		( ( _ptbl_process_handle = PTBL_Process( _ptbl_process_command, _ptbl_process_arguments ) ) != -1 )

	extern PTBL_ProcessHandle PTBL_Process( char * command, char ** arguments );

#else

	#error PORTABLE_PROCESS_H

#endif

#ifdef __cplusplus
}
#endif

#endif
