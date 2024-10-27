FROM ubuntu:latest

# Обновляем пакеты и устанавливаем необходимые зависимости
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    make \
    && apt-get clean

# Создаем рабочую директорию внутри контейнера
WORKDIR /usr/src/app

# Копируем все файлы в контейнер
COPY . .

# Создаем папку для сборки
RUN mkdir build

# Переходим в папку build и собираем проект с использованием CMake
WORKDIR /usr/src/app/build
RUN cmake .. && make -j12

# Указываем команду для запуска скомпилированного исполняемого файла
CMD ["./lab_2_multytheading"]
