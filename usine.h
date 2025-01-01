#ifndef USINE_H
#define USINE_H

#include "Batiment.h"

class Usine : public Batiment {
private:
    double productionRessources;  // Quantité de ressources produites par cycle
    double pollution;  // Pollution générée par cycle

public:
    // Constructeur
    Usine(int id, const QString& nom, const QString& type, double consommationEau, double consommationElectricite, double effetSatisfaction, double productionRessources, double pollution);

    // Méthode pour produire des ressources
    double produireRessources() const;

    // Méthode pour calculer la pollution
    double calculerPollution() const;

    // Affichage des détails
    void afficherDetails() const override;

    // Accesseurs
    double getProductionRessources() const;
    double getPollution() const;

    // Mutateurs
    void setProductionRessources(double newProduction);
    void setPollution(double newPollution);
};

#endif // USINE_H
