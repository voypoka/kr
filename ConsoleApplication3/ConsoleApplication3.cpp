//3) Объявить и заполнить одномерный динамический массив случайными числами от 1 до 50. Показать его на экран. 
// Написать функцию, которая находит и выводит на экран все пары элементов матрицы, сумма которых равна заданному числу (задается пользователем). 
// Функция должна принимать три параметра – указатель на динамический массив, количество элементов в массиве и заданное число. 
// Написать отдельную функцию для вывода массива на экран.

#include <iostream>
#include <vector>
#include <string>

struct Contact {
    std::string name; // имя
    std::string phoneNumber; // номер телефона
};


void addContact(std::vector<Contact>& contacts) {
    Contact newContact; // создаем новый контакт
    std::cout << "Enter the name of the contact: ";
    std::cin >> newContact.name; // вводим имя
    std::cout << "Enter the phone number of the contact: ";
    std::cin >> newContact.phoneNumber; // вводим номер телефона
    contacts.push_back(newContact); // добавляем в список контактов
}

void deleteContact(std::vector<Contact>& contacts) {
    if (contacts.empty()) { // проверяем, есть ли в списке контакты
        std::cout << "No contacts to delete." << std::endl;
        return;
    }

    std::string nameToDelete; // имя того, кого удаляем
    std::cout << "Enter the name of the contact to delete: ";
    std::cin >> nameToDelete; // вводим имя того, кого удаляем

    //поиск имени в векторе, который содержит контакты
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == nameToDelete) {
            contacts.erase(it);
            std::cout << "Contact deleted successfully." << std::endl;
            return;
        }
    }
    // Выводим, если ничего не нашли
    std::cout << "Contact not found." << std::endl;
}

void updateContact(std::vector<Contact>& contacts) {
    // Проверяем, пустой ли список контактов
    if (contacts.empty()) {
        std::cout << "No contacts to update." << std::endl;
        return;
    }

    std::string nameToUpdate; //имя того, кого мы хотим обновить
    std::cout << "Enter the name of the contact to update: ";
    std::cin >> nameToUpdate;
    // Поиск и обновления контакта
    for (auto& contact : contacts) {
        if (contact.name == nameToUpdate) {
            std::cout << "Enter the new phone number for the contact: ";
            std::cin >> contact.phoneNumber; 
            std::cout << "Contact updated successfully." << std::endl;
            return;
        }
    }
    // Выводим сообщение, если ничего не нашли и не обновили
    std::cout << "Contact not found." << std::endl;
}

void displayContacts(std::vector<Contact>& contacts) {
    // Проверяем, пуст ли список контактов
    if (contacts.empty()) {
        std::cout << "No contacts to display." << std::endl;
        return;
    }
    // Выводим список контактов
    for (const auto& contact : contacts) {
        std::cout << "Name: " << contact.name << ", Phone Number: " << contact.phoneNumber << std::endl;
    }
}

int sum_pairs(int target, int *nums, int n) {
    int count = 0; // количество пар

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (nums[i] + nums[j] == target) { // проверка
                count++;
            }
        }
    }
    return count;
}

int main()
{
    // task 1

    int n; //Вводим число
    std::cout << "Enter the number: ";
    std::cin >> n;
    int* arr = new int[n]; // создаем динамический массив

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 51; // заполняем рандомными числами от 1 до 51
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n";

    int s = sum_pairs(2, arr, n); // передаем значения в функцию, которая принимает три параметра. (число, массив, размер массива)
    
    std::cout << s;


   //task 2

    std::vector<Contact> contacts;

    void (*functionPtr[])(std::vector<Contact>&) = { addContact, deleteContact, updateContact, displayContacts};

    int choice;
    do {
        std::cout << "\nPhone Book Menu:\n1. Add Contact\n2. Delete Contact\n3. Update Contact\n4. Display Contacts\n0. Exit\n";
        std::cout << "Enter your choice: ";
        
        // Выбираем цифру от 1 до 4
        std::cin >> choice;

        if (choice >= 1 && choice <= 4) {
            (*functionPtr[choice - 1])(contacts); //запускаем функцию
        }
        else if (choice != 0) {
            std::cout << "Invalid choice. Please try again." << std::endl; //если ввели цифру не от 1 до 4
        }

    } while (choice != 0); // делаем данный цикл, пока не ввели 0.

    return 0;
}

