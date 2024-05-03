#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


#include "sgl/sgl.h"

int main()
{
    setlocale(LC_ALL,"zh_cn.utf-8");
    printf("启动耗时: %gsec\n",clock() / 1000.);


    


    printf("结束耗时: %gsec\n",clock() / 1000.);

    return 0;
}