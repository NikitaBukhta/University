FROM debian:latest

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y \
    cmake \
    make \
    g++ \
    qt6-base-dev \
    && apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app

RUN mkdir build || true && \
    cd build && \
    cmake .. && \
    make -j4

CMD ["./build/multythreading_lab_1"]
