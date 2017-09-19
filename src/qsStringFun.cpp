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

#include "qsStringFun.h"

/*==========================================================
 * 函数：qsLeft
 *
 * 输入参数：
 *   char *dst: 目标字符串；
 *   char *src: 源字符串
 *   int n:	   字符长度
 *
 * 返回值：
 *     char *
 *
 * 功能：从字符串的左边截取n个字符
 *
 * 例程：
 *     (1) 输入源字符串abcdefghijklmn, 字符长度4，输出abcd;
 *     (2) 输入源字符串name = "abc.exe"；
 *         定义字符串char *fmtchar = strrchr(name, '.');
 *         定义输出字符串output, 则qsLeft(output, name, strlen(name) - strlen(fmtchar));
 *    则output为abc;
 *
 * 注：调用该函数之前，src, dst需要事先开辟内存空间；
 * ----------------------------------------------------------------------
 * Function: qsLeft
 *
 * Arguments:
 *      char* dst - Destination String
 *      char* src - Source String
 *      int n - the Length of Destination String
 *
 * Returns:
 *      char*
 *
 * Summary:
 *      Cut n Char from the Left side of a String
 *
 * Examples:
 *      (1) Input "abcdefghijklmn", the Length is 4, then Output is: "abcd";
 *      (2) There is a string: name = "abc.exe";
 *          and:  char *fmtchar = strrchr(name, '.');
 *          Then: qsLeft(output, name, strlen(name) - strlen(fmtchar));
 *          FINALLY, the Output is: "abc";
 *
 * P.S:
 *      The Arguments "src", "dst" need to Initialize the Memory Before Call
 * this Function;
 ===========================================================
 */
char *qsLeft(char *dst,char *src, int n)
{
    char *p = src;
    char *q = dst;
    int len = strlen(src);

    if(n>len)
        n = len;
    while(n--)
        *(q++) = *(p++);
    /* 结尾赋值，字符串截断 */
    *(q++)='\0';
    return dst;
}

/*==========================================================
 * 函数：qsMid
 *
 * 输入参数：
 *   char *dst: 目标字符串；
 *   char *src: 源字符串
 *   int n:	   字符长度
 *   int m:   字符起始切割位置
 *
 * 返回值：
 *     char *
 *
 * 功能：从字符串的中间截取 n 个字符
 *
 * 注：调用该函数之前，src, dst需要事先开辟内存空间；
 * ----------------------------------------------------------------
 * Function: qsMid
 *
 * Arguments:
 *      char* dst - Destination String
 *      char* src - Source String
 *      int n - the Length of Destination String
 *      int m - the Start Position of Cut a String
 *
 * Returns:
 *      char*
 *
 * Summary:
 *      Cut n Char from the Middle of a String
 ===========================================================
 */
char *qsMid(char *dst, char *src, int n,int m) /*n为长度，m为位置*/
{
    char *p = src;
    char *q = dst;
    int len = strlen(src);

    if(n>len)
        n = len-m;    /*从第m个到最后*/
    if(m<0)
        m=0;    /*从第一个开始*/
    if(m>len)
        return NULL;
    p += m;
    while(n--)
        *(q++) = *(p++);
    /* 结尾赋值，字符串截断 */
    *(q++) = '\0';
    return dst;
}

/*==========================================================
 * 函数：qsRight
 * 输入参数：
 *   char *dst: 目标字符串；
 *   char *src: 源字符串
 *   int n:	   字符长度
 *
 * 返回值：
 *     char *
 *
 * 功能：从字符串的右边截取n个字符
 *
 * 例程：
 *     (1) 输入源字符串abcdefghijklmn, 字符长度4，输出klmn;
 *     (2) 输入源字符串name = "abc.exe"；
 *         定义字符串char *fmtchar = strrchr(name, '.');
 *         定义输出字符串output, 则qsRight(output, name, strlen(fmtchar));
 *    则output为.exe;
 *
 * 注：调用该函数之前，src, dst需要事先开辟内存空间；
 * ----------------------------------------------------------------
 * Function: qsRight
 *
 * Arguments:
 *      char* dst - Destination String
 *      char* src - Source String
 *      int n - the Length of Destination String
 *
 * Returns:
 *      char*
 *
 * Examples:
 *      (1) Input "abcdefghijklmn", the Length is 4, then Output is: "klmn";
 *      (2) There is a string: name = "abc.exe";
 *          and:  char *fmtchar = strrchr(name, '.');
 *          Then: qsRight(output, name, strlen(name) - strlen(fmtchar));
 *          FINALLY, the Output is: ".exe";
 *
 * Summary:
 *      Cut n Char from the Right side of a String
 ===========================================================
 */
char *qsRight(char *dst,char *src, int n)
{
    char *p = src;
    char *q = dst;
    int len = strlen(src);

    if(n>len)
        n = len;
    /* 从右边第n个字符开始，到0结束，很巧啊 */
    p += (len - n);
    while(*(q++) = *(p++))	;
    return dst;
}
