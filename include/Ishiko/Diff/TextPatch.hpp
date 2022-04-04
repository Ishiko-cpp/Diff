/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_DIFF_TEXTPATCH_HPP_
#define _ISHIKO_CPP_DIFF_TEXTPATCH_HPP_

#include "TextChunk.hpp"
#include <vector>

namespace Ishiko
{

class TextPatch
{
public:
    bool hasChanges() const;

    size_t size() const;
    const TextChunk& operator[](size_t index) const;

    void append(const TextChunk& chunk);

private:
    std::vector<TextChunk> m_chunks;
};

}

#endif
