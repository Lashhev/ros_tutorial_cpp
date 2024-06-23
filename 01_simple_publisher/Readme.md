# Демка простого паблишера

## Создание пакета

```bash
    catkin_create_pkg simple_publisher roscpp std_msgs
```

## Сборка пакета

```bash
    cd catkin_ws
    catkin_make --pkg simple_publisher 
```

## Запуск узла

```bash
    source ~/catkin_ws/devel/setup.bash
    rosrun simple_publisher simple_publisher_node
```

## Посмотреть публикуемые данные

```bash
    rostopic echo /chatting
```

## Замерить частоту публикуемых данных

```bash
    rostopic hz /chatting
```
