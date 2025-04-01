#include <crow.h>
#include <vector>

#include "ProductController.hpp"
#include "ProductPresenter.hpp"
#include "IProductPresenter.hpp"
#include "Product.hpp"
#include "message.hpp"


ProductPresenter::ProductPresenter(ProductController& productController) : productController(productController) {
    productController.subscribe((IProductPresenter*)this);
}

void ProductPresenter::showProduct(void* data) {
    Message* mes = (Message*)data;

    std::vector<Product> products = this->productController.getProductsForUser(mes->user);
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

    // Affichage des produits
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

    mes->res.set_header("Content-Type", "text/html");
    mes->res.write(html.str());
    mes->res.end();
}
