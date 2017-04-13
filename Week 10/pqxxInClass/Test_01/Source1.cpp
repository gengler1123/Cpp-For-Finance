#include <iostream>
#include <pqxx/pqxx>
#include <string>
#include <vector>

using namespace pqxx;

class DBConn
{
private:
	bool opened = false;
	std::string ConnParams;

public:
	//connection conn;
	std::vector<connection*> Conn;
	DBConn(std::string ConnParam);
	~DBConn();
	void createConn();
	void deleteConn();
	void checkConn();
};


DBConn::DBConn(std::string ConnParam)
{
	ConnParams = ConnParam;
}


DBConn::~DBConn()
{
	if (opened)
	{
		std::cout << "In Destructor" << std::endl;
		if (Conn[0]->is_open())
		{
			std::cout << "Still Open" << std::endl;
		}
		deleteConn();
	}
}


void DBConn::createConn()
{
	connection C(ConnParams);
	Conn.push_back(&C);
	if (Conn[0]->is_open())
	{
		std::cout << "DB Is Open!" << std::endl;
		opened = true;
	}
	else
	{
		std::cout << "DB Failed To Open" << std::endl;
	}


}


void DBConn::deleteConn()
{
	if (Conn[0]->is_open())
	{
		Conn[0]->disconnect();
		std::cout << "DB Closed!" << std::endl;
		opened = false;
	}

}


void DBConn::checkConn()
{
	if (Conn[0]->is_open())
	{
		std::cout << "It's Check, and open." << std::endl;
	}
}


int main()
{
	DBConn Conn("dbname=name user=user password=password hostaddr=ipaddress port=5432");

	Conn.createConn();
	Conn.checkConn();
	Conn.deleteConn();

	return 0;
}