#include "LandingPagePresenter.hpp"

void LandingPagePresenter::LanshowPage(const crow::request& req, crow::response& res, int userId) {
    User user = this->landingPageController.getUser(userId);
    std::stringstream html;

    html << R"(
    <!DOCTYPE html>
    <html>
    <head>
        <style>
            table, th, td {
                border: 1px solid black;
                border-collapse: collapse;
            }
        </style>
        <script>
            window.setInterval("reloadIFrame30k();", 30000);
            window.setInterval("reloadIFrame500();", 500);

            function reloadIFrame30k() {
                document.getElementById('ProductsViewId').contentWindow.location.reload();
            }

            function reloadIFrame500() {
                document.getElementById('OrdersViewId').contentWindow.location.reload();
            }
        </script>
    </head>
    <body>
    <p>This is the sample landing page presenter</p>
    <p>Logged in user ID: " << user.id << ", name: " << user.firstName << " " << user.lastName << "</p>
    <p>User role: " << user.userType << "</p>
    <iframe src='/product/" << user.id << "' title='Products' id='ProductsViewId' width='45%' height='500'></iframe>
    <iframe src='/order/" << user.id << "' title='Orders' id='OrdersViewId' width='45%' height='500'></iframe>
    </body>
    </html>
    )";

    res.set_header("Content-Type", "text/html");
    res.write(html.str());
}
