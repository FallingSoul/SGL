#include <iostream>
#include "sgl/sgl.h"

int main()
{
    auto config = sgl::sglGetConfigInfo();
    printf("lib: %s %d.%d.%d\n",config.name,config.version_major,config.version_minor,config.version_patch);
    auto compiler = sgl::sglGetCompilerInfo();
    printf("cl: %s %d.%d.%d\n",compiler.name,compiler.version_major,compiler.version_minor,compiler.version_patch);
    return 0;
}