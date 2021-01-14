/***************************************************
* Author: weiyuyijin
* Date: 2020/12/12
****************************************************/

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <unordered_set>

class Prize
{
public:
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

    Prize(const std::string name = "", const PrizeCategory category = PrizeCategory::eTank,
        const unsigned int goldValue = 0, const unsigned int creditValue = 0) :
        mName(name),
        mCategory(category),
        mGoldValue(goldValue),
        mCreditValue(creditValue)
    {}
    ~Prize() = default;

    std::string name() const { return mName; }
    PrizeCategory category() const { return mCategory; }

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
        mPrizes(),
        mResult()
    {}
    ~PrizePack() = default;

    std::string name() const { return mName; }
    void setOdds(const double odds) { mOdds = odds; }
    void addPrize(const Prize& prize) { mPrizes.push_back(prize); }

    void roll();
    std::vector<Prize> result() const { return mResult; }

private:
    std::string mName;
    double mOdds;
    bool mRepeatedDraw;
    std::vector<Prize> mPrizes;
    std::vector<Prize> mResult;
};

class LootCrateSimulator
{
public:
    LootCrateSimulator(const unsigned int rollTime = 50) :
        mRollTime(rollTime),
        mPrizePacks(),
        mResultSet()
    {
    }

    std::string resultString() const;

private:
    void roll();

    unsigned int mRollTime;
    std::vector<PrizePack> mPrizePacks;
    std::unordered_set<std::string> mResultSet;
};
