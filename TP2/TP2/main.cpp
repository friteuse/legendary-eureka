//
//  main.cpp
//  TP2
//
//  Created by Édouard Carré on 17-02-16.
//  Copyright © 2017 Édouard Carré. All rights reserved.
//

#include <iostream>
#include "Date.h"
#include "ContratException.h"
#include "Personne.h"
#include "validerFormat.h"

using namespace tp;
using namespace std;
using namespace util;

int main() {
    
    cout << "Bienvenue à l'outil d'ajout d'une personne " << endl;
    cout << "-----------------------------------------"<< endl;
    
    string nomPersonne;
    
    do
    {
        cout << "Entrez le nom de la personne :" << endl;
        cin >> nomPersonne;
        if(validerNom(nomPersonne) == false){
            cout << "Le nom n'est pas valide, veuillez réessayer !"<< endl;
        }
        
    } while (validerNom(nomPersonne) == false);
    
    
    string prenomPersonne;
    
    do
    {
        cout << "Entrez le prenom de la personne :" << endl;
        cin >> prenomPersonne;
        if(validerNom(prenomPersonne) == false){
            cout << "Le prenom n'est pas valide, veuillez réessayer !"<< endl;
        }
        
    } while (validerPrenom(prenomPersonne) == false);
    
    char numTelephone[256];
    cin.ignore();
    do
    {
        cout << "Entrez le numero de telephone de la personne :" << endl;
        cin.getline(numTelephone, 256);
        
        if(validerTelephone(numTelephone)== false){
            cout << "Le numero n'est pas valide, veuillez réessayer !"<< endl;
        }
        
    } while (validerTelephone(numTelephone) == false);
    
    
    long jourNaissance;
    long moisNaissance;
    long anneeNaissance;
    
    
    do{
        
        cout << "Veuillez entrer le jour de naissance : " << endl;
        cout << "Jour :"<< endl;
        cin >> jourNaissance;
        
        
        cout << "Veuillez entrer le mois de naissance : " << endl;
        cout << "Mois :"<< endl;
        cin >> moisNaissance;

        cout << "Veuillez entrer l'annee de naissance : " << endl;
        cout << "Annee :"<< endl;
        cin >> anneeNaissance;
        
        if(Date::validerDate(jourNaissance, moisNaissance, anneeNaissance)== false){
            cout << "Le numero n'est pas valide, veuillez réessayer !"<< endl;
        }
        
    } while (Date::validerDate(jourNaissance, moisNaissance, anneeNaissance) == false);
    
    
    
    
    Personne bob = Personne(nomPersonne, prenomPersonne, Date(jourNaissance,moisNaissance,anneeNaissance), numTelephone);
    

    cout << bob.reqPersonneFormate()<< endl;
    
    
    char nouveauNumero[256];
    cin.ignore();
    
    do {
        cout << "Entrez le nouveau numero de telephone"<<endl;
        cin.getline(nouveauNumero, 256);
        
        bob.asgTelephone(nouveauNumero);
        
    }while (validerTelephone(nouveauNumero) == false);

    
    
    
    
    
    
    
    
    
    
    return 0;
}

