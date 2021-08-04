#include <iostream>

#include "Login/UserDatabase.hpp"
#include "ProductCatalogue.hpp"
#include "Basket/Basket.hpp"

int main()
{
	//Product a(Product::LAPTOPS); 
	Laptop a(Laptop::APPLE, "MacBook Air 2018", 13.3, 219998, Laptop::INTEL, "i5-8210Y", 2, 1600, 3600, 4096, 8192, 4381);
	Laptop b(Laptop::APPLE, "MacBook Air 2020", 15, 354998, Laptop::INTEL, "i7-10510Y", 4, 1600, 3600, 5120, 16384, 6381);
	Laptop l(Laptop::LENOVO, "Lenovo X1 Carbon Gen3", 14.0, 79000, Laptop::INTEL, "i7-5600U", 2, 2600, 3200, 4736, 8192, 5678);

	ProductCatalogueType<Laptop> LaptopCatalogue;
	LaptopCatalogue.add(a);
	LaptopCatalogue.add(b);
	LaptopCatalogue.add(l);

	//LaptopCatalogue.printAll();

	/*Vector<Laptop> LaptopCatalogue;
	LaptopCatalogue.pushBack(a);
	LaptopCatalogue.pushBack(b);
	LaptopCatalogue.pushBack(l);*/
	//LaptopArray.printVector();

	//LaptopCatalogue.printModel("MacBook");

	//a.print();
	//std::cout << a << std::endl;

	//Product c(Product::PCS);
	PC c(PC::UNIDENTIFIED, "", 142600, PC::AMD, "Ryzen 5 3600X", 6, 3800, 4400, 36224, 16384, PC::AMD_GPU, "RX570", 650, 6, 512, 2048);
	//c.printPC();
	//std::cout << c << std::endl;

	Phone e(Phone::SAMSUNG, Phone::EXYNOS, 5, "Galaxy S20 5G", 6.2, 195581, "990", 12288, 4000, 64, 2.0, 10, 2.2, 1440, 3200, 1, 0, 1, 1);
	Phone f(Phone::APPLE, Phone::APPLE_CPU, 4, "iPhone SE (2020)", 4.7, 93685, "A13 Bionic", 3072, 1821, 12, 1.8, 7, 2.2, 1334, 750, 1, 0, 0, 0);

	//std::cout << e << std::endl << f;
	Product& temp = e;
	//temp.print();

	//Vector<Phone> phoneCatalogue;
	//phoneCatalogue.pushBack(e);
	//phoneCatalogue.pushBack(f);
	//phoneCatalogue.printModel("iPhone");

	//e.printPhone();
	//std::cout << e << std::endl;
	

	// Product a; a = Product(sth, sth); 

	/*User user1("Ivaylo", "pass123");
	std::cerr << user1.changePassword("pass123", "newpass123");
	std::cout << "\n" << user1.getUsername();
	std::cout << "\n" << user1.isThisAccountAnAdmin() << "\n";
	
	User user2(user1);
	user2 = user2;
	User user3 = user1;

	std::cout << "\n" << user2.getUsername();
	std::cout << "\n" << user3.getUsername() << "\n\n";

	Admin admin1;
	admin1.setup("ivaylo.admin", "myAdminPassword");
	std::cerr << admin1.changePassword("notMyAdminPassword", "This will return 0.") << std::endl;
	std::cout << admin1.getUsername() << "\n" << admin1.isThisAccountAnAdmin() << "\n\n";

	Admin admin2(admin1);
	admin2 = admin2;
	Admin admin3 = admin2;
	std::cout << admin3.passwordMatch("myAdminPassword") << std::endl;

	std::cout << admin2.getUsername() << "\n" << admin2.isThisAccountAnAdmin() << "\n\n";
	std::cout << admin3.getUsername() << "\n" << admin3.isThisAccountAnAdmin() << "\n\n";

	UserDatabase myUserDatabase(admin1);
	myUserDatabase.addUser(user1);*/

	Basket ba;
	ba.addObject(a);
	ba.addObject(c);
	ba.addObject(f);
	ba.printTotalPrice();

	std::cout << "\n";

	ba.printBasket();

	ba.removeObject(0);
	ba.removeObject(0);
	ba.printBasket();

	User ivo1234("ivo.normie", "easyPassword");
	std::cout << "\n\n";

	Admin ivoAdmina("ibelchev.admin", "tainaParola");

	UserDatabase userData;
	userData.addUser(ivo1234);
	userData.addUser(ivoAdmina);

	userData.printAll();


	/*Product myPhone("Samsung Galaxy S7 Edge", Product::ProductType::LAPTOPS);
	std::cout << myPhone.getName() << "\n";

	ProductCatalogueType<Product> catalogue(myPhone);*/

	return 0;
}