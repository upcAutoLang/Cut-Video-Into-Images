/*=================================================================
 * Some Functions to Cut Input String (Memory Inited) to get a new String.
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

#ifndef QSSTRINGFUN_H
#define QSSTRINGFUN_H

#define PATH_MAX	2048

#ifdef _WIN32
#include <direct.h>
#endif

#ifdef __gnu_linux__
#include <sys/stat.h>
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 从字符串的左边截取 n 个字符
// Cut n Char from the Left side of a String
char *qsLeft(char *dst, char *src, int n);

// 从字符串的中间截取 n 个字符
// Cut n Char from the Middle of a String
char *qsMid(char *dst, char *src, int n, int m); /*n为长度，m为位置*/

// 从字符串的右边截取 n 个字符
// Cut n Char from the Right side of a String
char *qsRight(char *dst, char *src, int n);

#endif // QSSTRINGFUN_H
