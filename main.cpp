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

// Вставка после указанного узла
template< class T >
void insertAfter(BiList< T >* node, const T& value);

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

// Получение первого элемента
template< class T >
T& front(BiList< T >* head, bool& success);

// Получение последнего элемента
template< class T >
T& back(BiList< T >* head, bool& success);

// Проверка на пустоту
template< class T >
bool empty(BiList< T >* head);

// Получение размера
template< class T >
int size(BiList< T >* head);

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
