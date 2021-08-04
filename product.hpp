#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>
#include <string>

//#include "Laptop/laptop.hpp"
//#include "PC/PC.hpp"
//#include "Phone/phone.hpp"

class Product /*: public PC, public Laptop, public Phone*/
{
public:
    enum ProductType : short // DO NOT TOUCH
    {
        NOTDEFINED, // 0
        LAPTOPS,    // 1
        PCS,        // 2
        PHONES      // 3
    };
protected:
    std::string name;
    unsigned int productNumber;
    ProductType category;
    bool hidden = 0;
    unsigned int price100; // Price multiplied by a 100
    //void copyFromProduct(const Product&);
    
public:
    void virtual print();

    Product();
    Product(const Product::ProductType);
    Product(std::string name, const Product::ProductType);
    Product(const Product&);
    Product& operator=(const Product&);
    void setType(const Product::ProductType);
    void set(std::string name, const Product::ProductType);
    //unsigned int getPrice100Product();
    unsigned int getProductNumber();
    unsigned int getPrice100();
    const std::string& getName();
    bool isHidden();
    ~Product();
};

#endif //PRODUCT_HPP