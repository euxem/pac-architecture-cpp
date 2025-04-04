#include "LandingPageAbstraction.hpp"

#include <vector>
#include "User.hpp"
#include "NoSuchUserException.hpp"

/**
 * @brief Retrieves a user from the database based on the given ID.
 * 
 * This method searches for a user by their unique identifier (ID). If the user
 * is found in the database, it returns the corresponding User object. Otherwise,
 * it throws a NoSuchUserException.
 * 
 * @param id The unique identifier of the user to search for.
 * @return The user corresponding to the given ID.
 * @throws NoSuchUserException if no user with the given ID is found.
 */
User& LandingPageAbstraction::getUser(int id) {
    // Retrieve the list of users from the database connection
    std::vector<User>& usr  = this->dbConnection.getUser();

    // Search for the user by ID
    for (User& u : usr) {
        if (id == u.getId()) {
            return u;  // Return the user if found
        }
    }
    
    // If no user is found, throw an exception
    throw NoSuchUserException("User with ID " + std::to_string(id) + " not found.");
}
