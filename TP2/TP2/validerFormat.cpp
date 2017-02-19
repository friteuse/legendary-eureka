//
//  validerFormat.cpp
//  TP1
//
//
//  Created by Édouard Carré on 17-02-07.
//  Copyright © 2017 Édouard Carré. All rights reserved.
//

#include "validerFormat.h"

using namespace std;
namespace util {

/*
 Prend un numéro de RAMQ et le compare avec les informations d'une personne. Retourne true si le numéro concorde avec les informations fournies
 Entrée: numRAMQ, nom, prenom, jour/mois/annee de naissance, sexe
 Sortie : true si les infos concordent avec le numRAMQ
 */
bool validerNumRAMQ(const std::string& p_numero, const std::string& p_nom, const
                    std::string& p_prenom, int p_jourNaissance, int p_moisNaissance, int
                    p_anneeNaissance, char p_sex){
    
    // On vérifie si le sexe est valid
    bool sexe_valide = false;
    if (p_sex == 'F' || p_sex == 'M'){
        sexe_valide = true;
    }
    
    // On vérifie si la date est valide (jour plus petit que 31 et mois plus petit que 12)
    bool date_valide = false;
    if (p_moisNaissance > 0 && p_moisNaissance <= 12 && p_jourNaissance > 0 && p_jourNaissance <= 31){
        date_valide = true;
    }
    
    
    // On initialise une string "compare"
    string compare;
    
    //On ajoute d'abord le nom, puis le prenom à compare en prenant soin de prendre seulement les lettres
    // voulues (méthode substring) et en mettant le tout en majuscule (fonction maj).
    compare += maj(p_nom.substr(0,3));
    compare += maj(p_prenom.substr(0,1));
    
    // On ajoute un espace pour respecter le format, ainsi que l'année de naissance à compare (qu'on transforme de int à string avec la fonction IntToString)
    compare += ' ';
    compare += (IntToString(p_anneeNaissance).substr(2,2));
    
    // Si le sexe est 'F', on ajoute 50 au mois de naissance. On ajoute ensuite le mois à string compare
    if (p_sex == 'F') {
        compare += IntToString(p_moisNaissance+50);
    }
    else {
        compare+= IntToString(p_moisNaissance);
    }
    
    // On ajoute l'espace pour le format, ainsi que le jour avec encore IntToString à compare
    compare += ' ';
    compare += IntToString(p_jourNaissance);
    
    // On regarde si p_numero (sans les 2 derniers chiffres) est identique à compare, si le sexe, la date de naissance et le sexe sont valides. Si oui, validerNumRAMQ retourne "true".
    if (compare == p_numero.substr(0,12) && p_numero.length() == 14 && validerNom(p_nom) == true && validerPrenom(p_prenom) == true && date_valide == true && sexe_valide == true && validerDerniersChiffres(p_numero) == true) {
        return true;
    }
    else {
        return false;
    }
    
}


/*
 Transforme un string en int
 Entrée : nombre(string)
 Sortie : nombre(int)
 */
string IntToString (int p_nombre)
{
    // Création d'un string stream
    ostringstream oss;
    
    oss << p_nombre;
    
    // Si le p_nombre est plus petit que 10, on doit ajouter un 0 pour que le format des mois soit respecté (ex: 5 --> 05).
    if(p_nombre < 10){
        return ('0'+ oss.str());
    }
    // return du stream, en string
    return oss.str();
}


/*
 Prend un string et return son équivalent en majuscule
 Entrée : chaine
 Sortie : chaine en majuscule
 
 */
string maj(std::string p_chaine){
    locale loc;
    string resultat;
    for (string::size_type i=0; i<p_chaine.length(); i++) {
        resultat += (std::toupper(p_chaine[i],loc));
    }
    return resultat;
}



/*
 Prend un nom et un prenom et vérifie s'ils sont valides (constitués de seulement des lettres)
 Entrées : nom et prenom (string)
 Sortie : true si les entrées sont valides
 */
bool validerNom(std::string nom_a_valider){
    
    // On regarde si les caractères du string nom_a_valider sont tous des lettres, sinon on return false
    for (int i = 0; i <nom_a_valider.length(); i++){
        if (!isalpha(nom_a_valider[i])){
            return false;
        }
    }
    return true;
}

bool validerPrenom(std::string prenom_a_valider){
    
    // Même chose, mais avec le prenom
    for (int i = 0; i <prenom_a_valider.length(); i++){
        if (!isalpha(prenom_a_valider[i])){
            return false;
        }
    }
    return true;
}


/* Fonction qui valide si les deux derniers caractères du RAMQ sont valides (donc sont des chiffres)
 Entrée : p_numero
 Sortie : bool (true si p_numero[13] et p_numero[14] sont des chiffres)
 */
bool chiffre_valide = true;

bool validerDerniersChiffres(std::string p_numero){
    if (isdigit(p_numero[13]) && isdigit(p_numero[14])){
        chiffre_valide = false;
    }
    return chiffre_valide;
    
}

/*
 Fonction qui valide un numero de téléphone selon le format canadien
 Entrée : numéro de téléphone (string)
 Sortie : Bool true si le numéro est de format valide
 */
bool validerTelephone(const std::string& p_telephone) {
    
    bool num_valide = true;
    
    // On regarde si le numéro fait bien 12 caractères de long
    if(p_telephone.length() != 12){
        return false;
    }
    
    // On initialise un tableau avec tous les indicatifs canadiens
    string const indicatifsCanadiens[33] ={"403", "780", "604", "236", "250", "778", "902", "204","506", "902", "905", "514", "289", "705","613", "807", "416", "647", "438","514", "450", "579", "418", "581", "819", "306","709", "867", "800", "866","877","888","855"};
    
    // Initialisation du string indicatif
    string indicatif;
    
    // On boucle sur l'intégralité du numéro de téléphone entré
    for (int i = 0; i <= 11; i++) {
        
        // On construit l'indicatif régional avec les 3 premiers chiffres
        if(i <=2){
            indicatif += p_telephone[i];
        }
        
        // Si i == 3, le format requiert un ' '. Si ce n'est pas le cas, on return false
        if (i == 3) {
            if (p_telephone[i] != ' ') {
                return false;;
            }
        }
        
        // Si i == 7, le format requiert un '-' si ce n'est pas le cas, on return false
        if (i == 7) {
            if (p_telephone[i] != '-') {
                return false;
            }
        }
        
        // On regarde si les autres indices (autres que 3 et 7) sont tous des chiffres
        if (i !=3 && i !=7){
            if (!isdigit(p_telephone[i])){
                return false;
            }
        }

    }
    
    
    // On boucle dans le tableau des indicatifs canadiens pour trouver une correspondance ou bien si le numéro commence par 9XX (900-999 --> indicatif valide). Si une correspondance est trouvé, return true
    bool indicatif_valide = false;
    
    for (int i = 0; i < 33; i++){
        if (indicatif == indicatifsCanadiens[i] || p_telephone[0] == '9'){
            indicatif_valide = true;
        }
    }
    
    // Si le numéro est valide, ainsi que l'indicatif, on return true
    if (num_valide && indicatif_valide){
        return true;
    }
    else{
        return false;
    }
}
}
