//
//  Personne.cpp
//  TP2
//
//  Created by Édouard Carré on 17-02-16.
//  Copyright © 2017 Édouard Carré. All rights reserved.
//

#include <stdio.h>
#include "Personne.h"
#include "Date.h"
#include "ContratException.h"
#include <iostream>
#include "validerFormat.h"

using namespace std;
using namespace tp;
using namespace util;


Personne::Personne(const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, const std::string& p_telephone) : m_nom(p_nom), m_prenom(p_prenom), m_dateNaissance(p_dateNaissance), m_telephone(p_telephone)
{
    
}


std::string Personne::reqNom(){
        return m_nom;
    }
    
std::string Personne::reqPrenom(){
    return m_prenom;
    }

util::Date Personne::reqDateNaissance(){
    return m_dateNaissance;
        
    }
std::string Personne::reqTelephone(){
    return m_telephone;
    }
    
void Personne::asgTelephone(const std ::string& p_telephone){
    if (util::validerTelephone(p_telephone) == true){
    m_telephone = p_telephone;
        
    cout << "Le numero a ete change pour : " << m_telephone << endl<<endl;
    
        
    cout << reqNom()<<", "<< reqPrenom()<< endl;
    cout << "-----------------" << endl;
    cout << "Nom :                 " << reqNom() << endl;
    cout << "Prenom :              " << reqPrenom() << endl;
    cout << "Date de naissance :   " << reqDateNaissance().reqDateFormatee() << endl;
    cout << "Numero de telephone : " << reqTelephone() << endl;
        
    }
    else {
        cout << "Le numero n'a pas ete change, car celui entre est invalide!"<< endl;
    }
}
std::string Personne::reqPersonneFormate(){
    ostringstream os;
    
    os << "Nouvelle personne"<< endl;
    os << "-----------------" << endl;
    os << "Nom :                 " << reqNom() << endl;
    os << "Prenom :              " << reqPrenom() << endl;
    os << "Date de naissance :   " << reqDateNaissance().reqDateFormatee() << endl;
    os << "Numero de telephone : " << reqTelephone() << endl;
    
    return os.str();

}

bool Personne::operator==(const Personne& unePersonne){
    
    return (m_telephone == unePersonne.m_telephone && m_nom == unePersonne.m_nom && m_dateNaissance == unePersonne.m_dateNaissance);
    }

Personne::~Personne()
{
    cout << "Objet détruit" << endl;
}


    



