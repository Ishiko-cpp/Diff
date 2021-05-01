/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_DIFF_TEXTPATCH_H_
#define _ISHIKO_DIFF_TEXTPATCH_H_

#include "TextChunk.h"
#include <vector>

namespace Ishiko
{
namespace Diff
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
}

#include "linkoptions.h"

#endif
