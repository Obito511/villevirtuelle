#ifndef SIMULATION_H
#define SIMULATION_H

#include "Ville.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Simulation {
private:
    int cycleActuel;  // Numéro du cycle actuel
    Ville* ville;  // Instance de la ville
    std::vector<std::string> evenements;  // Liste des événements

    // Méthode pour générer un événement aléatoire
    void genererEvenementAleatoire();

public:
    // Constructeur
    Simulation(Ville* ville);

    // Méthode pour démarrer un cycle
    void demarrerCycle();

    // Méthode pour terminer un cycle
    void terminerCycle();

    // Méthode pour déclencher un événement
    void declencherEvenement(const std::string& evenement);

    // Affichage des détails de la simulation
    void afficherDetails() const;

    // Accesseur pour le cycle actuel
    int getCycleActuel() const;

    // Destructeur
    ~Simulation();
};

#endif // SIMULATION_H
