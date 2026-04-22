#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <memory>

//FIX_ME: GoogleStyle запрещает использование пространства имен
//using namespace std;

//FIX_ME: приведем к snake_case, используем умный указатель unique_ptr
// и переименуем на английский
/*struct Uzel {
  int Znachenie;
  Uzel* Sleduyushiy;
}; */
// Структура узла
struct Node {
  int value;
  std::unique_ptr<Node> next;
};

//FIX_ME: имена приведем к snake_case и переименуем на английский
/*class Ochered {
private:
  Uzel* Nachalo;
  Uzel* Konec;

public:
  void Inicializaciya();
  void DobavitElement(int Chislo);
  void UdalitElement();
  void VivodElementov();
  void VivodUkazatelei();
};*/
// Класс очереди
class Queue {
private:
  Node* head_;  
  Node* tail_;

public:
  void initialize();
  void push(int number);
  void pop();
  void print() const;
  void print_pointers() const;
};

#endif
