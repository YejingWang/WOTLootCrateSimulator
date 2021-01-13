/***************************************************
* Author: Weiyuyijin
* Date: 2020/12/12
****************************************************/

#include <Windows.h>
#include <codecvt>

#include "nlohmann/json.hpp"
#include "LootCrateSimulator.hpp"

std::string w2u(const std::wstring &ws)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> conv;
    return conv.to_bytes(ws);
}

LootCrateSimulator::LootCrateSimulator(const unsigned int rollTime) :
    mRollTime(rollTime),
    mPrizePacks()
{}

std::string LootCrateSimulator::getCurrentDirectory() const
{
    wchar_t buffer[MAX_PATH];
    GetModuleFileNameW(NULL, buffer, MAX_PATH);
    std::wstring bufferW = buffer;
    return w2u(bufferW);
}
