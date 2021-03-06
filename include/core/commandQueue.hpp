#pragma once

#ifndef __APPLE__
#include <CL/cl.h>
#else
#include <OpenCL/cl.h>
#endif

namespace core
{

class CommandQueue
{

    friend class Kernel;

    friend class Context;

public:

    ~CommandQueue();

    const cl_command_queue getCommandQueue() const;

private:

    CommandQueue(const cl_context, const cl_device_id);

private:

    cl_command_queue m_commandQueue {nullptr};

};

}
