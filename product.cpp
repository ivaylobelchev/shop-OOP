#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
#include "product.hpp"

extern unsigned int productNumberCounter = 1;
// External variable in order to make sure all items have different sequential item numbers;

Product::Product()
{
	this->productNumber = productNumberCounter;
	++productNumberCounter;

	this->name = "";

	this->category = Product::NOTDEFINED;

	this->price100 = 0;
}

Product::Product(const Product::ProductType category)
{
	this->name = "";

	this->productNumber = productNumberCounter;
	++productNumberCounter;

	this->category = category;

	this->price100 = 0;
}

Product::Product(std::string name, const Product::ProductType category)
{
	/*short nameLength = 0;
	while (name[nameLength] != '\0')
	{
		++nameLength;
	}
	this->name = new char[nameLength + 1];
	for (size_t i = 0; i <= nameLength; i++)
	{
		this->name[i] = name[i];
	}
	this->name[nameLength] = '\0';*/

	this->productNumber = productNumberCounter;
	++productNumberCounter;

	set(name, category);
}

void Product::print()
{
	std::cout << "Product number: " << this->productNumber << "\n";
	if (this->name != "")
	{
		std::cout << "Name: " << this->name << "\n";
	}

	std::cout << "Category: ";
	switch (category)
	{
	case Product::NOTDEFINED:
		std::cout << "not defined\n";
		break;
	case Product::LAPTOPS:
		std::cout << "Laptops\n";
		break;
	case Product::PCS:
		std::cout << "PCs\n";
		break;
	case Product::PHONES:
		std::cout << "Phones\n";
		break;
	default:
		break;
	}


	/*switch (category)
	{
	case Product::NOTDEFINED:
		break;
	case Product::LAPTOPS:
		print();
		break;
	case Product::PCS:
		printPC();
		break;
	case Product::PHONES:
		printPhone();
		break;
	default:
		break;
	}*/
}

void Product::setType(const Product::ProductType category)
{
	this->category = category;
}

void Product::set(std::string name, const Product::ProductType category)
{
	this->name = name;

	this->category = category;

	this->price100 = 0;
}

Product::Product(const Product& from)
{
	// PRODUCT NUMBER SHOULD NOT BE COPIED
	this->productNumber = productNumberCounter;
	++productNumberCounter;

	this->name = from.name;

	this->hidden = from.hidden;

	this->category = from.category;
}

Product& Product::operator=(const Product& from)
{
	if (this != &from)
	{
		// PRODUCT NUMBER SHOULD NOT BE COPIED
		this->productNumber = productNumberCounter;
		++productNumberCounter;

		/*delete[] name;
		this->name = new char[strlen(from.name) + 1];*/
		this->name = from.name;

		this->hidden = from.hidden;

		this->category = from.category;
	}
	return *this;
}

//unsigned int Product::getPrice100Product()
//{
//	switch (category)
//	{
//	case Product::NOTDEFINED: return 0;
//		break;
//	case Product::LAPTOPS:
//		return getPrice100Laptop();
//		break;
//	case Product::PCS:
//		return getPrice100PC();
//		break;
//	case Product::PHONES:
//		return getPrice100Phone();
//		break;
//	default:
//		break;
//	}
//	return 0;
//}

unsigned int Product::getProductNumber()
{
	return productNumber;
}

unsigned int Product::getPrice100()
{
	return this->price100;
}

const std::string& Product::getName()
{
	return name;
}

bool Product::isHidden()
{
	return this->hidden;
}

Product::~Product()
{
	// no dynamically allocated memory
}

//void Product::copyFromProduct(const Product& from)
//{
//	// PRODUCT NUMBER SHOULD NOT BE COPIED
//	this->productNumber = productNumberCounter;
//	++productNumberCounter;
//
//	this->name = new char[strlen(from.name) + 1];
//	strcpy(this->name, from.name);
//
//	this->hidden = from.hidden;
//
//	this->category = from.category;
//}