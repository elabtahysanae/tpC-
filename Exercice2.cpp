#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    float x, y;

    // Saisie des coordonnées
    void saisie(float a, float b) {
        x = a;
        y = b;
    }

    // Déplacement du point
    void deplacer(float a, float b) {
        x += a;
        y += b;
    }

    // Retourne l'abscisse
    float abscisse() {
        return x;
    }

    // Retourne l'ordonnée
    float ordonnee() {
        return y;
    }

    // Vérifie si deux points sont identiques
    bool comparer(Point p) {
        return (x == p.x && y == p.y);
    }

    // Calcule la distance entre deux points
    float calculerDistance(Point p) {
        return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
    }

    // Affiche le point
    void afficher() {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Point p1, p2, p3;

    // Création des points
    p1.saisie(3.0, 4.0);
    p2.saisie(6.0, 8.0);
    p3.saisie(0.0, 0.0);

    // Affichage des points
    cout << "Coordonnées des points :\n";
    cout << "P1: "; p1.afficher(); cout << endl;
    cout << "P2: "; p2.afficher(); cout << endl;
    cout << "P3: "; p3.afficher(); cout << endl;

    // Calcul de la distance de P1 à l'origine
    cout << "\nDistance de P1 à l'origine : " << p1.calculerDistance(p3) << endl;

    // Calcul de la distance entre P1 et P2
    cout << "Distance entre P1 et P2 : " << p1.calculerDistance(p2) << endl;

    // Déplacement de P2
    p2.deplacer(20, 13);
    cout << "Après déplacement de P2 : "; p2.afficher(); cout << endl;

    // Vérification si P1 et P2 sont identiques
    if (p1.comparer(p2))
        cout << "P1 et P2 sont identiques.\n";
    else
        cout << "P1 et P2 sont différents.\n";

    // Vérification des deux points les plus proches
    float d1 = p1.calculerDistance(p2);
    float d2 = p1.calculerDistance(p3);
    float d3 = p2.calculerDistance(p3);

    cout << "Les deux points les plus proches sont : ";
    if (d1 <= d2 && d1 <= d3)
        cout << "P1 et P2\n";
    else if (d2 <= d1 && d2 <= d3)
        cout << "P1 et P3\n";
    else
        cout << "P2 et P3\n";

    return 0;
}
