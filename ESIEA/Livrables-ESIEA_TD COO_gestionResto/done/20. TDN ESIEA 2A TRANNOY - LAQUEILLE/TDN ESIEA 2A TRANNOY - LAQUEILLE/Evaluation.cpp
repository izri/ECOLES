#include "Evaluation.h"

using namespace std;

Evaluation::Evaluation(int noteAccueil, int noteService, int noteCuisine, int noteProprete) : m_accueil(noteAccueil),m_service(noteService), m_cuisine(noteCuisine), m_proprete(noteProprete) {
}

const int Evaluation::getAccueil() {
    return  m_accueil;
}

const int Evaluation::getService() {
    return m_service;
}

const int Evaluation::getCuisine() {
    return m_cuisine;
}

const int Evaluation::getProprete(){
    return m_proprete;
}

void Evaluation::affichage(){
    cout << "Note de l'accueil : " << m_accueil<< endl;
    cout << "Note du service : " << m_service << endl;
    cout << "Note de la cuisine : " << m_cuisine << endl;
    cout << "Note de la proprete : " <<  m_proprete << endl;
}
