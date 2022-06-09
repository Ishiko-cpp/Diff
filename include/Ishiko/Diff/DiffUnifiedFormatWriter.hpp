/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_DIFF_DIFFUNIFIEDFORMATWRITER_HPP_
#define _ISHIKO_CPP_DIFF_DIFFUNIFIEDFORMATWRITER_HPP_

#include "TextPatch.hpp"
#include <boost/filesystem.hpp>
#include <Ishiko/Errors.hpp>
#include <Ishiko/FileSystem.hpp>

namespace Ishiko
{

// TODO: this doesn't respect the spec even closely. This is some quick stuff I need to be able to display some output
// and I will fix as needed
class DiffUnifiedFormatWriter
{
public:
    // TODO: do I want to support writing to a stream
    DiffUnifiedFormatWriter(const boost::filesystem::path& outputFile, Ishiko::Error& error);
    void close();

    void writeOriginalFilePath(const std::string& path);
    void writeNewFilePath(const std::string& path);
    void write(const TextPatch& patch);

private:
    TextFile m_outputFile;
};

}

#endif
