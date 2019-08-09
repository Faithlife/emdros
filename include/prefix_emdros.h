/*
 * prefix_emdros.h.in
 *
 * A crude abstraction of the current OS.
 *
 * Ulrik Petersen
 * Created: 4/9-2005
 * Last update: 11/03-2005
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


#ifndef PREFIX_EMDROS__H__
#define PREFIX_EMDROS__H__

#include <string>

inline std::string prefix(void)
{
#ifdef WIN32
  return ".\\";
#elif defined(__DJGPP__)
  return ".\\";
#else
  return "/usr/local/";
#endif
}

// Must be implemented by the app.
// Is usually something line prefix() + "share/emdros/myapp/"
// On Win32, it should default to wxGetCwd().
extern std::string app_prefix(void);


#endif // PREFIX_EMDROS__H__
