#include "Usine.h"
#include <iostream>

// Constructeur
Usine::Usine(int id, const QString& nom, const QString& type, double consommationEau, double consommationElectricite, double effetSatisfaction, double productionRessources, double pollution)
    : Batiment(id, nom, type, consommationEau, consommationElectricite, effetSatisfaction),
    productionRessources(productionRessources),
    pollution(pollution) {}

// Méthode pour produire des ressources
double Usine::produireRessources() const {
    return productionRessources;
}

// Méthode pour calculer la pollution
double Usine::calculerPollution() const {
    return pollution;
}

// Affichage des détails
void Usine::afficherDetails() const {
    Batiment::afficherDetails();
    std::cout << "Production de ressources: " << productionRessources << " unités/cycle\n"
              << "Pollution: " << pollution << " unités/cycle\n";
}

// Accesseurs
double Usine::getProductionRessources() const {
    return productionRessources;
}

double Usine::getPollution() const {
    return pollution;
}

// Mutateurs
void Usine::setProductionRessources(double newProduction) {
    productionRessources = newProduction;
}

void Usine::setPollution(double newPollution) {
    pollution = newPollution;
}
