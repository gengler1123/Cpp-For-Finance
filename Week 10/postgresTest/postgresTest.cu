#include <iostream>

#include <cuda.h>
#include "device_launch_parameters.h"
#include "cuda_runtime.h"

#include <pqxx/pqxx>
#include <string>
#include <vector>


using namespace pqxx;
using namespace std;


result giveResult(connection &C,  string sql)
{
	nontransaction N(C);
	result R(N.exec( sql ));
	return R;
}


int main()
{

	string sql;
	vector<string> Schema;	
	
	int v1;
	int v2;

	cout << "Hello World!" << endl;
	try{
		connection C("dbname=name user=user password=password hostaddr=ipaddress port=5432");
		if (C.is_open())
		{
			cout << "Database " << C.dbname()  << " opened" << endl;
			
		}
		else
		{
			cout << "Cannot Open Database " << endl;
			return 1;
		}

		sql = "SELECT * "\
		      " FROM firing_times_test0 LIMIT 1;";

		//nontransaction N(C);

		//result R( N.exec( sql ));
		
		result R = giveResult(C, sql);

		/*
		for (result::const_iterator c = R.begin(); c != R.end(); ++c)
		{
			std::cout << (*c).size() << std::endl;
			c[0].to(v1);
			c[1].to(v2);
			cout << typeid(v1).name() << ":"  << v1  << "," << typeid(v2).name() << ":" <<  v2 <<  endl;
						
		}
		
		*/

		result::const_iterator c = R.begin();

		cout << c[0] << "," << c[1] << endl;

		C.disconnect();
	}
	catch(const exception &e)
	{
		cerr << e.what() << endl;
		return 1;
	}
	


	return 0;
}





