#include<iostream>
#include<windows.h>
#include<vector>
#include <iomanip>
#include <ctime>
#include <string>
#pragma warning(disable : 4996)

void menu() {
	std::cout << "Welcome! User" << '\n' << '\n';
	std::cout << "*** Shopping System ***" << '\n';
	std::cout << "------------------------" << '\n';
	std::cout << "[1]. Load starting data" << '\n';
	std::cout << "[2]. View CustomerRecord" << '\n';
	std::cout << "[3]. Add/drop account" << '\n';
	std::cout << "[4]. Edit balance" << '\n';
	std::cout << "[5]. Buy items" << '\n';
	std::cout << "[6]. View history change" << '\n';
	std::cout << "[7]. Exit" << '\n';
	std::cout << "------------------------" << '\n';
}

class CustomerRecord {
public:
	std::string customerID{};
	char customerRank{};
	int balance{};
};

class ItemRecord {
public:
	std::string itemID{};
	std::string itemDescription{};
	int itemPrice{};
};

class TransactionHistoryRecord {
public:
	std::string customerID{};
	std::string action{};
	std::string itemBought{};
	int balanceChange{};
	int debt{};
};

class InitCustomerRecord {
public:
	std::string customerID{};
	int balance{};
};

std::vector<CustomerRecord> customerRecords;
std::vector<ItemRecord> itemRecords;
std::vector <TransactionHistoryRecord> transactionHistoryRecords;
std::vector<InitCustomerRecord> initCustomerRecords;

void storeCustomerRecord() { // initialize data
	customerRecords.push_back({ "Tommy2015", 'B', 8500 });
	customerRecords.push_back({ "DavidChan", 'B', 22800 });
	customerRecords.push_back({ "Luna123", 'B', 650 });
	customerRecords.push_back({ "TigerMan", 'B', 14000 });
	customerRecords.push_back({ "Max5678", 'S', 2580 });
	customerRecords.push_back({ "Neo2000", 'S', 8000 });
	customerRecords.push_back({ "CCTang", 'S', 33554 });
	customerRecords.push_back({ "EchoWong", 'G', 8650 });
	customerRecords.push_back({ "Rubychow", 'G', 28000 });
	customerRecords.push_back({ "Ivy2023", 'G', 12340 });
}
void storeItemRecord() { // initialize data
	itemRecords.push_back({ "A01", "LG Internet TV", 3900 });
	itemRecords.push_back({ "A02", "Pioneer Hifi Set", 2400 });
	itemRecords.push_back({ "A03", "Sony DVD Player", 400 });
	itemRecords.push_back({ "B01", "Healthy Air Fryer", 1500 });
	itemRecords.push_back({ "B02", "Tefal Microwave Oven", 480 });
	itemRecords.push_back({ "B03", "Famous Coffee Maker", 1800 });
	itemRecords.push_back({ "B04", "Smart Rice Cooker", 600 });
	itemRecords.push_back({ "B05", "TechCook Toaster Oven", 450 });
	itemRecords.push_back({ "C01", "Wellcome $50 Coupon", 50 });
	itemRecords.push_back({ "C02", "Mannings $50 Coupon", 50 });
	itemRecords.push_back({ "C03", "Carol Restaurant $100 Coupon", 100 });
	itemRecords.push_back({ "C04", "Shell $200 Coupon", 200 });
	itemRecords.push_back({ "D01", "Clever Headset", 350 });
	itemRecords.push_back({ "D02", "HP Optic Mouse", 250 });
	itemRecords.push_back({ "D03", "Stylish Bluetooth Speaker", 800 });
}

void storeInitCustomerRecord() { // initialize data
	initCustomerRecords.push_back({ "Tommy2015", 8500 });
	initCustomerRecords.push_back({ "DavidChan", 22800 });
	initCustomerRecords.push_back({ "Luna123", 650 });
	initCustomerRecords.push_back({ "TigerMan", 14000 });
	initCustomerRecords.push_back({ "Max5678", 2580 });
	initCustomerRecords.push_back({ "Neo2000", 8000 });
	initCustomerRecords.push_back({ "CCTang", 33554 });
	initCustomerRecords.push_back({ "EchoWong", 8650 });
	initCustomerRecords.push_back({ "Rubychow", 28000 });
	initCustomerRecords.push_back({ "Ivy2023", 12340 });
}
void errorInput() {
	std::cin.clear();
	std::cin.ignore(10000, '\n');
}

void loadData() { // [1]  Load starting data
	system("CLS");
	std::cout << "Data loading" << '\n';
	Sleep(1000);
	std::cout << "Finish!";
	Sleep(1000);
	system("CLS");
}

void printCustomerRecord() { // [2] Customer Record
	std::cout << '\n';
	std::cout << "***CustomerRecord***" << '\n';
	std::cout << std::string(90, '=') << '\n';
	std::cout << std::setw(31) << "CustomerID";
	std::cout << std::setw(25) << "Rank";
	std::cout << std::setw(35) << "Points Balance" << '\n';
	std::cout << std::string(90, '=') << '\n';
	std::cout << std::left;
	for (auto& customerRecord : customerRecords) {
		std::cout << std::setw(31) << customerRecord.customerID;
		std::cout << std::setw(25) << customerRecord.customerRank;
		std::cout << customerRecord.balance << '\n';
	}
	std::cout << std::string(90, '=') << '\n';

}

void printItemRecord() { // [2] Customer Record
	std::cout << std::left;
	std::cout << "***Item Record***" << '\n';
	std::cout << std::string(90, '=') << '\n';
	std::cout << std::setw(10) << "ItemID" << std::setw(30) << "ItemDescription" << std::setw(20) << "Price" << '\n';
	std::cout << std::string(90, '=') << '\n';

	for (auto& itemRecord : itemRecords) {
		std::cout << std::setw(10) << itemRecord.itemID << std::setw(30) << itemRecord.itemDescription << std::setw(20) << itemRecord.itemPrice << '\n';
	}
	std::cout << std::string(90, '=') << '\n';
}

std::string editCustomer() { //[3] add/drop account
	system("CLS");
	std::string userID;
	char choice = ' ';
	std::cout << "If userID not FOUND, new account will be created" << '\n';
	std::cout << "If userID is FOUND, you can delete the account in the following action" << '\n';
	std::cout << "Register day >= 365 will be ranked as G(gold), >= 180 will be ranked as S(silver), else is B(bronze)," << '\n' << '\n';
	std::cout << "Enter userID:";
	std::cin >> userID;
	errorInput();
	return userID;
}

std::string enterUserName() {
	std::string userID;
	std::cout << "Enter the customer name:";
	std::cin >> userID;
	return userID;
}
bool findCustomer(std::string userID) {
	for (auto& customerRecord : customerRecords) {
		if (customerRecord.customerID == userID) {
			std::cout << "userID FOUND" << '\n';
			Sleep(1000);
			return true;
		}
	}
	std::cout << "userID NOT FOUND" << '\n';
	Sleep(1000);
	return false;
}

void deleteCustomer(std::string userID) { // [3] add/drop customer
	int checkUserIDPosition = -1;
	char areYouSure = ' ';
	while (areYouSure != 'Y' && areYouSure != 'N') {
		std::cout << "Are you sure you want to delete this account(Y/N):";
		std::cin >> areYouSure;
		errorInput();
		areYouSure = toupper(areYouSure);
	}
	if (areYouSure == 'Y') {
		for (auto& customerRecord : customerRecords) {
			checkUserIDPosition++;
			if (customerRecord.customerID == userID) {
				std::cout << "userID:" << userID << " - ERASED" << '\n';
				Sleep(1000);
				std::cout << "CustomerRecord updated";
				Sleep(1000);
				break;
			}
		}
		Sleep(1000);
		customerRecords.erase(customerRecords.begin() + checkUserIDPosition);
		initCustomerRecords.erase({ initCustomerRecords.begin() + checkUserIDPosition });
	}
	else if (areYouSure == 'N') {
		std::cout << "Action Cancelled" << '\n';
		Sleep(1000);
		std::cout << "Returning to the menu";
		Sleep(1000);
	}
}

bool leapYear(int year) {   // [3] add/drop customer
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
		return true;
	}
	else {
		return false;
	}
}

bool checkDate(int day, int month, int year) { // [3] add/drop customer
	bool valid = false;
	time_t now = time(nullptr);
	tm* localTime = localtime(&now);

	tm currentDate = { 0 };
	currentDate.tm_year = year - 1900;
	currentDate.tm_mon = month - 1;
	currentDate.tm_mday = day;

	time_t currentTimestamp = mktime(&currentDate);
	time_t presentTimestamp = mktime(localTime);

	double daysDifference = difftime(presentTimestamp, currentTimestamp) / (24 * 60 * 60);

	if (daysDifference < 0) {
		return valid;
	}
	if (day < 1 || day > 31) {
		//std::cout << "dayBug"; Sleep(3000);
		return valid;
	}
	if (month < 1 || month > 12) {
		//	std::cout << "monthBug"; Sleep(3000);
		return valid;
	}
	if (year < 1970) {
		//	std::cout << "yearBug"; Sleep(3000);
		return valid;
	}
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day <= 31) {
		valid = true;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day <= 30) {
		valid = true;
	}
	if (leapYear(year) == false) {
		if (month == 2 && month <= 28) {
			valid = true;
		}
	}
	if (leapYear(year) == true) {
		if (month == 2 && month <= 29) {
			valid = true;
		}
	}
	return valid;
}

char getRank(int day, int month, int year) { // [3] add/drop customer
	char getRank = ' ';
	time_t now = time(nullptr);
	tm* localTime = localtime(&now);

	tm currentDate = { 0 };
	currentDate.tm_year = year - 1900;
	currentDate.tm_mon = month - 1;
	currentDate.tm_mday = day;

	time_t currentTimestamp = mktime(&currentDate);
	time_t presentTimestamp = mktime(localTime);

	double daysDifference = difftime(presentTimestamp, currentTimestamp) / (24 * 60 * 60);

	if (static_cast<int>(daysDifference) >= 365) {
		getRank = 'G';
	}
	else if (static_cast<int>(daysDifference) >= 180) {
		getRank = 'S';
	}
	else {
		getRank = 'B';
	}
	std::cout << "\n";
	std::cout << "You have registed " << static_cast<int>(daysDifference) << " day" << '\n';
	std::cout << "Your Rank is:" << getRank << '\n';
	return getRank;
}

char convertStringToInt(std::string birthOfDate) { // [3] add/drop customer
	char temp[10] = {};   //  Size of DD/MM/YYYY   and '/' apper at postition 2,5
	int day, month, year;
	char rank = ' ';
	bool validDate = false;
	std::cout << "Enter your register day(DD/MM/YYYY):";
	while (birthOfDate.length() != 10 || birthOfDate.at(2) != '/' || birthOfDate.at(5) != '/' || validDate != true) {
		std::cin >> birthOfDate;
		if (birthOfDate.length() != 10) { // prevent array crash  array[10] = {'1', null, null, null} or array[15] but we only have array[10]
			birthOfDate = "99/99/9999"; // set array to [10]
		}
		for (int i = 0; i < 10; i++) { // convert string to char arry first
			temp[i] = birthOfDate.at(i);
		}
		day = static_cast<int>((temp[0] - '0') * 10 + temp[1] - '0'); // temp[0] temp[1] is DD  when - '0' it will show the correct int of char the fomular of day = if temp[0] = 2 and temp[1] = 6; when 2*10 = 20;  20 + temp[1] = 20 + 6 = 26
		month = static_cast<int>((temp[3] - '0') * 10 + temp[4] - '0'); // same fomular as Day
		year = static_cast<int>((temp[6] - '0') * 1000 + (temp[7] - '0') * 100 + (temp[8] - '0') * 10 + temp[9] - '0');
		validDate = checkDate(day, month, year);
		if (validDate == false) {
			std::cout << "Wrong date format or invalid date(DD/MM/YYYY):";
		}
	}
	std::cout << "Success! " << day << "/" << month << "/" << year << '\n';
	rank = getRank(day, month, year);
	return rank;
}

void addCustomer(std::string userID) { // [3] add/drop customer
	int balance = 0;
	std::string birthOfDate = " ";
	std::cout << "This userID haven't been taken, can be used to create account" << '\n' << '\n';
	std::cout << "Enter your balance (0 - 100,000,000):";
	while (!(std::cin >> balance) || balance < 0 || balance > 100000000) {
		errorInput();
		std::cout << "Must be integer and (0 - 100,000,000):";
	}
	errorInput();
	customerRecords.push_back({ userID, convertStringToInt(birthOfDate) , balance });
	initCustomerRecords.push_back({ userID, balance });
	std::cout << "Account Created" << '\n';
	Sleep(3000);
	std::cout << "CustomerRecord updated";
	Sleep(3000);
}

void editBalanceMenu(std::string userID) { // [4] Edit balance
	system("CLS");
	std::cout << "Welcome! " << userID << '\n' << '\n';
	std::cout << "***Edit Menu***" << '\n';
	std::cout << "------------------------" << '\n';
	std::cout << "[1]Deposit money" << '\n';
	std::cout << "[2]Withdraw money" << '\n';
	std::cout << "[3]Modify balance" << '\n';
	std::cout << "[4]Back to Customer Menu" << '\n';
	std::cout << "------------------------" << '\n';
}

void depositMoney(std::string userID) { // [4] Edit balance 
	int totalMoney = 0;
	int addMoney;
	system("CLS");
	for (auto& CustomerRecord : customerRecords) {
		if (CustomerRecord.customerID == userID) {
			std::cout << "Customer:" << userID << "  " << "Balances:" << CustomerRecord.balance << '\n';
		}
	}
	std::cout << "Input the money you want to deposit(0 - 100,000,000):";
	while (!(std::cin >> addMoney) || addMoney < 0 || addMoney > 100000000) {
		errorInput();
		std::cout << "Again(0 - 100,000,000):";
	}
	for (auto& CustomerRecord : customerRecords) {
		if (CustomerRecord.customerID == userID) {
			totalMoney = CustomerRecord.balance;
			CustomerRecord.balance += addMoney;
		}
	}
	std::cout << '\n';
	std::cout << "You have added $" << addMoney << '\n';
	Sleep(2000);
	std::cout << "Account Updated!" << '\n';
	Sleep(1000);
	std::cout << "Your balances is now:" << totalMoney + addMoney << '\n';
	Sleep(2000);
	transactionHistoryRecords.push_back({ userID, "Deposit money", "NULL", addMoney, 0 });
}

void withdrawMoney(std::string userID) { // [4] Edit balance
	int totalMoney = 0;
	int deductMoney;
	system("CLS");
	for (auto& CustomerRecord : customerRecords) {
		if (CustomerRecord.customerID == userID) {
			std::cout << "Customer:" << userID << "  " << "Balances:" << CustomerRecord.balance << '\n';
		}
	}
	std::cout << "Input the money you want to deposit(0 - 100,000,000):";
	while (!(std::cin >> deductMoney) || deductMoney < 0 || deductMoney > 100000000) {
		errorInput();
		std::cout << "Again(0 - 100,000,000):";
	}
	for (auto& CustomerRecord : customerRecords) {
		if (CustomerRecord.customerID == userID) {
			totalMoney = CustomerRecord.balance;
			CustomerRecord.balance -= deductMoney;
		}
	}
	std::cout << '\n';
	std::cout << "You have withdraw $" << deductMoney << '\n';
	Sleep(2000);
	std::cout << "Account Updated!" << '\n';
	Sleep(1000);
	std::cout << "Your balances is now:" << totalMoney - deductMoney << '\n';
	Sleep(2000);
	transactionHistoryRecords.push_back({ userID, "Withdraw Money", "NULL", deductMoney, 0 });
}

void modifyBalance(std::string userID) { // [4] Edit balance
	int modifyMoney;
	system("CLS");
	for (auto& CustomerRecord : customerRecords) {
		if (CustomerRecord.customerID == userID) {
			std::cout << "Customer:" << userID << "  " << "Balances:" << CustomerRecord.balance << '\n';
		}
	}
	std::cout << "Input the money you want to modify to(0 - 100,000,000):";
	while (!(std::cin >> modifyMoney) || modifyMoney < 0 || modifyMoney > 100000000) {
		errorInput();
		std::cout << "Again(0 - 100,000,000):";
	}
	for (auto& CustomerRecord : customerRecords) {
		if (CustomerRecord.customerID == userID) {
			CustomerRecord.balance = modifyMoney;
		}
	}
	std::cout << '\n';
	std::cout << "You have set your balance to :" << modifyMoney << '\n';
	Sleep(2000);
	std::cout << "Account Updated!" << '\n';
	Sleep(1000);
	std::cout << "Your balances is now:" << modifyMoney << '\n';
	Sleep(2000);
	transactionHistoryRecords.push_back({ userID, "Modify money", "NULL", modifyMoney, 0 });
}

void editBalanceAction(std::string userID) {
	int option = 0;
	while (option != 4) {
		editBalanceMenu(userID);
		std::cout << "Input your option:";
		std::cin >> option;
		errorInput();
		switch (option) {
		case 1:
			depositMoney(userID);
			break;
		case 2:
			withdrawMoney(userID);
			break;
		case 3:
			modifyBalance(userID);
			break;
		case 4: // Back to the shopping system menu (main menu)
			return;
			break;
		}
	}
}

void giftCateogryMenu(std::string userID) {
	for (auto& CustomerRecord : customerRecords) {
		if (CustomerRecord.customerID == userID) {
			std::cout << "Customer:" << userID << "  " << "Balances:" << CustomerRecord.balance << '\n';
		}
	}
	std::cout << "***Item Category***" << '\n';
	std::cout << "------------------------" << '\n';
	std::cout << "[1] Audio & Video" << '\n';
	std::cout << "[2] Kitchenware" << '\n';
	std::cout << "[3] Coupons" << '\n';
	std::cout << "[4] Computer Accessories" << '\n';
	std::cout << "[5] Back to Customer Menu" << '\n';
	std::cout << "------------------------" << '\n';
}

bool areYouSure2() { // no system("CLS")
	char choice = ' ';
	while (choice != 'Y' && choice != 'N') {
		std::cout << "Are you sure?(Y/N):";
		std::cin >> choice;
		errorInput();
		choice = toupper(choice);

		if (choice == 'Y') {
			return true;
		}
		else if (choice == 'N') {
			return false;
		}
	}
}
void buyItem(std::string userID, int option, char category) { // [5] buy item
	std::string itemID = " ";
	float discount = 1;
	int priceAfterDiscount = 0; // use for print the record
	int itemPrice = 0;  // store the price of the vector
	int customerBalnce = 0; // store the balance of the vector

	while (true) {
		bool itemFound = false;
		bool itemAvailable = false;
		system("CLS");
		//start of the menu
		for (auto& CustomerRecord : customerRecords) {
			if (CustomerRecord.customerID == userID) {
				customerBalnce = CustomerRecord.balance; // use in ***available record*** 
				std::cout << "Customer:" << userID << "  " << "Balances:" << CustomerRecord.balance << '\n';
				std::cout << "Your rank is:" << CustomerRecord.customerRank;
				if (CustomerRecord.customerRank == 'G') {
					discount = 0.7;
				}
				else if (CustomerRecord.customerRank == 'S') {
					discount = 0.9;
				}
				else {
					discount = 1;
				}
				if (discount < 1) {
					std::cout << ", you have " << discount * 100 << "% discount" << '\n' << '\n';
				}
				else {
					std::cout << ", you have no discount" << '\n' << '\n';
				}
			}
		}
		std::cout << std::left;
		std::cout << "***Item Record***" << '\n'; // print the record
		std::cout << std::string(90, '=') << '\n';
		std::cout << std::setw(10) << "ItemID" << std::setw(30) << "ItemDescription" << std::setw(20) << "Price" << std::setw(40) << "Price(After discount)" << '\n';
		std::cout << std::string(90, '=') << '\n';
		for (auto& itemRecord : itemRecords) {
			priceAfterDiscount = itemRecord.itemPrice * discount;
			if (itemRecord.itemID[0] == category) {
				std::cout << std::setw(10) << itemRecord.itemID << std::setw(30) << itemRecord.itemDescription << std::setw(20) << itemRecord.itemPrice << std::setw(40) << priceAfterDiscount << '\n';
			}
		}
		std::cout << std::string(90, '=') << '\n' << '\n';

		std::cout << "***Available Record***" << '\n'; // print the record
		std::cout << std::string(90, '=') << '\n';
		std::cout << std::setw(10) << "ItemID" << std::setw(30) << "ItemDescription" << std::setw(20) << "Price" << std::setw(40) << "Price(After discount)" << '\n';
		std::cout << std::string(90, '=') << '\n';
		for (auto& itemRecord : itemRecords) {
			priceAfterDiscount = itemRecord.itemPrice * discount;
			if (itemRecord.itemID[0] == category && customerBalnce > priceAfterDiscount) {
				itemAvailable = true;
				std::cout << std::setw(10) << itemRecord.itemID << std::setw(30) << itemRecord.itemDescription << std::setw(20) << itemRecord.itemPrice << std::setw(40) << priceAfterDiscount << '\n';
			}
		}
		if (itemAvailable == false) {
			std::cout << "No available item, you will be in debt when buying the item" << '\n';
		}
		std::cout << std::string(90, '=') << '\n';
		// end of the menu
		// down is the action
		std::cout << "Enter the itemID (q to exit):";
		std::cin >> itemID;
		errorInput();
		if (itemID == "q" || itemID == "Q") {
			break;
		}
		for (auto& itemRecord : itemRecords) {
			if ((itemID[0] == category) && itemID == itemRecord.itemID) {
				itemPrice = itemRecord.itemPrice;
				itemFound = true;
				break;
			}
		}
		if (itemFound == false) {
			std::cout << "No such a item." << '\n';
			Sleep(1000);
		}
		else {
			for (auto& CustomerRecord : customerRecords) {
				bool areYouSure = false;
				if (CustomerRecord.customerID == userID) {
					if (CustomerRecord.balance < itemPrice * discount) {
						std::cout << "You don't have enough money, are you sure you want to buy it:";
						areYouSure = areYouSure2();
					}
					if (CustomerRecord.balance > itemPrice * discount || areYouSure == true) {
						int price = itemPrice * discount;
						CustomerRecord.balance = CustomerRecord.balance - itemPrice * discount;
						std::cout << "Success, you have buy the item " << itemID << '\n';
						Sleep(1000);
						std::cout << "Price(After discount) is:" << itemPrice * discount << '\n';
						Sleep(1000);
						std::cout << "Your balance is now:" << CustomerRecord.balance << '\n';
						Sleep(1000);
						transactionHistoryRecords.push_back({ userID, "Buy item", itemID, price, 0 });
					}
				}
			}
		}
	}
}

void giftCategoryAction(std::string userID) { // [5] buy item
	int option = 0;
	char category = ' ';

	while (option != 5) {
		system("CLS");
		giftCateogryMenu(userID);
		std::cout << "Input your option:";
		std::cin >> option;
		errorInput();
		switch (option) {
		case 1:
			category = 'A';
			break;
		case 2:
			category = 'B';
			break;
		case 3:
			category = 'C';
			break;
		case 4:
			category = 'D';
			break;
		case 5: // Back to the shopping system menu (main menu)
			category = ' ';
			break;
		default:
			category = ' ';
			break;
		}
		if (category != ' ') {
			buyItem(userID, option, category);
		}
	}
}

void printTransactionHistory(std::string userID) { // [6] View history change
	bool anyRecord = false;
	int MoneyChange = 0;
	std::cout << "Customer:" << userID << '\n';
	std::cout << "***Transaction Histort***" << '\n';
	std::cout << std::string(90, '=') << '\n';
	for (auto& TransactionHistoryRecord : transactionHistoryRecords) {
		if (TransactionHistoryRecord.customerID == userID) {
			anyRecord = true;
			if (TransactionHistoryRecord.action == "Deposit money") {
				std::cout << "Action: " << TransactionHistoryRecord.action << '\n';
				std::cout << "Money Change: +" << TransactionHistoryRecord.balanceChange << '\n';
				std::cout << std::string(90, '-') << '\n';
			}
			else if (TransactionHistoryRecord.action == "Withdraw Money") {
				std::cout << "Action: " << TransactionHistoryRecord.action << '\n';
				std::cout << "Money Change: -" << TransactionHistoryRecord.balanceChange << '\n';
				std::cout << std::string(90, '-') << '\n';
			}
			else if (TransactionHistoryRecord.action == "Modify money") {
				std::cout << "Action: " << TransactionHistoryRecord.action << '\n';
				std::cout << "Money modify to: " << TransactionHistoryRecord.balanceChange << '\n';
				std::cout << std::string(90, '-') << '\n';
			}
			else if (TransactionHistoryRecord.action == "Buy item") {
				std::cout << "Action: " << TransactionHistoryRecord.action << '\n';
				std::cout << "ItemID: " << TransactionHistoryRecord.itemBought << '\n';
				std::cout << "Item price: " << TransactionHistoryRecord.balanceChange << '\n';
				std::cout << std::string(90, '-') << '\n';
			}
		}
	}
	int orginalBalance = 0;
	if (anyRecord == true) {
		for (auto& InitCustomerRecord : initCustomerRecords) {
			if (InitCustomerRecord.customerID == userID) {
				orginalBalance = InitCustomerRecord.balance;
				std::cout << "Original balance: " << InitCustomerRecord.balance << '\n';
			}
		}
		for (auto& CustomerRecord : customerRecords) {
			if (CustomerRecord.customerID == userID) {
				MoneyChange = CustomerRecord.balance;
				std::cout << "Balance now: " << CustomerRecord.balance << '\n';
			}
		}
		if (orginalBalance < MoneyChange) {
			std::cout << "Money change: +" << MoneyChange - orginalBalance << '\n';
		}
		else if (orginalBalance > MoneyChange) {
			if (MoneyChange > 0) {
				std::cout << "Money change: -" << orginalBalance - MoneyChange << '\n';
			}
			else {
				std::cout << "Money change: -" << orginalBalance + MoneyChange << '\n';
			}
		}
		else {
			std::cout << "Money change: " << orginalBalance - MoneyChange << '\n';
		}
	}
	if (anyRecord == false) {
		std::cout << "This account haven't take any action" << '\n';
	}
	std::cout << std::string(90, '=') << '\n';
}

bool areYouSure() {
	char choice = ' ';
	while (choice != 'Y' && choice != 'N') {
		system("CLS");
		std::cout << "Are you sure?(Y/N):";
		std::cin >> choice;
		errorInput();
		choice = toupper(choice);

		if (choice == 'Y') {
			system("CLS");
			return true;
		}
		else if (choice == 'N') {
			system("CLS");
			return false;
		}
	}
}

void exit() { // [7] exit
	system("CLS");
	std::cout << "Thank you very much!!!!!!!!!!!!!!" << '\n';
	std::cout << "If you found any bug, please feel free to tell me";
	return;
}

int main() {
	int option = 0;
	bool isDataLoad = false;
	bool left = false;
	while (isDataLoad == false) {
		system("CLS");
		menu();
		std::cout << "Please load the data first[1]:";
		std::cin >> option;
		errorInput();
		if (option == 1) {
			isDataLoad = true;
			option = 0;
			loadData();
			storeItemRecord();
			storeCustomerRecord();
			storeInitCustomerRecord();
		}
		else if (option == 7) {
			if (areYouSure() == true) {
				exit();
				break;
			}
		}
	}

	while (true && isDataLoad == true) {
		menu();
		if (option == 1) {
			std::cout << "Data already loaded, input other option(2-7):";
			std::cin >> option;
			errorInput();
		}
		else {
			std::cout << "Please input your option(2-7):";
			std::cin >> option;
			errorInput();
		}

		switch (option) {
		case 2:
			system("CLS");
			printItemRecord();
			printCustomerRecord();
			break;
		case 3:
			if (areYouSure() == true) {
				std::string userID = editCustomer();
				if (findCustomer(userID) == true) {
					deleteCustomer(userID);
				}
				else {
					addCustomer(userID);
				}
				system("CLS");
			}
			break;
		case 4:
			if (areYouSure() == true) {
				std::string userID = enterUserName();
				if (findCustomer(userID) == true) {
					editBalanceAction(userID);
				}
				system("CLS");
			}
			break;
		case 5:
			if (areYouSure() == true) {
				std::string userID = enterUserName();
				if (findCustomer(userID) == true) {
					giftCategoryAction(userID);
				}
				system("CLS");
			}
			break;
		case 6:
			if (areYouSure() == true) {
				std::string userID = enterUserName();
				if (findCustomer(userID) == true) {
					system("CLS");
					printTransactionHistory(userID);
				}
				else {
					system("CLS");
				}
			}
			break;
		case 7:
			if (areYouSure() == true) {
				exit();
				return 0;
			}
			break;
		default:
			system("CLS");
			break;
		}
	}
	return 0;
}
