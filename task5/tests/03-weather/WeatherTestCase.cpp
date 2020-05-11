//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"


TEST_F(WeatherTestCase, GetResponseForCityInvalidArgument) {
    ASSERT_THROW(weather->GetResponseForCity("abacaba"), std::invalid_argument);
}

TEST_F(WeatherTestCase, GetResponseForCity) {
    auto cityInfo = weather->GetResponseForCity("London");
    auto answer = json::parse("{\"list\" : [{\"main\": {\"temp\": 15}}]}");
    ASSERT_EQ(cityInfo, answer);
}

TEST_F(WeatherTestCase, SetApiKey) {
    ASSERT_NO_THROW(weather->SetApiKey("my_api_key"));
}

TEST_F(WeatherTestCase, GetTemperature) {
    ASSERT_EQ(weather->GetTemperature("London"), 15);
}

TEST_F(WeatherTestCase, FindDiffBetweenTwoCities) {
ASSERT_EQ(weather->FindDiffBetweenTwoCities("London", "Moscow"), 5);
}

TEST_F(WeatherTestCase, GetDifferenceStringWarmer) {
    std::string answer = "Weather in London is warmer than in Moscow by 5 degrees";
    ASSERT_EQ(weather->GetDifferenceString("London", "Moscow"), answer);
}

TEST_F(WeatherTestCase, GetDifferenceStringColder) {
    std::string answer = "Weather in Moscow is colder than in London by 5 degrees";
    ASSERT_EQ(weather->GetDifferenceString("Moscow", "London"), answer);
}