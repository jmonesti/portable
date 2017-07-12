#include "PortableProcess.h"

#ifdef __cplusplus
extern "C" {
#endif

PTBL_ProcessHandle PTBL_Process( char * command, char ** argv )
{

#if defined( WIN32 )

	/* information about process created by CreateProcess( ) */
	PROCESS_INFORMATION process_info;

	/* configure graphical environment (actually none) */
	STARTUPINFO startup_info;

	/* pack argv into single char * line */
	char * line = NULL;
	if ( argv != NULL ) {
		int size;
		char ** argument;
		size = 0;
		argument = argv;
		while( * argument != NULL ) { size = size + strlen( * argument ) + 1; argument ++; }
		line = ( char * )malloc( size );
		if ( line != NULL ) {
			char * copy;
			copy = line;
			argument = argv;
			while( * argument != NULL ) {
				char * source = * argument;
				if ( copy != line ) { * ( copy - 1 ) = ' '; }
				while( ( * copy ++ = * source ++ ) );
				argument ++;
			}
			* copy = '\0';
		}
	}

	if ( command == NULL ) { return -1; }

	/* setup startup info container */
	startup_info.cb          = sizeof( STARTUPINFO );
	startup_info.lpReserved  = NULL;
	startup_info.lpDesktop   = NULL;
	startup_info.lpTitle     = NULL;
	startup_info.dwFlags     = 0;
	startup_info.cbReserved2 = 0;
	startup_info.lpReserved2 = NULL;

	/* attempt to create process */
	if( CreateProcess( NULL, line, NULL, NULL, true, 0, NULL, NULL, & startup_info, & process_info ) == 0 ) {
		/* process creation failed */
		if ( line != NULL ) { free( line ); }
		return -1;
	}
	else {
		/* process creation succeeded */
		if ( line != NULL ) { free( line ); }
		return process_info.hProcess;
	}

#elif defined( __sun )

	if ( command == NULL ) { return -1; }
	/* beware of fork() that also duplicate threads of parent process */
	PTBL_ProcessHandle handle = fork1( );
	if( handle == 0 ) {
		int result = execvp( command, argv );
		if ( result == -1 ) {
			char * message = strerror( errno );
			fprintf( stderr, "ERROR: command '%s' %s\n", command, message ? message : "failed." );
		}
		exit( result );
	}
	return handle;

#elif defined( __linux )

	if ( command == NULL ) { return -1; }
	PTBL_ProcessHandle handle = fork( );
	if( handle == 0 ) {
		int result = execvp( command, argv );
		if ( result == -1 ) {
			char * message = strerror( errno );
			fprintf( stderr, "ERROR: command '%s' %s\n", command, message ? message : "failed." );
		}
		exit( result );
	}
	return handle;

#else

	return -1;

#endif
}

#ifdef __cplusplus
}
#endif
