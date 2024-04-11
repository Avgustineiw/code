/*
Реализуйте систему обработки заказов, которая проверяет 
корректность введенного количества товаров и их стоимости. 
Если количество товаров отрицательное или стоимость товара 
ниже допустимого предела, система должна генерировать исключения.

Требования к реализации:
Определение класса исключения: Создайте класс исключения 
OrderException, который наследуется от std::exception. 
Класс должен содержать два поля: сообщение об ошибке и код ошибки.
 Реализуйте конструктор, принимающий эти параметры, и методы для их 
 извлечения.

Функция обработки заказа: Реализуйте функцию processOrder, 
которая принимает количество товаров и их стоимость как аргументы. 
Функция должна проверять, что количество товаров не отрицательно 
 что стоимость товара не ниже минимально допустимой. В случае
  обнаружения ошибки, функция должна генерировать исключение 
  OrderException с соответствующим сообщением об ошибке и кодом ошибки.

Обработка исключений: В функции main, вызовите processOrder с
 различными параметрами для демонстрации работы системы. 
 Используйте блоки try-catch для обработки исключений, 
 генерируемых функцией processOrder. При перехвате исключения, 
  выводите информацию об ошибке и код ошибки.
*/

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
