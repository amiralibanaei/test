#include <iostream>
#include <iomanip>
#include <cmath>

double f1(double);
double f2(double);
void findroot( double (*f)(double), double x, double y, double e);

int main() {
  
  double x{};
  double y{};
  double e{0.0001};

  std::cout << "Finding root for function: " << std::endl;
  std::cout << "X^3 + X^2 + X + 1 = 0\n" << std::endl;
  
  std::cout << "Please enter the initial values: " << std::endl;
  std::cout << "x0: ";
  std::cin >> y;
  std::cout << "x1: ";
  std::cin >> x;

  findroot(f1, x, y, e);

  

  std::cout << "\n\n\nFinding root for function: " << std::endl;
  std::cout << "coth(x) - log(x) = 0\n" << std::endl;
  
  std::cout << "Please enter the initial values: " << std::endl;
  std::cout << "x0: ";
  std::cin >> y;
  while (y <= 0){
    std::cout << "Invalid value, please re enter x0: ";
    std::cin >> y;
  }
  std::cout << "x1: ";
  std::cin >> x;
  while (x <= 0){
    std::cout << "Invalid value, please re enter x1: ";
    std::cin >> x;
  }

  findroot(f2, x, y, e);

}

double f1(double x){
  double val = pow(x, 3) + pow(x, 2) + x + 1;
  return val;
}

double f2(double x){
  double val = 1/tanh(x) - log10(x);
  return val;
}


void findroot ( double (*f)(double), double x, double y, double e){
  double E{10};
  int n{1};
  char ctrl{'y'};
  double root{};
  
  std::cout << std::setw(3) << "n";
  std::cout << std::setw(8) << "xn+1";
  std::cout << std::setw(8) << "xn";
  std::cout << std::setw(8) << "xn-1";
  std::cout << std::setw(9) << "error";
  std::cout << std::endl << std::endl;


  while (E >= e && ctrl == 'y'){
    
    root = x - (f(x)*(x-y))/(f(x)-f(y));
    E = fabs((root-x)/x);

    std::cout << std::setw(3) << n;
    std::cout << std::setw(8) << std::setprecision(3) << std::fixed << root;
    std::cout << std::setw(8) << std::setprecision(3) << std::fixed << x;
    std::cout << std::setw(8) << std::setprecision(3) << std::fixed << y;
    std::cout << std::setw(9) << std::setprecision(5) << std::fixed << E;
    std::cout << std::endl << std::endl;


    n++;
    y = x;
    x = root;
    
    if (n==50){
      std::cout << std::endl;
      std::cout << "No root found for in repeats, ";
      std::cout << "do you want to continue or end progress?" << std::endl;
      std::cout << "Press y to continue and n to end progress: ";
      std::cin >> ctrl;
      
      if (ctrl == 'y')
	std::cout << "Progress will be continued."<<std::endl;
      if (ctrl == 'n')
	std::cout << "Progress terminated."<<std::endl;
    }
    if (n == 100){
      ctrl = 'n';
      std::cout << std::endl;
      std::cout << "No answer found in 100 repeats, ";
      std::cout << "progress terminated." << std::endl;
    }
  }

  std::cout << "\nThe root is: " << root << std::endl;
}
