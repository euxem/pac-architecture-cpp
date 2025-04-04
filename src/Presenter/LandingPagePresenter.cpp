#include "LandingPagePresenter.hpp"
#include "User.hpp"

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
void LandingPagePresenter::showPage(const crow::request& req, crow::response& res, int userId) {
    // Retrieve user object based on userId
    User user = this->landingPageController.getUser(userId);

    // Start building the HTML content using a stringstream
    std::stringstream html;

    html << "<!DOCTYPE html>"
         << "<html>"
         << "<head>"

         // Basic styling for tables
         << "<style>"
         << "table, th, td {"
         << "border: 1px solid black;"
         << "border-collapse: collapse;"
         << "}"
         << "</style>"

         // JavaScript to refresh iframes at intervals
         << "<script>"
         // Refresh Products iframe every 30 seconds
         << "window.setInterval(\"reloadIFrame30k();\", 30000);"
         // Refresh Orders iframe every 500ms (frequent updates)
         << "window.setInterval(\"reloadIFrame500();\", 500);"

         // Function to reload Products iframe
         << "function reloadIFrame30k() {"
         << "document.getElementById('ProductsViewId').contentWindow.location.reload();"
         << "}"

         // Function to reload Orders iframe
         << "function reloadIFrame500() {"
         << "document.getElementById('OrdersViewId').contentWindow.location.reload();"
         << "}"
         << "</script>"

         << "</head>"
         << "<body>"

         // Page header
         << "<p>This is the sample landing page presenter</p>"

         // Display user info: ID, full name
         << "<p>Logged in user ID: " << user.getId()
         << ", name: " << user.getFirstName() << " " << user.getLastName() << "</p>"

         // Display user role (either CUSTOMER or SELLER)
         << "<p>User role: " << (user.getUserType() == CUSTOMER ? "CUSTOMER" : "SELLER") << "</p>"

         // Embed Product view iframe
         << "<iframe src='/product/" << user.getId()
         << "' title='Products' id='ProductsViewId' width='45%' height='500'></iframe>"

         // Embed Order view iframe
         << "<iframe src='/order/" << user.getId()
         << "' title='Orders' id='OrdersViewId' width='45%' height='500'></iframe>"

         << "</body>"
         << "</html>";

    // Set the response content type to HTML and send the generated content
    res.set_header("Content-Type", "text/html");
    res.write(html.str());
    res.end();
}
