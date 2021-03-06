#pragma once

#include "exception/iexception.hpp"

#include <string>

namespace exception
{

class Invalid : public IException
{

public:

    Invalid(const std::string&) noexcept;

};

}
