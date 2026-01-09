#include <SoftwareSerial.h>
#include <rn2xx3.h> //https://github.com/jpmeijers/RN2483-Arduino-Library/blob/master/src/rn2xx3.h


#define txPin 5
#define rxPin 6
#define LedPin 2

SoftwareSerial mySerial(rxPin, txPin);
rn2xx3 Lora(mySerial);

void commLoRa(String msg)
{
    Lora.tx(msg);
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

    Lora.autobaud();

    String hweui = Lora.hweui();
    while (hweui.length() != 16)
    {
        Serial.println("Communication with RN2483 unsuccessful. Power cycle the board.");
        Serial.println(hweui);
        delay(10000);
        hweui = Lora.hweui();
    }

    // print out the HWEUI
    Serial.println("When using OTAA, register this DevEUI: ");
    Serial.println(Lora.hweui());
    Serial.println("RN2483 firmware version:");
    Serial.println(Lora.sysver());

    // Join via OTAA
    Serial.println("Trying to join Chirpstack");
    bool join_result = false;
    const char *Eui = "059e6eb52f689162"; // Here put the AppEUI provided by Chirpstack
    const char *Key = "d56f6d7d3433ed17318e00ec3dd543d2"; // Here put the AppKey provided by Chirpstack
    join_result = Lora.initOTAA(Eui, Key);

    while (!join_result)
    {
        Serial.println("Unable to join. Trying again...");
        delay(10000);
        join_result = Lora.init();
    }
    Serial.println("Successfully joined Chirpstack!");
}

void setup()
{
    pinMode(LedPin, OUTPUT);
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
    if (sensorValue > 500){
        digitalWrite(LedPin, HIGH);
    }
    else{
        digitalWrite(LedPin, LOW);
    }
    // Envoyer via LoRa
    commLoRa(String(sensorValue));
    delay(10000); // Attendre 10 secondes avant le prochain envoi
}