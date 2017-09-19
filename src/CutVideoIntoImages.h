/*=================================================================
 * A Console Program to Cut a Video Into a series of Images based on OpenCV
 * Libraries.
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

#ifndef CUTVIDEOINTOIMAGES_H
#define CUTVIDEOINTOIMAGES_H

#ifdef _WIN32
#include <direct.h>
#endif

#ifdef __gnu_linux__
#include <sys/stat.h>
#endif

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <ctype.h>
#include <sys/stat.h>

#include "cv.h"
#include "highgui.h"

#include "qsStringFun.h"
#include "qsDirFun.h"

// 以输入参数作为列表，读取其中文件，并将列表中所有视频逐帧切割，存放在相应的文件夹中；
// Regard the Input Argument as a List, and Read Videos from it, then Cut Videos
//      which is in the List frame by frame and Save the Images into Specified Folders.
int CutVideoIntoImages(const char *infoname, int num);

#endif // CUTVIDEOINTOIMAGES_H
