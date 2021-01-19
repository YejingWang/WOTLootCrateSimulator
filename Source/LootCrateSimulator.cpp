/***************************************************
* Author: weiyuyijin
* Date: 2020/12/12
****************************************************/

#include "Util.hpp"
#include "RngGenerator.hpp"
#include "LootCrateSimulator.hpp"

static RngGenerator<double> rng(0., 1.);

bool loadString(
    nlohmann::json& jsonNode,
    const std::string& content)
{
    try {
        jsonNode = nlohmann::json::parse(content);
        return true;
    }
    catch (nlohmann::json::parse_error& e) {
        std::string s;
        size_t pos1 = (e.byte - 50 < 0 ? 0 : e.byte - 50);
        if (e.byte > 1) {
            s += content.substr(pos1, e.byte - 1 - pos1);
        }
        s += " [[[ " + content.substr(e.byte - 1, 1) + " ]]] ";
        if (e.byte < content.length()) {
            s += content.substr(e.byte);
        }
        printf("Failed to parse json string near the [[[]]] marks: [%s]", s.c_str());
        printf("Error %d: %s", e.id, e.what());
        return false;
    }
    catch (...) {
        printf("Unknown errors when parsing json string [%s]", content.c_str());
        return false;
    }
}

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

bool LootCrateSimulator::loadJson(const std::string& fileName, nlohmann::json& jsonNode)
{
    try {
        std::string fileContent = Util::readUTF8StringFromFile(fileName);
        loadString(jsonNode, fileContent);
        return true;
    }
    catch (...) {
        printf("Failed to load json file [%s]", fileName.c_str());
        return false;
    }
}

bool LootCrateSimulator::wirteToFile(const std::string& fileName)
{
    nlohmann::json node;

    std::string str = node.dump();
}
