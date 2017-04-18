# Life Simulation

Этот репозиторий включает в себя реализацию дискретной модели симуляции жизни.Для сборки нужно выполнить следующие шаги:
1.  скачать последнюю версию [**Life_Simulation**](https://github.com/einerfreiheit/life_simulation.git)
2.  установить cmake: 
    *  sudo apt-get install cmake
3.  установить следующие библиотеки: 
    - OpenCV: 
         -  sudo apt-get install libopencv-dev
    - boost program_option: 
         - sudo apt-get install libboost-all-dev
4.  собрать **Life Simulation**:
      -  cmake CMakeLists.txt
      -  make
5.  запустить симуляцию:
     -   ./LifeSim
