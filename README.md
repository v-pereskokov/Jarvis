#J.A.R.V.I.S
[![Build Status](https://travis-ci.org/vladpereskokov/Jarvis.svg?branch=voice)](https://travis-ci.org/vladpereskokov/Jarvis)
===
![J.A.R.V.I.S. brain](/docs/home.png)
===
##Оглавление
+ [Введение](#introduction)
+ [Графический интерфейс](#GUI)
+ [Распознавание голоса](#Voice)
+ [Arduino](#Arduino)
===  
<a name="introduction"></a>
##Введение
+ [Для чего мне эта система?](#why)
+ [Почему именно эта система?](#feautures)
+ [Рассмотрение аналогов](#analogs)
===
<a name="why"></a>   
###Для чего мне эта система?  
Целью данного проекта является создание умного дома. Под умным домом понимается интеллектуальная система управления домом, обеспечивающая автоматическую и согласованную работу всех систем жизнеобеспечения и безопасности.  
Управлением будет заниматься автоматизированная система ```J.A.R.V.I.S.```. Пользователю отсается лишь установить оборудование в доме и подключить устройство через интерфейс клиента.  
<a name="feautures"></a>  
###Почему именно эта система?  
Данную систему очень легко подключить к домашним устройствам. Вам нужно всего лишь подключить к устройствам датчики, установить "мозг" системы и зарегистрировать дом. Одно из главных достоинств - не обязательно держать "мозг" системы возле управляемого устройтсва. Все датчики, которые вы подключаете связаны и могут посылать сигналы друг другу от главного устройства - "мозга" - пока не дойдет до нужного.   
У Вас есть возможность контролировать дом даже за его пределами. Посылайте команды через телефон также посредством голоса или получить информацию об активных устройствах по смс. 
Вы можете не беспокоиться, что кто-то сторонний подключится к дому, поскольку наша система предоставляет всем пользователям надежную защиту данных. ```Описание алгоритма шифрования(soon)```  
<a name="analogs"></a>  
* Google Home  
Беспроводной динамик, снабженный голосовым управлением, разработанный в Google. В составе Google Home Ассистент занимается прослушиванием и распознаванием команд пользователя.
Неясными остаются возможности слежки со стороны международной корпорации Google при использовании Google Home. Google внедрила опциональный режим анонимизации запросов, в котором запросы сохраняются без возможности просмотра истории из аккаунта пользователя.  
* Apple Home  
Благодаря новому приложению «Дом» вы можете управлять всеми аксессуарами с поддержкой HomeKit прямо с устройства iOS. Выключите свет с помощью iPhone. Включите iPad и узнайте, кто стоит у входной двери. С приложением «Дом» все ваши подключённые устройства работают намного эффективнее.  
Два вышеописанных аналога в сравнении с нашим продуктом - намного дороже, не позволяют включать обычные лампы накаливания (а предлагают купить оборудование, которое подходит к системе). Еще одним минусом является - зависимость от местоположения устройства. Находясь далеко от устройства - "home" от известных компаний может не ловить Ваши устройства.   
<a name="helpers></a>  
Помимо функции управления домом - наша система способна помогать Вам контролировать планы на день, предлагает более быстрые маршруты объезда пробок. Более подробный список всех доступных функций Вы можете найти ниже. ```(soon)```  
===  
<a name="GUI"></a>  
##Графический интерфейс  
===  
![GUI1](https://github.com/vladpereskokov/Jarvis/tree/voice/docs/1.jpeg)  
===  
![GUI1](https://github.com/vladpereskokov/Jarvis/tree/voice/docs/2.jpeg)  
===  
![GUI1](https://github.com/vladpereskokov/Jarvis/tree/voice/docs/3.jpeg)  
===  
![GUI1](https://github.com/vladpereskokov/Jarvis/tree/voice/docs/4.jpeg)  
===  
<a name="Voice"></a>  
##Распознавание голоса  
Распознавание голоса производится с помощью сервиса от компании "Yandex" "SpeechKitCloud".   
SpeechKit Cloud — это программа, которая открывает разработчикам доступ к технологиям распознавания и синтеза речи Яндекса, а также выделения смысловых объектов в произносимом тексте. Инфраструктура сервиса спроектирована с учетом высоких нагрузок, чтобы обеспечивать доступность и безотказную работу системы даже при большом количестве одновременных обращений.    
Взаимодействие со SpeechKit Cloud идет через HTTP API. Поэтому вам не придется разворачивать и поддерживать свою инфраструктуру, чтобы в сжатые сроки реализовать самые разные функции:    
* голосовой ввод в компьютерных играх и приложениях;  
* голосовое управление в салоне автомобиля — например,   навигационной системой;  
* интерактивное голосовое меню (IVR) в телефонии;  
* голосовой интерфейс систем «Умный дом»;  
* голосовой интерфейс электронных роботов;  
* голосовое управление бытовой техникой и т.д.  
Схема управления представлена ниже:  
![VOICE1](https://github.com/vladpereskokov/Jarvis/tree/voice/docs/Voice1.png)  
Как видно из схемы - пользователь произносит команду, которая преобразуется в строку на сервере "Yandex", после чего произойдет разбор команды на лексемы и выявления главных частей. Далее составится запрос для "мозга" системы, который отправится к устройству. После того, как устройство выполнит указанное действие - оно отправит серверу через "мозг" подтверждение выполнилась ли команда и в каком состоянии находилось устройство в момент отправки обратного сообщения.   
<a name = "Arduino"></a>  
##Arduino  
"Мозг" системы состоит из плат Arduino и множества датчиков. Ниже приведены схемы подключения некоторых датчиков. 
```Схема 1```  
![Arduino1](https://github.com/vladpereskokov/Jarvis/tree/voice/docs/Arduino1.png)  
На ```Схеме 1``` представлено подключение датчиков шума, освещенности и зуммер.   
===  
```Схема 2```  
![Arduino2](https://github.com/vladpereskokov/Jarvis/tree/voice/docs/Arduino2.png)  
На этой схеме изображена схема подключения Bluetooth - датчика. 
===  
![Arduino3](https://github.com/vladpereskokov/Jarvis/tree/voice/docs/Arduino3.png)  
Выше описано устройство беспроводного соединения по Bluetooth - "HC-06".  
===  
<a name="technologies"></a>  
##Технологии  
