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

//function guarantees that we get a signed long from user input
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
			break;
		}
		if (result<minNum || result>maxNum)
		{
			std::cout << "Please enter a number between " << minNum << " and " << maxNum << ".\n";
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
	std::vector<std::string> PokedexAsString = ReadFileIntoVector(pokedexFileName);

	std::cout << "Welcome to Pokedex!\n";
	
	int userInput = 1;
	while(userInput!= 0)
	{
		long userInput = fnRetNum("Enter the number of the Pokemon you would like to view, or press 0 to exit\n", 1, 150);
		if (userInput!=0)
		{
			//magic number of -1 is for array offset
			PrintPokemon(userInput - 1, PokedexAsString);
		}
	}

	return 0;
}
 

