/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#include "TextPatch.hpp"

namespace Ishiko
{

bool TextPatch::hasChanges() const
{
    return !m_chunks.empty();
}

size_t TextPatch::size() const
{
    return m_chunks.size();
}

const TextChunk& TextPatch::operator[](size_t index) const
{
    return m_chunks[index];
}

void TextPatch::append(const TextChunk& chunk)
{
    m_chunks.push_back(chunk);
}

}
