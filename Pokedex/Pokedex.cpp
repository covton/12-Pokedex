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

//read Pokemon from file into Pokemon vector
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


//read Pokemon from file into string vector
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
		//read each line into a temporary string (breaks on new line)
		while (std::getline(ReadFile, strTemp))
		{
					vecResult.push_back(strTemp);
		}
	}
	ReadFile.close();
	return vecResult;
}

//read string vector into required Pokemon types
Pokemon readPokemonFromString(std::string input)
{
	std::string tempString;
	PDexNumber tempPDexNumber;
	Name tempName;
	PokemonType tempType;
	Weight tempWeight;
	Height tempHeight;
	PokemonGender tempGender;
	PrevEvo tempPrevEvo;

	std::stringstream ss(input);

	while (std::getline(ss, tempString))
	{
		std::stringstream ss2(tempString);

		std::string tempString2;
		std::string tempString3;

		ss2 >> tempPDexNumber >> tempName >> tempString2 >> tempWeight >> tempHeight >> tempString3 >> tempPrevEvo;

		tempType = convertStringToPokemonType(tempString2);
		tempGender = convertStringToPokemonGender(tempString2);
	}
	Pokemon tempPokemon(tempPDexNumber, tempName, tempType, tempWeight, tempHeight, tempGender, tempPrevEvo);
	return tempPokemon;
}

std::vector<Pokemon> readPokemonFromStringVectorIntoPokemonVector(std::vector<std::string> inputVector)
{
	std::vector<Pokemon> PokemonVector;
	for (int i = 0; i != inputVector.size(); i++)
	{
		PokemonVector.push_back(readPokemonFromString(inputVector[i]));
	}
	return PokemonVector;
}

std::vector<Pokemon> getPokemonFromFile(std::string filename)
{
	std::vector<std::string> tempStrVector;
	tempStrVector = ReadFileIntoVector(filename);
	std::vector<Pokemon> tempPokemonVector;
	tempPokemonVector = readPokemonFromStringVectorIntoPokemonVector(tempStrVector);

	return tempPokemonVector;
}


//return Pokemon from database
void PrintPokemon(int PokedexNo, std::vector<std::string> VectorToReadFrom)
{
	//define stream with string from vector and temporary vector
	std::stringstream PokemonData(VectorToReadFrom.at(PokedexNo));
	std::vector<std::string> tempVector;

	//now break on commas and store each into tempVector
	while (!PokemonData.eof())
	{
		std::string tempStr;
		//read each line into a temporary string
		while (std::getline(PokemonData, tempStr))
		{
			while (tempStr.length() > 0)
			{
				//now break on commas and store index, then push into tempVector
				int index = tempStr.find_first_of(',');

				//find_first_of returns std::string::npos if it doesn't find anything
				if (index == std::string::npos)
				{
					tempVector.push_back(tempStr);
				}
				else
				{
					tempVector.push_back(tempStr.substr(0, index));
				}

				//remove the start of tempStr and loop
				if (index == std::string::npos)
				{
					tempStr = "";
				}
				else
				{
					tempStr = tempStr.substr(index + 2);
				}
			}
		}
	}

	//now output each part of the vector
	std::cout << "Name: " << tempVector.at(0) << "\n";
	std::cout << "Type: " << tempVector.at(1) << "\n";
	std::cout << "Weight: " << tempVector.at(2) << "\n";
	std::cout << "Height: " << tempVector.at(3) << "\n";
	std::cout << "Gender: " << tempVector.at(4) << "\n";

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

	return 0;
}
 

