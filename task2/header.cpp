#include "header.h"

//FIX_ME: имена приведем к snake_case и переименуем на английский
/*void Ochered::Inicializaciya() {
  Nachalo = nullptr;
  Konec = nullptr;
}*/
// Инициализация
void Queue::initialize() {
head_ = nullptr;
tail_ = nullptr;
}

//FIX_ME: имена приведем к snake_case, переименуем на английский
//и добавим умный указатель
/*void Ochered::DobavitElement(int Chislo) {
  Uzel* Noviy = new Uzel;
  Noviy->Znachenie = Chislo;
  Noviy->Sleduyushiy = nullptr;

  if (Nachalo == nullptr) {
    Nachalo = Noviy;
    Konec = Noviy;
  }
  else {
    Konec->Sleduyushiy = Noviy;
    Konec = Noviy;
  }
}*/
// Добавление элемента
void Queue::push(int number) {
  auto new_node = std::make_unique<Node>();
  new_node->value = number;
  new_node->next = nullptr;

  Node* raw_ptr = new_node.get();

  if (head_ == nullptr) {
    head_ = raw_ptr;
    tail_ = raw_ptr;
  }
  else {
    tail_->next = std::move(new_node);
    tail_ = raw_ptr;
    return;
  }
  // FIX_ME: перенос владения
  // старый код: отсутствовало
  if (head_ == raw_ptr) {
  }
}

//FIX_ME: имена приведем к snake_case и переименуем на английский
/*void Ochered::UdalitElement() {
  if (Nachalo == nullptr) {
    cout << "Очередь пуста!" << endl;
    return;
  }*/
  //Удаление элемента
void Queue::pop() {
  if (head_ == nullptr) {
    throw std::runtime_error("Queue is empty");
  }

  //FIX_ME: освобождение через unique_ptr
  /*Uzel* Vremenny = Nachalo;
  Nachalo = Nachalo->Sleduyushiy;
  delete Vremenny;*/
  auto temp = std::move(head_->next);
  head_ = temp.release();

  //FIX_ME: имена приведем к snake_case и переименуем на английский
  /*if (Nachalo == nullptr)
    Konec = nullptr;*/
  if (head_ == nullptr) {
    tail_ = nullptr;
  }
}

//FIX_ME: имена приведем к snake_case и переименуем на английский
/*void Ochered::VivodElementov() {
  Uzel* Tekushiy = Nachalo;
  while (Tekushiy != nullptr) {
    cout << Tekushiy->Znachenie << " ";
    Tekushiy = Tekushiy->Sleduyushiy;
  }
  cout << endl;
}*/
// Вывод элементов
void Queue::print() const {
  Node* current = head_;
  while (current != nullptr) {
    std::cout << current->value << " ";
    current = current->next.get();
  }
  std::cout << std::endl;
}

//FIX_ME: имена приведем к snake_case и переименуем на английский
/*void Ochered::VivodUkazatelei() {
  cout << "Адрес начала: " << Nachalo;
  if (Nachalo != nullptr)
    cout << " (значение: " << Nachalo->Znachenie << ")";
  cout << endl;

  cout << "Адрес конца:  " << Konec;
  if (Konec != nullptr)
    cout << " (значение: " << Konec->Znachenie << ")";
  cout << endl;
}*/
// Вывод указателей
void Queue::print_pointers() const {
  std::cout << "Адрес начала: " << head_;
  if (head_ != nullptr) {
    std::cout << " (значение: " << head_->value << ")";
  }
  std::cout << std::endl;

  std::cout << "Адрес конца: " << tail_;
  if (tail_ != nullptr) {
    std::cout << " (значение: " << tail_->value << ")";
  }
  std::cout << std::endl;
}
