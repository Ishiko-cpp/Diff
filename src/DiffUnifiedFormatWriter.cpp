/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#include "DiffUnifiedFormatWriter.hpp"

using namespace Ishiko;

DiffUnifiedFormatWriter::DiffUnifiedFormatWriter(const boost::filesystem::path& outputFile, Ishiko::Error& error)
{
    m_outputFile.create(outputFile, error);
}

void DiffUnifiedFormatWriter::close()
{
    m_outputFile.close();
}

void DiffUnifiedFormatWriter::writeOriginalFilePath(const std::string& path)
{
    m_outputFile.write("--- ");
    m_outputFile.writeLine(path.c_str());
    // TODO: timestamp?
}

void DiffUnifiedFormatWriter::writeNewFilePath(const std::string& path)
{
    m_outputFile.write("+++ ");
    m_outputFile.writeLine(path.c_str());
    // TODO: timestamp?
}

void DiffUnifiedFormatWriter::write(const TextPatch& patch)
{
}
