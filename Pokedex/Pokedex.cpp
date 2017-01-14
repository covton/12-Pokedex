// Pokedex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

//define global const which is where the Pokedex file is found
const std::string POKEDEX_FILE_NAME = "Data.txt";

//define required Pokemon characteristics at the beginning
typedef	int PDexNumber;
typedef	std::string Name;
typedef double Weight;
typedef double Height;
typedef int PrevEvo;

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

//allow us to convert strings to these enums
PokemonType convertStringToPokemonType(std::string input)
{
	if (input == "Normal")
	{
		return Normal;
	}
	else if (input == "Fire")
	{
		return Fire;
	}
	else if (input == "Water")
	{
		return Water;
	}
	else if (input == "Grass")
	{
		return Grass;
	}
	else if (input == "Fighting")
	{
		return Fighting;
	}
	else if (input == "Flying")
	{
		return Flying;
	}
	else if (input == "Poison")
	{
		return Poison;
	}
	else if (input == "Electric")
	{
		return Electric;
	}
	else if (input == "Ground")
	{
		return Ground;
	}
	else if (input == "Psychic")
	{
		return Psychic;
	}
	else if (input == "Rock")
	{
		return Rock;
	}
	else if (input == "Ice")
	{
		return Ice;
	}
	else if (input == "Bug")
	{
		return Bug;
	}
	else if (input == "Dragon")
	{
		return Dragon;
	}
	else if (input == "Ghost")
	{
		return Ghost;
	}
}
PokemonGender convertStringToPokemonGender(std::string input)
{
	if (input == "Male")
	{
		return Male;
	}
	else if (input == "Female")
	{
		return Female;
	}
	else if (input == "Both")
	{
		return Both;
	}
	else if (input == "None")
	{
		return None;
	}
}

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
	PrevEvo prevEvo;

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
	PrevEvo getprevEvo(void);
	void setPrevEvo(int num);

	Pokemon(PDexNumber pdexNumber, Name name, PokemonType type, Weight weight, Height height,
			PokemonGender gender, PrevEvo nextevo);
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
PrevEvo Pokemon::getprevEvo(void)
{
	return prevEvo;
}
void Pokemon::setPrevEvo(int num)
{
	prevEvo = num;
}
//constructor function where we initialise each value to the value provided (saving copying and pasting back)
Pokemon::Pokemon(PDexNumber pdexNumber, Name name, PokemonType type, Weight weight, Height height,
	PokemonGender gender, PrevEvo prevEvo)
	: pdexNumber(pdexNumber), name(name), type(type), weight(weight), height(height),
	gender(gender), prevEvo(prevEvo)
{



}

std::vector<Pokemon> readFileIntoPokemonVector (std::string filename)
{
	std::ifstream readFile(filename);
	std::vector<Pokemon> tempPokemon;

	std::string tempPDexNumber;
	std::string tempName;
	std::string tempType;
	std::string tempWeight;
	std::string tempHeight;
	std::string tempGender;
	std::string tempPrevEvo;

	std::getline(readFile, tempPDexNumber, ',');
	std::getline(readFile, tempName, ',');
	std::getline(readFile, tempType, ',');
	std::getline(readFile, tempWeight, ',');
	std::getline(readFile, tempHeight, ',');
	std::getline(readFile, tempGender, ',');
	std::getline(readFile, tempPrevEvo, ',');

	while (readFile)
	{
		tempPokemon.push_back(Pokemon(std::stoi(tempPDexNumber), tempName, convertStringToPokemonType(tempType),
			std::stod(tempWeight), std::stod(tempHeight), convertStringToPokemonGender(tempGender), std::stoi(tempPrevEvo)));

		std::getline(readFile, tempPDexNumber, ',');
		std::getline(readFile, tempName, ',');
		std::getline(readFile, tempType, ',');
		std::getline(readFile, tempWeight, ',');
		std::getline(readFile, tempHeight, ',');
		std::getline(readFile, tempGender, ',');
		std::getline(readFile, tempPrevEvo, ',');
	}
	return tempPokemon;
}

 Name returnNextEvoName(PDexNumber origPokemonNum, std::vector<Pokemon> pokemonVector)
{
	//the next evolution is never more than 3 pokemon away
	//(most are two, but Eevee has three)
	//therefore, all we need to do is check the next three pokemon to see if their prevEvo
	//is equal to the pdex number of the one we are looking at

	for (int pdexOffset = 1; pdexOffset < 4; pdexOffset++)
	{
		if (pokemonVector.at(origPokemonNum + pdexOffset).getprevEvo() == origPokemonNum + 1)
		{
			return pokemonVector.at(origPokemonNum + pdexOffset).getName();
		}
	}
	return "No further evolutions";
}

 Name returnPrevEvoName(PDexNumber origPokemonNum, std::vector<Pokemon> pokemonVector)
 {
	 if (pokemonVector.at(origPokemonNum).getprevEvo() == 0)
	 {
		 return "No previous evolution";
	 }
	 else
	 {
		 return pokemonVector.at(pokemonVector.at(origPokemonNum).getprevEvo() - 1).getName();
	 }
 }

void PrintPokemon(int pokedexNo, std::vector<Pokemon> pokemonVector)
{
	int numOfCharactersInName;
	numOfCharactersInName = pokemonVector.at(pokedexNo).getName().length();
	std::string titleUnderline="-";
	for (int i = 1; i < numOfCharactersInName; i++)
	{
		titleUnderline = titleUnderline + "-";
	}
	
	std::cout << pokemonVector.at(pokedexNo).getName() << "\n";
	std::cout << titleUnderline << "\n";
	std::cout << "Pokedex number: " << pokedexNo << "\n";
	std::cout << "Type: " << pokemonVector.at(pokedexNo).getType() << "\n";
	std::cout << "Height: " << pokemonVector.at(pokedexNo).getHeight() << "\n";
	std::cout << "Weight: " << pokemonVector.at(pokedexNo).getWeight() << "\n";
	std::cout << "Gender: " << pokemonVector.at(pokedexNo).getGender() << "\n";
	std::cout << "Previous Evolution: " << returnPrevEvoName(pokedexNo, pokemonVector) << "\n";
	std::cout << "Next Evolution: " << returnNextEvoName(pokedexNo, pokemonVector) << "\n";
}

//function guarantees that we get a long from user input
long fnRetNum(std::string strPrompt, long minNum, long maxNum) {

	long result = 0;

	while (true || (result >= minNum && result <= maxNum))
	{

		std::string strinput = "";
		//use getline to avoid errors with inputs
		std::cout << strPrompt;
		std::getline(std::cin, strinput);

		// this line defines a stringstream called 'mystream' and gives it the value of strinput
		std::stringstream myStream(strinput);
		//this line looks for result (i.e. a signed long) and stores it. If it can't, it returns false
		if (myStream >> result) {
			if (result<minNum || result>maxNum)
			{
				std::cout << "Please enter a number between " << minNum << " and " << maxNum << ".\n";
			}
			else
			{
				break;
			}
		}
		else
		{
			std::cout << "That's not a number. Please enter a number.\n";
		}
	}
	return result;
}

int main()
{
    //load Pokedex
	std::vector<Pokemon> Pokedex = readFileIntoPokemonVector(POKEDEX_FILE_NAME);


	std::cout << "Welcome to Pokedex!\n";

	int choosePokemon=0;

	do
	{
		std::cin >> choosePokemon;
		PrintPokemon(choosePokemon - 1, Pokedex); //offset -1 because vectors start at 0
		
	} while (choosePokemon != 0);
	
	return 0;
}
 

