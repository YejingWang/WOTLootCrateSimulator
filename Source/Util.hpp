/***************************************************
* Author: weiyuyijin
* Date: 2020/12/12
****************************************************/

#pragma once

#include <Windows.h>
#include <codecvt>

class Util
{
public:
    static std::string w2u(const std::wstring& ws) {
        std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> conv;
        return conv.to_bytes(ws);
    }

    static std::string getCurrentDirectory() {
        wchar_t buffer[MAX_PATH];
        GetModuleFileNameW(NULL, buffer, MAX_PATH);
        std::wstring bufferW = buffer;
        return w2u(bufferW);
    }
};
