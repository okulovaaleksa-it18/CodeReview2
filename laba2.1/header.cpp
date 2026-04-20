#include "header.h"
#include <cctype> 
#include <iostream>
#include <string>
#include <sstream>

Node::Node(int value) : data(value), next(nullptr) {}
Stack::Stack() : top_(nullptr) {}

  //FIX_ME: добавление умного указателя для добавления элемента в стек
  /*void push(int value) {
    Node* newNode = new Node(value); // Создаем новый узел
    newNode->next = top;             // Новый узел указывает на текущую вершину
    top = newNode;                   // Обновляем вершину стека
    cout << "Элемент " << value << " добавлен в стек." << endl;
  } */
void Stack::push(int value) {
  auto new_node = std::make_unique<Node>(value);
  new_node->next = std::move(top_);
  top_ = std::move(new_node);

  std::cout << "Элемент " << value << " добавлен в стек.\n";
}

  // Метод для удаления элемента из стека
  /*void pop() {
    if (top == nullptr) {
      cout << "Стек пуст! Невозможно удалить элемент." << endl;
      return;
    }*/
void Stack::pop() {
  if (!top_) {
    std::cout << "Стек пуст! Невозможно удалить элемент.\n";
    return;
  }
  /*  Node* temp = top;
    top = top->next;
    cout << "Элемент " << temp->data << " удален из стека." << endl;
    delete temp;
  }*/
// FIX_ME: сохранение значения перед удалением
  int value = top_->data;
  top_ = std::move(top_->next);
  std::cout << "Элемент " << value << " удален из стека.\n";
}

  /*void print() {
    if (top == nullptr) {
      cout << "Стек пуст!" << endl;
      return;
    }
    Node* current = top;
    cout << "Элементы стека: ";
    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }*/
void Stack::print() const {
  if (!top_) {
    std::cout << "Стек пуст!\n";
    return;
  }

  const Node* current = top_.get();

  std::cout << "Элементы стека: ";
  while (current) {
    std::cout << current->data << " ";
    current = current->next.get();
  }
  std::cout << "\n";
}

  //FIX_ME: приведем имена к snake_case
  /*Node* getTop() {
    return top;
  }*/
Node* Stack::get_top() const {
  return top_.get();
}

  //FIX_ME: приведем имена к snake_case
  /*void clearStack() {
    while (top != nullptr) {
      Node* temp = top;
      top = top->next;
      delete temp;                 // Удаляем узел
    }
    cout << "Стек очищен." << endl;
  } */
void Stack::clear_stack() {
  while (top_) {
    top_ = std::move(top_->next);
  }

  std::cout << "Стек очищен.\n";
}

//FIX_ME: приведем имя к snake_case, существенное назовем вершину стека
/*void addElementAndPrintAddress(Stack& stack, int D) {
  stack.push(D);
  cout << "Адрес новой вершины стека: " << stack.getTop() << endl;
}*/
void add_element_and_print_address(Stack& stack, int value) {
  stack.push(value);
  std::cout << "Адрес новой вершины стека: "
    << stack.get_top() << "\n";
}

// FIX_ME: проверка ввода 
bool is_number(const std::string& str) {
  if (str.empty()) return false;

  int start = 0;

  if (str[0] == '-') {
    if (str.size() == 1) return false;
    start = 1;
  }

  for (int i = start; i < str.size(); ++i) {
    if (!isdigit(str[i])) return false;
  }

  return true;
}

int read_int() {
  std::string input;

  while (true) {
    std::cin >> std::ws; // пропускаем ведущие пробелы
    std::getline(std::cin, input); // читаем всю строку до Enter

    // Проверяем, что строка не пустая и без пробелов
    if (input.empty()) {
      std::cout << "Ошибка! Введите число: ";
      continue;
    }

    bool valid = true;
    int start = 0;

    if (input[0] == '-') {
      if (input.size() == 1) {
        valid = false;
      }
      else {
        start = 1;
      }
    }

    for (int i = start; i < input.size(); ++i) {
      if (!isdigit(input[i])) {
        valid = false;
        break;
      }
    }

    if (valid) {
      // безопасно преобразуем
      std::stringstream ss(input);
      int value;
      ss >> value;

      // если после числа ещё что-то осталось ? ошибка
      if (ss.eof()) {
        return value;
      }
    }

    std::cout << "Ошибка! Введите корректное число: ";
  }
}