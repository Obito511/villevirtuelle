#include "Ville.h"

// Constructeur
Ville::Ville(const QString& nom, double budget, int population, double ressourcesEau, double ressourcesElectricite)
    : nom(nom), budget(budget), population(population), satisfaction(100.0), ressourcesEau(ressourcesEau), ressourcesElectricite(ressourcesElectricite) {}

// Ajouter un bâtiment
void Ville::ajouterBatiment(Batiment* b) {
    batiments.push_back(b);
}

// Modifier un bâtiment
void Ville::modifierBatiment(const Batiment& batimentModifie) {
    for (auto& b : batiments) {
        if (b->getId() == batimentModifie.getId()) {
            b->setNom(batimentModifie.getNom());
            b->setType(batimentModifie.getType());
            b->setConsommationEau(batimentModifie.getConsommationEau());
            b->setConsommationElectricite(batimentModifie.getConsommationElectricite());
            b->setEffetSatisfaction(batimentModifie.getEffetSatisfaction());

            // Vérifier et appliquer les modifications spécifiques aux sous-classes
            Maison* maisonExistante = dynamic_cast<Maison*>(b);
            const Maison* maisonModifiee = dynamic_cast<const Maison*>(&batimentModifie);
            if (maisonExistante && maisonModifiee) {
                maisonExistante->ajouterHabitants(maisonModifiee->getHabitantsActuels() - maisonExistante->getHabitantsActuels());
            }

            Usine* usineExistante = dynamic_cast<Usine*>(b);
            const Usine* usineModifiee = dynamic_cast<const Usine*>(&batimentModifie);
            if (usineExistante && usineModifiee) {
                usineExistante->setProductionRessources(usineModifiee->getProductionRessources());
            }

            std::cout << "Bâtiment avec ID " << batimentModifie.getId() << " modifié avec succès.\n";
            return;
        }
    }
    std::cerr << "Aucun bâtiment avec ID " << batimentModifie.getId() << " trouvé.\n";
}

// Supprimer un bâtiment par ID
void Ville::supprimerBatiment(int id) {
    auto it = std::remove_if(batiments.begin(), batiments.end(), [id](Batiment* b) {
        return b->getId() == id;
    });
    if (it != batiments.end()) {
        delete *it;
        batiments.erase(it, batiments.end());
    }
}

// Calculer la consommation totale d'eau et d'électricité
void Ville::calculerConsommationTotale() const {
    double totalEau = 0.0, totalElectricite = 0.0;
    for (const auto& b : batiments) {
        totalEau += b->getConsommationEau();
        totalElectricite += b->getConsommationElectricite();
    }
    std::cout << "Consommation totale d'eau: " << totalEau << " L\n"
              << "Consommation totale d'électricité: " << totalElectricite << " kWh\n";
}

// Vérifier l'équilibre des ressources
void Ville::verifierEquilibreRessources() {
    double totalEau = 0.0, totalElectricite = 0.0;
    for (const auto& b : batiments) {
        totalEau += b->getConsommationEau();
        totalElectricite += b->getConsommationElectricite();
    }
    if (totalEau > ressourcesEau || totalElectricite > ressourcesElectricite) {
        std::cerr << "Alerte : Les ressources disponibles sont insuffisantes pour couvrir la consommation totale.\n";
    } else {
        std::cout << "Les ressources sont suffisantes pour couvrir la consommation actuelle.\n";
    }
}

// Optimiser les ressources
void Ville::optimiserRessources() {
    double totalEau = 0.0, totalElectricite = 0.0;
    for (const auto& b : batiments) {
        totalEau += b->getConsommationEau();
        totalElectricite += b->getConsommationElectricite();
    }
    if (totalEau > ressourcesEau) {
        std::cout << "Réduction de la consommation d'eau nécessaire.\n";
    }
    if (totalElectricite > ressourcesElectricite) {
        std::cout << "Réduction de la consommation d'électricité nécessaire.\n";
    }
}

// Calculer le niveau de satisfaction moyen
void Ville::calculerSatisfaction() {
    if (batiments.empty()) {
        satisfaction = 0.0;
        return;
    }
    double totalSatisfaction = 0.0;
    for (const auto& b : batiments) {
        totalSatisfaction += b->getEffetSatisfaction();
    }
    satisfaction = totalSatisfaction / batiments.size();
}

// Surveiller le niveau de satisfaction
void Ville::surveillerSatisfaction() {
    if (satisfaction < 50.0) {
        std::cerr << "Alerte : Le niveau de satisfaction est critique !\n";
    } else if (satisfaction < 75.0) {
        std::cout << "Attention : Le niveau de satisfaction pourrait être amélioré.\n";
    }
}

// Ajouter un parc
void Ville::ajouterParc(const Parc& parc) {
    Parc* nouveauParc = new Parc(parc);
    ajouterBatiment(nouveauParc);
    std::cout << "Le parc " << parc.getNom().toStdString() << " a été ajouté à la ville.\n";
}

// Afficher les détails de la ville
void Ville::afficherDetails() const {
    std::cout << "Nom de la ville: " << nom.toStdString() << "\n"
              << "Budget: " << budget << "\n"
              << "Population: " << population << "\n"
              << "Satisfaction moyenne: " << satisfaction << "\n"
              << "Ressources en eau: " << ressourcesEau << " L\n"
              << "Ressources en électricité: " << ressourcesElectricite << " kWh\n"
              << "Nombre de bâtiments: " << batiments.size() << "\n";
}

// Interrompre la production des usines
void Ville::interrompreProductionUsines() {
    for (auto& b : batiments) {
        Usine* usine = dynamic_cast<Usine*>(b);
        if (usine) {
            usine->setProductionRessources(0);
            std::cout << "Production interrompue pour l'usine: " << usine->getNom().toStdString() << "\n";
        }
    }
}

// Réduire l'effet des parcs
void Ville::reduireEffetParcs(double facteur) {
    for (auto& b : batiments) {
        Parc* parc = dynamic_cast<Parc*>(b);
        if (parc) {
            double nouvelEffet = parc->getEffetSatisfaction() * facteur;
            parc->setEffetSatisfaction(nouvelEffet);
            std::cout << "Effet de satisfaction réduit pour le parc: " << parc->getNom().toStdString()
                      << " à " << nouvelEffet << "\n";
        }
    }
}

// Destructeur
Ville::~Ville() {
    for (auto& b : batiments) {
        delete b;
    }
}
double Ville::getRessourcesEau() const {
    return ressourcesEau;
}

// Implementation of getRessourcesElectricite
double Ville::getRessourcesElectricite() const {
    return ressourcesElectricite;
}

// Implementation of other accessors, if missing
double Ville::getSatisfaction() const {
    return satisfaction;
}
// Implementation of setRessourcesEau
void Ville::setRessourcesEau(double newEau) {
    ressourcesEau = newEau;
}

// Implementation of setRessourcesElectricite
void Ville::setRessourcesElectricite(double newElectricite) {
    ressourcesElectricite = newElectricite;
}

// Implementation of setSatisfaction
void Ville::setSatisfaction(double newSatisfaction) {
    satisfaction = newSatisfaction;
}
