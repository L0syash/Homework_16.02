#include <iostream>

template< class T >
struct BiList {
  T val;
  BiList<T> * next;
  BiList<T> * prev;
};

// Вставка в начало списка
template< class T >
void pushFront(BiList< T >*& head, const T& value);

// Вставка в конец списка
template< class T >
void pushBack(BiList< T >*& head, const T& value);

// Удаление первого элемента
template< class T >
void popFront(BiList< T >*& head);

// Удаление последнего элемента
template< class T >
void popBack(BiList< T >*& head);

// Удаление узла по значению
template< class T >
bool erase(BiList< T >*& head, const T& value);

// Поиск элемента
template< class T >
BiList< T >* find(BiList< T >* head, const T& value);

// Проверка на пустоту
template< class T >
bool empty(BiList< T >* head);

// Очистка списка
template< class T >
void clear(BiList< T >*& head);

// Создание списка из массива
template< class T >
BiList< T >* fromArray(const T* arr, size_t size);

// Печать списка
template< class T >
void print(BiList< T >* head);

// Печать массива и списка
template< class T >
void printArrayAndList(const T* arr, BiList< T >* list, size_t size);

template< class T >
bool empty(BiList< T >* head) {
  return head == nullptr;
}
template< class T >
void print(BiList< T >* head) {
  std::cout << "Список: ";
  while (head) {
    std::cout << head->val;
    if (head->next) {
      std::cout << " -> ";
    }
    head = head->next;
  }
  std::cout << "\n";
}
template< class T >
BiList< T >* fromArray(const T* arr, size_t size) {
  if (!arr || size == 0) return nullptr;
  BiList< T >* head = nullptr;
  BiList< T >* tail = nullptr;
  for (size_t i = 0; i < size; ++i) {
    BiList< T >* newNode = new BiList< T >;
    newNode->val = arr[i];
    newNode->next = nullptr;
    newNode->prev = tail;
    if (!head) {
      head = newNode;
    }
    if (tail) {
      tail->next = newNode;
    }
    tail = newNode;
  }
  return head;
}
template< class T >
void pushFront(BiList< T >*& head, const T& value) {
  BiList< T >* newNode = new BiList< T >;
  newNode->val = value;
  newNode->prev = nullptr;
  newNode->next = head;
  if (head) {
    head->prev = newNode;
  }
  head = newNode;
}
template< class T >
void pushBack(BiList< T >*& head, const T& value) {
  BiList< T >* newNode = new BiList< T >;
  newNode->val = value;
  newNode->next = nullptr;
  if (!head) {
    newNode->prev = nullptr;
    head = newNode;
    return;
  }
  BiList< T >* current = head;
  while (current->next) {
    current = current->next;
  }
  newNode->prev = current;
  current->next = newNode;
}
template< class T >
void popFront(BiList< T >*& head) {
  if (!head) return;
  BiList< T >* temp = head;
  head = head->next;
  if (head) {
    head->prev = nullptr;
  }
  delete temp;
}
template< class T >
void popBack(BiList< T >*& head) {
  if (!head) return;
  if (!head->next) {
    delete head;
    head = nullptr;
    return;
  }
  BiList< T >* current = head;
  while (current->next) {
    current = current->next;
  }
  current->prev->next = nullptr;
  delete current;
}
template< class T >
BiList< T >* find(BiList< T >* head, const T& value) {
  while (head) {
    if (head->val == value) {
      return head;
    }
    head = head->next;
  }
  return nullptr;
}
