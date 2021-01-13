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
    Prize(const std::string name = "", const PrizeCategory category = PrizeCategory::eTank,
        const unsigned int goldValue = 0, const unsigned int creditValue = 0, const bool useGoldForCompensation = true) :
        mName(name),
        mCategory(category),
        mGoldValue(goldValue),
        mCreditValue(creditValue),
        mUseGoldForCompensation(useGoldForCompensation)
    {}
    ~Prize() = default;

    std::string result() const;

private:
    std::string mName;
    PrizeCategory mCategory;
    unsigned int mGoldValue;
    unsigned int mCreditValue;
    bool mUseGoldForCompensation;
};

class PrizePack
{
public:
    PrizePack(const std::string& name = "", const double odds = 0., const bool repeatedDraw = false) :
        mName(name),
        mOdds(odds),
        mPrizes()
    {}
    ~PrizePack() = default;

    void setOdds(const double odds) { mOdds = odds; }
    void addPrize(const Prize& prize) { mPrizes.push_back(prize); }

    std::string roll() const;

private:
    std::string mName;
    double mOdds;
    bool mRepeatedDraw;
    std::vector<Prize> mPrizes;
};

class LootCrateSimulator
{
public:
    LootCrateSimulator(const unsigned int rollTime = 50) :
        mRollTime(rollTime),
        mPrizePacks()
    {
    }

private:
    std::string getCurrentDirectory() const;
    void roll();

    unsigned int mRollTime;
    std::vector<PrizePack> mPrizePacks;
};
