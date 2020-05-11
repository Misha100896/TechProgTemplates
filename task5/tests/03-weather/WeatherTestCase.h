
#pragma once

#include <gtest/gtest.h>
#include <Weather.h>
#include "WeatherMock.h"

class WeatherTestCase : public ::testing::Test {
protected:
    void SetUp() {
        weather = new WeatherMock;
    }

    void TearDown() {
        delete weather;
    }
    Weather *weather;
};



