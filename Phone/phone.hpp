#ifndef PHONE_HPP
#define PHONE_HPP

#include "../product.hpp"

class Phone : public Product
{
public:
	enum PhoneManufacturer : char
	{
		UNIDENTIFIED = 1,
		SAMSUNG,
		APPLE,
		ONEPLUS,
		HUAWEI,
		XIOAMI,
		GOOGLE,
		LG,
		NOKIA
	};
	enum ProcessorManufacturer : char
	{
		OTHER = 1,
		QUALCOMM,
		EXYNOS,
		APPLE_CPU,
		MEDIATEK
	};
private:
	PhoneManufacturer phoneManufacturer;
	ProcessorManufacturer processorManufacturer;
	short networkTypeSupport_G;
	std::string model;
	double screenSize; // in inches
	std::string processorName;
	unsigned int RAMinMB;
	unsigned int batterymAh;
	float mainCameraMP;
	float mainCameraF;
	float selfieCameraMP;
	float selfieCameraF;
	short displayResolutionHorizontal;
	short displayResolutionVertical;
	bool fingerprintSensor;
	bool headphonejack;
	bool curvedDisplay;
	bool USBC;
public:
	Phone();
	Phone(
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
		bool USBC);
	void setPhone(
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
		bool USBC);
	Phone(const Phone& from);
	Phone& operator=(const Phone& from);
	void print();
	friend std::ostream& operator<<(std::ostream&, const Phone&);
	//unsigned int getPrice100();
	const std::string& getModel() const;
	~Phone();
};

#endif //PHONE_HPP