#include <iostream>
#include <exception>
#include <string>


class OrderException : std::exception
{
protected:
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

const int MIN_PRICE = 5;

void processOrder(int quant, double price)
{
  if (quant < 0) {
    throw OrderException("Quantity is negative", 101);
    return;
  }
  else if (price < MIN_PRICE) {
    throw OrderException("Price is below minimum", 102);
    return;
  }
  else {
    std::cout << "Order has been placed!" << '\n';
    std::cout << "Quantity: " << quant << '\n';
    std::cout << "Price per item: " << price << "\n\n";
    return;
  }
}

int main() {
  try {
    processOrder(-99, 12.0);
  } catch (const OrderException& e) {
    std::cout << "исключение: " << e.what() << "\nкод ошибки: " << e.getErrorCode() << "\n\n";
  }

  try {
    processOrder(10, 4.0);
  } catch (const OrderException& e) {
    std::cout << "исключение: " << e.what() << "\nкод ошибки: " << e.getErrorCode() << "\n\n";
  }

  try {
    processOrder(50, 6.0);
  } catch (const OrderException& e) {
    std::cout << "исключение: " << e.what() << "\nкод ошибки: " << e.getErrorCode() << "\n\n";
  }

  return 0;
}
