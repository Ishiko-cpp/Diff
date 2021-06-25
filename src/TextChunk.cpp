/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#include "TextChunk.h"

namespace Ishiko
{
namespace Diff
{

TextChunk::TextChunk(size_t originalPosition, size_t newPosition, Type type, const std::string& text)
    : m_originalPosition(originalPosition), m_newPosition(newPosition), m_type(type), m_text(text)
{
}

size_t TextChunk::originalPosition() const
{
    return m_originalPosition;
}

size_t TextChunk::newPosition() const
{
    return m_newPosition;
}

TextChunk::Type TextChunk::type() const
{
    return m_type;
}

const std::string& TextChunk::text() const
{
    return m_text;
}

}
}
