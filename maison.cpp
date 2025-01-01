#include "maison.h"
#include <iostream>

// Constructeur
Maison::Maison(int id, const QString& nom, const QString& type, double consommationEau, double consommationElectricite, double effetSatisfaction, int capaciteHabitants)
    : Batiment(id, nom, type, consommationEau, consommationElectricite, effetSatisfaction),
    capaciteHabitants(capaciteHabitants),
    habitantsActuels(0) {}

// Méthode pour ajouter des habitants
void Maison::ajouterHabitants(int nb) {
    if (nb < 0) {
        std::cerr << "Le nombre d'habitants à ajouter doit être positif." << std::endl;
        return;
    }
    habitantsActuels = std::min(habitantsActuels + nb, capaciteHabitants);
}

// Méthode pour retirer des habitants
void Maison::retirerHabitants(int nb) {
    if (nb < 0) {
        std::cerr << "Le nombre d'habitants à retirer doit être positif." << std::endl;
        return;
    }
    habitantsActuels = std::max(habitantsActuels - nb, 0);
}

// Affichage des détails
void Maison::afficherDetails() const {
    Batiment::afficherDetails();
    std::cout << "Capacité des habitants: " << capaciteHabitants << "\n"
              << "Habitants actuels: " << habitantsActuels << "\n";
}

// Accesseurs
int Maison::getCapaciteHabitants() const {
    return capaciteHabitants;
}

int Maison::getHabitantsActuels() const {
    return habitantsActuels;
}

// Mutateurs
void Maison::setCapaciteHabitants(int newCapacite) {
    capaciteHabitants = newCapacite;
}
