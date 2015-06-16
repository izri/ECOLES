//
//  Index.h
//  LangageEtCompil
//
//  Created by DESVAUX Lou-Evans on 18/01/2015.
//  Copyright (c) 2015 DESVAUX Lou-Evans. All rights reserved.
//

#ifndef __LangageEtCompil__Index__
#define __LangageEtCompil__Index__

#include <stdio.h>
#include <string>
#include <vector>
class Index{
    
private:
    std::string previousletter;
    std::vector<std::string> I;
    std::string nom;
    std::string previousindex;
    
public:
    Index();
    std::string& getPreviousletter();
    std::string& getPreviousindex();
    std::string& getNom();
    std::string& getI(int cpt);
    int getTaille();
    void setNom(std::string);
    void setI(std::string);
    void setPreviousletter(std::string);
    void setPreviousindex(std::string);
    void clear();
    void clear2(int cpt);
};
#endif /* defined(__LangageEtCompil__Index__) */
