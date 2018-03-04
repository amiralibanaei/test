#include <iostream>


int main () {
  int n{};
  long int result{};
  std::cout << "Please enter the quantity of numbers:" << std::endl;
  std::cin >> n;

  int* seq = new int[n];
  std::cout << "Please enter the sequence of numbers: " << std::endl;
  for (int i{}; i < n; i++)
    std::cin >> seq[i];
  
  for (int r{1}; r <= n; r++){
    for (int l{1}; l <= r; l++){
      for(int i{l}; i <= r; i++){
	result += seq[i-1];
      }
    }
  }

  std::cout << "The result is: "<< result << std::endl;
  
  return 0;
}
