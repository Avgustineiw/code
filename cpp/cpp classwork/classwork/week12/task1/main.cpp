#include <cstdlib>
#include <iostream>


/*
В рамках организации благотворительного марафона, необходимо 
создать программу для регистрации участников, которая строго 
проверяет возрастные ограничения. Марафон открыт для участников 
в возрасте от 18 до 60 лет включительно. Программа должна запросить 
у пользователя его возраст и выбранную дистанцию, а затем проверить, 
удовлетворяет ли возраст условиям участия в марафоне. 
Если условия нарушены, программа должна сгенерировать исключение.

Задачи:
Определить класс исключения AgeRestrictionException, 
который должен содержать сообщение об ошибке, указывающее на
 то, что возраст участника не соответствует требованиям.
Создать функцию registerParticipant, которая принимает возраст
 участника и выбранную дистанцию. Функция должна проверять, 
 соответствует ли возраст ограничениям. Если нет, функция должна 
 бросить исключение AgeRestrictionException.
В функции main реализовать запрос на ввод возраста и дистанции
 от пользователя, вызов функции registerParticipant и обработку
 возможного исключения, выводящую сообщение об ошибке, если возраст
  участника не попадает в допустимый диапазон.
Требования:
Использовать механизм исключений C++ для обработки ошибок, 
связанных с возрастными ограничениями.
Предусмотреть корректную обработку пользовательского ввода, включая
 ввод нечисловых значений.
Вывести подтверждение успешной регистрации, если возраст участника 
соответствует требованиям.

Введите ваш возраст: 25
Выберите дистанцию (5km, 10km, 21km): 10km
Регистрация успешно завершена!

Введите ваш возраст: 17
Выберите дистанцию (5km, 10km, 21km): 5km
Ошибка: Ваш возраст не соответствует требованиям для участия в
 марафоне.

*/

#include <iostream>
#include <exception>
#include <string>

class AgeRestrictionException : std::exception
{
private:
  std::string msg;
  int code;

public:
  AgeRestrictionException(std::string msg, int code): msg(msg), code(code) {};

  int getCode() const {
    return code;
  }

  const char* what() const throw() {
    return msg.c_str();
  }
};

void registerParticipant(int age) {
  if (age < 18 || age > 60) {
    throw AgeRestrictionException("Ваш возраст не соответствует требованиям участия в марафоне", 101);
    std::cout << "Registration failed" << '\n';
  }
  else {
    std::cout << "Регистрация успешно завершена!" << '\n';
  }
  return;
}


bool check_number(std::string str) {
  for (int i = 0; i < str.length(); i++) {
    if (isdigit(str[i]) == false)
      return false;
  }
  return true;
}


int main() {
  std::string user_input_age;
  std::string user_input_dist;

  std::cout << "Введите ваш возраст: ";
  std::cin >> user_input_age;

  if (!check_number(user_input_age)) {
    std::cout << "Incorrect format";
    std::exit(0);
  }
  
  std::cout << "Выберите дистанцию (5km, 10km, 21km): ";
  std::cin >> user_input_dist;

  if (!check_number(user_input_dist)) {
    std::cout << "Incorrect format";
    std::exit(0);
  }
  else if (stoi(user_input_dist) != 5 && stoi(user_input_dist) != 10 && stoi(user_input_dist) != 21) {
    std::cout << "Incorrect format";
    std::exit(0);
  }

  try {
    registerParticipant(stoi(user_input_age));
  } catch (AgeRestrictionException& e) {
    std::cout << "Ошибка: " << e.what() << "\n\n";
  }

  return 0;
}
