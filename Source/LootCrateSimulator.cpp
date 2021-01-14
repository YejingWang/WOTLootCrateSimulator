/***************************************************
* Author: weiyuyijin
* Date: 2020/12/12
****************************************************/

#include "nlohmann/json.hpp"
#include "RngGenerator.hpp"
#include "LootCrateSimulator.hpp"

static RngGenerator<double> rng(0., 1.);

void PrizePack::roll()
{
    if (mRepeatedDraw) {
        for (auto& prize : mPrizes) {
            if (rng() < mOdds) {
                mResult += prize.name();
            }
        }
    }
    else {
        double rngRes = rng();
        if (rngRes < mOdds) {
            mResult += mPrizes[(size_t)(rngRes / (mOdds / mPrizes.size()))].name();
        }
    }
}

void LootCrateSimulator::roll()
{
    for (unsigned int i = 0; i < mRollTime; ++i) {
        for (auto& p : mPrizePacks) {

        }
    }
}