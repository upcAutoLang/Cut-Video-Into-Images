#include <stdio.h>
#include <cv.h>
#include <highgui.h>

#include "CutVideoIntoImages.h"

int main(int argc, char *argv[])
{
    int i = 0;
    int num = 5;
    char *nullname = (char*)"NULL";
    /* file name with marked up image descriptions */
    char *infoname = NULL;

    // 命令行只输入一个参数
    if(argc == 1)
    {
        printf("Usage: %s\n"
                "  [-info <video_files_name_list>]\n"
                "  [-num <number_of_video_in_list>]\n",
                argv[0]);

        return 0;
    }

    // 命令行参数处理
    for(i = 1; i < argc; ++i)
    {
        if( !strcmp(argv[i], "-info") )
        {
            infoname = argv[++i];
        }
        else if( !strcmp(argv[i], "-num") )
        {
            num = atoi(argv[++i]);
        }
    }

    // 显示参数相关信息
    printf( "Video Files List File's Name: %s\n",
        ( (infoname == NULL) ? nullname : infoname) );
    printf( "Number of Videos: %d\n", num);

    // 动作实现
    if( infoname )
    {
        int total;
        printf("Cutting Images from Video...\n");

        total = CutVideoIntoImages(infoname, num);
        printf("Done. Cut %d Images.\n"
                "  Cut Images are storaged in <Video CutImages>.\n",
                total);
    }

    return 0;
}
