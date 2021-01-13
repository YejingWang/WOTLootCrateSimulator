/***************************************************
* Author: weiyuyijin
* Date: 2020/12/12
****************************************************/

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

class Prize
{
    enum PrizeCategory {
        eTank,
        eGold,
        eCredit,
        ePremiumAccount,
        e3DStyle,
        e2DStyle,
        eDecal,
        eDecoration
    };

public:
    Prize(const std::string name = "", const unsigned int goldValue = 0,
        const unsigned int creditValue = 0, const bool useGoldForCompensation = true) :
        mName(name),
        mGoldValue(goldValue),
        mCreditValue(creditValue),
        mUseGoldForCompensation(useGoldForCompensation)
    {}
    ~Prize() = default;

    std::string result() const;

private:
    std::string mName;
    unsigned int mGoldValue;
    unsigned int mCreditValue;
    bool mUseGoldForCompensation;
};

class PrizeType : public std::vector<Prize>
{
    PrizeType(const bool repeatedDraw = false) :
        mRepeatedDraw(repeatedDraw)
    {}
    ~PrizeType() = default;

private:
    bool mRepeatedDraw;
};

class LootCrateSimulator
{
public:
    LootCrateSimulator(const unsigned int rollTime = 50) :
        mRollTime(rollTime),
        mPrizes()
    {
    }

private:
    std::string getCurrentDirectory() const;
    void roll();

    unsigned int mRollTime;
    std::unordered_map<double, PrizeType> mPrizes;
};
