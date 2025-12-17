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

## Quelques photos

- ![Le transceiver LoRa](/docs/LoRaTransceiver.jpg)
- ![La connexion du trasnceiver à une carte Arduino](/docs/LoRa_connection.jpg) avec une potentiomètre.