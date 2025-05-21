#ifndef STATUTILS_HPP
#define STATUTILS_HPP

#include <vector>

double getMean(const std::vector<double>& vec);
double getMedian(const std::vector<double>& vec);
std::vector<double> getSortedVector(const std::vector<double>& vec);

#endif