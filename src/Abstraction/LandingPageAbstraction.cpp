#include "LandingPageAbstraction.hpp"

#include <vector>
#include "User.hpp"
#include "NoSuchUserException.hpp"

/**
 * Retrieves a user from the database based on the given ID.
 * 
 * @param id The unique identifier of the user to search for.
 * @return The user corresponding to the given ID.
 * @throws NoSuchUserException if no user with the given ID is found.
 */
User& LandingPageAbstraction::getUser(int id) {
    std::vector<User>& usr  = this->dbConnection.getUser();

    for (User& u : usr) {
        if (id == u.getId()) {
            return u;
        }
    }
    throw NoSuchUserException("User with ID " + std::to_string(id) + " not found.");
}
