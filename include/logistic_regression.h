#ifndef LOGISTIC_REGRESSION_H
#define LOGISTIC_REGRESSION_H

#include <string>
#include <vector>

class LogisticRegression {
    public:
        LogisticRegression();

        double predict(const std::vector<double>& x) const;
        void fit(const std::vector<std::vector<double>>& X, const std::vector<double>& y, int epochs);
        double accuracy(const std::vector<std::vector<double>>& X, const std::vector<double>& y) const;


    private: 
        double sigmoid(double z) const;
        double bias_;
        std::vector<double> weights_;
        double learning_rate_;

};

#endif