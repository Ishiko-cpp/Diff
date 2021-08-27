/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_DIFF_TEXTDIFF_H_
#define _ISHIKO_CPP_DIFF_TEXTDIFF_H_

#include "TextPatch.h"
#include <boost/filesystem/path.hpp>
#include <Ishiko/Errors.hpp>

namespace Ishiko
{
namespace Diff
{

class TextDiff
{
public:
    static TextPatch CharacterDiff(const std::string& originalString, const std::string& newString);
    static TextPatch WordDiff(const std::string& originalString, const std::string& newString);
    static TextPatch LineDiffFiles(const boost::filesystem::path& originalFile, const boost::filesystem::path& newFile,
        Error& error);
};

}
}

#include "linkoptions.h"

#endif
