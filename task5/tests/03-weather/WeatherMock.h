//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#pragma once

#include <gmock/gmock.h>
#include <Weather.h>

class WeatherMock : public Weather {
public:
    MOCK_METHOD1(Get, cpr::Response(const std::string& city));
};



