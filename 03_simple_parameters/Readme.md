# Демка простого подписчика

## Создание пакета

```bash
    catkin_create_pkg simple_parameters_demo roscpp diagnostic_msgs
```

## Сборка пакета

```bash
    cd catkin_ws
    catkin_make --pkg simple_parameters_demo 
```

## Запуск узла

```bash
    source ~/catkin_ws/devel/setup.bash
    rosrun simple_parameters_demo http_client_node
```

## Запуск узла с измененными параметрами

```bash
    rosrun simple_parameters_demo http_client_node _ip_address:=10.12.10.128 _port:=9002 _request:=name
```

## Посмотреть публикуемые данные

```bash
    rostopic echo /diagnostic
```

## Замерить частоту публикуемых данных

```bash
    rostopic hz /diagnostic
```

## Запрсить список параметров

```bash
    rosparam get 
```
