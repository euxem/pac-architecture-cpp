#include <crow.h>
#include <vector>

#include "OrderController.hpp"
#include "OrderPresenter.hpp"
#include "IOrderPresenter.hpp"
#include "Order.hpp"
#include "Product.hpp"
#include "message.hpp"

OrderPresenter::OrderPresenter(OrderController& orderController) : orderController(orderController) {
    orderController.subscribe((IOrderPresenter*)this);
}

void OrderPresenter::showOrder(void* data) {    
    Message* mes = (Message*)data;

    std::vector<Order> orders = this->orderController.getOrdersForUser(mes->user);
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
    </head>
    <body>
    <p>This is the sample order presenter</p>
    <table>
        <tr>
            <th>Order ID</th>
            <th>Customer Name</th>
            <th>Products</th>
        </tr>
    )";

    // Affichage des commandes
    for (Order& order : orders) {
        for (Product& product : order.getProducts()) {
            html << "<tr>"
                 << "<td>" << order.getId() << "</td>"
                 << "<td>" << order.getCustomer().getFirstName() << "</td>"
                 << "<td>" << product.getName() << "</td>"
                 << "</tr>";
        }
    }

    html << R"(
    </table>
    </body>
    </html>
    )";

    mes->res.set_header("Content-Type", "text/html");
    mes->res.write(html.str());
    mes->res.end();
}
