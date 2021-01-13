/***************************************************
* Author: weiyuyijin
* Date: 2020/12/12
****************************************************/

#include <random>

template <typename T>
class RngGenerator
{
public:
    RngGenerator(const T low, const T high) :
        mEngine(std::random_device()()),
        mDistribution(low, high)
    {}

    T operator()() {
        return mDistribution(mEngine);
    }

private:
    std::default_random_engine mEngine;
    std::uniform_real_distribution<T> mDistribution;
};
