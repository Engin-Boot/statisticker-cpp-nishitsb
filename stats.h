#include <vector>
#include <limits>
#include <cmath>

struct Stats
    {
        float average;
        float min;
        float max;
    };

namespace Statistics
{
    Stats ComputeStatistics(const std::vector<float> &);
} // namespace Statistics
