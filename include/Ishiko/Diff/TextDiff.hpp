/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_DIFF_TEXTDIFF_HPP_
#define _ISHIKO_CPP_DIFF_TEXTDIFF_HPP_

#include "TextPatch.hpp"
#include <boost/filesystem/path.hpp>
#include <Ishiko/Errors.hpp>

namespace Ishiko
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

#endif
