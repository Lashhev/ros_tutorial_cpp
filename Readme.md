# Демки ROS на c++

## Создание рабочего пространства(Custom Workspace)
Для сборки этого пакета нужно создать рабочее пространство
```bash
    mkdir -p catkin_ws/src # создаем папку для рабочего пространства
    cd catkin_ws/src 
    catkin_init_workspace # скрипт создающий новое рабочее пространство.
```

## Создание метапакета ([Metapackage](https://wiki.ros.org/Metapackages))
Данные команды представлены для примера как создавать метапакет. Для работы с данным 
    демо нужно лишь сделать git clone этого примера в папку с вашим рабочим пространством
```bash
    mkdir ros_tutorial_cpp
    cd ros_tutorial_cpp
    catkin_create_pkg ros_tutorial_cpp --meta # создаем метапакет ros_tutorial_cpp
```

## Клонирование пакета с этой демкой

```bash
    cd catkin_ws/src 
    git clone git@github.com:Lashhev/ros_tutorial_cpp.git
```

## Сборка пакета 
```bash
    cd catkin_ws 
    catkin_make 
```

## Запуск rosmaster

```bash
    roscore
```