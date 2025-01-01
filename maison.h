#ifndef MAISON_H
#define MAISON_H

#include "Batiment.h"
#include <algorithm>
class Maison : public Batiment {
private:
    int capaciteHabitants;  // Capacité maximale des habitants
    int habitantsActuels;  // Nombre actuel d'habitants

public:
    // Constructeur
    Maison(int id, const QString& nom, const QString& type, double consommationEau, double consommationElectricite, double effetSatisfaction, int capaciteHabitants);

    // Méthode pour ajouter des habitants
    void ajouterHabitants(int nb);

    // Méthode pour retirer des habitants
    void retirerHabitants(int nb);

    // Affichage des détails
    void afficherDetails() const override;

    // Accesseurs
    int getCapaciteHabitants() const;
    int getHabitantsActuels() const;

    // Mutateurs
    void setCapaciteHabitants(int newCapacite);
};

#endif // MAISON_H
