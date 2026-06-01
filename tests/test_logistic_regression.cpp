#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "logistic_regression.h"

TEST_CASE("Sigmoid Function") { 
    LogisticRegression lr;

    REQUIRE_THAT(
        lr.sigmoid_for_test(0.0),
        Catch::Matchers::WithinAbs(0.5, 1e-6)
    );
    REQUIRE_THAT(
        lr.sigmoid_for_test(1.0),
        Catch::Matchers::WithinAbs(0.7310585786300049, 1e-6)    
    );
    REQUIRE_THAT(
        lr.sigmoid_for_test(-1.0),
        Catch::Matchers::WithinAbs(0.2689414213699951, 1e-6)    
    );  
}

TEST_CASE("Predict Function Bounds Test") { 

    LogisticRegression lr;

    std::vector<double> x{1.0, 2.0};

    double p = lr.predict(x);

    REQUIRE(p >= 0.0);
    REQUIRE(p <= 1.0);
}

TEST_CASE("Simple Fit Test") { 
    std::vector<std::vector<double>> X = {
        {0.0, 0.0},
        {1.0, 0.0},
        {4.0, 1.0},
        {5.0, 1.0}
    };

    std::vector<double> y = {0.0, 0.0, 1.0, 1.0};

    LogisticRegression lr;
    lr.fit(X, y, 100);
    double acc = lr.accuracy(X, y);

    REQUIRE(acc == 1.0);
}

  