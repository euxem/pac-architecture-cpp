#include "LandingPagePresenter.hpp"
#include "User.hpp"

void LandingPagePresenter::showPage(const crow::request& req, crow::response& res, int userId) {
    User user = this->landingPageController.getUser(userId);
    std::stringstream html;

    html << "<!DOCTYPE html>"
         << "<html>"
         << "<head>"
         << "<style>"
         << "table, th, td {"
         << "border: 1px solid black;"
         << "border-collapse: collapse;"
         << "}"
         << "</style>"
         << "<script>"
         << "window.setInterval(\"reloadIFrame30k();\", 30000);"
         << "window.setInterval(\"reloadIFrame500();\", 500);"
         << "function reloadIFrame30k() {"
         << "document.getElementById('ProductsViewId').contentWindow.location.reload();"
         << "}"
         << "function reloadIFrame500() {"
         << "document.getElementById('OrdersViewId').contentWindow.location.reload();"
         << "}"
         << "</script>"
         << "</head>"
         << "<body>"
         << "<p>This is the sample landing page presenter</p>"
         << "<p>Logged in user ID: " << user.getId() << ", name: " << user.getFirstName() << " " << user.getLastName() << "</p>"
         << "<p>User role: " << (user.getUserType() == CUSTOMER ? "CUSTOMER" : "SELLER") << "</p>"
         << "<iframe src='/product/" << user.getId() << "' title='Products' id='ProductsViewId' width='45%' height='500'></iframe>"
         << "<iframe src='/order/" << user.getId() << "' title='Orders' id='OrdersViewId' width='45%' height='500'></iframe>"
         << "</body>"
         << "</html>";

    res.set_header("Content-Type", "text/html");
    res.write(html.str());
    res.end();
}
