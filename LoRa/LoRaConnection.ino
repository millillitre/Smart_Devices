#include <TheThingsNetwork.h>
#include <SoftwareSerial.h>

#define lora mySerial
#define debug Serial
#define freq TTN_FP_EU868 // plan de fréquence LoRaWAN : TTN_FP_EU868 pour l'Europe, TTN_FP_US915 pour les États-Unis

const byte t_pin = 11;
const byte r_pin = 10;
const int sensor_pin = 0;

SoftwareSerial mySerial(r_pin, t_pin);
TheThingsNetwork ttn(lora, debug, freq);

// Ici il faut créer un compte sur TheThingsNetwork
const char *Eui = ""; // identifiant unique de l'application TTN
const char *Key = ""; // clé secrète pour l'authentification et le chiffrement
int val = 0;          // stocke la valeur lue du capteur de gaz

void setup()
{
    lora.begin(57600);
    debug.begin(9600);
    ttn.join(Eui, Key); // rejoint le réseau TTN en utilisant l'EUI et la clé (nécessite un compte TTN configuré)
}

void loop()
{
    val = analogRead(sensor_pin);
    debug.println(val);
    byte payload[2];
    payload[0] = val & 0xFF;
    payload[1] = (val >> 8) & 0xFF;
    ttn.sendBytes(payload, sizeof(payload));
    delay(10000); // pause de 10 secondes entre chaque envoi pour éviter la surcharge
}