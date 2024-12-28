# Projet Euskal Plantxa 2023 : Partie Arduino/C++ par Ilyas

## 1. Identification du travail à faire
Dans ce projet, je dois programmer la carte Arduino Wemos afin de pouvoir lancer la cuisson en activant le relais et arrêter la plantxa en désactivant le relais. Je dois afficher le temps de cuisson de chaque client suite à une authentification avec un bouton poussoir, et une fois la cuisson lancée afficher le temps qui lui reste sur un afficheur matriciel. Une fois la cuisson finie, le temps restant doit être envoyé à la base de données.

### 1.2 Etude préliminaire
Chaque client dès l'arrivée au camping aura un numéro d’utilisateur pour qu’il puisse s’authentifier à une plantxa. Après avoir allumé la plantxa, il devra entrer son numéro d’utilisateur à l'aide d’un bouton poussoir et appuyer de nouveau sur le bouton de démarrage pour lancer la cuisson.

### 1.3 Outils matériels et logiciels utilisés

#### 1.3.1 Arduino Wemos D1 Mini
Une carte Wemos D1 est une carte électronique, proche de la carte UNO. Elle intègre un module WIFI ESP8266-12 en natif, une mémoire SPIFFS.

#### 1.3.2 Module Relais
Le module relais Arduino est un dispositif électromécanique qui sert à fermer et à ouvrir un circuit électrique au moyen d'un électroaimant commandant des contacts secs.

#### 1.3.3 Wemos Matrix Led Shield 16x16
Le Wemos Matrix est spécialement conçu pour être utilisé avec les cartes Wemos. Cet afficheur matriciel peut être utilisé pour créer des images, faire défiler du texte et plus encore.

Un potentiomètre est une résistance variable. Dans notre projet, le potentiomètre choisira le numéro de plancha, chose qui sera faite par le technicien le jour de la pose de la carte Wemos.
