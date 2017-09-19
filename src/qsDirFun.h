/*=================================================================
 * Some Functions to get Directory Information from Input String.
 *
 * Copyright (C) 2017 Chandler Geng. All rights reserved.
 *
 *     This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 *     You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc., 59
 * Temple Place, Suite 330, Boston, MA 02111-1307 USA
===================================================================
*/

#ifndef QSDIRFUN_H
#define QSDIRFUN_H

#define PATH_MAX	2048

#ifdef _WIN32
#include <direct.h>
#endif

#ifdef __gnu_linux__
#include <sys/stat.h>
#include <unistd.h>
#endif

#include <stdio.h>
#include <string.h>

#include "qsStringFun.h"

// 获取文件名
// Get the File Name's String;
char *qsGetFileName(const char *inputname);

// 获取输入字符串的路径
// Get the Directory of Input String;
char *qsGetDirName(const char *inputname);

#endif
/* QSDIRFUN_H */
