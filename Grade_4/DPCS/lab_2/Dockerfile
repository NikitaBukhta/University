FROM ubuntu::latest

RUN apt update && \
    apt install -y qml6-module-q* && \
    apt install -y qt6-declarative-dev

COPY . /app

WORKDIR /app

RUN mkdir build

WORKDIR /app/build

RUN cmake .. || true && make -j12

CMD ["./lab_2_dpcs"]