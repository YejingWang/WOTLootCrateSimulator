/***************************************************
* Author: weiyuyijin
* Date: 2020/12/12
****************************************************/

#include "nlohmann/json.hpp"
#include "LootCrateSimulator.hpp"

std::string Prize::result() const
{
    return "";
}

std::string PrizePack::roll() const
{
    if (mRepeatedDraw) {

    }
    else {

    }
    return "";
}

void LootCrateSimulator::roll()
{
    for (unsigned int i = 0; i < mRollTime; ++i) {
        for (auto& p : mPrizePacks) {

        }
    }
}