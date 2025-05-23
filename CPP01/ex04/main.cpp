/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armetix <armetix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:54:43 by armetix           #+#    #+#             */
/*   Updated: 2025/04/22 16:22:30 by armetix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

std::string	replaceAll(std::string line, std::string s1, std::string s2)
{
	std::string final;
	std::string::size_type end = 0;
	int start = 0;

	while(true)
	{
		end = line.find(s1, start);
		if (end == std::string::npos)
			break ;
		final += line.substr(start, end - start);
		final += s2;
		start = end + s1.length();
	}
	final += line.substr(start);
	return final;
}

int main(int argc, char const *argv[])
{
	std::string filename;
	std::string s1;
	std::string s2;
	std::string line;
	std::string newLine;
	int firstLine = 1;

	if (argc != 4)
	{
		std::cout << "Erreur: le nombre d'arguments" << std::endl;
		return (0);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (filename.empty() || s1.empty())
	{
		std::cout << "Erreur: argument(s) manquant(s)" << std::endl;
		return (0);
	}
	std::ifstream inputFile(filename.c_str());
	if (!inputFile)
	{
		std::cout << "Erreur: impossible d'ouvrir le fichier" << std::endl;
		return (0);
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile)
	{
		std::cout << "Erreur: impossible de créer le fichier de sortie" << std::endl;
		return (0);
	}
	while(std::getline(inputFile, line))
	{
		if (!firstLine)
			outputFile << std::endl;
		firstLine = 0;
		newLine = replaceAll(line, s1, s2);
		
		outputFile << newLine;
	}
	return (0);
}
