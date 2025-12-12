#include <SoftwareSerial.h>
#include <SPI.h>

#define txPin 5
#define rxPin 6

SoftwareSerial mySerial(rxPin, txPin);
rn2xx3 myLora(mySerial);

void commLoRa(String msg)
{
    myLora.tx(msg);
}

void initialize_radio()
{
    // Reset RN2483
    pinMode(12, OUTPUT);
    digitalWrite(12, LOW);
    delay(500);
    digitalWrite(12, HIGH);

    delay(100); // wait for the RN2xx3's startup message
    mySerial.flush();

    myLora.autobaud();

    String hweui = myLora.hweui();
    while (hweui.length() != 16)
    {
        Serial.println("Communication with RN2483 unsuccessful. Power cycle the board.");
        Serial.println(hweui);
        delay(10000);
        hweui = myLora.hweui();
    }

    // print out the HWEUI
    Serial.println("When using OTAA, register this DevEUI: ");
    Serial.println(myLora.hweui());
    Serial.println("RN2483 firmware version:");
    Serial.println(myLora.sysver());

    // Join via OTAA
    Serial.println("Trying to join Chirpstack");
    bool join_result = false;
    const char *Eui = ""; // Here put the AppEUI provided by Chirpstack
    const char *Key = ""; // Here put the AppKey provided by Chirpstack
    join_result = myLora.initOTAA(Eui, Key);

    while (!join_result)
    {
        Serial.println("Unable to join. Trying again...");
        delay(10000);
        join_result = myLora.init();
    }
    Serial.println("Successfully joined Chirpstack!");
}

void setup()
{
    Serial.begin(57600);  // serial port to computer
    mySerial.begin(9600); // serial port to radio
    Serial.println("Startup LoRa");
    initialize_radio();
}

void loop()
{
    // Exemple
    int sensorValue = analogRead(A0); //valeur dans la pin A0
    Serial.println(sensorValue);
    // Envoyer via LoRa
    commLoRa(String(sensorValue));
    delay(10000); // Attendre 10 secondes avant le prochain envoi
}