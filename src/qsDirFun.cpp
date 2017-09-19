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

#include "qsDirFun.h"

/*==========================================================
 * 函数：qsGetDirName
 *
 * 输入参数：const char *inputname
 *
 * 返回值：char *
 *
 * 功能：获取输入字符串的路径
 *
 * 例程：
 *      (1) 输入MyKit/abcdef.exe，输出MyKit
 *      (2) 输入MyKit/MyKit2\\abcdef.exe，输出MyKit/MyKit2\\
 * ---------------------------------------------------------------
 * Function: qsGetDirName
 *
 * Arguments:
 *      const char *inputname
 *
 * Returns: char *
 *
 * Summary:
 *      Get the Directory of Input String;
 *
 * Examples:
 *      (1) Input "MyKit/abcdef.exe", Output is: "MyKit";
 *      (2) Input "MyKit/MyKit2\\abcdef.exe", Output is: "MyKit/MyKit2\\"
 ===========================================================
 */
char *qsGetDirName(const char *inputname)
{
    char *fullname, *filename;
    char *dirname;

    strcpy( fullname, inputname );

    // 判断字符串中是否包含\\或/, 如果不包含，则返回空字符串；
    filename = strrchr(fullname, '\\');
    if(filename == NULL){
        filename = strrchr(fullname, '/');
    }

    if(filename == NULL){
        filename = "";
    }
    else{
        dirname = new char[ strlen(inputname) - strlen(filename) + 1];
        qsLeft(dirname, fullname, strlen(inputname) - strlen(filename) + 1);
    }
}

/*==========================================================
 * 函数：qsGetFileName
 *
 * 输入参数：const char *inputname
 *
 * 返回值：char *
 *
 * 功能：获取文件名
 *
 * 例程：
 *      (1) 输入abcdef.exe，输出abcdef.exe
 *      (2) 输入MyKit/abcdef.exe，输出abcdef.exe
 *      (3) 输入MyKit/MyKit2\\abcdef.exe，输出abcdef.exe
 * ------------------------------------------------------------
 * Functions: qsGetFileName
 *
 * Arguments:
 *      const char *inputname
 *
 * Returns: char*
 *
 * Summary:
 *      Get the File Name's String;
 *
 * Examples:
 *      (1) Input "abcdef.exe", Output is: "abcdef.exe";
 *      (2) Input "MyKit/abcdef.exe", Output is: "abcdef.exe";
 *      (3) Input "MyKit/MyKit2\\abcdef.exe", Output is: "abcdef.exe";
 ===========================================================
 */
char *qsGetFileName(const char *inputname)
{
    char fullname[PATH_MAX], *filename;

    strcpy( fullname, inputname );
    // 判断字符串中是否包含\\或/, 如果不包含，则输出完整名称；
    filename = strrchr(fullname, '\\');
    if(filename == NULL){
        filename = strrchr( fullname, '/');
    }

    if(filename == NULL){
        filename = fullname;
    }
    else{
        filename++;
    }

    return filename;
}
