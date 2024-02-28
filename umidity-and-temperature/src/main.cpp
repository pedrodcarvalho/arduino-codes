#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define READ_DELAY 2000
#define BAUD_RATE 9600

DHT dht(DHTPIN, DHTTYPE);

float humidity, temperature, heat_index = 0;

void setup() {
    Serial.begin(BAUD_RATE);

    dht.begin();
}

void loop() {
    delay(READ_DELAY);

    humidity = dht.readHumidity();
    temperature = dht.readTemperature();
    heat_index = dht.computeHeatIndex(temperature, humidity, false);

    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
    }
    else {
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.print("%\n");
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println("°C\n");
        Serial.print("Heat index: ");
        Serial.print(heat_index);
        Serial.println("°C\n");
    }
}
