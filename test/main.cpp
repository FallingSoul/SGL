#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <ctime>


#include "sgl/sgl.h"

int main()
{
    setlocale(LC_ALL,"zh_cn.utf-8"); // Change Charset
    printf("\n启动耗时: %g sec\n",1. * clock() / CLOCKS_PER_SEC);


    core::sglWindowContext ctx;
    core::sglWindow window("Hello Window!",1280,720);
    window.show();
    while(!window.closed())
    {
        sglDouble beg = ctx.get_time();
        ctx.poll_events();
        if(window.key_pressed(core::sglKeyCode::Escape))
        {
            window.close();
        }
        printf("\r事件帧率: %g fps",1 / (ctx.get_time() - beg));
    }



    printf("\n结束耗时: %g sec\n",1. * clock() / CLOCKS_PER_SEC);

    return 0;
}