import requests
import time
from random import randrange

customers=[(0, 0, "John", "Doe", "customer address 0", "123456"),
          (1, 0, "Serena", "Williams", "customer address 1", "234567")];

sellers=[(2, 1, "Swift", "Taylor", "seller address 2", "345678"),
          (3, 1, "Andrew", "Wilson", "seller address 3", "456789")];

products=[(0, "Product0", 100, 0),
          (1, "Product1", 100, 0),
          (2, "Product2", 100, 1),
          (3, "Product3", 100, 1)];

for index in range(3, 1000):
    time.sleep(5) # 5 sec wait
    
    customerId=randrange(2);
    productId=randrange(4);

    customer=customers[customerId];
    product=products[productId];
    seller=sellers[product[3]];

    url = 'http://localhost:8080/order'
    body = {
        "id": index,
        "customer": {
            "id": customer[0],
            "userType": customer[1],
            "firstName": customer[2],
            "lastName": customer[3],
            "address": customer[4],
            "accountNo": customer[5]
        },
        "products": [
            {
                "id": product[0],
                "name": product[1],
                "quantity": product[2],
                "seller": {
                    "id": seller[0],
                    "userType": seller[1],
                    "firstName": seller[2],
                    "lastName": seller[3],
                    "address": seller[4],
                    "accountNo": seller[5]
                }
            }
        ]
    }

    response = requests.post(url, json = body)

    print(response.text)