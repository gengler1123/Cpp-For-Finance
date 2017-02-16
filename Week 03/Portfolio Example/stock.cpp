#include "stock.h"


Stock::Stock(
	std::string name_,
	std::string tickerID_,
	int shares_,
	double price_)
{
	name = name_;
	tickerID = tickerID_;
	shares = shares_;
	price = price_;
}


double Stock::currentValue()
{
	return double(shares) * price;
}

