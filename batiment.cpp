#include "batiment.h"
#include <qvectornd.h>

// Constructeur
Batiment::Batiment(int id, const QString& nom, const QString& type, double consommationEau, double consommationElectricite, double effetSatisfaction )
    : id(id), nom(nom), type(type), consommationEau(consommationEau), consommationElectricite(consommationElectricite), effetSatisfaction(effetSatisfaction) {}

// Méthodes pour afficher les détails
void Batiment::afficherDetails() const {
    std::cout << "ID: " << id << "\n"
              << "Nom: " << nom.toStdString() << "\n"
              << "Type: " << type.toStdString() << "\n"
              << "Consommation d'eau: " << consommationEau << " L/cycle\n"
              << "Consommation d'électricité: " << consommationElectricite << " kWh/cycle\n"
              << "Effet sur la satisfaction: " << effetSatisfaction << "\n";
}

// Méthode pour calculer l'impact sur les ressources
double Batiment::calculerImpactRessources() const {
    return consommationEau + consommationElectricite;
}

// Accesseurs
int Batiment::getId() const { return id; }
QString Batiment::getNom() const { return nom; }
QString Batiment::getType() const { return type; }
double Batiment::getConsommationEau() const { return consommationEau; }
double Batiment::getConsommationElectricite() const { return consommationElectricite; }
double Batiment::getEffetSatisfaction() const { return effetSatisfaction; }

// Mutateurs
void Batiment::setNom(const QString& newNom) { nom = newNom; }
void Batiment::setType(const QString& newType) { type = newType; }
void Batiment::setConsommationEau(double newConsommationEau) { consommationEau = newConsommationEau; }
void Batiment::setConsommationElectricite(double newConsommationElectricite) { consommationElectricite = newConsommationElectricite; }
void Batiment::setEffetSatisfaction(double newEffetSatisfaction) { effetSatisfaction = newEffetSatisfaction; }
