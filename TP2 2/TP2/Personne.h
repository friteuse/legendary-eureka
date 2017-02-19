//
//  Personne.h
//  TP2
//
//  Created by Édouard Carré on 17-02-16.
//  Copyright © 2017 Édouard Carré. All rights reserved.
//

#ifndef Personne_h
#define Personne_h


#include <string>
#include"Date.h"

namespace tp {
    
    class Personne
    {
    public:
        Personne();
        Personne ( const std::string& p_nom,
                  const std::string& p_prenom,
                  const util::Date& p_dateNaissance,
                  const std::string& p_telephone);
        
        /**
         @brief Va chercher le nom de la personne
         @return m_nom
         */
        std::string reqNom();
        
        /**
         @brief Va chercher le prenom de la personne
         @return m_prenom
         */
        std::string reqPrenom();
        
        /**
         @brief Va chercher la date de naissance de la personne
         @return m_dateNaissance
         */
        util::Date reqDateNaissance();
        std::string reqTelephone();
        
        void asgTelephone(const std ::string& p_telephone);
        std::string reqPersonneFormate ();
        bool operator==(const Personne& unePersonne);
        
        ~Personne();
        
        
    private:
        std::string m_nom;
        std::string m_prenom;
        std::string m_telephone;
        util::Date m_dateNaissance;
    };
}
     

#endif /* Personne_h */
