#ifndef __LANDINGPAGEABSTRACTION_H__
#define __LANDINGPAGEABSTRACTION_H__

#include "DummyDBData.hpp"
#include "User.hpp"

/**
 * This class serves as an abstraction layer for the landing page,  
 * providing methods to interact with user data.
 */
class LandingPageAbstraction {
private:
    /**  
     * Database connection providing access to user data.  
     */
    DummyDBData& dbConnection;
public:
    LandingPageAbstraction(DummyDBData& dbConnection) : dbConnection(dbConnection) {}
    
    /**
     * Retrieves a user from the database based on the given ID.
     * 
     * @param id The unique identifier of the user to search for.
     * @return The user corresponding to the given ID.
     * @throws NoSuchElementException if no user with the given ID is found.
     */
    User& getUser(int id);
};

#endif
