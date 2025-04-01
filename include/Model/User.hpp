#ifndef __USER_H__
#define __USER_H__

#include <string>

/**
 * Enum representing the type of user in the system.  
 * A user can either be a CUSTOMER or a SELLER.
 */
typedef enum {
    /** Represents a customer user type. */
    CUSTOMER, 

    /** Represents a seller user type. */
    SELLER
} UserType;

/**
 * Represents a user in the system, which can either be a customer or a seller.
 * Contains information about the user's ID, type, name, address, and account number.
 */
class User {
    private:
        /** The unique identifier for the user. */
        int id;

        /** The type of user (either CUSTOMER or SELLER). */
        UserType userType;

        /** The first name of the user. */
        std::string firstName;

        /** The last name of the user. */
        std::string lastName;

        /** The address of the user. */
        std::string address;

        /** The account number of the user. */
        std::string accountNo;

    public:
        User(int id, UserType userType, std::string firstName, std::string lastName, std::string address, std::string accountNo) : id(id), userType(userType), firstName(firstName), lastName(lastName), address(address), accountNo(accountNo) {}

        /**
         * get the user id
         * 
         * @return the user id
         */
        int getId();

        /**
         * get the type of the user
         * 
         * @return the type of the user
         */
        UserType getUserType();

        /**
         * getter for firstname
         * 
         * @return firstname
         */
        std::string& getFirstName();

        /**
         * getter for LastName
         * 
         * @return lastname
         */
        std::string& getLastName();

        /**
         * getter for address
         * 
         * @return the address
         */
        std::string& getAddress();

        /**
         * gettre for AccountNo
         * 
         * @return the accountNo
         */
        std::string& getAccountNo();
};
#endif
