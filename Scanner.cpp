#include <iostream>         // pour cout (affichage)
#include <cstring>          // pour memset
#include <sys/socket.h>     // pour socket(), connect()
#include <arpa/inet.h>      // pour sockaddr_in, inet_pton()
#include <unistd.h>         // pour close()

int main() {
    const char* cible = "192.168.64.2";  // la cible à scanner

    for (int port = 1; port <= 1024; port++) {

        // 1. Créer le socket TCP
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) continue;   // si erreur, on passe au port suivant

        // 2. Préparer l'adresse de la cible (IP + port)
        sockaddr_in adresse;
        memset(&adresse, 0, sizeof(adresse));           // remplir de zéros
        adresse.sin_family = AF_INET;                   // IPv4
        adresse.sin_port = htons(port);                 // port (format réseau)
        inet_pton(AF_INET, cible, &adresse.sin_addr);    // IP texte -> binaire

        // 3. Tenter la connexion (déclenche le handshake TCP)
        int resultat = connect(sock, (sockaddr*)&adresse, sizeof(adresse));

        // 4. Analyser le résultat
        if (resultat == 0) {
            std::cout << "Port " << port << " : OUVERT\n";
        }

        // 5. Raccrocher avant de passer au port suivant
        close(sock);
    }

    return 0;
}