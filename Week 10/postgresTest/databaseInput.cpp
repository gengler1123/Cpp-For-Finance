#include <iostream>

#include <pqxx/pqxx>
#include <string>
#include <vector>

using namespace pqxx;
using namespace std;



int main()
{

	try {
		connection C("dbname=name user=user password=password hostaddr=ipaddress port=5432");
		if (C.is_open())
		{
			
			cout << "Database " << C.dbname() << " opened!" << endl;

		}
		
		else
		{
			cout << "Cannot Open Database" << endl;
			return 1;
		}

		int NAME;
		double VALUE;
		
		cout << "Enter Name: ";
		cin >> NAME;
		cout << "\n" ;
		cout << "Enter Value: ";
		cin >> VALUE;
		
		string sql;
		
		sql = "INSERT INTO cpptest VALUES (" + to_string(NAME) + "," + to_string(VALUE) + ");" ;
		
		work W(C);

		W.exec(sql);
		W.commit();
		C.disconnect();
	}

	catch(const exception &e)
	{
		cerr < e.what() ;
		return 1;
	}

	return 0;

}

