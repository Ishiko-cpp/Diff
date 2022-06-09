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
    for (size_t i = 0; i < patch.size(); ++i)
    {
        const TextChunk& chunk = patch[i];
        switch (chunk.type())
        {
        case TextChunk::eDeletion:
            m_outputFile.write("-");
            break;

        case TextChunk::eIdentical:
            // TODO: in fact this doesn't work because the TextPatch we are creating do not contain the identical lines
            m_outputFile.write(" ");
            break;

        case TextChunk::eInsertion:
            m_outputFile.write("+");
            break;

        default:
            // TODO
            break;
        }
        m_outputFile.writeLine(chunk.text().c_str());
    }
}
