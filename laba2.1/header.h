#ifndef HEADER_H_
#define HEADER_H_

#include <memory>
#include <iostream>
//FIX_ME: приведем к snake_case + используем умный указатель unique_ptr
/*class Node {
public:
  int data;
  Node* next;


  Node(int value) : data(value), next(nullptr) {}
}; */
class Node {
public:
  int data;
  std::unique_ptr<Node> next;  // FIX_ME: заменен сырой указатель
  // причина: управление памятью

  explicit Node(int value);
};

class Stack {
public:
  Stack();

  void push(int value);
  void pop();
  void print() const;

  //FIX_ME: приведем имена в snake_case
  //void cleasStack
  //Node* getTop() {
  //void addElementAndPrintAddress(Stack& stack, int D) {
  void clear_stack();
  Node* get_top() const;

  friend void add_element_and_print_address(Stack& stack, int value);

  

private:
  // FIX_ME: тк поле класса добавим к имени _ + unique_ptr
  //Node* top; 
  std::unique_ptr<Node> top_;
};
// FIX_ME: функция проверки ввода
bool is_number(const std::string& str);
int read_int();


#endif 
