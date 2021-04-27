/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#include "TextPatch.h"

namespace Ishiko
{
namespace Diff
{

bool TextPatch::hasChanges() const
{
    return !m_chunks.empty();
}

size_t TextPatch::size() const
{
    return m_chunks.size();
}

}
}
