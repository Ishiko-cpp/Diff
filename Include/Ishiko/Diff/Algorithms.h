/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_DIFF_ALGORITHMS_H_
#define _ISHIKO_DIFF_ALGORITHMS_H_

#include <string>

namespace Ishiko
{
namespace Diff
{

size_t MyersAlgorithm(const std::string& originalString, const std::string& newString);
size_t WagnerFischerAlgorithm(const std::string& originalString, const std::string& newString);

}
}

#include "linkoptions.h"

#endif
