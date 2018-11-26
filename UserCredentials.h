#ifndef SICKLEAVES_USERCREDENTIALS_H
#define SICKLEAVES_USERCREDENTIALS_H

#include <iostream>

using namespace std;

class UserCredentials {
private:
    string login;
    string password;
public:

    UserCredentials() {}

    UserCredentials(const string &login, const string &password) : login(login), password(password) {}

    void setLogin(string login) {
        this->login = login;
    }

    string getLogin() {
        return login;
    }

    void setPassword(string password) {
        this->password = password;
    }

    string getPassword() {
        return password;
    }

};

#endif //SICKLEAVES_USERCREDENTIALS_H
