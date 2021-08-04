#include <iostream>
#include <iomanip>

#include <cstring>
#pragma warning (disable:4996)

#include "phone.hpp"

Phone::Phone()
{
	this->category = Product::ProductType::PHONES;

	phoneManufacturer = Phone::UNIDENTIFIED;

	model = "";

	screenSize = 0;
	price100 = 0;
	processorManufacturer = Phone::OTHER;

	processorName = "";

	RAMinMB = 0;
	batterymAh = 0;
	networkTypeSupport_G = 0;
	mainCameraMP = 0;
	mainCameraF = 0;
	selfieCameraMP = 0;
	selfieCameraF = 0;
	displayResolutionHorizontal = 0;
	displayResolutionVertical = 0;
	fingerprintSensor = 0; 
	headphonejack = 0;
	curvedDisplay = 0;
	USBC = 0;

	this->category = Product::PHONES;
	/*this->name = new char[1];
	this->name[0] = 0;*/
	this->hidden = 0;
}

void Phone::setPhone(
	PhoneManufacturer phoneManufacturer,
	ProcessorManufacturer processorManufacturer,
	short networkTypeSupport_G,
	std::string model,
	double screenSize,
	unsigned int price100,
	std::string processorName,
	unsigned int RAMinMB,
	unsigned int batterymAh,
	float mainCameraMP,
	float mainCameraF,
	float selfieCameraMP,
	float selfieCameraF,
	short displayResolutionHorizontal,
	short displayResolutionVertical,
	bool fingerprintSensor,
	bool headphonejack,
	bool curvedDisplay,
	bool USBC)
{
	this->phoneManufacturer = phoneManufacturer;

	this->model = model;

	this->screenSize = screenSize;
	this->price100 = price100;
	this->processorManufacturer = processorManufacturer;

	this->processorName = processorName;

	this->RAMinMB = RAMinMB;
	this->batterymAh = batterymAh;
	this->networkTypeSupport_G = networkTypeSupport_G;
	this->mainCameraMP = mainCameraMP;
	this->mainCameraF = mainCameraF;
	this->selfieCameraMP = selfieCameraMP;
	this->selfieCameraF = selfieCameraF;
	this->USBC = USBC;
	this->curvedDisplay = curvedDisplay;
	this->headphonejack = headphonejack;
	this->fingerprintSensor = fingerprintSensor;
	this->displayResolutionHorizontal = displayResolutionHorizontal;
	this->displayResolutionVertical = displayResolutionVertical;
}

Phone::Phone(
	PhoneManufacturer phoneManufacturer,
	ProcessorManufacturer processorManufacturer,
	short networkTypeSupport_G,
	std::string model,
	double screenSize,
	unsigned int price100,
	std::string processorName,
	unsigned int RAMinMB,
	unsigned int batterymAh,
	float mainCameraMP,
	float mainCameraF,
	float selfieCameraMP,
	float selfieCameraF,
	short displayResolutionHorizontal,
	short displayResolutionVertical,
	bool fingerprintSensor,
	bool headphonejack,
	bool curvedDisplay,
	bool USBC)
{
	this->category = Product::ProductType::PHONES;
	setPhone(phoneManufacturer, processorManufacturer, networkTypeSupport_G, model, screenSize, price100,
		processorName, RAMinMB, batterymAh, mainCameraMP, mainCameraF, selfieCameraMP, selfieCameraF,
		displayResolutionHorizontal, displayResolutionVertical, fingerprintSensor, headphonejack, curvedDisplay, USBC);
	/*this->name = new char[1];
	this->name[0] = 0;*/
	this->hidden = 0;
}

Phone::Phone(const Phone& from)
{
	this->phoneManufacturer = from.phoneManufacturer;

	this->model = from.model;

	this->screenSize = from.screenSize;
	this->price100 = from.price100;
	this->processorManufacturer = from.processorManufacturer;

	this->processorName = from.processorName;

	this->RAMinMB = from.RAMinMB;
	this->batterymAh = from.batterymAh;
	this->networkTypeSupport_G = from.networkTypeSupport_G;
	this->mainCameraMP = from.mainCameraMP;
	this->mainCameraF = from.mainCameraF;
	this->selfieCameraMP = from.selfieCameraMP;
	this->selfieCameraF = from.selfieCameraF;
	this->USBC = from.USBC;
	this->curvedDisplay = from.curvedDisplay;
	this->headphonejack = from.headphonejack;
	this->fingerprintSensor = from.fingerprintSensor;
	this->displayResolutionHorizontal = from.displayResolutionHorizontal;
	this->displayResolutionVertical = from.displayResolutionVertical;

	////PRODUCT NUMBER SHOULD NOT BE COPIED
	//this->productNumber = productNumberCounter;
	//++productNumberCounter;

	this->name = from.name;

	this->hidden = from.hidden;

	this->category = Product::ProductType::PHONES;
}

Phone& Phone::operator=(const Phone& from)
{
	if (this != &from)
	{
		this->phoneManufacturer = from.phoneManufacturer;

		this->model = from.model;

		this->screenSize = from.screenSize;
		this->price100 = from.price100;
		this->processorManufacturer = from.processorManufacturer;

		this->processorName = from.processorName;

		this->RAMinMB = from.RAMinMB;
		this->batterymAh = from.batterymAh;
		this->networkTypeSupport_G = from.networkTypeSupport_G;
		this->mainCameraMP = from.mainCameraMP;
		this->mainCameraF = from.mainCameraF;
		this->selfieCameraMP = from.selfieCameraMP;
		this->selfieCameraF = from.selfieCameraF;
		this->USBC = from.USBC;
		this->curvedDisplay = from.curvedDisplay;
		this->headphonejack = from.headphonejack;
		this->fingerprintSensor = from.fingerprintSensor;
		this->displayResolutionHorizontal = from.displayResolutionHorizontal;
		this->displayResolutionVertical = from.displayResolutionVertical;

		////PRODUCT NUMBER SHOULD NOT BE COPIED
		//this->productNumber = productNumberCounter;
		//++productNumberCounter;

		this->name = from.name;

		this->hidden = from.hidden;

		this->category = from.category;
	}
	return *this;
}

void Phone::print()
{
	std::cout << *this;
	return;

	/*this->print();
	std::cout << "Phone model: ";

	switch (phoneManufacturer)
	{
	case Phone::UNIDENTIFIED:
		std::cout << "Unidentified ";
		break;
	case Phone::SAMSUNG:
		std::cout << "Samsung ";
		break;
	case Phone::APPLE:
		std::cout << "Apple ";
		break;
	case Phone::ONEPLUS:
		std::cout << "OnePlus ";
		break;
	case Phone::HUAWEI:
		std::cout << "Huawei ";
		break;
	case Phone::XIOAMI:
		std::cout << "Xioami ";
		break;
	case Phone::GOOGLE:
		std::cout << "Google ";
		break;
	case Phone::LG:
		std::cout << "LG ";
		break;
	case Phone::NOKIA:
		std::cout << "Nokia ";
		break;
	default:
		break;
	}
	std::cout << model << '\n';
	std::cout << "Screen size: " << screenSize << "\"\n";
	std::cout << "Price: " << price100 / 100 << '.';
	if (price100 % 100 < 10) std::cout << '0';
	std::cout << price100 % 100 << " BGN\n";

	std::cout << "Processor: ";
	switch (processorManufacturer)
	{
	case Phone::OTHER:
		std::cout << "Other";
		break;
	case Phone::QUALCOMM:
		std::cout << "Qualcomm";
		break;
	case Phone::EXYNOS:
		std::cout << "Exynos";
		break;
	case Phone::APPLE_CPU:
		std::cout << "Apple";
		break;
	case Phone::MEDIATEK:
		std::cout << "Mediatek";
		break;
	default:
		break;
	}
	std::cout << ' ' << processorName << "\n";

	switch (networkTypeSupport_G)
	{
	case 2: std::cout << "Network type support: 2G"; break;
	case 3: std::cout << "Network type support: 2G/3G"; break;
	case 4: std::cout << "Network type support: 2G/3G/4G"; break;
	case 5: std::cout << "Network type support: 2G/3G/4G/5G"; break;
	default:
		break;
	}
	std::cout << std::endl;
	
	std::cout << "RAM: " << RAMinMB << " MB\n";
	std::cout << "Battery: " << batterymAh << " mAh\n";

	std::cout << "Main camera: \t";
	std::cout << std::setprecision(3) << mainCameraMP << " MP\t";
	std::cout << "F. " << std::setprecision(2) << mainCameraF << "\n";
	std::cout << "Selfie camera: \t";
	std::cout << std::setprecision(3) << selfieCameraMP << " MP\t";
	std::cout << "F. " << std::setprecision(2) << selfieCameraF << "\n";

	std::cout << "Screen resolution is: " << displayResolutionHorizontal << 'x' << displayResolutionVertical << "px\n";

	if (fingerprintSensor) std::cout << "The phone has a fingerprint sensor.\n";
	else std::cout << "The phone does not have a fingerprint sensor.\n";
	if (headphonejack) std::cout << "The phone has a heaphone jack.\n";
	else std::cout << "The phone does not have a heaphone jack.\n";
	if (curvedDisplay) std::cout << "The phone has a curved display.\n";
	else std::cout << "The phone does not have a curved display.\n";
	if (USBC) std::cout << "The phone has a USB Type-C.\n";
	else if (phoneManufacturer == Phone::APPLE) std::cout << "The phone has a lightning port.\n";
	else std::cout << "The phone does not have a USB Type-C.\n";*/
}

//unsigned int Phone::getPrice100()
//{
//	return price100;
//}

std::ostream& operator<<(std::ostream& out, const Phone& to_print)
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

	out << "Phone model: ";

	switch (to_print.phoneManufacturer)
	{
	case Phone::UNIDENTIFIED:
		out << "Unidentified ";
		break;
	case Phone::SAMSUNG:
		out << "Samsung ";
		break;
	case Phone::APPLE:
		out << "Apple ";
		break;
	case Phone::ONEPLUS:
		out << "OnePlus ";
		break;
	case Phone::HUAWEI:
		out << "Huawei ";
		break;
	case Phone::XIOAMI:
		out << "Xioami ";
		break;
	case Phone::GOOGLE:
		out << "Google ";
		break;
	case Phone::LG:
		out << "LG ";
		break;
	case Phone::NOKIA:
		out << "Nokia ";
		break;
	default:
		break;
	}
	out << to_print.model << '\n';
	out << "Screen size: " << to_print.screenSize << "\"\n";
	out << "Price: " << to_print.price100 / 100 << '.';
	if (to_print.price100 % 100 < 10) out << '0';
	out << to_print.price100 % 100 << " BGN\n";

	out << "Processor: ";
	switch (to_print.processorManufacturer)
	{
	case Phone::OTHER:
		out << "Other";
		break;
	case Phone::QUALCOMM:
		out << "Qualcomm";
		break;
	case Phone::EXYNOS:
		out << "Exynos";
		break;
	case Phone::APPLE_CPU:
		out << "Apple";
		break;
	case Phone::MEDIATEK:
		out << "Mediatek";
		break;
	default:
		break;
	}
	out << ' ' << to_print.processorName << "\n";

	switch (to_print.networkTypeSupport_G)
	{
	case 2: out << "Network type support: 2G"; break;
	case 3: out << "Network type support: 2G/3G"; break;
	case 4: out << "Network type support: 2G/3G/4G"; break;
	case 5: out << "Network type support: 2G/3G/4G/5G"; break;
	default:
		break;
	}
	out << std::endl;

	out << "RAM: " << to_print.RAMinMB << " MB\n";
	out << "Battery: " << to_print.batterymAh << " mAh\n";

	out << "Main camera: \t";
	out << std::setprecision(3) << to_print.mainCameraMP << " MP\t";
	out << "F. " << std::setprecision(2) << to_print.mainCameraF << "\n";
	out << "Selfie camera: \t";
	out << std::setprecision(3) << to_print.selfieCameraMP << " MP\t";
	out << "F. " << std::setprecision(2) << to_print.selfieCameraF << "\n";

	out << "Screen resolution is: " << to_print.displayResolutionHorizontal << 'x' << to_print.displayResolutionVertical << "px\n";

	if (to_print.fingerprintSensor) out << "The phone has a fingerprint sensor.\n";
	else out << "The phone does not have a fingerprint sensor.\n";
	if (to_print.headphonejack) out << "The phone has a heaphone jack.\n";
	else out << "The phone does not have a heaphone jack.\n";
	if (to_print.curvedDisplay) out << "The phone has a curved display.\n";
	else out << "The phone does not have a curved display.\n";
	if (to_print.USBC) out << "The phone has a USB Type-C.\n";
	else if (to_print.phoneManufacturer == Phone::APPLE) out << "The phone has a lightning port.\n";
	else out << "The phone does not have a USB Type-C.\n";

	return out;
}

const std::string& Phone::getModel() const
{
	return this->model;
}

Phone::~Phone()
{
	// no need
}