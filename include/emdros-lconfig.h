/*
 * emdros-lconfig.h.in
 *
 * Local configuration
 *
 * Ulrik Petersen
 * Created: 10/21-2001
 * Last update: 2/15-2019
 *
 */

/*
 * Copyright (C) 2001-2018     Ulrik Sandborg-Petersen
 * Copyright (C) 2018-present  Sandborg-Petersen Holding ApS, Denmark
 *
 * Licensed under the MIT License.
 *
 * Please see the file COPYING in the root of the sources for more details.
 *
 */



/*
 * This file is to be run through configure's AC_OUTPUT line.
 *
 */


#ifndef LCONFIG__H__
#define LCONFIG__H__

#ifndef USE_POSTGRESQL
#define USE_POSTGRESQL 1
#endif

#ifndef USE_MYSQL
#define USE_MYSQL 1
#endif

#ifndef USE_SQLITE3
#define USE_SQLITE3 1
#endif

#ifndef USE_BPT
#define USE_BPT 0
#endif

#ifndef LINUX
#define LINUX 1
#endif

#ifndef SUN
#define SUN 0
#endif

#ifndef DEFAULT_BACKEND_ENUM

#if 0

#define DEFAULT_BACKEND_ENUM none

#else

#if USE_SQLITE3
#define DEFAULT_BACKEND_ENUM kSQLite3
#elif USE_MYSQL
#define DEFAULT_BACKEND_ENUM kMySQL
#elif USE_POSTGRESQL
#define DEFAULT_BACKEND_ENUM kPostgreSQL
#else
#define DEFAULT_BACKEND_ENUM kBackendNone
#endif 

#endif /* 0 */

#endif /* !defined(DEFAULT_BACKEND_ENUM) */


#ifndef USE_SYSTEM_SQLITE3
/** USE_SYSTEM_SQLITE3 must be zero if we are using the local SQLite3,
 * otherwise, it must be non-zero.
 *@internal
 */
#define USE_SYSTEM_SQLITE3 (0)
#endif

#ifndef USE_SYSTEM_ZLIB
/** USE_SYSTEM_ZLIB must be zero if we are using the local zlib,
 * otherwise, it must be non-zero.
 *@internal
 */
#define USE_SYSTEM_ZLIB (1)
#endif

#ifndef EMDROS_VERSION
#define EMDROS_VERSION "3.7.1"
#endif

#ifndef EMDROS_VERSION_MAJOR
#define EMDROS_VERSION_MAJOR (3)
#endif

#ifndef EMDROS_VERSION_MINOR
#define EMDROS_VERSION_MINOR (7)
#endif

#ifndef EMDROS_VERSION_RELEASE
#define EMDROS_VERSION_RELEASE (1)
#endif


/* Is current version at least (<=) MAJOR.MINOR.RELEASE ? */
#define EMDROS_CHECK_VERSION(MAJOR, MINOR, RELEASE) \
  (((MAJOR)>EMDROS_VERSION_MAJOR) ? 0 :	    \
   (((MAJOR)<EMDROS_VERSION_MAJOR) ? 1 :    \
    (((MINOR)>EMDROS_VERSION_MINOR) ? 0 :   \
     (((MINOR)<EMDROS_VERSION_MINOR) ? 1 :  \
      (((RELEASE)>EMDROS_VERSION_RELEASE) ? 0 : \
       1)))))


#endif /* LCONFIG__H__ */
