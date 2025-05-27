#ifndef LINEAR_REGRESSION_HPP
#define LINEAR_REGRESSION_HPP

#include <vector>

class LinearRegression
{
    // input or predictors
    std::vector<std::vector<double> > m_X;

    // output or targets
    std::vector<double> m_y;

    // weights to be determined
    std::vector<double> m_w;

    // bias term to be determined
    double m_b;

    // number of columns
    int m_numFeatures;

    // sample size
    int m_numSamples;

    // target average
    double m_yAvg;

    // other intermediate vectors and matrices
    std::vector<double> m_Uy;
    std::vector<double> m_XTUy;
    std::vector<std::vector<double> > m_XTUX;
    std::vector<std::vector<double> > m_XTX;
    std::vector<double> m_XrowSum;
    std::vector<std::vector<double> > m_XTUXInv;
private:
    void calculateWeights();
    void calculateBias();
    void initialize();

public:
    LinearRegression(const std::vector<std::vector<double> >& X, const std::vector<double>& y);
    void solve();
};

#endif