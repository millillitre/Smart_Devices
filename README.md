# Smart Devices

Développé par Marie-Lien Da Costa Bento, Célian Hilal Hamdan et Jean-Phillipe Loubejac--Combalbert pour le cours *Microcontroller and Open Source Hardware*.

## Organisation

Dans ce repo, vous pourrez trouver:

- sur la branche *main*:
  - Les fichiers de schémas et de routage [KiCad](/KiCAD/)
  - Les fichiers de simulation [LTSpice](/LTSpice/)
  - Le montage du [transceiver LoRa](/LoRa) pour notre réseau et sa [configuration arduino](/LoRa/LoRaConnection.ino).
  - Les configurations [MIT_App](/MIT_App/) sur la partie application.
  - Les fichiers de configuration [Node-RED](/NodeRED/)
  - Les différents [documents](/docs/) (photos, screenshots) utilisés pour appuyer notre propos.
  - La licence *Creative Commons*
  - La [datasheet](/Datasheet_gaz_sensor.pdf) de notre capteur.
  - [README.md](/README.md)

## Usage

### Matériels

Pour effectuer le projet, nous avons utilisé:
    - une carte Arduino UNO, 
    - un module LoRa,
    - les capteurs de gaz conçues à l'AIME.

### Communication

Pour obtenir les données via LoRa, nous avons eu besoin d'un accès à une gateway LoRa and un serveur (Chirpstack de l'INSA Toulouse dans notre cas)

## Le capteur de GAZ effectué à l'AIME

Voici, étape par étape, le travail que nous avons effectué pour fabriquer notre capteur à l'AIME.

### Etape 1 : Fabrication des nanoparticules du capteur

1. Synthèse des nanoparticules : préparation de nanobâtonnets de WO₃

   - Préparation des précurseurs (Na₂WO₄·2H₂O et NaCl)
   - Préparation de l’acide (HCl)
   - Recuit et refroidissement

2. Traitement post-synthèse des nanoparticules

   - Centrifugation
   - Stockage des nanobâtonnets dans un flacon

### Etape 2: Fabrication de la puce du capteur

1. Procédé de fabrication de la puce : [photolithographie métallique](/docs/Mask.jpg)

   - Séchage et dépôt de résine photosensible
   - Exposition aux UV
   - Développement
   - Gravure de l’aluminium
   - Recuit du métal
   - Sélection des meilleures puces

2. Conditionnement et assemblage du dispositif

   - Découpe diamantée de la puce
   - Montage sur le support à l’aide d’un adhésif époxy et polymérisation
   - Soudage par ultrasons des fils aluminium-silicium pour les connexions électriques

### Etape 3 : Fabrication de la phase finale du capteur

1. Procédé de diélectrophorèse

   - Intégration des nanoparticules (NP) par diélectrophorèse
   - Application d’une tension sinusoïdale aux électrodes interdigitées Peigne d'électrodes
   - Positionnement précis des nanoparticules sur le dispositif

### Etape 4 : Tests du capteur

1. Tests électriques préliminaires

   - Mesure des résistances aux bornes du capteur
   - Vérification des connexions électriques et du fonctionnement

2. Tests fonctionnels sous atmosphère gazeuse

   - Tests sous méthane, air synthétique et éthanol à 250 °C (522 K)

### Etape 5 : Caractérisation du capteur

1. Analyse par microscopie électronique à balayage (MEB)

   - Observation du capteur et de ses nanobâtonnets par [MEB](/docs/MEB.tif)

## Amplification du signal

Lors des TP d'Analog Electronic Labs, on a modélisé sur LTSpice un amplificateur. On peut le tretrouver [ici](/LTSpice/ampliyoplait_avec_capteur.asc).

Nous avons également mis en place l'amplificateur en banc de test [ici](/docs/montage_ampliop.png).

## Programmation du capteur et transmission via LoRa

### Montage et soudure du banc de test

Nous avons soudé et monté un transceiver LoRa pour notre réseau. Les détails de ces étapes sont accessibles [ici](/LoRa/README.md).

Nous avons également testé électriquement avec un wattmètre notre soudure.

### Transmission LoRa

Les communications sont accessibles sur [https://srv-chirpstack.insa-toulouse.fr](chirpstack).

## Conception du PCB via KiCAD
Nous avons suivi les instructions de M.Biganzoli, et nous avons décidé de faire une seule face, pour ne pas avoir de via et éviter d'avoir à connecter par nous me^me l'autre côté à l'aide de fils. 

Les fichiers du PCB sont trouvables [ici](/KiCAD/kicad-roger-shield-uno/).

<p align="center">
  <img src="/docs/pcbKICAD.png" width="324" alt="Design du PCB" />
</p>

Nous avons pu ensuite l'imprimer avec Cathy et nous avons percé un à un les trous. Nous avons également souder par la suite. Ci-dessous notre PCB imprimé et le montage:

<p align="center">
  <img src="/docs/pcb.jpg" width="324" alt="Impression du PCB" />
</p>

<p align="center">
  <img src="/docs/final.png" width="324" alt="Montage final" />
</p>

## Node-RED

Nous avons développé un tableau de bord avec [Node-RED](/NodeRED/) pour visualiser les données transmises via LoRa. Ce tableau de bord simple affiche :
    - la dernière valeur mesurée,
    - une jauge indiquant la position de cette valeur par rapport aux seuils minimum et maximum de gaz détectables par le capteur,
    - ainsi que la variation de la quantité de gaz.

<p align="center">
  <img src="/docs/gauge.png" width="324" alt="Jauge de mesure" />
</p>

## MIT Application
Nous avons mis en place une application pour mobile via MIT App, elle se trouve [ici](/MIT_App/Application/). L'idée de cette application est d'afficher la valeur du capteur de gaz en temps réel, qui change de coucleur si la valeur est critique et qui affiche un graphe d'évolution des valeurs.

<p align="center">
  <img src="/docs/application.png" width="324" alt="Application mobile" />
</p>
