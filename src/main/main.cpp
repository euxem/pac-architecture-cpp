#include <crow.h>
#include "routes.cpp"

#include "DummyDBData.hpp"
#include "LandingPagePresenter.hpp"
#include "LandingPageController.hpp"
#include "LandingPageAbstraction.hpp"

int main() {
    // Setup the Crow application
    crow::SimpleApp app;

    // Setup and init the db
    DummyDBData db;

    LandingPageAbstraction landAbs(&db);

    LandingPageController landCont(&landAbs, nullptr, nullptr);

    LandingPagePresenter landPage(&landCont);

    // Définir les routes
    app.route_dynamic("/<int>").methods("GET"_method)
    ([&](const crow::request& req, crow::response& res, int userId) {
        landingPagePresenter.showPage(req, res, userId);
    });

    app.port(8080).run();
}