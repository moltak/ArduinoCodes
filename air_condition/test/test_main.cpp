#include <Arduino.h>
#include <unity.h>
#include "ArduinoJson.h"

void test_simple_json_parsing(void)
{
    char json[] = "{\"PM10\":33.0,\"PM25\":15.0}";

    StaticJsonBuffer<200> jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(json);

    TEST_ASSERT_TRUE(root.success())
}

void test_extract_raw(void) {
    String raw = "[{\"PM10\":33.0,\"PM25\":15.0}]";

    String extracted = raw.substring(raw.indexOf("[") + 1, raw.indexOf("]"));

    TEST_ASSERT_EQUAL_STRING("{\"PM10\":33.0,\"PM25\":15.0}", extracted.c_str());
}

void test_json_parsing(void)
{
    String raw = "{\"a\":{\"b\":1,\"c\":{\"d\":\"0\"},\"row\":[{\"PM10\":33.0,\"PM25\":15.0}]}}";

    StaticJsonBuffer<200> jsonBuffer;
    String extracted = raw.substring(raw.indexOf("[") + 1, raw.indexOf("]"));

    JsonObject &root = jsonBuffer.parseObject(extracted);

    TEST_ASSERT_TRUE(root.success());

    double pm10 = root["PM10"];
    TEST_ASSERT_EQUAL(33.0, pm10);
}

void test_json_parsing_with_unicode(void)
{
    String raw = "{\"ko\": \"한글kr\"}";

    StaticJsonBuffer<200> jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(raw);

    TEST_ASSERT_TRUE(root.success());
}

void test_seoul_json_parsing(void) {
    String raw = "{\"RealtimeCityAir\":{\"list_total_count\":1,\"RESULT\":{\"CODE\":\"INFO-000\",\"MESSAGE\":\"정상 처리되었습니다\"},\"row\":[{\"MSRDT\":\"201812032000\",\"MSRRGN_NM\":\"동북권\",\"MSRSTE_NM\":\"성북구\",\"PM10\":33.0,\"PM25\":15.0,\"O3\":0.0070,\"NO2\":0.045,\"CO\":0.6,\"SO2\":0.0030,\"IDEX_NM\":\"보통\",\"IDEX_MVL\":75.0,\"ARPLT_MAIN\":\"NO2\"}]}}";

    StaticJsonBuffer<400> jsonBuffer;
    String extracted = raw.substring(raw.indexOf("[") + 1, raw.indexOf("]"));
    JsonObject &root = jsonBuffer.parseObject(extracted);

    TEST_ASSERT_TRUE(root.success());
}

void setup()
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(3000);

    UNITY_BEGIN(); // IMPORTANT LINE!

    RUN_TEST(test_extract_raw);
    RUN_TEST(test_simple_json_parsing);
    RUN_TEST(test_json_parsing);
    RUN_TEST(test_json_parsing_with_unicode);
    RUN_TEST(test_seoul_json_parsing);
}

void loop()
{
}