#include <iostream>
#include <string>

using namespace std;

struct Etudiant {
    string nom;
    string prenom;
    int CNE;
    float notes[5];

    
    void creer() {
        cout << "Nom: ";
        cin >> nom;
        cout << "Prenom: ";
        cin >> prenom;
        cout << "CNE: ";
        cin >> CNE;
        cout << "Entrez les 5 notes : ";
        for (int i = 0; i < 5; i++) {
            cin >> notes[i];
        }
    }

    
    float getMaxNote() {
        float max = notes[0];
        for (int i = 1; i < 5; i++) {
            if (notes[i] > max) max = notes[i];
        }
        return max;
    }

    
    float getMinNote() {
        float min = notes[0];
        for (int i = 1; i < 5; i++) {
            if (notes[i] < min) min = notes[i];
        }
        return min;
    }

    
    float getMoyenneNote() {
        float somme = 0;
        for (int i = 0; i < 5; i++) {
            somme += notes[i];
        }
        return somme / 5;
    }

    
    float getQuota() {
        int count = 0;
        for (int i = 0; i < 5; i++) {
            if (notes[i] >= 10) count++;
        }
        return (count / 5.0) * 100;
    }

    void affiche() {
        cout << "Etudiant: " << prenom << " " << nom << " (CNE: " << CNE << ")\n";
        cout << "Notes: ";
        for (int i = 0; i < 5; i++) cout << notes[i] << " ";
        cout << "\nMax Note: " << getMaxNote();
        cout << "\nMin Note: " << getMinNote();
        cout << "\nMoyenne: " << getMoyenneNote();
        cout << "\nQuota >= 10: " << getQuota() << "%\n\n";
    }
};

int main() {
    
    int n;
    cout << "Nombre d'etudiants : ";
    cin >> n;
    Etudiant etudiants[n];

    for (int i = 0; i < n; i++) {
        cout << "\nCreation de l'etudiant " << i + 1 << " :\n";
        etudiants[i].creer();
    }

    
    cout << "\n--- Liste des etudiants ---\n";
    for (int i = 0; i < n; i++) {
        etudiants[i].affiche();
    }

    return 0;
}

