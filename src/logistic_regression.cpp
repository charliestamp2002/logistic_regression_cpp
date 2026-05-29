#include "logistic_regression.h"

#include <cmath>

LogisticRegression::LogisticRegression()
:bias_(0.0), learning_rate_(0.01) 
{
}

double LogisticRegression::sigmoid(double z) const {
    // return 1.0/(1.0 + std::exp(-z));
    if (z >= 0) {
        return 1.0/(1.0 + std::exp(-z));
    }
    else {
        return std::exp(z)/(1.0 + std::exp(z));
    }  
}

double LogisticRegression::predict(const std::vector<double>& x) const {

    double sum{0.0};
    for (size_t i = 0; i < x.size() && i < weights_.size(); i++) {
        sum += weights_[i] * x[i];
    } 
    double z = sum + bias_;

    return sigmoid(z);
}

void LogisticRegression::fit(const std::vector<std::vector<double>>& X, const std::vector<double>& y, int epochs) {
    size_t num_samples = X.size();
    size_t num_features = X[0].size();

    weights_ = std::vector<double>(num_features, 0.0);

    for (int epoch = 0; epoch < epochs; epoch++) {
        for (size_t i = 0; i < num_samples; i++) {
            double y_pred = predict(X[i]);
            double error = y_pred - y[i];
            for (size_t j = 0; j < num_features; j++) {
                weights_[j] = weights_[j] - (learning_rate_ * error * X[i][j]);
            }
            bias_ = bias_ - (learning_rate_ * error);
        }
    }
}

double LogisticRegression::accuracy(const std::vector<std::vector<double>>& X, const std::vector<double>& y) const {

    size_t num_samples = X.size();
    int correct = 0;
     

    for (size_t i = 0; i < num_samples; i++) {
        double pred = predict(X[i]);
        int pred_class{};
   
        if (pred >= 0.5) {
            pred_class = 1;
        }
        else {
            pred_class = 0;
        }

        if (pred_class == static_cast<int>(y[i])) {
            correct += 1;
        }
        else {
            continue;
        }
    }
    double acc = static_cast<double>(correct) / num_samples;
    return acc;

}



