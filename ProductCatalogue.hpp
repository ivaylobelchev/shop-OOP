#ifndef PRODUCTCATALOGUE_HPP
#define PRODUCTCATALOGUE_HPP

#include "Phone/phone.hpp"
#include "Laptop/laptop.hpp"
#include "PC/PC.hpp"

#include <vector>
#include <string>

template <typename T>
class ProductCatalogueType
{
private:
	std::vector<T> products;
	friend class AllProductsCatalogue;
public:
	ProductCatalogueType();
	ProductCatalogueType(const T& firstObject);
	ProductCatalogueType(const ProductCatalogueType& other);
	ProductCatalogueType& operator=(const ProductCatalogueType& other);
	~ProductCatalogueType();

	void add(const T& objectToAdd);
	T* get(const std::string productName);
	T* remove(const std::string productName);
	void searchAndPrint(const std::string productName);
	void printAll();
};

template <typename T>
ProductCatalogueType<T>::ProductCatalogueType()
{
	this->products.clear();
}

template <typename T>
ProductCatalogueType<T>::ProductCatalogueType(const T& firstObject)
{
	this->products.push_back(firstObject);
}

template<typename T>
ProductCatalogueType<T>::ProductCatalogueType(const ProductCatalogueType& other)
{
	this->products = other.products;
}

template<typename T>
ProductCatalogueType<T>& ProductCatalogueType<T>::operator=(const ProductCatalogueType<T>& other)
{
	products.clear();
	products = other.products;
	return *this;
}

template<typename T>
ProductCatalogueType<T>::~ProductCatalogueType()
{
	// No need?
}

template <typename T>
void ProductCatalogueType<T>::add(const T& objectToAdd)
{
	this->products.push_back(objectToAdd);
}

template <typename T>
T* ProductCatalogueType<T>::get(const std::string productName)
{
	size_t i = 0;
	for (; i < products.size(); i++)
	{
		std::string gottenName = products[i].getName();
		T& temp = products[i];
		if (gottenName == productName) return &temp;
	}
	return nullptr;
}

template <typename T>
T* ProductCatalogueType<T>::remove(const std::string productName)
{
	auto i = 0;
	for (; i < products.size(); i++)
	{
		std::string gottenName = products[i].getName();
		if (gottenName == productName)
		{
			T* temp = new T;
			*temp = products[i];
			products.erase(products.begin() + i);
			return temp;
		}
	}
	return nullptr;
}

template<typename T>
void ProductCatalogueType<T>::searchAndPrint(const std::string productName)
{
	std::cout << get(productName);
}

template <typename T>
void ProductCatalogueType<T>::printAll()
{
	for (size_t i = 0; i < products.size(); i++)
	{
		if (products[i].isHidden() == 0)
		std::cout << products[i] << std::endl;
	}
}

#endif // !PRODUCTCATALOGUE_HPP