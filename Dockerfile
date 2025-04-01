# Author: Chinthaka Senanayaka, Emile Guillaume, Alireza Abrehforoush
# Year: 2025-2026
FROM ubuntu:jammy

RUN apt-get update && apt-get -y upgrade
# Installing G++ and git
RUN apt-get -y install g++ git cmake python3 libasio-dev

# Installing Crow
RUN git clone https://github.com/CrowCpp/Crow.git && \
    cd Crow && \
    mkdir build && cd build && \
    cmake .. && make && \
    make install
