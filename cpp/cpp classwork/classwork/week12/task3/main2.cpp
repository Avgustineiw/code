#include <cmath>
#include <exception>
#include <iostream>
#include <string>

const int MIN_PRICE = 5;

class OrderException : std::exception
{
private:
  std::string msg;
  int code;

public:
  OrderException(std::string msg, int code): msg(msg), code(code) {};

  int getErrorCode() const {
    return code;
  }

  virtual const char* what() const throw() {
    return msg.c_str();
  }
};


void processOrder(int quant, double price) {
  if (quant < 0) {
    throw OrderException("Quantity cannot be negative", 101);
  }
  else if (quant == 0) {
    throw OrderException("Quantity cannot be zero", 102);
  }
  else if (price < MIN_PRICE) {
    throw OrderException("Price cannot be below minimum price", 103);
  }
  else {
    std::cout << "The order has been successfully placed!" << '\n';
    std::cout << "Quantity: " << quant << " items" << '\n';
    std::cout << "Price: " << price << "$ per item" << "\n\n";
  }
}


int main()
{ 
  try {
    processOrder(-99, 12.0);
  } catch (const OrderException& e) {
    std::cout << "исключение: " << e.what() << "\nкод ошибки: " << e.getErrorCode() << "\n\n";
  }

  try {
    processOrder(10, 5.0);
  } catch (const OrderException& e) {
    std::cout << "исключение: " << e.what() << "\nкод ошибки: " << e.getErrorCode() << "\n\n";
  }

  return 0;
}
