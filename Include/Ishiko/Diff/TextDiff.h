/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_DIFF_TEXTDIFF_H_
#define _ISHIKO_DIFF_TEXTDIFF_H_

#include "TextPatch.h"
#include <Ishiko/Errors/Error.h>
#include <boost/filesystem/path.hpp>

namespace Ishiko
{
namespace Diff
{

class TextDiff
{
public:
    static TextPatch Diff(const boost::filesystem::path& originalFile, const boost::filesystem::path& newFile,
        Error& error);
};

}
}

#include "linkoptions.h"

#endif
