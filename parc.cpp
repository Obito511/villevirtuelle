#include "parc.h"
#include <iostream>

// Constructeur
Parc::Parc(int id, const QString& nom, const QString& type, double consommationEau, double consommationElectricite, double effetSatisfaction, double surface, double effetBienEtre)
    : Batiment(id, nom, type, consommationEau, consommationElectricite, effetSatisfaction),
    surface(surface),
    effetBienEtre(effetBienEtre) {}

// Méthode pour améliorer le bien-être
double Parc::ameliorerBienEtre() const {
    return effetBienEtre;
}

// Affichage des détails
void Parc::afficherDetails() const {
    Batiment::afficherDetails();
    std::cout << "Surface: " << surface << " m²\n"
              << "Effet sur le bien-être: " << effetBienEtre << "\n";
}

// Accesseurs
double Parc::getSurface() const {
    return surface;
}

double Parc::getEffetBienEtre() const {
    return effetBienEtre;
}

// Mutateurs
void Parc::setSurface(double newSurface) {
    surface = newSurface;
}

void Parc::setEffetBienEtre(double newEffetBienEtre) {
    effetBienEtre = newEffetBienEtre;
}
