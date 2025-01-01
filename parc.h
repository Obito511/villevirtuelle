#ifndef PARC_H
#define PARC_H

#include "Batiment.h"

class Parc : public Batiment {
private:
    double surface;  // Surface du parc en mètres carrés
    double effetBienEtre;  // Amélioration du bien-être des habitants

public:
    // Constructeur
    Parc(int id, const QString& nom, const QString& type, double consommationEau, double consommationElectricite, double effetSatisfaction, double surface, double effetBienEtre);

    // Méthode pour améliorer le bien-être
    double ameliorerBienEtre() const;

    // Affichage des détails
    void afficherDetails() const override;

    // Accesseurs
    double getSurface() const;
    double getEffetBienEtre() const;

    // Mutateurs
    void setSurface(double newSurface);
    void setEffetBienEtre(double newEffetBienEtre);
};
#endif // PARC_H
