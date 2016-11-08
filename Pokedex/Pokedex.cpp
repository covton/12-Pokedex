// Pokedex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

//define global const which is where the Pokedex file is found
const std::string pokedexFileName = "Data.txt";

//define types at the beginning
typedef	int PDexNumber;
typedef	std::string Name;
typedef double Weight;
typedef double Height;
typedef int NextEvo;

//define Pokemon types
enum PokemonType
{
	Normal,
	Fire,
	Water,
	Grass,
	Fighting,
	Flying,
	Poison,
	Electric,
	Ground,
	Psychic,
	Rock,
	Ice,
	Bug,
	Dragon,
	Ghost,
};

//define Pokemon genders
enum PokemonGender
{
	Male,
	Female,
	Both,
	None,
};


//define Pokemon class
class Pokemon
{
private:
	PDexNumber pdexNumber;
	Name name;
	PokemonType type;
	Weight weight;
	Height height;
	PokemonGender gender;
	NextEvo nextEvo;

public:
	//getter and setter functions
	PDexNumber getpdexNumber(void);
	void setpdexNumber(int num);
	Name getName(void);
	void setName(std::string nm);
	PokemonType getType(void);
	void setType(PokemonType typ);
	Weight getWeight(void);
	void setWeight(double wgt);
	Height getHeight(void);
	void setHeight(double hgt);
	PokemonGender getGender(void);
	void setGender(PokemonGender gend);
	NextEvo getnextEvo(void);
	void setnextEvo(int num);

	Pokemon(PDexNumber pdexNumber, Name name, PokemonType type, Weight weight, Height height,
			PokemonGender gender, NextEvo nextevo);
};

//code getters and setters for class Pokemon
PDexNumber Pokemon::getpdexNumber(void)
{
	return pdexNumber;
}
void Pokemon::setpdexNumber(int num)
{
	pdexNumber = num;
}
Name Pokemon::getName(void)
{
	return name;
}
void Pokemon::setName(std::string nm)
{
	name = nm;
}
PokemonType Pokemon::getType(void)
{
	return type;
}
void Pokemon::setType(PokemonType typ)
{
	type = typ;
}
Weight Pokemon::getWeight(void)
{
	return weight;
}
void Pokemon::setWeight(double wgt)
{
	weight = wgt;
}
Height Pokemon::getHeight(void)
{
	return height;
}
void Pokemon::setHeight(double hgt)
{
	height = hgt;
}
PokemonGender Pokemon::getGender(void)
{
	return gender;
}
void Pokemon::setGender(PokemonGender gend)
{
	gender = gend;
}
NextEvo Pokemon::getnextEvo(void)
{
	return nextEvo;
}
void Pokemon::setnextEvo(int num)
{
	nextEvo = num;
}
//constructor function where we initialise each value to the value provided (saving copying and pasting back)
Pokemon::Pokemon(PDexNumber pdexNumber, Name name, PokemonType type, Weight weight, Height height,
	PokemonGender gender, NextEvo nextevo)
	: pdexNumber(pdexNumber), name(name), type(type), weight(weight), height(height),
	gender(gender), nextEvo(nextevo)
{
}



//read Pokemon from file
std::vector<std::string> ReadFileIntoVector(std::string filename)
{
	//define an input file stream called ReadFile
	std::fstream ReadFile;

	//open the file into the stream
	ReadFile.open(filename);

	//define a vector to hold each result 
	std::string strTemp;
	std::vector<std::string> vecResult;

	while (!ReadFile.eof())
	{
		//read each line into a temporary string
		while (std::getline(ReadFile, strTemp))
		{
					vecResult.push_back(strTemp);
		}
	}
	ReadFile.close();
	return vecResult;
}

//read Pokemon vector into correct types



//return Pokemon from database
void PrintPokemon(std::string searchTerm, std::string searchType)
{

	//we assume that searchType can only be number or name (only two fields guaranteed to be unique)
	if (searchType == "NAME")
	{
		
	}
	else if (searchType == "NUMBER")
	{

	}
	else
	{
		std::cout << "Could not find Pokemon.";
	}
}


int main()
{
    //load Pokedex
	std::vector<Pokemon> vecPokedex = ReadListOfPokemonFromFile("PokedexTxt.txt");

	std::cout << "Welcome to Pokedex!\n";
	std::cout << "What would you like to do?\n";
	std::cout << "The first Pokemon is:" << vecPokedex.at[1][1];
	
	system("PAUSE");

	return 0;
}
 
//function guarantees that we get a signed long from user input
signed long fnRetNum(std::string strPrompt) {

	signed long result = 0;

	while (true) {

		std::string strinput = "";
		//use getline to avoid errors with inputs
		std::cout << strPrompt;
		std::getline(std::cin, strinput);

		// this line defines a stringstream called 'mystream' and gives it the value of strinput
		std::stringstream myStream(strinput);
		//this line looks for result (i.e. a signed long) and stores it. If it can't, it returns false
		if (myStream >> result) {
			break;
		}
		std::cout << "That's not a number. Please enter a number.\n";
	}
	return result;
}
