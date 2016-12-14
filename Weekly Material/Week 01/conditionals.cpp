#include <iostream>


int main()
{
  int x,y;
  x = 10;
  y = 15;
  
  if (x < y)
  {
    std::cout << "x is less than y" << std::endl;
  }
  
  else
  {
    std::cout << "x is not less than y" << std::endl;
  }
  
  std::cout << std::endl;
  
  y = 10;
  
  if (x == y)
  {
    std::cout << "x is equal to y" << std::endl;
  }
  
  else
  {
    std::cout << "x is not equal to y" << std::endl;
  }
  
  std::cout << std::endl;
  
  if (y >= x)
  {
    std::cout << "y is greater than or equal to x" << std::endl;
  }
  
  else
  {
    std::cout << "y is not greater than or equal to x" << std::endl;
  }
  
  return 0;
}
