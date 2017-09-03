# Life Simulation
 О репозитории.
 Этот репозиторий включает в себя реализацию модели симуляции существования и эволюции одноклеточных организмов. Организмы располагаются на участке карты, обладают набором действий (движение, питание, атака) и способностью к размножению. Реализована модель генома, включающая в себя набор гомологичных хромосом, в которых содержатся гены, определяющие параметры метаболизма существа. Генетическая информация передается через механизм конъюгации, аналогично таковому у бактерий.  
  * Для сборки нужно выполнить следующие шаги:
1.  скачать последнюю версию [**Life_Simulation**](https://github.com/einerfreiheit/life_simulation.git)
2. скопировать config.ini из  /life_simulation/config/ в /life_simulation/.
3.  установить cmake: 
    *  sudo apt-get install cmake
4.  установить следующие библиотеки: 
    - freeglut3-dev libglew1.5-dev libglu1-mesa-dev libgl1-mesa-glx libgl1-mesa-dev libsoil-dev libglm-dev
    - OpenCV: 
         -  sudo apt-get install libopencv-dev
    - boost program_option: 
         - sudo apt-get install libboost-all-dev
5.  собрать **Life Simulation**:
      -  cmake CMakeLists.txt
      -  make
6.  запустить симуляцию:
     -   ./LifeSim
