#ifndef __PORTFOLIO_H__
#define __PORTFOLIO_H__

#include "stock.h"

#include <vector>

class Portfolio
{
private:
	std::vector<Stock> Stocks;
	double currentValue = 0;
public:
	void addStock(/*Parameters Here*/);
	void buyStock(/*Parameters Here*/);
	void sellStock(/*Parameters Here*/);
	void removeStock(/*Parameters Here*/);

};



#endif