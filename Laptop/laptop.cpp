#include <iostream>
#include "laptop.hpp"
#include <cstring>
#pragma warning (disable:4996)

Laptop::Laptop()
{
	this->category = Product::ProductType::LAPTOPS;
	laptopManufacturer = Laptop::UNIDENTIFIED;
	model = "";
	screenSize = 0;
	price100 = 0;
	processorManufacturer = Laptop::OTHER;
	processorName = "";
	processorCores = 0;
	processorMHz = 0;
	processorTurboMHz = -1;
	processorCacheKB = 0;
	RAMinMB = 0;
	batterymAh = 0;
}

void Laptop::setLaptop(
	const Laptop::LaptopManufacturer laptopManufacturer,
	std::string model,
	const double screenSize,
	const unsigned int price100,
	const Laptop::ProcessorManufacturer processorManufacturer,
	std::string processorName,
	const unsigned short processorCores,
	const unsigned short processorMHz,
	const int processorTurboMHz,
	const unsigned int processorCacheKB,
	const unsigned int RAMinMB,
	const unsigned int batterymAh
)
{
	this->laptopManufacturer = laptopManufacturer;

	this->model = model;

	this->screenSize = screenSize;
	this->price100 = price100;
	this->processorManufacturer = processorManufacturer;

	this->processorName = processorName;

	this->processorCores = processorCores;
	this->processorMHz = processorMHz;
	this->processorTurboMHz = processorTurboMHz;
	this->processorCacheKB = processorCacheKB;
	this->RAMinMB = RAMinMB;
	this->batterymAh = batterymAh;
}

Laptop::Laptop(
	const Laptop::LaptopManufacturer laptopManufacturer,
	std::string model,
	const double screenSize,
	const unsigned int price100,
	const Laptop::ProcessorManufacturer processorManufacturer,
	std::string processorName,
	const unsigned short processorCores,
	const unsigned short processorMHz,
	const int processorTurboMHz,
	const unsigned int processorCacheKB,
	const unsigned int RAMinMB,
	const unsigned int batterymAh
)
{
	this->category = Product::ProductType::LAPTOPS;
	setLaptop(laptopManufacturer, model, screenSize, price100, processorManufacturer, processorName,
		processorCores, processorMHz, processorTurboMHz, processorCacheKB, RAMinMB, batterymAh);
}

Laptop::Laptop(const Laptop& from)
{
	this->category = Product::ProductType::LAPTOPS;
	this->laptopManufacturer = from.laptopManufacturer;

	this->model = from.model;

	this->screenSize = from.screenSize;
	this->price100 = from.price100;
	this->processorManufacturer = from.processorManufacturer;

	this->processorName = from.processorName;

	this->processorCores = from.processorCores;
	this->processorMHz = from.processorMHz;
	this->processorTurboMHz = from.processorTurboMHz;
	this->processorCacheKB = from.processorCacheKB;
	this->RAMinMB = from.RAMinMB;
	this->batterymAh = from.batterymAh;
}

Laptop& Laptop::operator=(const Laptop& from)
{
	if (this != &from)
	{
		this->category = (Product::ProductType)1;
		this->laptopManufacturer = from.laptopManufacturer;

		this->model = from.model;

		this->screenSize = from.screenSize;
		this->price100 = from.price100;
		this->processorManufacturer = from.processorManufacturer;

		this->processorName = from.processorName;

		this->processorCores = from.processorCores;
		this->processorMHz = from.processorMHz;
		this->processorTurboMHz = from.processorTurboMHz;
		this->processorCacheKB = from.processorCacheKB;
		this->RAMinMB = from.RAMinMB;
		this->batterymAh = from.batterymAh;
	}
	return *this;
}

void Laptop::print()
{
	std::cout << *this;
	return;

	//this->print();
	////LaptopManufacturer laptopManufacturer;
	//std::cout << "Laptop model: ";
	//switch (laptopManufacturer)
	//{
	//case Laptop::UNIDENTIFIED:
	//	std::cout << "Unidentified";
	//	break;
	//case Laptop::LENOVO:
	//	std::cout << "Lenovo";
	//	break;
	//case Laptop::HP:
	//	std::cout << "HP";
	//	break;
	//case Laptop::APPLE:
	//	std::cout << "Apple";
	//	break;
	//case Laptop::DELL:
	//	std::cout << "Dell";
	//	break;
	//case Laptop::ASUS:
	//	std::cout << "Asus";
	//	break;
	//case Laptop::ACER:
	//	std::cout << "Acer";
	//	break;
	//case Laptop::MICROSOFT:
	//	std::cout << "Microsoft";
	//	break;
	//case Laptop::TOSHIBA:
	//	std::cout << "Toshiba";
	//	break;
	//case Laptop::ALIENWARE:
	//	std::cout << "Alienware";
	//	break;
	//case Laptop::XIAOMI:
	//	std::cout << "Xiaomi";
	//	break;
	//case Laptop::HUAWEI:
	//	std::cout << "Huawei";
	//	break;
	//default:
	//	break;
	//}

	//std::cout << " " << model << "\n";
	//std::cout << "Screen size: " << screenSize << "\"\n";
	//std::cout << "Price: " << price100 / 100 << '.';
	//if (price100 % 100 < 10) std::cout << '0';
	//std::cout << price100 % 100 << " BGN\n";

	////ProcessorManufacturer processorManufacturer;
	//std::cout << "Processor: ";
	//switch (processorManufacturer)
	//{
	//case Laptop::OTHER: std::cout << "Other ";
	//	break;
	//case Laptop::INTEL: std::cout << "Intel ";
	//	break;
	//case Laptop::AMD: std::cout << "AMD ";
	//	break;
	//case Laptop::QUALCOMM: std::cout << "Qualcomm ";
	//	break;
	//default:
	//	break;
	//}

	//std::cout << processorName << "\n";

	//std::cout << processorCores << "-core CPU\n";
	//std::cout << "CPU frequency: " << processorMHz << "MHz\n";
	//if (processorTurboMHz > 0) std::cout << "CPU turbo boost frequency: " << processorTurboMHz << "MHz\n";
	//std::cout << "CPU cache: " << processorCacheKB << " KB\n";
	//std::cout << "RAM: " << RAMinMB << " MB\n";
	//std::cout << "Battery: " << batterymAh << " mAh\n";
}

//unsigned int Laptop::getPrice100()
//{
//	return this->price100;
//}

std::ostream& operator<<(std::ostream& out, const Laptop& to_print)
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

	out << "Laptop model: ";
	switch (to_print.laptopManufacturer)
	{
	case Laptop::UNIDENTIFIED:
		out << "Unidentified";
		break;
	case Laptop::LENOVO:
		out << "Lenovo";
		break;
	case Laptop::HP:
		out << "HP";
		break;
	case Laptop::APPLE:
		out << "Apple";
		break;
	case Laptop::DELL:
		out << "Dell";
		break;
	case Laptop::ASUS:
		out << "Asus";
		break;
	case Laptop::ACER:
		out << "Acer";
		break;
	case Laptop::MICROSOFT:
		out << "Microsoft";
		break;
	case Laptop::TOSHIBA:
		out << "Toshiba";
		break;
	case Laptop::ALIENWARE:
		out << "Alienware";
		break;
	case Laptop::XIAOMI:
		out << "Xiaomi";
		break;
	case Laptop::HUAWEI:
		out << "Huawei";
		break;
	default:
		break;
	}

	out << " " << to_print.model << "\n";
	out << "Screen size: " << to_print.screenSize << "\"\n";
	out << "Price: " << to_print.price100 / 100 << '.';
	if (to_print.price100 % 100 < 10) out << '0';
	out << to_print.price100 % 100 << " BGN\n";

	//ProcessorManufacturer processorManufacturer;
	out << "Processor: ";
	switch (to_print.processorManufacturer)
	{
	case Laptop::OTHER: out << "Other ";
		break;
	case Laptop::INTEL: out << "Intel ";
		break;
	case Laptop::AMD: out << "AMD ";
		break;
	case Laptop::QUALCOMM: out << "Qualcomm ";
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
	out << "Battery: " << to_print.batterymAh << " mAh\n";

	return out;
}

const std::string& Laptop::getModel() const
{
	return this->model;
}

Laptop::~Laptop()
{
	// no need
};