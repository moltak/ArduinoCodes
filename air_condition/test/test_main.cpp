#include <Arduino.h>
#include <unity.h>
#include "ArduinoJson.h"

void test_json_parsing(void) {
    String raw =  "{\"RealtimeCityAir\":{\"list_total_count\":1,\"RESULT\":{\"CODE\":\"INFO-000\",\"MESSAGE\":\"정상 처리되었습니다\"},\"row\":[{\"MSRDT\":\"201812032000\",\"MSRRGN_NM\":\"동북권\",\"MSRSTE_NM\":\"성북구\",\"PM10\":33.0,\"PM25\":15.0,\"O3\":0.0070,\"NO2\":0.045,\"CO\":0.6,\"SO2\":0.0030,\"IDEX_NM\":\"보통\",\"IDEX_MVL\":75.0,\"ARPLT_MAIN\":\"NO2\"}]}}";

    StaticJsonBuffer<200> jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(raw);

    //fp.pm25 = root["RealtimeCityAir"]["row"][0]["PM25"];
    int list_total_count = root["RealtimeCityAir"]["list_total_count"];

    TEST_ASSERT_EQUAL(1, list_total_count);
}

void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(3000);

    UNITY_BEGIN();    // IMPORTANT LINE!

    RUN_TEST(test_json_parsing);
}


void loop()
{
}