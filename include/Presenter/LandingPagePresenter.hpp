#ifndef __LANDINGPAGEPRESENTER_H__
#define __LANDINGPAGEPRESENTER_H__

#include <crow.h>
#include "LandingPageController.hpp"

/**
 * @class LandingPagePresenter
 * @brief Handles the presentation logic for the landing page.
 *
 * This class is responsible for generating and displaying the landing page
 * for users by retrieving user data and rendering an HTML page.
 */
class LandingPagePresenter {
private:
    LandingPageController& landingPageController; ///< Reference to the landing page controller
public:
    /**
     * @brief Constructs a LandingPagePresenter with a reference to a controller.
     * @param landingPageController Reference to the LandingPageController instance.
     */
    LandingPagePresenter(LandingPageController& landingPageController) : landingPageController(landingPageController) {}

    /**
     * @brief Generates and sends the HTML content for the landing page.
     *
     * This function retrieves user details based on the provided userId and generates
     * an HTML page containing the user's information and two iframes for products
     * and orders. It also includes JavaScript to refresh these iframes periodically.
     *
     * @param req Incoming HTTP request.
     * @param res HTTP response to be filled with HTML content.
     * @param userId The ID of the logged-in user.
     */
    void showPage(const crow::request& req, crow::response& res, int userId);
};

#endif
