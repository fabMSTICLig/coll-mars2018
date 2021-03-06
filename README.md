<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/3.0/fr/"><img alt="Licence Creative Commons" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/3.0/fr/88x31.png" /></a><br />Les différentes partie de ce projet sont mise à disposition selon les termes de la <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/3.0/fr/">Licence Creative Commons Attribution - Pas d’Utilisation Commerciale - Partage dans les Mêmes Conditions 3.0 France</a>.

---

# Semaine de découverte du Labex Persyval-Lab
Projets fait par des collégiens de 3ème durant le semaine de découverte du Labex Persyval-Lab.
Le prototype de base est un petit véhicule pilotable en wifi. Les élèves le personnalisent selon leur envies.

Il est composé de :
- Un pack de 3 piles AAA
- Une carte Wemos D1 mini
- Deux servomoteurs 9g à rotation continu
- Deux led RGB
- Un intérupteur magnétique
- Un capteur de luminosité

L'apparance/coque du prototype est réalisée en papier. Les élèves la concoivent sur des logiciels tels que sketchup ou openscad. Ils doivent prendre en compte les dimentions des éléments qui sont intégrés au prototype.

Trois prototypes différents ont été réalisés:
- un PacMan sur lequel on peux poser un objet. Réagie a la présence d'objet. (ProjetSV)
- une voiture dont le but est de toucher l'arriere de ou des voitures adverses pour leur faire perdre des point. (Projet2)
- une voiture qui porte un téléphone. Réagie a la présence du téléphone. (Projet3)


# Installation

- Installer le logiciel arduino [lien](https://www.arduino.cc/en/Main/Software)
- Installer le plugin pour la carte Wemos D1 mini (ESP8266). Suivre l'étape 1 du tutoriel suivant : [lien](https://projetsdiy.fr/programmer-esp8266-ide-arduino-librairies-gpio-web-serveur-client/)
- Ajouter les bibliotèques suivantes (suivre ce tutoriel [lien](https://www.arduino.cc/en/Guide/Libraries))
  - Adafruit NeoPixel
  - Bounce2
- Ajouter la librairie college se trouvant dans le dossier base dans les librairies arduino

