# Smart Devices

Développé par Marie-Lien Da Costa Bento, Célian Hilal Hamdan et Jean-Phillipe Loubejac--Combalbert pour le cours *Microcontroller and Open Source Hardware*.

## Organisation

Dans ce repo, vous pourrez trouver:

- sur la branche *main*:
  - Les fichiers de simulation [LTSpice](/LTSpice/)
  - Les fichiers de schémas et de routage [KiCad](/KiCAD/)
  - Le montage du [transceiver LoRa](/LoRa) pour notre réseau et sa [configuration arduino](/LoRa/LoRaConnection.ino).
  - Le [TP](/MIT_App/) sur la partie application android avec MIT_App.
  - La datasheet de notre capteur.
  - README.md

## Usage

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

## Node-RED

Nous avons développé un tableau de bord avec [Node-RED](/NodeRED/) pour visualiser les données transmises via LoRa. Ce tableau de bord simple affiche :
    - la dernière valeur mesurée,
    - une jauge indiquant la position de cette valeur par rapport aux seuils minimum et maximum de gaz détectables par le capteur,
    - ainsi que la variation de la quantité de gaz.

<img src="/docs/gauge.png" width="324" height="546"/>

## MIT Application
