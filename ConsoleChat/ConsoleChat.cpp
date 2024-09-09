#include "User.h"
#include "Chat.h"

int main()
{
    setlocale(LC_ALL, "rus");
    Chat chat;

    while (true) {
        cout << "1. Регистрация" << endl;
        cout << "2. Вход" << endl;
        cout << "3. Отправить сообщение" << endl;
        cout << "4. Показать сообщения" << endl;
        cout << "5. Выход" << endl;

        int choice;
        cin >> choice;
        cin.ignore();

        try {
            if (choice == 1) {
                string username, password, name;
                cout << "Введите логин: ";
                getline(cin, username);
                cout << "Введите пароль: ";
                getline(cin, password);
                cout << "Введите имя: ";
                getline(cin, name);
                chat.registerUser(username, password, name);
                cout << "Регистрация успешна!" << endl;
            }
            else if (choice == 2) {
                string username, password;
                cout << "Введите логин: ";
                getline(cin, username);
                cout << "Введите пароль: ";
                getline(cin, password);
                chat.login(username, password);
                cout << "Вход успешен!" << endl;
            }
            else if (choice == 3) {
                string recipient, text;
                cout << "Введите получателя: ";
                getline(cin, recipient);
                cout << "Введите текст сообщения: ";
                getline(cin, text);
                chat.sendMessage(recipient, text);
                cout << "Сообщение отправлено!" << endl;
            }
            else if (choice == 4) {
                string username;
                cout << "Введите ваш логин для показа сообщений: ";
                getline(cin, username);
                chat.showMessages(username);
            }
            else if (choice == 5) {
                break;
            }
            else {
                cout << "Неверный выбор!" << endl;
            }
        }
        catch (const runtime_error& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
    }

    return 0;
}
