#ifndef LAPTOP_HPP
#define LAPTOP_HPP

#include "../product.hpp"

class Laptop: public Product
{
public:
	enum LaptopManufacturer : short
	{
		UNIDENTIFIED,
		LENOVO,
		HP,
		APPLE,
		DELL,
		ASUS,
		ACER,
		MICROSOFT,
		TOSHIBA,
		ALIENWARE,
		XIAOMI,
		HUAWEI
	};
	enum ProcessorManufacturer : short
	{
		OTHER,
		INTEL,
		AMD,
		QUALCOMM
	};
private:
	//Product product;
	//friend Product;
	LaptopManufacturer laptopManufacturer;
	ProcessorManufacturer processorManufacturer;
	std::string model;
	double screenSize; // in inches
	std::string processorName;
	unsigned short processorCores;
	unsigned short processorMHz;
	int processorTurboMHz;
	unsigned int processorCacheKB; // L1 + L2 + L3
	unsigned int RAMinMB;
	unsigned int batterymAh;
	//unsigned int ProductNo;
public:
	Laptop();
	Laptop(
		LaptopManufacturer laptopManufacturer,
		std::string model,
		const double screenSize,
		const unsigned int price100,
		const ProcessorManufacturer processorManufacturer,
		std::string processorName,
		const unsigned short processorCores,
		const unsigned short processorMHz,
		const int processorTurboMHz,
		const unsigned int processorCacheKB,
		const unsigned int RAMinMB,
		const unsigned int batterymAh
	);
	void setLaptop(
		LaptopManufacturer laptopManufacturer,
		std::string model,
		const double screenSize,
		const unsigned int price100,
		const ProcessorManufacturer processorManufacturer,
		std::string processorName,
		const unsigned short processorCores,
		const unsigned short processorMHz,
		const int processorTurboMHz,
		const unsigned int processorCacheKB,
		const unsigned int RAMinMB,
		const unsigned int batterymAh
	);
	Laptop(const Laptop& from); // Copy contructor
	Laptop& operator=(const Laptop& from);
	void print();
	//unsigned int getPrice100();
	friend std::ostream& operator<<(std::ostream&, const Laptop&);
	const std::string& getModel() const;
	~Laptop();
};

#endif //LAPTOP_HPP