#include "User.hpp"

/**
 * get the user id
 * 
 * @return the user id
 */
int User::getId() {
    return this->id;
}

/**
 * get the type of the user
 * 
 * @return the type of the user
 */
UserType User::getUserType() {
    return this->userType;
}

/**
 * getter for firstname
 * 
 * @return firstname
 */
std::string& User::getFirstName() {
    return this->firstName;
}

/**
 * getter for LastName
 * 
 * @return lastname
 */
std::string& User::getLastName() {
    return this->lastName;
}

/**
 * getter for address
 * 
 * @return the address
 */
std::string& User::getAddress() {
    return this->address;
}

/**
 * gettre for AccountNo
 * 
 * @return the accountNo
 */
std::string& User::getAccountNo() {
    return this->accountNo;
}
