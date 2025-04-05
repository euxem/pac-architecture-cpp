/**
 * This main file just create all PAC agent object and initiate the Crow FrameWork
 * It is not invole in the PAC logic,it just launch the logic
 */

 #include <crow.h>
 #include <crow/json.h>
 
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
 #include "Order.hpp"
 #include "Product.hpp"
 #include "User.hpp"
 
 int main() {
     // Setup the Crow application
     crow::SimpleApp app;
 
     // Initialize the in-memory dummy database
     DummyDBData db;
 
     // Create PAC agents for Product
     ProductAbstraction prodAbs(db);
     ProductController prodCont(prodAbs);
     ProductPresenter prodPres(prodCont);
 
     // Create PAC agents for Order
     OrderAbstraction ordAbs(db);
     OrderController ordCont(ordAbs);
     OrderPresenter ordPres(ordCont);
 
     // Create PAC agents for Landing Page and connect with Product & Order controllers
     LandingPageAbstraction landAbs(db);
     LandingPageController landCont(landAbs, prodCont, ordCont);
     LandingPagePresenter landPage(landCont);
 
     // Route: GET /<userId> -> Landing page for a specific user
     app.route_dynamic("/<int>").methods("GET"_method)
     ([&](const crow::request& req, crow::response& res, int userId) {
         landPage.showPage(req, res, userId);
     });
 
     // Route: GET /product/<userId> -> Show product view for the user
     app.route_dynamic("/product/<int>").methods("GET"_method)
     ([&](const crow::request& req, crow::response& res, int userId) {
         // Wrap request/response and user into a message object
         Message mes = {req, res, landCont.getUser(userId)};
         landCont.getProductPresenter((void*)&mes);
     });
 
     // Route: GET /order/<userId> -> Show order view for the user
     app.route_dynamic("/order/<int>").methods("GET"_method)
     ([&](const crow::request& req, crow::response& res, int userId) {
         Message mes = {req, res, landCont.getUser(userId)};
         landCont.getOrderPresenter((void*)&mes);
     });
 
     // Route: POST /order -> Create a new order
     CROW_ROUTE(app, "/order").methods("POST"_method)
     ([&](const crow::request& req) {
         try {
             auto json = crow::json::load(req.body);
             if (!json) {
                 // Invalid JSON format
                 return crow::response(400, "Invalid JSON");
             }
 
             // Parse order data from JSON
             Order order;
             order.setId(json["id"].i());
 
             // Assign customer to order
             int customerId = json["customerId"].i();
             order.setCustomer(landCont.getUser(customerId));
 
             // Parse product list and assign to order
             std::vector<Product> products;
             for (const auto& item : json["products"]) {
                 Product p;
                 p.setId(item["id"].i());
                 // Other fields could be added here as needed
                 products.push_back(p);
             }
             order.setProducts(products);
 
             // Pass order to controller to handle creation
             landCont.createOrder(order);
 
             return crow::response(201, "Order created successfully");
         } catch (const std::exception& e) {
             // Catch and return any runtime error during processing
             return crow::response(500, std::string("Error creating order: ") + e.what());
         }
     });
 
     // Route: POST /product -> Create a new product
     CROW_ROUTE(app, "/product").methods("POST"_method)
     ([&](const crow::request& req) {
         try {
             auto json = crow::json::load(req.body);
             if (!json) {
                 // Invalid JSON input
                 return crow::response(400, "Invalid JSON");
             }
 
             // Parse product data from JSON
             Product product;
             product.setId(json["id"].i());
             product.setName(json["name"].s());
             product.setQuantity(json["quantity"].i());
 
             // Set seller of the product
             int sellerId = json["sellerId"].i();
             product.setSeller(landCont.getUser(sellerId));
 
             // Delegate creation to controller
             landCont.createProduct(product);
 
             return crow::response(201, "Product created successfully");
         } catch (const std::exception& e) {
             return crow::response(500, std::string("Error creating product: ") + e.what());
         }
     });
 
     // Run the web server on port 8080
     app.port(8080).run();
 }
 