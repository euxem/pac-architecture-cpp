#include <crow.h>

#include "DummyDBData.hpp"

// Landing include 
#include "LandingPagePresenter.hpp"
#include "LandingPageController.hpp"
#include "LandingPageAbstraction.hpp"

// Order include
#include "OrderPresenter.hpp"
#include "OrderController.hpp"
#include "OrderAbstraction.hpp"

// Product include
#include "ProductPresenter.hpp"
#include "ProductController.hpp"
#include "ProductAbstraction.hpp"

#include "message.hpp"

int main() {
    // Setup the Crow application
    crow::SimpleApp app;

    // Setup and init the db
    DummyDBData db;

    ProductAbstraction prodAbs(db);
    ProductController prodCont(prodAbs);
    ProductPresenter prodPres(prodCont);

    OrderAbstraction ordAbs(db);
    OrderController ordCont(ordAbs);
    OrderPresenter ordPres(ordCont);

    LandingPageAbstraction landAbs(db);
    LandingPageController landCont(landAbs, prodCont, ordCont);
    LandingPagePresenter landPage(landCont);

    // Définir les routes
    app.route_dynamic("/<int>").methods("GET"_method)
    ([&](const crow::request& req, crow::response& res, int userId) {
        landPage.showPage(req, res, userId);
    });

    // Définir les routes
    app.route_dynamic("/product/<int>").methods("GET"_method)
    ([&](const crow::request& req, crow::response& res, int userId) {
        Message mes = {req, res, landCont.getUser(userId)};
        landCont.getProductPresenter((void*)&mes);
    });

    // Définir les routes
    app.route_dynamic("/order/<int>").methods("GET"_method)
    ([&](const crow::request& req, crow::response& res, int userId) {
        Message mes = {req, res, landCont.getUser(userId)};
        landCont.getOrderPresenter((void*)&mes);
    });

    app.port(8080).run();
}