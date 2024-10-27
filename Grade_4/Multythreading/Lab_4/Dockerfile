FROM vookimedlo/ubuntu-qt:qt6_latestdistroofficial_gcc_oracular

WORKDIR /usr/src/app

COPY . .

RUN mkdir build

WORKDIR /usr/src/app/build
RUN cmake .. && make -j$(nproc)

CMD ["./lab_4_multythreading"]
