/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_DIFF_TEXTCHUNK_HPP_
#define _ISHIKO_CPP_DIFF_TEXTCHUNK_HPP_

#include <string>

namespace Ishiko
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

#endif
