/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_DIFF_TEXTPATCH_H_
#define _ISHIKO_DIFF_TEXTPATCH_H_

#include <vector>

namespace Ishiko
{
namespace Diff
{

class TextPatch
{
public:
    class Chunk
    {
    };

    bool hasChanges() const;

    size_t size() const;

private:
    std::vector<Chunk> m_chunks;
};

}
}

#include "linkoptions.h"

#endif
