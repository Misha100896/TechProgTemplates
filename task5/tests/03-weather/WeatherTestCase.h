
#pragma once

#include <gtest/gtest.h>
#include <Weather.h>
#include "WeatherMock.h"

class WeatherTestCase : public ::testing::Test {
protected:
    void SetUp() {
        weather = new WeatherMock;

        // Mock1
        cpr::Response mockResponse1;
        mockResponse1.status_code = 404;
        EXPECT_CALL(*weather, Get("abacaba")).WillRepeatedly(testing::Return(mockResponse1));

        // Mock2
        cpr::Response mockResponse2;
        mockResponse2.status_code = 200;
        mockResponse2.text = "{\"list\" : [{\"main\": {\"temp\": 15}}]}";
        EXPECT_CALL(*weather, Get("London")).WillRepeatedly(testing::Return(mockResponse2));

        // Mock3
        cpr::Response mockResponse3;
        mockResponse3.status_code = 200;
        mockResponse3.text = "{\"list\" : [{\"main\": {\"temp\": 10}}]}";
        EXPECT_CALL(*weather, Get("Moscow")).WillRepeatedly(testing::Return(mockResponse3));


    }

    void TearDown() {
        delete weather;
    }
    WeatherMock *weather;
};



