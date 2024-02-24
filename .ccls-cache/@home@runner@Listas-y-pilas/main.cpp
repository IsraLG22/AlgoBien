#include <iostream>

class Vertex {
public:
  float value;
  Vertex *next;
  Vertex() { next = nullptr; }
};

// Clase Stack
class Stack {
public:
  Stack();
  void push(float value);
  void pop();
  void top();
  void print();

private:
  Vertex *head;
};

Stack::Stack() { head = nullptr; }

// Stack::push()
void Stack::push(float value) {
  Vertex *vtx = new Vertex();
  vtx->value = value;
  vtx->next = head;
  head = vtx;
}

// Stack::pop()
void Stack::pop() {
  Vertex *del = head;
  if (head == nullptr) {
    std::cout << "La pila está vacia" << std::endl;
  } else {
    head = head->next;
    delete del;
  }
}

// Stack::top()
void Stack::top() {
  std::cout << head->value << std::endl;
};

// Stack::print()
void Stack::print() {
  Vertex *v = head;
  while (v != nullptr) {
    std::cout << v->value << "->";
    v = v->next;
  }
  std::cout << std::endl;
}

// Clase Lista *********
class List {
public:
  List();
  void append(int value);
  void insertAt(int pos, int value);
  void insertFirst(int value);
  void removeFirst();
  void removeAt(int pos);
  void removeLast();
  void removeValue(int value);
  void print();

private:
  Vertex *head, *tail;
};

List::List() {
  head = nullptr;
  tail = nullptr;
}
void List::insertFirst(int value) {
  Vertex *vtx = new Vertex();
  vtx->value = value;
  if (head != nullptr)
    vtx->next = head;
  else
    tail = vtx;
  head = vtx;
}

void List::append(int value) {
  Vertex *v = new Vertex();
  v->value = value;
  if (tail != nullptr) {
    tail->next = v;
  } else {
    tail = v;
    head = v;
  }
}

void List::insertAt(int pos, int value) {
  Vertex *vtx = new Vertex();
  vtx->value = value;
  pos = pos - 1;

  if (pos == 0) {
    insertFirst(value);
  } else {
    Vertex *prev = head;
    for (int i = 1; i < pos && prev != nullptr; i++) {
      prev = prev->next;
    }

    if (prev == nullptr) {
      std::cout << "Eso no se puede D:< (Porque lo quieres tronar?)"
                << std::endl;
      return;
    }
    vtx->next = prev->next;
    prev->next = vtx;

    if (prev == tail) {
      tail = vtx;
    }
  }
}

// void List::removeFirst()
void List::removeFirst() {
  Vertex *del = head;
  if (head == nullptr) {
    std::cout << "la lista esta vacia" << std::endl;
  } else {
    head = head->next;
    delete del;
  }
}

// void List::removeLast()
void List::removeLast() {
  Vertex *prev = head;
  int i = 0;
  while (prev != nullptr) {
    i++;
    prev = prev->next;
  }
  if (head == nullptr) {
    std::cout << "la lista esta vacia" << std::endl;
  } else if (i == 1) {
    Vertex *temp = head;
    head = nullptr;
    tail = nullptr;
    delete temp;
  } else {
    prev = head;
    for (int k = 0; k < (i - 2); k++) {
      prev = prev->next;
    }
    Vertex *del = prev->next;
    prev->next = nullptr;
    tail = prev;
    delete del;
  }
}

// void List::removeAt()
void List::removeAt(int pos) {
  char res;
  int pospos;
  pospos = pos;
  if (head == nullptr and tail == nullptr) {
    std::cout << "No hay nada que borrar D:<" << std::endl;
  }
  pos = pos - 1;
  int i = 0;
  Vertex *prev = head;
  if (pos < 1) {
    std::cout
        << "Amigazo!, Por que harias una lista con posiciones negativas? D:<"
        << std::endl;
  } else if (pos > 1) {
    while (prev->next != nullptr) {
      i++;
      prev = prev->next;
    }
    if (i < pos) {
      std::cout << "No D:\nNo eliminamos ningun dato" << std::endl;
      std::cout << "Esa posicion esta fuera de rango (" << pospos
                << "),\nQuieres borrar la ultima posicion en cambio? \n(1) Si "
                   "\n(2) No"
                << std::endl;
      std::cin >> res;
      switch (res) {
      case '1':
        removeLast();
      case '2':
        break;
      default:
        std::cout << "No te entendi" << std::endl;
      }
    } else {
      prev = head;
      for (int k = 0; k < (pos - 1); k++) {
        prev = prev->next;
      }
      Vertex *del = prev->next;
      prev->next = del->next;
      delete del;
    }
  }
}

// void List::removeValue()
void List::removeValue(int value) {
  Vertex *prev = head;
  bool si = false;
  while (prev->next != nullptr) {
    if (prev->next->value == value) {
      Vertex *del = prev->next;
      prev->next = del->next;
      delete del;
    }
    si = true;
    prev = prev->next;
  }
  if (si == true) {
    std::cout << "no se encontro nada" << std::endl;
  }
}

void List::print() {
  Vertex *v = head;
  while (v != nullptr) {
    std::cout << v->value << "->";
    v = v->next;
  }
  std::cout << std::endl;
}
int main() {

  /* List lista;
   lista.append(0);
   lista.insertFirst(6);
   lista.insertAt(1, 9);
   lista.insertFirst(7);
   lista.append(2);
   //lista.insertAt(8, 2);
   lista.print();
   lista.removeAt(-1);
   lista.removeValue(-6);
   lista.print();*/
  Stack pila;
  pila.push(1);
  pila.push(2);
  pila.push(3);
  pila.print();
  pila.pop();
  pila.push(4);
  pila.print();
  pila.top();
}