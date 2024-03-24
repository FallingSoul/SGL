#ifndef __SGL_FRAMEWORK_MAIN__
#define __SGL_FRAMEWORK_MAIN__

#include "sgl/core.h"

#define SGL_DECALRE_MAIN int main(int argc,const char ** argv)

SGL_DECALRE_MAIN;
namespace sgl
{
    class SGL_API sglMainArgs
    {
    public:
        static sglInt get_count();
        static const sglChar * get_arg(sglInt index);
        const sglChar * operator [] (sglInt index)const;
    };
    class SGL_API sglMain
    {
    public:
        static sglBool check();
    private:
        friend class sglMainArgs;
        friend SGL_DECALRE_MAIN;
        sglMain(sglInt argc,const sglChar ** argv);
        ~sglMain();
    private:
        struct sglMain_Impl * _main;
    };
}
#ifndef SGL_BUILD
namespace sgl
{
    class sglMainEntrance : sglMainArgs
    {
    private:
        friend SGL_DECALRE_MAIN;
        sglInt main();
    };
    SGL_DECALRE_MAIN
    {
        sglMain main(argc,argv);
        sglMainEntrance entrance;
        (void)main;
        (void)entrance;
        return entrance.main();
    }
}
SGL_DECALRE_MAIN
{
    return sgl::main(argc,argv);
}
#define main() ::sgl::sglMainEntrance::main()
#endif

#endif //!__SGL_FRAMEWORK_MAIN__