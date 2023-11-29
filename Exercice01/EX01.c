#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// Variable globale pour compter les signaux SIGINT reçus
int sigint_count = 0;

// Handler pour SIGINT
void sigint_handler(int signo) {
    if (signo == SIGINT) {
        sigint_count++;
        printf("\nNombre de signaux SIGINT reçus : %d\n", sigint_count);
    }
}

// Handler pour SIGTERM
void sigterm_handler(int signo) {
    if (signo == SIGTERM) {
        printf("\nReçu un signal SIGTERM. Fin du programme.\n");
        exit(EXIT_SUCCESS);
    }
}

int main() {
    // Affichage du PID du processus afin de pouvoir plus facilement l'identifier pour pouvoir lui envoyer un SIGTERM (kill -15 <PID>)
    printf("PID du processus : %d\n", getpid());

    // Configuration des handlers de signaux
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("Erreur lors de la configuration du gestionnaire de signal pour SIGINT");
        return EXIT_FAILURE;
    }

    if (signal(SIGTERM, sigterm_handler) == SIG_ERR) {
        perror("Erreur lors de la configuration du gestionnaire de signal pour SIGTERM");
        return EXIT_FAILURE;
    }

   while (1) {
        // Attente passive
    }

    return 0;
}
