#include <iostream>
#include "header.h"
//FIX_ME: GoogleStyle запрещает использование пространства имен
//using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");

 //FIX_ME: имена приведем к snake_case и переименуем на английский
 /* Ochered Ochered1, Ochered2;
  Ochered1.Inicializaciya();
  Ochered2.Inicializaciya();*/

  Queue queue1;
  Queue queue2;

  queue1.initialize();
  queue2.initialize();

  std::cout << "Введите 10 чисел:\n";

  for (int i = 1; i <= 10; i++) {

    //FIX_ME: имя переименуем на английский
    //int Chislo;
    int number;
    std::cout << "Число " << i << ": ";

    //FIX_ME: имя переименуем на английский
    //cin >> Chislo;
    std::cin >> number;
      if (std::cin.fail()) {
      std::cout << "Ошибка ввода!\n";
      return 0;
    }

    //FIX_ME: имена переименуем на английский
    /*if (i % 2 != 0)
      Ochered1.DobavitElement(Chislo);
    else
      Ochered2.DobavitElement(Chislo);
  }*/
    if (i % 2 != 0) {
      queue1.push(number);
    }
    else {
      queue2.push(number);
    }
  }

  std::cout << "\nНечетная очередь:\n";
  //FIX_ME: имена приведем к snake_case и переименуем на английский
  /*Ochered1.VivodElementov();
  Ochered1.VivodUkazatelei();*/
  queue1.print();
  queue1.print_pointers();

  std::cout << "\nЧетная очередь:\n";
  //FIX_ME: имена приведем к snake_case и переименуем на английский
  /*Ochered2.VivodElementov();
  Ochered2.VivodUkazatelei();*/
  queue2.print();
  queue2.print_pointers();

  return 0;
}
