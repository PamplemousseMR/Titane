#pragma once

#include "core/buffer.hpp"
#include "core/commandQueue.hpp"

#ifndef __APPLE__
#include <CL/cl.h>
#else
#include <OpenCL/cl.h>
#endif

#include <iostream>

namespace core
{

class Kernel
{

    friend class Program;

public:

    ~Kernel();

    template< typename... A >
    void enqueueNDRange(const CommandQueue&, const std::vector< size_t >&, const std::vector< size_t >&, const A&...);

    void finish();

private:

    void setArgs(uint32_t) const;

    template< typename T, typename... A>
    void setArgs(uint32_t, const T&, const A&...) const;

    template< typename T >
    void setArg(const Buffer< T >&, uint32_t) const;

    template< typename T >
    void setArg(const T&, uint32_t) const;

    Kernel(const cl_program, const std::string&);

private:

    cl_kernel m_kernel {nullptr};

    cl_command_queue m_commandQueue {nullptr};

};

}
