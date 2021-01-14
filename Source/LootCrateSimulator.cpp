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
                mResult.push_back(prize);
            }
        }
    }
    else {
        double rngRes = rng();
        if (rngRes < mOdds) {
            mResult.push_back(mPrizes[(size_t)(rngRes / (mOdds / mPrizes.size()))]);
        }
    }
}

void LootCrateSimulator::roll()
{
    for (unsigned int i = 0; i < mRollTime; ++i) {
        for (auto& p : mPrizePacks) {
            p.roll();
        }
    }
}

std::string LootCrateSimulator::resultString() const
{
    std::string res;

    for (unsigned int i = 0; i < mRollTime; ++i) {
        for (auto& prizePack : mPrizePacks) {
            for (auto& prize : prizePack.result()) {
                switch (prize.category())
                {
                case Prize::PrizeCategory::eTank:
                    if (mResultSet.find(prize.name()) != mResultSet.end()) {
                        res += prize.name();
                    }
                    break;
                default:
                    break;
                }
            }
        }
    }

    return std::move(res);
}