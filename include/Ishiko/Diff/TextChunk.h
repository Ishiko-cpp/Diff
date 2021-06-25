/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_DIFF_TEXTCHUNK_
#define _ISHIKO_DIFF_TEXTCHUNK_

#include <string>

namespace Ishiko
{
namespace Diff
{

class TextChunk
{
public:
    enum Type
    {
        eIdentical,
        eDeletion,
        eInsertion
    };

    TextChunk(size_t originalPosition, size_t newPosition, Type type, const std::string& text);
    
    size_t originalPosition() const;
    size_t newPosition() const;
    Type type() const;
    const std::string& text() const;

private:
    size_t m_originalPosition;
    size_t m_newPosition;
    Type m_type;
    std::string m_text;
};

}
}

#endif
