/*  */


/* Function for a) */
double dotProduct_ptr(
			double *x,
			double *y,
			int size)
{
	double dot = 0;
	for (int i = 0; i < size; i++)
	{
		dot += x[i] * y[i];
	}
	return dot;
}

double dotProcduct_vec(
			std::vector<double> x,
			std::vector<double> y)
{
	if (x.size() != y.size())
	{
		return;
	}
	
	double dot = 0;
	for (int i = 0; i < x.size(); i++)
	{
		dot += x[i] * y[i];
	}
	return dot;
}


int main()
{
	
	double x[4] = {1.2,   3.4,  5.2, 1.6};
	double y[4] = {6.3, -12.0, -1.0, 5.2};
	
	double o[3] = {1.0, -2.0, 0};
	double p[3] = {6.0,  3.0, 1.23};
	
	std::cout << "x * y = " << dotProduct_ptr(x,y,4) << std::endl;
	std::cout << "o * p = " << dotProduct_ptr(o,p,4) << std::endl;
	
	return 0;
}