#include <crow.h>
#include <vector>

#include "ProductController.hpp"
#include "ProductPresenter.hpp"
#include "IProductPresenter.hpp"
#include "Product.hpp"
#include "message.hpp"

/**
 * @brief Constructs a ProductPresenter and subscribes to the ProductController.
 *
 * This constructor initializes the presenter and subscribes it to receive product updates.
 *
 * @param productController Reference to the ProductController.
 */
ProductPresenter::ProductPresenter(ProductController& productController) : productController(productController) {
    // Register this presenter as a subscriber to receive updates from the controller
    productController.subscribe((IProductPresenter*)this);
}

/**
 * @brief Generates and sends the HTML content for displaying products.
 *
 * This function retrieves a list of products for a given user, formats them into an HTML table,
 * and sends the response back to the client.
 *
 * @param data Pointer to a Message object containing request details.
 */
void ProductPresenter::showProduct(void* data) {
    Message* mes = (Message*)data;

    // Fetch products associated with the user from the controller
    std::vector<Product> products = this->productController.getProductsForUser(mes->user);

    // Start building the HTML page with a table
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
    <p>This is the sample product presenter</p>
    <table>
        <tr>
            <th>Product ID</th>
            <th>Product Name</th>
            <th>Quantity</th>
            <th>Seller Name</th>
        </tr>
    )";

    // Loop through the product list and fill each table row with product data
    for (Product& product : products) {
        html << "<tr>"
                << "<td>" << product.getId() << "</td>"
                << "<td>" << product.getName() << "</td>"
                << "<td>" << product.getQuantity() << "</td>"
                << "<td>" << product.getSeller().getFirstName() << "</td>"
                << "</tr>";
    }

    html << R"(
    </table>
    </body>
    </html>
    )";

    // Set content type and send the constructed HTML response
    mes->res.set_header("Content-Type", "text/html");
    mes->res.write(html.str());
    mes->res.end();
}
