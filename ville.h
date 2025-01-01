#ifndef VILLE_H
#define VILLE_H

#include "Batiment.h"
#include "maison.h"
#include "parc.h"
#include "usine.h"
#include <QString>
#include <vector>
#include <algorithm>
#include <iostream>

class Ville {
private:
    QString nom;                        // Nom de la ville
    double budget;                      // Budget de la ville
    int population;                     // Population totale de la ville
    double satisfaction;                // Niveau de satisfaction des habitants
    std::vector<Batiment*> batiments;   // Liste des bâtiments de la ville
    double ressourcesEau;               // Ressources en eau disponibles
    double ressourcesElectricite;       // Ressources en électricité disponibles

public:
    // Constructeur
    Ville(const QString& nom, double budget, int population, double ressourcesEau, double ressourcesElectricite);

    // Ajouter un bâtiment
    void ajouterBatiment(Batiment* b);

    // Modifier un bâtiment
    void modifierBatiment(const Batiment& batimentModifie);

    // Supprimer un bâtiment par ID
    void supprimerBatiment(int id);

    // Calculer la consommation totale d'eau et d'électricité
    void calculerConsommationTotale() const;

    // Vérifier l'équilibre des ressources
    void verifierEquilibreRessources();

    // Optimiser les ressources
    void optimiserRessources();

    // Calculer le niveau de satisfaction moyen
    void calculerSatisfaction();

    // Surveiller et maintenir le niveau de satisfaction
    void surveillerSatisfaction();

    // Ajouter un parc
    void ajouterParc(const Parc& parc);

    // Afficher les détails de la ville
    void afficherDetails() const;

    // Interrompre la production des usines
    void interrompreProductionUsines();

    // Réduire l'effet des parcs
    void reduireEffetParcs(double facteur);

    // Accesseurs
    QString getNom() const;
    double getBudget() const;
    int getPopulation() const;
    double getSatisfaction() const;
    double getRessourcesEau() const;
    double getRessourcesElectricite() const;

    // Mutateurs
    void setBudget(double newBudget);
    void setPopulation(int newPopulation);
    void setRessourcesEau(double newEau);
    void setRessourcesElectricite(double newElectricite);
    void setSatisfaction(double newSatisfaction);

    // Destructeur
    ~Ville();
};


#endif // VILLE_H
