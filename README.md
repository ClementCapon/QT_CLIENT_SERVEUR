# Projet Client-Serveur TCP avec Qt

Ce projet implémente un système Client-Serveur TCP en utilisant le framework Qt. Il inclut :

  - Un serveur TCP qui écoute les connexions entrantes et répond aux messages des clients.

  - Un client TCP avec une interface utilisateur graphique (UI) permettant de se connecter au serveur, d'envoyer des messages et de lire les réponses.


Prérequis

Pour exécuter ce projet, vous avez besoin de :

- [x]  `1. Qt Creator (version 5 ou plus récente) : IDE pour développer des applications avec Qt.`


- [x]  `2. Qt Framework : Incluant les modules QtNetwork et QtWidgets.`


- [x]  `3. Une compréhension basique des notions de client/serveur et de réseau est un plus.`




---

## Installation et Configuration

### Étape 1 : Cloner ou télécharger le projet

1. Clonez ce dépôt sur votre machine :

  ```bash
  git clone https://votre-repo.git
  ```
ou téléchargez les fichiers et extrayez-les.



### Étape 2 : Ouvrir les fichiers dans Qt Creator

1. Lancez Qt Creator.


2. Ouvrez les fichiers .pro des deux projets :

server.pro : Pour le projet du serveur.

client.pro : Pour le projet du client.




Étape 3 : Compiler les projets

1. Dans Qt Creator, ouvrez chaque projet séparément.


2. Cliquez sur "Construire" (Build) pour compiler le serveur et le client.




---

Exécution

Démarrer le serveur

1. Lancez le projet serveur dans Qt Creator.


2. Le serveur écoute sur l'adresse 127.0.0.1 (localhost) et le port 1234.


3. Vérifiez la console du serveur pour les logs de connexion ou d'échange de messages.



Utiliser le client

1. Lancez le projet client dans Qt Creator.


2. Une interface s'ouvre avec :

Un champ de saisie pour entrer un message.

Deux boutons : Se connecter et Envoyer.



3. Cliquez sur Se connecter pour établir une connexion avec le serveur.


4. Entrez un message dans le champ de saisie, puis cliquez sur Envoyer.


5. Les réponses du serveur apparaîtront dans la console.




---

Fonctionnalités

1. Serveur TCP :

Accepte les connexions de clients sur l'adresse 127.0.0.1 et le port 1234.

Affiche dans la console les messages reçus des clients.

Répond automatiquement à certains messages. Par exemple, si le client envoie "hello", le serveur répond "Bonjour".



2. Client TCP :

Interface utilisateur simple pour interagir avec le serveur.

Permet de se connecter au serveur et d'envoyer des messages.

Affiche les réponses du serveur dans la console.





---

Dépannage

Si vous rencontrez des problèmes, voici quelques points à vérifier :

1. Erreur : Le serveur ne démarre pas

Assurez-vous qu'aucun autre programme n'utilise le port 1234.

Vous pouvez modifier le port dans le fichier server.cpp :

if (!tcpServer->listen(QHostAddress::Any, 1234)) {



2. Erreur : Le client ne peut pas se connecter au serveur

Vérifiez que le serveur est bien démarré.

Assurez-vous que le port et l'adresse IP dans client.cpp sont corrects :

tcpSocket->connectToHost("127.0.0.1", 1234);



3. Le message n’est pas envoyé ou reçu correctement

Assurez-vous d'utiliser le bouton Se connecter avant d'envoyer un message.

Vérifiez les logs de la console pour diagnostiquer les problèmes.





---

Structure des fichiers

Serveur :

server.h : Déclaration de la classe du serveur.

server.cpp : Implémentation du serveur TCP.

main.cpp : Point d'entrée pour lancer le serveur.

server.pro : Fichier de projet Qt.


Client :

client.h : Déclaration de la classe du client.

client.cpp : Implémentation du client TCP avec UI.

main.cpp : Point d'entrée pour lancer le client.

client.pro : Fichier de projet Qt.




---

Améliorations possibles

1. Sécurisation des échanges : Utilisez des sockets sécurisés (QSslSocket).


2. Gestion des erreurs avancée : Ajoutez une gestion détaillée des erreurs réseau.


3. Interface utilisateur améliorée : Ajoutez un affichage des messages reçus directement dans la fenêtre du client.




---
