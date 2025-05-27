#include "linear_regression.hpp"

std::vector<std::vector<double> > getInverse(const std::vector<std::vector<double> >& mat)
{
    int size = mat.size();
    std::vector<std::vector<double> > ret;
    for(int i = 0; i < size; i++)
    {
        std::vector<double> vec;
        for(int j = 0; j < size; j++)
        {
            vec.push_back((i == j) ? 1 : 0);
        }
        ret.push_back(vec);
    }
    return ret;
}

LinearRegression::LinearRegression(const std::vector<std::vector<double> >& X, const std::vector<double>& y)
{
    m_X = X;
    m_y = y;
    initialize();
}

void LinearRegression::initialize()
{
    m_numSamples = m_X.size();
    m_numFeatures = (m_numSamples > 0) ? m_X[0].size() : 0;
    double ySum = 0;
    for(auto x: m_y)
    {
        ySum += x;
    }
    m_yAvg = ySum / m_numSamples;
    for(int i = 0; i < m_numSamples; i++)
    {
        m_Uy.push_back(m_y[i] - m_yAvg);
    }
    for(int j = 0; j < m_numFeatures; j++)
    {
        double sum = 0;
        for(int i = 0; i < m_numSamples; i++)
        {
            sum += m_X[i][j] * m_Uy[i];
        }
        m_XTUy.push_back(sum);
    }
    for(int j0 = 0; j0 < m_numFeatures; j0++)
    {
        std::vector<double> vec;
        for(int j1 = 0; j1 < m_numFeatures; j1++)
        {
            double sum = 0;
            for(int k = 0; k < m_numSamples; k++)
            {
                sum += m_X[k][j0] * m_X[k][j1];
            }
            vec.push_back(sum);
        }
        m_XTX.push_back(vec);
    }
    for(int j = 0; j < m_numFeatures; j++)
    {
        double sum = 0;
        for(int i = 0; i < m_numSamples; i++)
        {
            sum += m_X[i][j];
        }
        m_XrowSum.push_back(sum);
    }
    for(int j0 = 0; j0 < m_numFeatures; j0++)
    {
        std::vector<double> vec;
        for(int j1 = 0; j1 < m_numFeatures; j1++)
        {
            vec.push_back(m_XTX[j0][j1] - m_XrowSum[j0] * m_XrowSum[j1] / m_numSamples);
        }
        m_XTUX.push_back(vec);
    }
    m_XTUXInv = getInverse(m_XTUX);
}

void LinearRegression::calculateWeights()
{
    //
}

void LinearRegression::calculateBias()
{
    std::vector<double> sums;
    for(int i = 0; i < m_numSamples; i++)
    {
        double sum = m_y[i];
        for(int j = 0; j < m_numFeatures; j++)
        {
            sum -= (m_X[i][j] * m_w[j]);
        }
        sums.push_back(sum);
    }
    double sum = 0;
    for(auto x: sums)
    {
        sum += x;
    }
    m_b = sum / m_numSamples;
}

void LinearRegression::solve()
{
    calculateWeights();
    calculateBias();
}