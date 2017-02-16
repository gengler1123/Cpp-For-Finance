// Week03_b.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>


class Stock
{
private:
	std::string name;
	std::string tickerID;
	int shares;
	double price;


public:
	Stock();
	Stock(
		std::string name_,
		std::string tickerID_,
		int shares_,
		double price_);

	double currentValue(){ return double(shares) * price; };

	void buyShares(
		int numShares_,
		double price_);

	void sellShares(
		int numShares_,
		double price_);
};

Stock::Stock()
{
	
}

Stock::Stock(
	std::string name_,
	std::string tickerID_,
	int numShares_,
	double price_)
{
	name = name_;
	tickerID = tickerID_;
	shares = numShares_;
	price = price_;
}




int main()
{
	Stock IBM("International Business...",
		"IBM",
		1000,
		101.0);

	std::cout << "The current value of IBM is $" << IBM.currentValue() << std::endl;

	
}