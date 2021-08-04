#include <iostream>
#include "Basket.hpp"

void Basket::addObject(Product& product)
{
	if (products.empty()) this->sum = 0;
	this->products.push_back(&product);
	sum += product.getPrice100();
}

unsigned int Basket::getSize()
{
	return products.size();
}

unsigned long long Basket::priceIn100()
{
	return sum;
}

void Basket::printTotalPrice()
{
	std::cout << "Price: " << sum / 100 << '.';
	if (sum % 100 < 10) std::cout << '0';
	std::cout << sum % 100 << " BGN\n";
}

void Basket::printBasket()
{
	for (size_t i = 0; i < this->products.size(); i++)
	{
		std::cout << "Product number in basket: " << i << std::endl;
		(*products[i]).print();
		std::cout << std::endl;
	}
}

void Basket::removeObject(unsigned int objectToRemove)
{
	this->products.erase(products.begin() + objectToRemove);
}