## Инструкция по сборке приложения

Для сборки приложения требуются библиотеки Qt, Eigen, и средство сборки CMake

    sudo apt-get install qt6-base-dev libeigen3-dev cmake

Для сборки следуйте следующим командам

    *открыть терминал в папке проекта
    mkdir build
    cd build
    cmake ..
    make

При запуске приложения появится таблица. Вводить можно только значения *theta*.
Остальные значения заморожены. Поменять эти значения можно в файле parameters.h.
