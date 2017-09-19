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

#include "CutVideoIntoImages.h"

/*==================================================================
 * 函数：CutVideoIntoImages
 *
 * 输入参数：
 *      const char *infoname: 视频文件列表，由控制台命令行中输入，即命令行参
 *              数 -info 后面的参数；
 *      int num: 视频文件列表中，包含的视频文件个数；
 *
 * 返回值：int
 *      生成图片个数；
 *
 * 功能：以输入参数作为列表，读取其中文件，并将列表中所有视频逐帧切割，存
 *      放在相应的文件夹中；
 * ---------------------------------------------------------------------------
 * Function: CutVideoIntoImages
 *
 * Arguments:
 *      const char *infoname - the List of Video Files, which inputs from Console's Command
 *               Line ( the Argument behind the Command Line's Argument ' -info ' )
 *      int num - the Number of Video Files in the list
 *
 * Returns:  int
 *      the Number of Images Generated
 *
 * Summary:
 *      Regard the Input Argument as a List, and Read Videos from it, then Cut Videos
 * which is in the List frame by frame and Save the Images into Specified Folders.
 ===================================================================
 */
int CutVideoIntoImages(const char *infoname, int num)
{
    // 视频缓存
    // Video Buffer
    CvCapture *BufCapture;

    // 文件路径字符串
    // the String of file's full name ( Include File's name & Directory's name)
    char fullname[PATH_MAX];

    // 文件名称字符串
    // the String of File's name
    char* filename;

    // 文件所在目录字符串
    // the String of the Directory of the File
    char* dirname;

    // 生成图像文件名称前缀
    // the Prefix of Generating Images Filename
    char baseimgfile[PATH_MAX];

    // 图像文件名称缓存
    // the Buffer of Image Filename
    char bufimgfile[PATH_MAX];

    // 缓存图像存放文件夹
    // the Save Folder's Name of Genarating Images
    char *imgpath = "Video CutImages";

    // 剪切文件总数
    // the Number of Cut Images
    int total = -1;

    // 单帧图像缓存
    // Buffer of one frame Image
    IplImage *img = 0;

    // 视频文件列表文件流
    // File Stream of Video File List
    FILE *info;

    // 文件名错误代码
    // Error code
    int error;

    // 列表文档中的行数
    // the Line Number in List
    int line;

    // 读取列表文件
    // Read List File
    info = fopen(infoname, "r");
    if(info == NULL)
    {
        fprintf(stderr, "Unable to open Video List File: %s\n", infoname);
        return total;
    }

    // 处理文件名字符串
    // Extract File & Directory String
    filename = qsGetFileName(infoname);
    dirname = qsGetDirName(infoname);

    // 创建视频文件存储的文件夹
    // Create Images' Storage Folder
    int status;
#ifdef _WIN32
    status = _mkdir(imgpath);
#endif
#ifdef __gnu_linux__
    status = mkdir(imgpath, 0777);
#endif

    // 遍历文件列表
    // Traversal the List of Videos
    for( line = 0, error = 0, total = 0; line < num; line++)
    {
        int count;
        count = 1;

        error = (fscanf(info, "%s", filename) != 1);
        if(!error)
        {
            // 获得去除格式后缀的视频文件名，存储在baseimgfile中
            // get the Video's name whose format suffix is Removed and Save it into Variable 'baseimgfile'
            char *fmtchar;
            fmtchar = strrchr(filename, '.');
            qsLeft(baseimgfile, filename, strlen(filename) - strlen(fmtchar));

            // 创建子文件夹
            // Create Subfolder
            char BufSubFolderPath[PATH_MAX];
            strcpy(BufSubFolderPath, imgpath);
            strcat(BufSubFolderPath, "/");
            strcat(BufSubFolderPath, baseimgfile);

            char* realFileName;
            realFileName = new char[ sizeof(dirname) + sizeof(filename) + 2];
            strcpy(realFileName, dirname);
            strcat(realFileName, filename);

#ifdef _WIN32
            status = _mkdir(BufSubFolderPath);
#endif
#ifdef __gnu_linux__
            status = mkdir(BufSubFolderPath, 0777);
#endif

            // 读取文件列表中每个文件视频，并将视频剪成帧序列
            // Read Every Video including the File List, and Cut videos into Frame Sequence
            BufCapture = cvCaptureFromFile(realFileName);

            // 读取视频
            // Read Video
            while(1)
            {
                // 捕获一帧图片
                // Capture a frame of Image
                img = cvQueryFrame(BufCapture);

                // 捕获图片失败时，说明该视频捕获完毕，跳出循环
                // When Capture Image Failed, it means this Video Captures Finished, and Jump out of this loop
                if(img == NULL)
                    break;

                // 生成文件名
                // Generate a File's Name
                strcpy(bufimgfile, BufSubFolderPath);
                strcat(bufimgfile, "/");
                strcat(bufimgfile, baseimgfile);
                char buf[PATH_MAX];
                strcat(bufimgfile, "_");
                sprintf(buf, "%06d", total);
                strcat(bufimgfile, buf);
                strcat(bufimgfile, ".jpg");

                // 生成文件
                // Generate a Image
                cvSaveImage(bufimgfile, img);

                total++;
            }
        }
        else
        {
            printf("List Name Done.\n");
            break;
        }
    }

    // 释放空间
    // Release the Memory
    cvReleaseImage(&img);
    cvReleaseCapture(&BufCapture);
    fclose(info);

    return total;
}
