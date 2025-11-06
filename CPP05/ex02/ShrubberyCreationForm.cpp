/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:59:51 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/06 00:59:51 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    // Le constructeur appelle le constructeur de AForm avec les grades requis
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);  // Appelle l'opérateur = de la classe parent
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Implémentation de l'action spécifique : créer un fichier avec des arbres ASCII
void ShrubberyCreationForm::executeAction() const
{
    std::string filename = this->target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open())
        throw std::runtime_error("Cannot create file");
    
    file << "       ###\n";
    file << "      #o###\n";
    file << "    #####o###\n";
    file << "   #o#\\#|#/###\n";
    file << "    ###\\|/#o#\n";
    file << "     # }|{  #\n";
    file << "       }|{\n";
    
    file.close();
    std::cout << "Shrubbery has been planted at " << filename << std::endl;
}