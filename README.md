# portable
A set of `typedef` and `#define` intended to provide portability across Linux / Win32.

## About PortableTypes.h

1. Retargetted typedefs of signed and unsigned integer types of 8, 16, 32 and 64 bits size:

   - `uint8`, `uint16`, `uint32`, `uint64`

   - `sint8`, `sint16`, `sint32`, `sint64`

2. Retargetted min and max values for types defined in 1.

   - `UINT8_MIN`, `UINT16_MIN`, `UINT32_MIN` and `UINT64_MIN`

   - `UINT8_MAX`, `UINT16_MAX`, `UINT32_MAX` and `UINT64_MAX`

   - `SINT8_MIN`, `SINT16_MIN`, `SINT32_MIN` and `SINT64_MIN`

   - `SINT8_MAX`, `SINT16_MAX`, `SINT32_MAX` and `SINT64_MAX`

3. OS-retargetted constant setting (mainly point about 64 bits constants)

   - `SINT8_C(x)`, `SINT16_C(x)`, `SINT32_C(x)` and `SINT64_C(x)` to define 8, 16, 32 and 64 bits signed constants

   - `UINT8_C(x)`, `UINT16_C(x)`, `UINT32_C(x)` and `UINT64_C(x)` to define 8, 16, 32 and 64 bits unsigned constants

   - Example :

       `uint64 x = UINT64(0xDDEEAADDBBEEEEFF);`

     Will be develop for Windows Visual C++ as:

       `unsigned __int64 x = ( ( unsigned __int64 )( 0xDDEEAADDBBEEEEFF ) );`

     And will be develop for SunOS / gcc as:

       `unsigned long long int x = 0xDDEEAADDBBEEEEFFULL;`

4. definition of macros to hide OS differences about printf( "%" ) format specifications.

   - `SINT_CFORMAT(f)`, `SINT8_CFORMAT(f)`, `SINT16_CFORMAT(f)`, `SINT32_CFORMAT(f)` and `SINT64_CFORMAT(f)` to print default, 8, 16, 32 and 64 bits signed integers as decimal signed values with sign prefix.

   - `UINT_CFORMAT(f)`, `UINT8_CFORMAT(f)`, `UINT16_CFORMAT(f)`, `UINT32_CFORMAT(f)` and `UINT64_CFORMAT(f)` to print default, 8, 16, 32 and 64 bits unsigned integers as decimal unsigned values (no prefix).

   - `XINT_CFORMAT(f)`, `XINT8_CFORMAT(f)`, `XINT16_CFORMAT(f)`, `XINT32_CFORMAT(f)` and `XINT64_CFORMAT(f)` to print default, 8, 16, 32 and 64 bits integers in hexadecimal with "0x" prefix.

   - `OINT_CFORMAT(f)`, `OINT8_CFORMAT(f)`, `OINT16_CFORMAT(f)`, `OINT32_CFORMAT(f)` and `OINT64_CFORMAT(f)` to print default, 8, 16, 32 and 64 bits integers in octal with "0" prefix.

   - `INT_CFORMAT(f)`, `INT8_CFORMAT(f)`, `INT16_CFORMAT(f)`, `INT32_CFORMAT(f)` and `INT64_CFORMAT(f)` to print default, 8, 16, 32 and 64 bits integers as decimal values with sign prefix when negative only.

   - `STRING_CFORMAT(f)` to print zero-ended 8-bits character strings.

   - `POINTER_CFORMAT(f)` to print host pointer values.

   - Example :
```

       sint64 x = -33;
       printf( "Variable " STRING_CFORMAT("-4")
               "at "       POINTER_CFORMAT("")
               " = "       XINT64_CFORMAT("016")
               " : "       SINT64_CFORMAT("")
               "\n",
               "x", &x, x );
```
     Will be developped for Windows as:
```

       unsigned __int64 x;
       printf( "Variable " "%-4s"
               "at "       "0x%x"
               " = "       "0x%016I64x"
               " : "       "%+d"
               "\n",
               "x", &x, x, x );
```

     and for Linux systems as:
```

       unsigned long long x;
       printf( "Variable " "%-4s"
               "at "       "%p"
               " = "       "0x%016llx"
               " : "       "%+d"
               "\n",
               "x", &x, x, x );
```

## About PortableFunctions.h

1. Mapping of some usual Unix functions to Windows ones

    - `strcasecmp`, `strcasencmp`

    - `vsnprint`, `snprintf`, `strdup`

    - `stat`

## About PortableDll.h

A portable API for explicitly loading shared libraries.

### Load Library
```

    PTBL_DLL_OPEN( _ptbl_dll_handle_, _ptbl_name_ )
    - explicit load the DLL/shared library
    - modify _ptbl_dll_handle_
    - return != 0 if OK
```

### Retrieve Symbol
```

    PTBL_DLL_GET_SYMBOL( _ptbl_dll_handle_, _ptbl_pointer_, _ptbl_name_ )
    - get symbol pointer( void* typed )
    - modify _ptbl_pointer_
    - return != 0 if OK
```

```

    PTBL_DLL_GET_TYPED_SYMBOL( _ptbl_dll_handle_, _ptbl_pointer_, _ptbl_name_, _ptbl_type_ )
    - get symbol pointer with recast to _ptbl_type_
    - modify _ptbl_pointer_
    - return != 0 if OK
```

### Unload Library
```

    PTBL_DLL_CLOSE( _ptbl_dll_handle_ )
    - unload the DLL/shared library
    - return 0 if OK
```

### Error Handling
```

    PTBL_DLL_GET_ERROR( _ptbl_msg_ )
    - get latest error message
    - modify _ptbl_msg_ character pointer
```

## About PortableMutex.h

    if ( ! PTBL_MUTEX_OPEN( & mutex   ) ) { ... error ... }
    if ( ! PTBL_MUTEX_LOCK( & mutex   ) ) { ... error ... }
    if ( ! PTBL_MUTEX_UNLOCK( & mutex ) ) { ... error ... }
    if ( ! PTBL_MUTEX_CLOSE( & mutex  ) ) { ... error ... }

## About PortableSemaphore.h

    if ( ! PTBL_SEMAPHORE_OPEN( & semaphore, 0 ) ) { ... error ... }
    if ( ! PTBL_SEMAPHORE_WAIT( & semaphore    ) ) { ... error ... }
    if ( ! PTBL_SEMAPHORE_POST( & semaphore    ) ) { ... error ... }
    if ( ! PTBL_SEMAPHORE_CLOSE( & semaphore   ) ) { ... error ... }

## About PortableThread.h

## About PortableProcess.h

## About PortableSharedMemory.h
