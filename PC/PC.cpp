#include <iostream>
#include "PC.hpp"
#include <cstring>
#pragma warning (disable:4996)

PC::PC()
{
	this->category = Product::ProductType::PCS;

	computerManufacturer = PC::UNIDENTIFIED;

	model = "";

	price100 = 0;
	processorManufacturer = PC::OTHER;

	processorName = "";

	processorCores = 0;
	processorMHz = 0;
	processorTurboMHz = -1;
	processorCacheKB = 0;
	RAMinMB = 0;
	GPU = PC::NONE;

	GPUmodel = "";

	PSUwattage = 0;
	numberOfUSBports = 0;
	SSD_GB = 0;
	HDD_GB = 0;
}

void PC::setPC(
	const ComputerManufacturer computerManufacturer,
	std::string model,
	const unsigned int price100,
	const ProcessorManufacturerPC processorManufacturer,
	std::string processorName,
	const unsigned short processorCores,
	const unsigned short processorMHz,
	const int processorTurboMHz,
	const unsigned int processorCacheKB,
	const unsigned int RAMinMB, 
	const GPUmanufacturer GPU,
	std::string GPUmodel,
	const unsigned short PSUwattage,
	const unsigned short numberOfUSBports,
	const unsigned short SSD_GB,
	const unsigned short HDD_GB
)
{
	this->computerManufacturer = computerManufacturer;

	this->model = model;

	this->price100 = price100;
	this->processorManufacturer = processorManufacturer;

	this->processorName = processorName;

	this->processorCores = processorCores;
	this->processorMHz = processorMHz;
	this->processorTurboMHz = processorTurboMHz;
	this->processorCacheKB = processorCacheKB;
	this->RAMinMB = RAMinMB;

	this->GPU = GPU;
	this->GPUmodel = GPUmodel;

	this->PSUwattage = PSUwattage;
	this->numberOfUSBports = numberOfUSBports;
	this->SSD_GB = SSD_GB;
	this->HDD_GB = HDD_GB;
}

PC::PC(
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
)
{
	this->category = Product::ProductType::PCS;
	setPC(computerManufacturer, model, price100,
		processorManufacturer, processorName,
		processorCores, processorMHz, processorTurboMHz,
		processorCacheKB, RAMinMB, GPU, GPUmodel, 
		PSUwattage, numberOfUSBports, SSD_GB, HDD_GB);
}

PC::PC(const PC& from)
{
	this->category = Product::ProductType::PCS;

	this->computerManufacturer = from.computerManufacturer;

	this->model = from.model;

	this->price100 = from.price100;
	this->processorManufacturer = from.processorManufacturer;

	this->processorName = from.processorName;

	this->GPU = from.GPU;
	
	this->GPUmodel = from.GPUmodel;

	this->processorCores = from.processorCores;
	this->processorMHz = from.processorMHz;
	this->processorTurboMHz = from.processorTurboMHz;
	this->processorCacheKB = from.processorCacheKB;
	this->RAMinMB = from.RAMinMB;
	this->PSUwattage = from.PSUwattage;
	this->numberOfUSBports = from.numberOfUSBports;
	this->SSD_GB = from.SSD_GB;
	this->HDD_GB = from.HDD_GB;

	this->name = from.name;

	this->hidden = from.hidden;

	this->category = from.category;
}

PC& PC::operator=(const PC& from)
{
	if (this != &from)
	{
		this->computerManufacturer = from.computerManufacturer;

		this->model = from.model;

		this->price100 = from.price100;
		this->processorManufacturer = from.processorManufacturer;

		this->processorName = from.processorName;

		this->GPU = from.GPU;

		this->GPUmodel = from.GPUmodel;

		this->processorCores = from.processorCores;
		this->processorMHz = from.processorMHz;
		this->processorTurboMHz = from.processorTurboMHz;
		this->processorCacheKB = from.processorCacheKB;
		this->RAMinMB = from.RAMinMB;
		this->PSUwattage = from.PSUwattage;
		this->numberOfUSBports = from.numberOfUSBports;
		this->SSD_GB = from.SSD_GB;
		this->HDD_GB = from.HDD_GB;

		this->name = from.name;

		this->hidden = from.hidden;

		this->category = from.category;
	}
	return *this;
}

void PC::print()
{
	std::cout << *this;
	return;

	/*this->print();
	std::cout << "PC model: ";
	switch (computerManufacturer)
	{
	case PC::UNIDENTIFIED:
		std::cout << "Unidentified";
		break;
	case PC::LENOVO:
		std::cout << "Lenovo";
		break;
	case PC::HP:
		std::cout << "HP";
		break;
	case PC::APPLE:
		std::cout << "Apple";
		break;
	case PC::DELL:
		std::cout << "Dell";
		break;
	case PC::ASUS:
		std::cout << "Asus";
		break;
	case PC::ACER:
		std::cout << "Acer";
		break;
	case PC::ALIENWARE:
		std::cout << "Alienware";
		break;
	default:
		break;
	}

	std::cout << ' ' << model << '\n';
	std::cout << "Price: " << price100 / 100 << '.';
	if (price100 % 100 < 10) std::cout << '0';
	std::cout << price100 % 100 << " BGN\n";

	std::cout << "Processor: ";
	switch (processorManufacturer)
	{
	case PC::OTHER: std::cout << "Other ";
		break;
	case PC::INTEL: std::cout << "Intel ";
		break;
	case PC::AMD: std::cout << "AMD ";
		break;
	default:
		break;
	}

	std::cout << processorName << "\n";

	std::cout << processorCores << "-core CPU\n";
	std::cout << "CPU frequency: " << processorMHz << "MHz\n";
	if (processorTurboMHz > 0) std::cout << "CPU turbo boost frequency: " << processorTurboMHz << "MHz\n";
	std::cout << "CPU cache: " << processorCacheKB << " KB\n";
	std::cout << "RAM: " << RAMinMB << " MB\n";
	std::cout << "PSU: " << PSUwattage << " W\n"; 
	std::cout << numberOfUSBports << " USB ports\n";
	std::cout << "SSD: " << SSD_GB << " GB\n";
	std::cout << "HDD: " << HDD_GB << " GB\n";*/
}

//unsigned int PC::getPrice100()
//{
//	return this->price100;
//}

std::ostream& operator<<(std::ostream& out, const PC& to_print)
{
	out << "Product number: " << to_print.productNumber << "\n";
	if (to_print.name != "")
	{
		out << "Name: " << to_print.name << "\n";
	}

	out << "Category: ";
	switch (to_print.category)
	{
	case Product::NOTDEFINED:
		out << "not defined\n";
		break;
	case Product::LAPTOPS:
		out << "Laptops\n";
		break;
	case Product::PCS:
		out << "PCs\n";
		break;
	case Product::PHONES:
		out << "Phones\n";
		break;
	default:
		break;
	}

	out << "PC model: ";
	switch (to_print.computerManufacturer)
	{
	case PC::UNIDENTIFIED:
		out << "Unidentified";
		break;
	case PC::LENOVO:
		out << "Lenovo";
		break;
	case PC::HP:
		out << "HP";
		break;
	case PC::APPLE:
		out << "Apple";
		break;
	case PC::DELL:
		out << "Dell";
		break;
	case PC::ASUS:
		out << "Asus";
		break;
	case PC::ACER:
		out << "Acer";
		break;
	case PC::ALIENWARE:
		out << "Alienware";
		break;
	default:
		break;
	}

	out << ' ' << to_print.model << '\n';
	out << "Price: " << to_print.price100 / 100 << '.';
	if (to_print.price100 % 100 < 10) out << '0';
	out << to_print.price100 % 100 << " BGN\n";

	out << "Processor: ";
	switch (to_print.processorManufacturer)
	{
	case PC::OTHER: out << "Other ";
		break;
	case PC::INTEL: out << "Intel ";
		break;
	case PC::AMD: out << "AMD ";
		break;
	default:
		break;
	}

	out << to_print.processorName << "\n";

	out << to_print.processorCores << "-core CPU\n";
	out << "CPU frequency: " << to_print.processorMHz << "MHz\n";
	if (to_print.processorTurboMHz > 0) out << "CPU turbo boost frequency: " << to_print.processorTurboMHz << "MHz\n";
	out << "CPU cache: " << to_print.processorCacheKB << " KB\n";
	out << "RAM: " << to_print.RAMinMB << " MB\n";
	out << "PSU: " << to_print.PSUwattage << " W\n";
	out << to_print.numberOfUSBports << " USB ports\n";
	out << "SSD: " << to_print.SSD_GB << " GB\n";
	out << "HDD: " << to_print.HDD_GB << " GB\n";

	return out;
}

const std::string& PC::getModel() const
{
	return this->model;
}

PC::~PC()
{
	// no need
}