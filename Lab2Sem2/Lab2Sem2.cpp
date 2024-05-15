#include <iostream>
#include <string>
#include <Chrono>

using namespace std;

struct List
{
    int data;
    List* head;
    List* tail;
};

void showData(List* beg)
{
    List* p = beg;
    while (p->tail)
    {
        cout << p->data << ' ';
        p = p->tail;
    }
    cout << p->data << ' ';
    cout << '\n';
}

int lengthOfList(List* list)
{
    int length = 0;
    List* curr = list;
    while (curr)
    {
        length++;
        curr = curr->tail;
    }
    return length;
}

void insert(List*& list, int pos, int value)
{
    auto clockStart = chrono::high_resolution_clock::now();
    List* curr = list;
    List* addElem = new List;
    addElem->data = value;
    if (pos == 1)
    {
        addElem->head = 0;
        addElem->tail = list;
        list->head = addElem;
        list = addElem;
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            curr = curr->tail;
        }
        if (curr->tail == 0)
        {
            curr->tail = addElem;
            addElem->tail = 0;
            addElem->head = curr->head->tail;
        }
        else
        {
            List* next = curr->tail;
            addElem->tail = next;
            addElem->head = curr;
            next->head = addElem;
            curr->tail = addElem;
        }
    }
    auto clockEnd = chrono::high_resolution_clock::now();
    cout << "Время list: ";
    cout << (chrono::duration_cast<chrono::microseconds>(clockEnd - clockStart).count()) << "ms\n";
    showData(list);
}

void deleteElem(List*& list, short option, int a)
{
    auto clockStart = chrono::high_resolution_clock::now();
    if (option)
    {
        List* curr = list;
        while (curr->data != a)
        {
            curr = curr->tail;
        }
        if (!curr->head)
        {
            list = curr->tail->tail->head;
            delete curr;
            list->head = 0;
        }
        else
        {
            if (!curr->tail)
            {
                curr->head->tail = 0;
                delete curr;
            }
            else
            {
                List* next = curr->tail;
                List* prev = curr->head;
                next->head = curr->head;
                prev->tail = curr->tail;
                delete curr;
            }
        }
    }
    else
    {
        List* curr = list;
        if (a == 1)
        {
            list = curr->tail->tail->head;
            delete curr;
            list->head = 0;
        }
        else
        {
            for (int i = 1; i < a; i++)
            {
                curr = curr->tail;
            }
            if (!curr->tail)
            {
                curr->head->tail = 0;
                delete curr;
            }
            else
            {
                List* next = curr->tail;
                List* prev = curr->head;
                next->head = curr->head;
                prev->tail = curr->tail;
                delete curr;
            }
        }
    }

    auto clockEnd = chrono::high_resolution_clock::now();
    cout << "Время list: ";
    cout << (chrono::duration_cast<chrono::microseconds>(clockEnd - clockStart).count()) << "ms\n";
    showData(list);
}

void swapElem(List* list, int pos1, int pos2)
{
    auto clockStart = chrono::high_resolution_clock::now();
    List* curr = list;
    List* currA = 0;
    List* currB = 0;
    for (int i = 1; i < max(pos1, pos2); i++)
    {
        if (i == min(pos1, pos2))
        {
            currA = curr;
        }
        curr = curr->tail;
    }
    currB = curr;
    if (pos1 == pos2)
    {
        currA = currB;
    }
    int t;
    t = currA->data;
    currA->data = currB->data;
    currB->data = t;
    auto clockEnd = chrono::high_resolution_clock::now();
    cout << "Время list: ";
    cout << (chrono::duration_cast<chrono::microseconds>(clockEnd - clockStart).count()) << "ms\n";
    showData(list);
}

void findElem(List* list, short option, int a)
{
    auto clockStart = chrono::high_resolution_clock::now();
    if (option)
    {
        int num = 0;
        bool isFind = false;
        List* curr = list;
        while (curr->tail)
        {
            if (curr->data == a)
            {
                isFind = true;
                cout << a << " - значение элемента с номером " << num + 1 << '\n';
                break;
            }
            else
            {
                num++;
                curr = curr->tail;
            }
        }
        if (curr->data == a)
        {
            isFind = true;
            cout << a << " - значение элемента с номером " << num + 1 << '\n';
        }
        if (!isFind)
        {
            cout << "такого значения нет в списке\n";
        }
    }
    else
    {
        List* curr = list;
        for (int i = 1; i < a; i++)
        {
            curr = curr->tail;
        }
        cout << "Элемент с номером " << a << ": " << curr->data << '\n';
    }
    auto clockEnd = chrono::high_resolution_clock::now();
    cout << "Время list: ";
    cout << (chrono::duration_cast<chrono::microseconds>(clockEnd - clockStart).count()) << "ms\n";
}

void deleteFullList(List* list)
{
    List* next = list;
    while (list)
    {
        next = list->tail;
        delete list;
        list = next;
    }
}

int* insertArr(int*& arr, int pos, int value, int length)
{
    auto clockStart = chrono::high_resolution_clock::now();
    int* arr1 = new int[length + 1];
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (i == pos - 1)
        {
            arr1[j] = value;
            j++;
        }
        arr1[j] = arr[i];
        j++;
    }
    auto clockEnd = chrono::high_resolution_clock::now();
    cout << "Время array: ";
    cout << (chrono::duration_cast<chrono::microseconds>(clockEnd - clockStart).count()) << "ms\n";
    delete[] arr;
    return arr1;
}

int* deleteElemArr(int*& arr, short option, int a, int length)
{
    auto clockStart = chrono::high_resolution_clock::now();
    int* arr1 = new int[length - 1];
    int j = 0;
    if (option)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] != a)
            {
                arr1[j] = arr[i];
                j++;
            }
        }
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            if (i != a - 1)
            {
                arr1[j] = arr[i];
                j++;
            }
        }
    }
    auto clockEnd = chrono::high_resolution_clock::now();
    cout << "Время array: ";
    cout << (chrono::duration_cast<chrono::microseconds>(clockEnd - clockStart).count()) << "ms\n";
    delete[] arr;
    return arr1;
}

void swapArr(int*& arr, int pos1, int pos2, int length)
{
    auto clockStart = chrono::high_resolution_clock::now();
    int t;
    t = arr[pos1 - 1];
    arr[pos1 - 1] = arr[pos2 - 1];
    arr[pos2 - 1] = t;
    auto clockEnd = chrono::high_resolution_clock::now();
    cout << "Время array: ";
    cout << (chrono::duration_cast<chrono::microseconds>(clockEnd - clockStart).count()) << "ms\n";
}

void findArr(int*& arr, short option, int a, int length)
{
    auto clockStart = chrono::high_resolution_clock::now();
    if (option)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == a)
            {
                cout << a << " - значение элемента с номером " << i + 1 << '\n';
                break;
            }
        }
    }
    else
    {
        cout << "Элемент c номером " << a << ": " << arr[a - 1];
    }
    auto clockEnd = chrono::high_resolution_clock::now();
    cout << "Время array: ";
    cout << (chrono::duration_cast<chrono::microseconds>(clockEnd - clockStart).count()) << "ms\n";
}

int* createArray(List* beg, int length)
{
    auto clockStart = chrono::high_resolution_clock::now();
    int* arr = new int[length];
    int i = 0;
    List* curr = beg;
    while (curr->tail)
    {
        arr[i] = curr->data;
        i++;
        curr = curr->tail;
    }
    arr[i] = curr->data;
    auto clockEnd = chrono::high_resolution_clock::now();
    cout << "Время array: ";
    cout << (chrono::duration_cast<chrono::microseconds>(clockEnd - clockStart).count()) << "ms\n";
    return arr;
}

void idzList(List*& list, int num) // Уменьшите каждый четный элемент на значение, введенное пользователем. Каждый нечетный умножьте на случайную величину от 1 до 5
{
    auto clockStart = chrono::high_resolution_clock::now();
    bool isEven = false;
    List* curr = list;
    while (curr)
    {
        if (isEven)
        {
            curr->data -= num;
        }
        else
        {
            int num2 = rand() % 5 + 1;
            curr->data *= num2;
        }
        curr = curr->tail;
        isEven = !isEven;
    }
    auto clockEnd = chrono::high_resolution_clock::now();
    cout << "Время list: ";
    cout << (chrono::duration_cast<chrono::microseconds>(clockEnd - clockStart).count()) << "ms\n";
    showData(list);
}

int* idzArr(int*& arr, int num, int length) // Уменьшите каждый четный элемент на значение, введенное пользователем. Каждый нечетный умножьте на случайную величину от 1 до 5
{
    auto clockStart = chrono::high_resolution_clock::now();
    for (int i = 0; i < length; i++)
    {
        if ((i + 1) % 2 == 1)
        {
            int num2 = rand() % 5 + 1;
            arr[i] *= num2;
        }
        else
        {
            arr[i] -= num;
        }
    }
    auto clockEnd = chrono::high_resolution_clock::now();
    cout << "Время array: ";
    cout << (chrono::duration_cast<chrono::microseconds>(clockEnd - clockStart).count()) << "ms\n";
    return arr;
}

void workWithList(List* beg, int listLength)
{
    cout << '\n';
    List* list = beg;
    int* arr = createArray(beg, listLength);
    bool isEnd = false;
    while (!isEnd)
    {
        showData(list);
        cout << "\nВыберите действие:\n0. Выход\n1. Вставка элемента\n2. Удаление элемента\n3. Обмен\n4. Получение элемента\n5. Идз\n";
        short choise;
        cin >> choise;
        switch (choise)
        {
        case (1):
            int value, pos;
            cout << "Введите номер позиции, куда Вы хотите вставить элемент: ";
            cin >> pos;
            cout << "Введите значение элемента: ";
            cin >> value;
            insert(list, pos, value);
            arr = insertArr(arr, pos, value, lengthOfList(list));
            break;
        case (2):
            short option;
            cout << "0. Удалить по индексу\n1. Удалить по значению\n";
            cin >> option;
            int a;
            if (option)
            {
                cout << "Введите значение, которое Вы хотите удалить: ";
                cin >> a;
            }
            else
            {
                cout << "Введите номер элемента, который Вы хотите удалить: ";
                cin >> a;
            }
            if (lengthOfList(list) <= 2)
            {
                cout << "В списке слишком мало элементов\n";
            }
            else
            {
                deleteElem(list, option, a);
                arr = deleteElemArr(arr, option, a, lengthOfList(list));
            }
            break;
        case (3):
            int pos1, pos2;
            cout << "Введите номера элементов, которые хотите поменять местами: ";
            cin >> pos1;
            cin >> pos2;
            swapElem(list, pos1, pos2);
            swapArr(arr, pos1, pos2, lengthOfList(list));
            break;
        case (4):
            short option1;
            cout << "0. Найти по индексу\n1. Найти по значению\n";
            cin >> option1;
            int a1;
            if (option1)
            {
                cout << "Введите значение, которое Вы хотите найти: ";
                cin >> a1;
            }
            else
            {
                cout << "Введите номер элемента, который Вы хотите найти: ";
                cin >> a1;
            }
            findElem(list, option1, a1);
            findArr(arr, option1, a1, lengthOfList(list));
            break;
        case (5):
            int num;
            cout << "Введите целое число от 1 до 5, на которое хотите уменьшить каждый четный элемент: ";
            cin >> num;
            while ((num < 1) || (num > 5))
            {
                cout << "Неверное число, попробуйте еще раз!\n";
                cout << "Введите целое число от 1 до 5, на которое хотите уменьшить каждый четный элемент: ";
                cin >> num;
            }
            idzList(list, num);
            idzArr(arr, num, lengthOfList(list));
            break;
        default:
            isEnd = true;
            break;
        }
    }
    deleteFullList(list);
    delete[] arr;
}

void createListA()
{
    auto clockStart = chrono::high_resolution_clock::now();
    int listLength;
    srand(time(NULL));
    cout << "Введите длину списка: ";
    cin >> listLength;
    List* curr = 0;
    List* next = 0;
    for (int i = 1; i <= listLength; i++)
    {
        curr = new List;
        curr->data = rand() % 100;
        curr->tail = next;
        if (next)
        {
            next->head = curr;
        }
        next = curr;
    }
    curr->head = 0;
    List* beg = curr;
    auto clockEnd = chrono::high_resolution_clock::now();
    cout << "Время list: ";
    cout << (chrono::duration_cast<chrono::microseconds>(clockEnd - clockStart).count()) << "ms\n";
    showData(beg);
    workWithList(beg, listLength);
}

void createListB()
{
    auto clockStart = chrono::high_resolution_clock::now();
    bool isEnd = false;
    List* curr = 0;
    List* next = 0;
    List* beg = 0;
    int listLength = 0;
    while (!isEnd)
    {
        cout << "Введите число или ""end"", если хотите завершить ввод\n";
        string a;
        cin >> a;
        if (a == "end")
        {
            isEnd = true;
        }
        else
        {
            curr = new List;
            if (!listLength)
            {
                beg = curr;
            }
            listLength++;
            curr->data = stoi(a);
            curr->head = next;
            if (next)
            {
                next->tail = curr;
            }
            next = curr;
        }
    }
    curr->tail = 0;
    auto clockEnd = chrono::high_resolution_clock::now();
    cout << "Время list: ";
    cout << (chrono::duration_cast<chrono::microseconds>(clockEnd - clockStart).count()) << "ms\n";
    showData(beg);
    workWithList(beg, listLength);
}

void menu()
{
    short choise;
    cout << "Как вы хотите создать список?\n0. Ввод с консоли\n1. Заполнение случайными числами\n";
    cin >> choise;
    if (choise)
    {
        createListA();
    }
    else
    {
        createListB();
    }
    short choise1;
    cout << "Хотите пересоздать список?\n0. Нет\n1. Да\n";
    cin >> choise1;
    if (choise1)
    {
        menu();
    }
}

int main()
{
    setlocale(0, "");
    menu();
}

