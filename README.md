# pac-architecture-cpp

Implementation Exemple of the PAC Architecture througth a E-Commerce Application Project.

## To run the code

- Install docker
- run ./build.bat or ./build.sh depending on your OS
- run ./run.bat or ./run.sh
- go to your webBrowser and hit http://localhost:8080/0

you can hit different user with diffent number (ex : http://localhost:8080/1, http://localhost:8080/2 ...)

## To run some test data

 - in a terminal run :
  docker exec -it container-pac-demo-cpp bash
  cd /project/script
 - then select wich script do you want to launch :
        python3 order.py     (will add order)
     or python3 product.py   (will add product)
 - hit http://localhost:8080/1 to see the result
