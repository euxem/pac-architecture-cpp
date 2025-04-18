#include <crow.h>
#include <vector>

#include "OrderController.hpp"
#include "OrderPresenter.hpp"
#include "IOrderPresenter.hpp"
#include "Order.hpp"
#include "Product.hpp"
#include "message.hpp"

/**
 * @brief Constructs an OrderPresenter and subscribes to the OrderController.
 *
 * This constructor initializes the presenter and subscribes it to receive order updates.
 *
 * @param orderController Reference to the OrderController.
 */
OrderPresenter::OrderPresenter(OrderController& orderController) : orderController(orderController) {
    // Register this presenter as a subscriber to receive notifications from the controller
    orderController.subscribe((IOrderPresenter*)this);
}

/**
 * @brief Generates and sends the HTML content for displaying orders.
 *
 * This function retrieves a list of orders for a given user, formats them into an HTML table,
 * and sends the response back to the client.
 *
 * @param data Pointer to a Message object containing request details.
 */
void OrderPresenter::showOrder(void* data) {    
    Message* mes = (Message*)data;

    // Retrieve all orders related to the given user
    std::vector<Order> orders = this->orderController.getOrdersForUser(mes->user);

    // Start building the HTML content
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

    // Loop through each order and its products to fill table rows
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

    // Set response content type and return the generated HTML
    mes->res.set_header("Content-Type", "text/html");
    mes->res.write(html.str());
    mes->res.end();
}
