#include <iostream>


int main()
{
  int x;
  std::cout << "Enter an integer value for x: ";
  std::cin >> x;
  
  std::cout << "x is equal to " << x << std::endl;
  
  if (x > 0)
  {
    std::cout << "x is positive" << std::endl;
  }
  else if (x == 0)
  {
    std::cout << "x is equal to zero" << std::endl;
  }
  else if (x < 0)
  {
    std::cout << "x is negative" << std::endl;
  }
  return 0;
}
