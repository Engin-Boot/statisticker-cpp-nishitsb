#include "stats.h"

std::vector<float> removeNaN(const std::vector<float> &inputNumbers)
{
    std::vector<float> floatInputs;
    for (float x : inputNumbers)
    {
        if (!std::isnan(x))
        {
            floatInputs.push_back(x);
        }
    }
    return floatInputs;
}

float getAverage(const std::vector<float> &inputNumbers)
{
    float sum = 0;
    int count = 0;

    for (float x : inputNumbers)
    {
        sum = sum + x;
        count++;
    }

    return sum / count;
}

float getMax(const std::vector<float> &inputNumbers)
{
    float max = std::numeric_limits<float>::min();

    for (float x : inputNumbers)
    {
        if (x > max)
            max = x;
    }
    return max;
}

float getMin(const std::vector<float> &inputNumbers)
{
    float min = std::numeric_limits<float>::max();

    for (float x : inputNumbers)
    {
        if (x < min)
            min = x;
    }
    return min;
}

Stats Statistics::ComputeStatistics(const std::vector<float> &inputNumbers)
{
    std::vector<float> floatInputs = removeNaN(inputNumbers);

    Stats stat;

    if (floatInputs.size() == 0  && inputNumbers.size()>=0)
    {
        stat.average = std::numeric_limits<float>::quiet_NaN();
        stat.min = std::numeric_limits<float>::quiet_NaN();
        stat.max = std::numeric_limits<float>::quiet_NaN();

        return stat;
    }

    stat = {getAverage(floatInputs), getMin(floatInputs), getMax(floatInputs)};

    return stat;
}