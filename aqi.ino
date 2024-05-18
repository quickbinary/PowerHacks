/* AIR QUALITY MONITORING SYSTEM */
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include <WiFi.h>
#include <Tomoto_HM330X.h>

const char THING_ID[] = "your_thing_id";
const char DEVICE_ID[] = "your_device_id";
const char SSID[]     = "YOUR_WIFI_SSID";
const char PASS[]     = "YOUR_WIFI_PASSWORD";

Tomoto_HM330X sensor;
float pm2_5;
int aqi;
String aqiDescription;

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);

// AQI calculation based on US EPA standards (https://www.airnow.gov/aqi/aqi-basics/)
int getAQI(float pm2_5) {
  if (pm2_5 <= 12.0) {
    return 50; // Good
  } else if (pm2_5 <= 35.4) {
    return 100; // Moderate
  } else if (pm2_5 <= 55.4) {
    return 150; // Unhealthy for Sensitive Groups
  } else if (pm2_5 <= 150.4) {
    return 200; // Unhealthy
  } else if (pm2_5 <= 250.4) {
    return 300; // Very Unhealthy
  } else {
    return 400; // Hazardous
  }
}

void printValue(const char* label, int value) {
  Serial.print(label);
  Serial.print(": ");
  Serial.println(value);
}

void initProperties() {
  ArduinoCloud.addProperty(pm2_5, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(aqi, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(aqiDescription, READ, 1 * SECONDS, NULL);
}

void setup() {
  Serial.begin(115200);
  delay(100);

  if (!sensor.begin()) {
    Serial.println("Failed to initialize HM330X");
    while (1)
      ;
  }

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  Serial.println("HM330X initialized");
  Serial.println();
}

void loop() {
  ArduinoCloud.update();

  if (!sensor.readSensor()) {
    Serial.println("Failed to read HM330X");
  } else {
    printValue("Sensor number", sensor.getSensorNumber());

    pm2_5 = sensor.std.getPM2_5();
    aqi = getAQI(pm2_5);

    Serial.println("Concentration based on atmospheric environment (ug/m^3) --");
    printValue("PM2.5", pm2_5);
    printValue("Air Quality Index (AQI)", aqi);

    // Determine AQI description based on the calculated value
    if (aqi <= 50) {
      aqiDescription = "Good";
    } else if (aqi <= 100) {
      aqiDescription = "Moderate";
    } else if (aqi <= 150) {
      aqiDescription = "Unhealthy for Sensitive Groups";
    } else if (aqi <= 200) {
      aqiDescription = "Unhealthy";
    } else if (aqi <= 300) {
      aqiDescription = "Very Unhealthy";
    } else {
      aqiDescription = "Hazardous";
    }

    Serial.print("AQI Description: ");
    Serial.println(aqiDescription);
    Serial.println();
  }

  delay(5000);
}
