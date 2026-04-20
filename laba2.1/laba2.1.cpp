#include <iostream>
#include "header.h"
//FIX_ME: Google Style запрещает использования 
//using namespace std;

int main() {
  setlocale(LC_ALL, "RU");
  Stack stack;
  int choice;
  int value;

  while (true) {
    std::cout << "\nМеню:\n";
    std::cout << "1. Добавить элемент в стек\n";
    std::cout << "2. Удалить элемент из стека\n";
    std::cout << "3. Вывести элементы стека\n";
    std::cout << "4. Очистить стек\n";
    std::cout << "5. Выйти\n";
    std::cout << "Введите ваш выбор: ";

    choice = read_int();

    switch (choice) {
    case 1:
      std::cout << "Введите число для добавления в стек: ";
      value = read_int();
      add_element_and_print_address(stack, value);
      break;
    case 2:
      stack.pop();
      break;
    case 3:
      stack.print();
      break;
    case 4:
      stack.clear_stack();
      break;
    case 5:
      std::cout << "Выход из программы." << std::endl;
      return 0;
    default:
      std::cout << "Неверный выбор! Пожалуйста, попробуйте снова." << std::endl;
    }
  }

  return 0;
}