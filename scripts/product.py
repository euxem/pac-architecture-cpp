import requests
import time
from random import randrange

sellers=[(2, 1, "Swift", "Taylor", "seller address 2", "345678"),
          (3, 1, "Andrew", "Wilson", "seller address 3", "456789")];

for index in range(4, 100):
    time.sleep(10) # 10 sec wait

    sellerId=randrange(2);
    seller=sellers[sellerId];

    url = 'http://localhost:8080/product'
    body = { "id": index, 
            "name": "product"+str(index), 
            "quantity": 100, 
            "seller": { 
                "id": seller[0], 
                "userType": seller[1], 
                "firstName": seller[2], 
                "lastName": seller[3], 
                "address": seller[4], 
                "accountNo": seller[5] 
            }
            }

    response = requests.post(url, json = body)

    print(response.text)