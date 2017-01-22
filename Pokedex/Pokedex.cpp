// Pokedex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

//define global const which is where the Pokedex file is found
const std::string POKEDEX_FILE_NAME = "Data.txt";

//define required Pokemon characteristics at the beginning
typedef	int PDexNumber;
typedef	std::string Name;
typedef double Weight;
typedef double Height;
typedef int PrevEvo;

//define basic Pokemon types
enum class basicPokemonType
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
	Fairy,
};

basicPokemonType convertStringToType(std::string input)
{
	std::stringstream sstr(input);
	std::string typeString;
	sstr >> typeString;

	if (typeString == "Normal")
	{
		return basicPokemonType::Normal;
	}
	else if (typeString == "Fire")
	{
		return basicPokemonType::Fire;
	}
	else if (typeString == "Water")
	{
		return basicPokemonType::Water;
	}
	else if (typeString == "Grass")
	{
		return basicPokemonType::Grass;
	}
	else if (typeString == "Fighting")
	{
		return basicPokemonType::Fighting;
	}
	else if (typeString == "Flying")
	{
		return basicPokemonType::Flying;
	}
	else if (typeString == "Poison")
	{
		return basicPokemonType::Poison;
	}
	else if (typeString == "Electric")
	{
		return basicPokemonType::Electric;
	}
	else if (typeString == "Ground")
	{
		return basicPokemonType::Ground;
	}
	else if (typeString == "Psychic")
	{
		return basicPokemonType::Psychic;
	}
	else if (typeString == "Rock")
	{
		return basicPokemonType::Rock;
	}
	else if (typeString == "Ice")
	{
		return basicPokemonType::Ice;
	}
	else if (typeString == "Bug")
	{
		return basicPokemonType::Bug;
	}
	else if (typeString == "Dragon")
	{
		return basicPokemonType::Dragon;
	}
	else if (typeString == "Ghost")
	{
		return basicPokemonType::Ghost;
	}
	else if (typeString == "Fairy")
	{
		return basicPokemonType::Fairy;
	}
}
std::string convertTypeToString(basicPokemonType input)
{
	if (input == basicPokemonType::Normal)
	{
		return "Normal";
	}
	else if (input == basicPokemonType::Fire)
	{
		return "Fire";
	}
	else if (input == basicPokemonType::Water)
	{
		return "Water";
	}
	else if (input == basicPokemonType::Grass)
	{
		return "Grass";
	}
	else if (input == basicPokemonType::Fighting)
	{
		return "Fighting";
	}
	else if (input == basicPokemonType::Flying)
	{
		return "Flying";
	}
	else if (input == basicPokemonType::Poison)
	{
		return "Poison";
	}
	else if (input == basicPokemonType::Electric)
	{
		return "Electric";
	}
	else if (input == basicPokemonType::Ground)
	{
		return "Ground";
	}
	else if (input == basicPokemonType::Psychic)
	{
		return "Psychic";
	}
	else if (input == basicPokemonType::Rock)
	{
		return "Rock";
	}
	else if (input == basicPokemonType::Ice)
	{
		return "Ice";
	}
	else if (input == basicPokemonType::Bug)
	{
		return "Bug";
	}
	else if (input == basicPokemonType::Dragon)
	{
		return "Dragon";
	}
	else if (input == basicPokemonType::Ghost)
	{
		return "Ghost";
	}
	else if (input == basicPokemonType::Fairy)
	{
		return "Fairy";
	}
}

//define Pokemon genders
enum class PokemonGender
{
	Male,
	Female,
	Both,
	None,
};
PokemonGender convertStringToPokemonGender(std::string input)
{
	std::stringstream sstr(input);
	std::string gendString;

	std::vector<std::string> tempVector;

	while (sstr)
	{
		sstr >> gendString;
		tempVector.push_back(gendString);
	}

	if (tempVector.size() != 1)
	{
		return PokemonGender::Both;
	}
	else if (tempVector.at(0) == "Male")
	{
		return PokemonGender::Male;
	}
	else if (tempVector.at(0) == "Female")
	{
		return PokemonGender::Female;
	}
	else if (tempVector.at(0) == "None")
	{
		return PokemonGender::None;
	}
}
std::string convertPokemonGenderToString(PokemonGender gend)
{
	if (gend == PokemonGender::Male)
	{
		return "Male";
	}
	else if (gend == PokemonGender::Female)
	{
		return "Female";
	}
	else if (gend == PokemonGender::Both)
	{
		return "Male and Female";
	}
	else if (gend == PokemonGender::None)
	{
		return "None";
	}
}

//define Pokemon class
class Pokemon
{
private:
	PDexNumber pdexNumber;
	Name name;
	basicPokemonType type;
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
	basicPokemonType getType(void);
	void setType(basicPokemonType typ);
	Weight getWeight(void);
	void setWeight(double wgt);
	Height getHeight(void);
	void setHeight(double hgt);
	PokemonGender getGender(void);
	void setGender(PokemonGender gend);
	PrevEvo getprevEvo(void);
	void setPrevEvo(int num);

	Pokemon(PDexNumber pdexNumber, Name name, basicPokemonType type, Weight weight, Height height,
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
basicPokemonType Pokemon::getType(void)
{
	return type;
}
void Pokemon::setType(basicPokemonType typ)
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
Pokemon::Pokemon(PDexNumber pdexNumber, Name name, basicPokemonType type, Weight weight, Height height,
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
		tempPokemon.push_back(Pokemon(std::stoi(tempPDexNumber), tempName, convertStringToType(tempType),
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
	std::cout << "Pokedex number: " << pokedexNo + 1 << "\n";
	std::cout << "Type: " << convertTypeToString(pokemonVector.at(pokedexNo).getType()) << "\n";
	std::cout << "Height: " << pokemonVector.at(pokedexNo).getHeight() << "\n";
	std::cout << "Weight: " << pokemonVector.at(pokedexNo).getWeight() << "\n";
	std::cout << "Gender: " << convertPokemonGenderToString(pokemonVector.at(pokedexNo).getGender()) << "\n";
	std::cout << "Previous Evolution: " << returnPrevEvoName(pokedexNo, pokemonVector) << "\n";
	std::cout << "Next Evolution: " << returnNextEvoName(pokedexNo, pokemonVector) << "\n";
}

//function guarantees that we get a long from user input
long getLongFromUser(std::string strPrompt, long minNum, long maxNum) {

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

	long choosePokemon = 0;
	do
	{
		choosePokemon = getLongFromUser("Please enter the number of the Pokemon you want to look up, or enter 0 to exit.\n", 0, 150);
		if (choosePokemon != 0)
		{
			PrintPokemon(choosePokemon - 1, Pokedex); //offset -1 because vectors start at 0
		}
	} while (choosePokemon != 0);	
	return 0;
}