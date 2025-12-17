# Construction du transceiver LoRa 

## Soudure

On a un module LoRa [RN2483](/docs/RN2483_datasheet.pdf) dont on va souder seulement les pins qui nous intéresse sur une carte fille:

- `GND` : la terre
- `Vin` : tension d'alimentation dont on aura besoin pour alimenter notre capteur
- `3v3`
- `RST` : reset
- Les 4 bus de communication UART:
  - `RTS`
  - `CTS`
  - `RX`
  - `TX`

## Programmes

- [Initialisation](/LoRaConnection)
- [Ajout d'une LED](/LoRaConnectionWithLED)

## Quelques photos

- ![Le transceiver LoRa](/docs/LoRaTransceiver.jpg)
- ![La connexion du transceiver à une carte Arduino](/docs/LoRa_connection.jpg) avec un potentiomètre.
- ![La LED qui s'allume](/docs/LoRa_connection.jpg) selon la valeur du potentiomètre.