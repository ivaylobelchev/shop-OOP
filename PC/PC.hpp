#ifndef PC_HPP
#define PC_HPP

#include "../product.hpp"

class PC: public Product
{
public:
	enum ComputerManufacturer : short
	{
		UNIDENTIFIED,
		LENOVO,
		HP,
		APPLE,
		DELL,
		ASUS,
		ACER,
		ALIENWARE,
	};
	enum ProcessorManufacturerPC : short
	{
		OTHER,
		INTEL,
		AMD
	};
	enum GPUmanufacturer : short
	{
		NONE,
		NVIDIA,
		AMD_GPU,
		INTEL_GPU
	};
private:
	ComputerManufacturer computerManufacturer;
	ProcessorManufacturerPC processorManufacturer;
	std::string model;
	std::string processorName;
	unsigned short processorCores;
	unsigned short processorMHz;
	int processorTurboMHz;
	unsigned int processorCacheKB; // L1 + L2 + L3
	unsigned int RAMinMB;
	GPUmanufacturer GPU;
	std::string GPUmodel;
	unsigned short PSUwattage;
	unsigned short numberOfUSBports;
	unsigned short SSD_GB;
	unsigned short HDD_GB;
public:
	PC();
	PC(
		ComputerManufacturer computerManufacturer,
		std::string model,
		const unsigned int price100,
		const ProcessorManufacturerPC processorManufacturer,
		std::string processorName,
		const unsigned short processorCores,
		const unsigned short processorMHz,
		const int processorTurboMHz,
		const unsigned int processorCacheKB,
		const unsigned int RAMinMB,
		GPUmanufacturer GPU,
		std::string GPUmodel,
		const unsigned short PSUwattage,
		const unsigned short numberOfUSBports,
		const unsigned short SSD_GB,
		const unsigned short HDD_GB
	);
	void setPC(
		ComputerManufacturer computerManufacturer,
		std::string model,
		const unsigned int price100,
		const ProcessorManufacturerPC processorManufacturer,
		std::string processorName,
		const unsigned short processorCores,
		const unsigned short processorMHz,
		const int processorTurboMHz,
		const unsigned int processorCacheKB,
		const unsigned int RAMinMB,
		GPUmanufacturer GPU,
		std::string GPUmodel,
		const unsigned short PSUwattage,
		const unsigned short numberOfUSBports,
		const unsigned short SSD_GB,
		const unsigned short HDD_GB
	);
	PC(const PC& from);
	PC& operator=(const PC& from);
	void print();
	//unsigned int getPrice100();
	friend std::ostream& operator<<(std::ostream&, const PC&);
	const std::string& getModel() const;
	~PC();
};

#endif //PC_HPP