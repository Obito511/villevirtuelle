#ifndef BATIMENT_H
#define BATIMENT_H

#include <QString>
#include <iostream>
#include <qvectornd.h>

class Batiment {
private:
    int id;  // Identifiant unique
    QString nom;  // Nom du bâtiment
    QString type;  // Type de bâtiment (Habitation, Ressource, Service, etc.)
    double consommationEau;  // Consommation d'eau par cycle
    double consommationElectricite;  // Consommation d'électricité par cycle
    double effetSatisfaction;  // Impact sur la satisfaction des habitants


public:
    // Constructeur
    Batiment(int id, const QString& nom, const QString& type, double consommationEau, double consommationElectricite, double effetSatisfaction);

    // Méthodes pour afficher les détails
    virtual void afficherDetails() const;

    // Méthode pour calculer l'impact sur les ressources
    double calculerImpactRessources() const;

    // Accesseurs
    int getId() const;
    QString getNom() const;
    QString getType() const;
    double getConsommationEau() const;
    double getConsommationElectricite() const;
    double getEffetSatisfaction() const;

    // Mutateurs
    void setNom(const QString& newNom);
    void setType(const QString& newType);
    void setConsommationEau(double newConsommationEau);
    void setConsommationElectricite(double newConsommationElectricite);
    void setEffetSatisfaction(double newEffetSatisfaction);

};

#endif // BATIMENT_H
