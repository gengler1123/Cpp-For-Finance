#ifndef __STOCK_H__
#define __STOCK_H__

#include <string>

class Stock
{
private:
	std::string name;
	std::string tickerID;
	int shares;
	double price;
public:
	Stock(){};

	std::string giveID(){ return tickerID; };
	Stock(
		std::string name_,
		std::string tickerID_,
		int shares_,
		double price_);

	double currentValue();
};



#endif