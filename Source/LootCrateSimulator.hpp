/***************************************************
* Author: Weiyuyijin
* Date: 2020/12/12
****************************************************/

#pragma once

#include <string>
#include <vector>
#include <memory>

class Prize
{
    enum PrizeType {
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

class PrizePack
{
public:
    PrizePack(const std::string& name = "", const double odds = 0.) :
        mName(name),
        mOdds(odds),
        mPrizes()
    {}
    ~PrizePack() = default;

    void setOdds(const double odds) { mOdds = odds; }
    void addPrize(const Prize& prize) { mPrizes.push_back(prize); }

private:
    std::string mName;
    double mOdds;
    std::vector<Prize> mPrizes;
};

class LootCrateSimulator
{
public:
    LootCrateSimulator(const unsigned int rollTime = 50);

private:
    std::string getCurrentDirectory() const;

    unsigned int mRollTime;
    std::vector<PrizePack> mPrizePacks;
};
