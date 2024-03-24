#include <assert.h>
#include "sgl/framework/main.h"

#include <stdio.h>

#undef main

namespace sgl
{
    struct sglMain_Impl
    {
        static sglMain * main;
        sglInt argc;
        const sglChar ** argv;
    };
    sglMain * sglMain_Impl::main = nullptr;
    sglMain::sglMain(sglInt argc,const sglChar ** argv)
        :_main(new sglMain_Impl)
    {
        sglMain_Impl::main = this;
        this->_main->argc = argc;
        this->_main->argv = argv;
    }
    sglMain::~sglMain()
    {
        delete this->_main;
        this->_main = nullptr;
    }
    sglBool sglMain::check()
    {
        return nullptr != sglMain_Impl::main;
    }
    
    sglInt sglMainArgs::get_count()
    {
        assert(sglMain::check());
        return sglMain_Impl::main->_main->argc;
    }
    const sglChar * sglMainArgs::get_arg(sglInt index)
    {
        assert(sglMain::check());
        assert(index < sglMain_Impl::main->_main->argc);
        return sglMain_Impl::main->_main->argv[index];
    }
    const sglChar * sglMainArgs::operator [] (sglInt index)const
    {
        return get_arg(index);
    }
}