//
//  validerFormat.h
//  TP1
//
//  Created by Édouard Carré on 17-02-07.
//  Copyright © 2017 Édouard Carré. All rights reserved.
//

#ifndef validerFormat_h
#define validerFormat_h

#include <iostream>
#include <string>
#include <sstream>
#include <locale>

namespace util {


bool validerNumRAMQ(const std::string& p_numero, const std::string& p_nom, const
                    std::string& p_prenom, int p_jourNaissance, int p_moisNaissance, int
                    p_anneeNaissance, char p_sex);

std::string IntToString(int p_nombre);

std::string maj(std::string p_chaine);

bool validerNom(std::string p_nom_a_valider);
    
bool validerPrenom(std::string p_prenom_a_valider);

bool validerDerniersChiffres(std::string p_chiffre);

bool validerTelephone(const std::string& p_telephone);

bool validerNumRAMQ(const std::string& p_numero, const std::string& p_nom, const std::string& p_prenom,
                    int p_jourNaissance, int p_moisNaissance, int p_anneeNaissance, char p_sex);

}
#endif /* fonction_validerFormat */
