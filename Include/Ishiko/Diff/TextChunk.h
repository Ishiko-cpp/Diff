/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
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

    TextChunk(Type type, const std::string& text);
    
    Type type() const;
    const std::string& text() const;

private:
    Type m_type;
    std::string m_text;
};

}
}

#endif
