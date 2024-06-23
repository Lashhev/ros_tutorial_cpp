# Демка простого подписчика

## Создание пакета

```bash
    catkin_create_pkg simple_subscriber roscpp std_msgs
```

## Сборка пакета

```bash
    cd catkin_ws
    catkin_make --pkg simple_subscriber 
```

## Запуск узла

```bash
    source ~/catkin_ws/devel/setup.bash
    rosrun simple_subscriber simple_subscriber_node
```

## Посмотреть публикуемые данные

```bash
    rostopic echo /chatting
```

## Замерить частоту публикуемых данных

```bash
    rostopic hz /chatting
```
