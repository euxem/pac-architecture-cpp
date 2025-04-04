#include "User.hpp"

/**
 * @brief Retrieves the user's unique ID.
 * 
 * @return The ID of the user.
 */
int User::getId() {
    return this->id;
}

/**
 * @brief Gets the type of the user (e.g., CUSTOMER or SELLER).
 * 
 * @return The UserType enum value representing the user's role.
 */
UserType User::getUserType() {
    return this->userType;
}

/**
 * @brief Gets the user's first name.
 * 
 * @return A reference to the user's first name as a string.
 */
std::string& User::getFirstName() {
    return this->firstName;
}

/**
 * @brief Gets the user's last name.
 * 
 * @return A reference to the user's last name as a string.
 */
std::string& User::getLastName() {
    return this->lastName;
}

/**
 * @brief Retrieves the user's address.
 * 
 * @return A reference to the user's address string.
 */
std::string& User::getAddress() {
    return this->address;
}

/**
 * @brief Gets the user's account number.
 * 
 * @return A reference to the user's account number as a string.
 */
std::string& User::getAccountNo() {
    return this->accountNo;
}
