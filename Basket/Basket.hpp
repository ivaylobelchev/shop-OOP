#ifndef BASKET_HPP
#define BASKET_HPP

#include "..\Laptop\laptop.hpp"
#include "..\PC\PC.hpp"
#include "..\Phone\phone.hpp"

#include <vector>

class Basket
{
private:
	unsigned long long sum;
	std::vector<Product*> products;
public:
	void addObject(Product&);
	void printTotalPrice();
	unsigned long long priceIn100();
	unsigned int getSize();
	void printBasket();
	void removeObject(unsigned int);
};

#endif //BASKET_HPP