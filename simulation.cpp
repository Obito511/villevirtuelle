#include "simulation.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Constructeur
Simulation::Simulation(Ville* ville)
    : cycleActuel(0), ville(ville) {
    srand(time(0));  // Initialisation du générateur de nombres aléatoires
}

// Méthode pour générer un événement aléatoire
void Simulation::genererEvenementAleatoire() {
    int randomEvent = rand() % 5;  // Générer un nombre aléatoire entre 0 et 4
    switch (randomEvent) {
    case 0:
        declencherEvenement("Incendie");
        ville->setRessourcesEau(ville->getRessourcesEau() - 300);
        ville->setSatisfaction(ville->getSatisfaction() - 10);
        std::cout << "Un incendie a consommé 300 ressources d'eau et réduit la satisfaction de 10.\n";
        break;
    case 1:
        declencherEvenement("Nuée de pigeons géants");
        ville->setSatisfaction(ville->getSatisfaction() * 0.85);
        std::cout << "Une nuée de pigeons géants a envahi la ville, satisfaction diminuée de 15%.\n";
        break;
    case 2:
        declencherEvenement("Panne de courant");
        ville->setRessourcesElectricite(ville->getRessourcesElectricite() * 1.5);
        std::cout << "Une panne de courant augmente la consommation d'énergie de 50%.\n";
        break;
    case 3:
        declencherEvenement("Grève des jardiniers");
        ville->setSatisfaction(ville->getSatisfaction() - 20);
        ville->reduireEffetParcs(0.5);
        std::cout << "Les jardiniers sont en grève, satisfaction diminuée de 20% et effet des parcs réduit de moitié.\n";
        break;
    case 4:
        declencherEvenement("Tempête de neige");
        ville->interrompreProductionUsines();
        ville->setSatisfaction(ville->getSatisfaction() - 30);
        std::cout << "Une tempête de neige interrompt la production et réduit la satisfaction de 30.\n";
        break;
    default:
        break;
    }
}

// Méthode pour démarrer un cycle
void Simulation::demarrerCycle() {
    std::cout << "--- Cycle " << cycleActuel << " démarré ---\n";
    ville->calculerConsommationTotale();
    ville->calculerSatisfaction();
    genererEvenementAleatoire();
}

// Méthode pour terminer un cycle
void Simulation::terminerCycle() {
    std::cout << "--- Cycle " << cycleActuel << " terminé ---\n";
    cycleActuel++;
}

// Méthode pour déclencher un événement
void Simulation::declencherEvenement(const std::string& evenement) {
    evenements.push_back(evenement);
    std::cout << "\nÉvénement déclenché: " << evenement << "\n";
}

// Affichage des détails de la simulation
void Simulation::afficherDetails() const {
    std::cout << "Cycle actuel: " << cycleActuel << "\n";
    ville->afficherDetails();
    std::cout << "Événements passés: \n";
    for (const auto& evenement : evenements) {
        std::cout << "- " << evenement << "\n";
    }
}

// Accesseur pour le cycle actuel
int Simulation::getCycleActuel() const {
    return cycleActuel;
}

// Destructeur
Simulation::~Simulation() {
    delete ville;  // Libérer la mémoire de la ville
}
