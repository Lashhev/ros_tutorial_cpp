# Демки ROS на c++

## Создание рабочего пространства(Custom Workspace)

```bash
    mkdir -p catkin_ws/src # создаем папку для рабочего пространства
    cd catkin_ws/src 
    catkin_init_workspace # скрипт создающий новое рабочее пространство.
```

## Создание метапакета ([Metapackage](https://wiki.ros.org/Metapackages))

```bash
    mkdir ros_tutorial_cpp
    cd ros_tutorial_cpp
    catkin_create_pkg ros_tutorial_cpp --meta # создаем метапакет ros_tutorial_cpp
```

## Запуск rosmaster

```bash
    roscore
```