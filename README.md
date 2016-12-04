# J.A.R.V.I.S
[![Build Status](https://travis-ci.org/vladpereskokov/Jarvis.svg?branch=voice)](https://travis-ci.org/vladpereskokov/Jarvis)
===
![J.A.R.V.I.S. brain](/docs/home.png)
===
## Оглавление
+ [Введение](#introduction)
+ [Графический интерфейс](#GUI)
+ [Распознавание голоса](#Voice)
+ [Arduino](#Arduino)
+ [Сервер](#server)
+ [Технологии](#technologies)
+ [Диаграммы](#diagrams)

<a name="introduction"></a>
## Введение
+ [Для чего мне эта система?](#why)
+ [Почему именно эта система?](#feautures)
+ [Рассмотрение аналогов](#analogs)
+ [Дополнительные функции](#helpers)

<a name="why"></a>   
### Для чего мне эта система?  
Целью данного проекта является создание умного дома. Под умным домом понимается интеллектуальная система управления домом, обеспечивающая автоматическую и согласованную работу всех систем жизнеобеспечения и безопасности.  
Управлением будет заниматься автоматизированная система ```J.A.R.V.I.S.```. Пользователю отсается лишь установить оборудование в доме и подключить устройство через интерфейс клиента.  

<a name="feautures"></a>  
### Почему именно эта система?  
Данную систему очень легко подключить к домашним устройствам. Вам нужно всего лишь подключить к устройствам датчики, установить "мозг" системы и зарегистрировать дом. Одно из главных достоинств - не обязательно держать "мозг" системы возле управляемого устройтсва. Все датчики, которые вы подключаете связаны и могут посылать сигналы друг другу от главного устройства - "мозга" - пока не дойдет до нужного.   
У Вас есть возможность контролировать дом даже за его пределами. Посылайте команды через телефон также посредством голоса или получить информацию об активных устройствах по смс. 
Вы можете не беспокоиться, что кто-то сторонний подключится к дому, поскольку наша система предоставляет всем пользователям надежную защиту данных. ```Описание алгоритма шифрования(soon)``` 

<a name="analogs"></a> 
### Рассмотрение аналогов 
* Google Home  
Беспроводной динамик, снабженный голосовым управлением, разработанный в Google. В составе Google Home Ассистент занимается прослушиванием и распознаванием команд пользователя.
Неясными остаются возможности слежки со стороны международной корпорации Google при использовании Google Home. Google внедрила опциональный режим анонимизации запросов, в котором запросы сохраняются без возможности просмотра истории из аккаунта пользователя.  
* Apple Home  
Благодаря новому приложению «Дом» вы можете управлять всеми аксессуарами с поддержкой HomeKit прямо с устройства iOS. Выключите свет с помощью iPhone. Включите iPad и узнайте, кто стоит у входной двери. С приложением «Дом» все ваши подключённые устройства работают намного эффективнее.  
Два вышеописанных аналога в сравнении с нашим продуктом - намного дороже, не позволяют включать обычные лампы накаливания (а предлагают купить оборудование, которое подходит к системе). Еще одним минусом является - зависимость от местоположения устройства. Находясь далеко от устройства - "home" от известных компаний может не ловить Ваши устройства.

<a name="helpers"></a>
### Дополнительные функции
Помимо функции управления домом - наша система способна помогать Вам контролировать планы на день, предлагает более быстрые маршруты объезда пробок. Более подробный список всех доступных функций Вы можете найти ниже. ```(soon)```  

<a name="GUI"></a>
## Графический интерфейс    
![GUI1](/docs/1.jpg)  
<hr>
![GUI1](/docs/2.jpg)  
<hr> 
![GUI1](/docs/3.jpg)  
<hr>
![GUI1](/docs/4.jpg)  

<a name="Voice"></a>  
## Распознавание голоса  
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

![VOICE1](/docs/Voice1.png)  
Как видно из схемы - пользователь произносит команду, которая преобразуется в строку на сервере "Yandex", после чего произойдет разбор команды на лексемы и выявления главных частей. Далее составится запрос для "мозга" системы, который отправится к устройству. После того, как устройство выполнит указанное действие - оно отправит серверу через "мозг" подтверждение - выполнилась ли команда и в каком состоянии находилось устройство в момент отправки обратного сообщения.   

<a name = "Arduino"></a>  
## Arduino  
"Мозг" системы состоит из плат Arduino и множества датчиков. Ниже приведены схемы подключения некоторых датчиков. 

```Схема 1```   

![Arduino1](/docs/Arduino1.png)  
На ```Схеме 1``` представлено подключение датчиков шума, освещенности и зуммер.   
<hr>

```Схема 2```  

![Arduino2](/docs/Arduino2.png)  
На этой схеме изображено подключение Bluetooth - датчика. 
<hr>

```Схема 3```  

![Arduino3](/docs/Arduino3.png)  
Выше описано устройство беспроводного соединения по Bluetooth - "HC-06".  

<a name="server"></a>  
## Сервер (```soon```)

<a name="technologies"></a>  
## Технологии  
+ [Языки программирования](#languages)
+ [Фреймворки и библиотеки](#libs)
+ [IDE](#ide)

<a name="languages"></a>  
### Языки программирования
В проекте использовались следующие языки программирования (```на данный момент```):    
+ [C](#C)
+ [C++](#CPP)
+ [Python](#python)

<a name="С"></a>  
#### С
Использовался для написания кода под Arduino. Поскольку ```С ```является низкоуровневым языком программирования - он отлично подходит для написания алгоритмов для Arduino. Однако бибилотеки удобнее писать на языке, речь о котором пойдет ниже - ```C++```.

<a name="СPP"></a>  
#### С++
Перед началом реализации проекта - данный язык сравнивался со следующими:
* Python
* C++
* Swift
* C#

Рассмотрим каждый из них. 

```Python``` - высокоуровневый язык программирования, который обладает огромным количеством различных библиотек. Несмотря на всю его простоту кода - он все же проигрывает по скорости остальным рассматриваемым языкам. 
<hr>
```Swift``` - отличный язык программирования для написания приложений под устройства ```Apple```. Но в этом и есть его минус. Наша цель - сделать кроссплатформенное приложение. 
<hr>
```C#``` - высокоуровневый язык, обладает множеством библиотек. Но все же в нем нет стольких же полезных библиотек, как, например, в том же, ```Python```. К тому же на тот момент на ```C#``` в основном можно было писать только в ```ОС Windows```, что также является его минусом.
<hr>
```C++``` - язык, который обладает свойствами и низкоуровнего, и высокоуровнего программирования. На ```C++``` легко писать библиотеки под Arduino. Написанные на этом языке библиотеки будут работать быстрее, чем на большинстве других. Библиотек и фреймворков хватает, чтобы разработка проекта была не слишком замороченной. Для ```C++``` существуют все необходимые технологии под данный проект. Приложение, написанное на этом языке будут более оптимизированым и быстрым, чем на прочих высокоуровневых языках программирования.    
Именно поэтому как основной язык был выбран ```C++```. 

<a name="Python"></a>  
#### Python
В силу всего, что было сказано выше об этом языке - ```Python``` мы тоже не оставили в стороне. С его помощью всего лишь в 30 строчек кода было написано приложение для записи голоса и сохранения его в аудиофайл. Однако, с последующими обновлениями проекта - мы напишем реализацию приложения для записи голоса на ```C++```. 

<a name="libs"></a>  
### Фреймворки и библиотеки
+ [Qt](#Qt)
+ [Библиотеки](#libraries)

<a name="Qt"></a>  
#### Qt

В нашем проекте использовался фреймворк ```Qt``` для написания графического интерфейса. ```Qt``` позволяет запускать написанное с его помощью ПО в большинстве современных операционных систем путём простой компиляции программы для каждой ОС без изменения исходного кода. Отличительная особенность ```Qt``` от других библиотек — использование Meta Object Compiler (MOC) — предварительной системы обработки исходного кода. MOC позволяет во много раз увеличить мощь библиотек, вводя такие понятия, как слоты и сигналы. Кроме того, это позволяет сделать код более лаконичным. Утилита MOC ищет в заголовочных файлах на ```C++``` описания классов, содержащие макрос ```Q_OBJECT```, и создаёт дополнительный исходный файл на ```C++```, содержащий метаобъектный код. 
Главным достоинством этого фреймворка является кроссплатформенность.

<a name="libraries"></a>  
#### Библиотеки

+ [STL](#stl)
+ [Boost](#boost)
+ [Curl](#curl)
+ Планируется добавление еще 2 библиотек (для работы с лексемами и русским языком)

<a name="stl"></a>  
##### STL

Стандартная библиотека шаблонов в языке ```C++```. Используется для работы с авлгоритмами, строками, векторами, отображениями и многими иными необходимыми структурами данных. 

<a name="boost"></a>  
##### BOOST

Boost - собрание библиотек классов, использующих функциональность языка ```C++``` и предоставляющих удобный кроссплатформенный высокоуровневый интерфейс для лаконичного кодирования различных повседневных подзадач программирования (работа с данными, алгоритмами, файлами, потоками и т.п.). 
Из библиотеки Boost мы использовали следующее:

* Boost.Asio

Многие думают, что данная библиотека необходима только для работы с сетью. Но они ошибаются. Она прекрасно подходит для "общения" между устройствами (например, платой и компьютером). 

Если коротко, Boost.Asio это, большей частью, кросс-платформенная С++ библиотека для программирования сетей и некоторых других низкоуровневых программ ввода/вывода. 
Есть много реализаций для решения сетевых задач, но Boost.Asio превзошел их все; он был принят в Boost в 2005 и с тех пор был протестирован большим количеством пользователей Boost, используется во многих проектах, таких как:

* Remobo - позволяет вам создавать собственную IPN
* libtorrent - является библиотекой, которая реализует Bittorrent клиент
* PokerTH - представляет собой игру в покер с поддержкой LAN и Internet

Кроме этого вы можете делать input или output программирование синхронным или асинхронным:

```c++
read(stream, buffer [, extra options]) 
async_read(stream, buffer [, extra options], handler)
write(stream, buffer [, extra options])
async_write(stream, buffer [, extra options], handler)
```

Boost.Asio успешно абстрагирует понятия input и output, которые работают не только для работы в сети, но и для последовательных COM-портов, файлов и так далее.

* Boost.property_tree    

В Boost начиная с версии 1.41.1 появилась библиотека Property Tree. Эта библиотека предоставляет новый тип данных, древовидную структуру boost::propetry_tree::ptree.

ptree это обычная древовидная структура, каждый элемент которой, помимо данных, может содержать упорядоченный список дочерних элементов, каждый из которых имеет свое имя.

Структура выглядит так:
```c++
struct ptree
{
   data_type data;                         // Данные элемента
   list<pair<key_type, ptree>> children;   // упорядочненный список дочерних элементов
};
```

В основном в качестве key_type используется обычная строка. Структура ptree очень удобна для чтения, записи, сохранения и загрузки древовидных данных. 

В качестве парсера ```json``` и ```xml``` файлов - использовали ```<boost/property_tree/json_parser.hpp>``` и ```<boost/property_tree/xml_parser.hpp>``` соответственно. Данные библиотеки отлично работают со структурой property_tree, из которой легко потом получать необходимые данные. 

<a name="curl"></a>  
##### Curl

```libcurl``` - это свободная и простая в использовании клиентская библиотека по передачи данных по URL, она поддерживает DICT, FILE, FTP, FTPS, GOPHER, HTTP, HTTPS, IMAP, IMAPS, LDAP, LDAPS, POP3, POP3S, RTMP, RTSP, SCP, SFTP, SMTP, SMTPS, TELNET и TFTP. Также libcurl имеет поддержку SSL сертификатов, HTTP POST, HTTP PUT, FTP загрузку, HTTP form загрузку, proxy, cookies, user+password авторизацию (Basic, Digest, NTLM, Negotiate, Kerberos), докачивания файлов, http прокси туннелирования и многого другого.

```libcurl``` легко переносима, она собирается и работает на многих платформах, включая Solaris, NetBSD, FreeBSD, OpenBSD, Darwin, HPUX, IRIX, AIX, Tru64, Linux, UnixWare, HURD, Windows, Amiga, OS/2, BeOs, Mac OS X, Ultrix, QNX, OpenVMS, RISC OS, Novell NetWare, DOS и остальные.

```libcurl``` свободна, потокобезопасна, совместима с IPv6, функциональна, имеет хорошую поддержку, быстрая, тщательно задокументирована и уже используется во многих известных, крупных и успешных компаний и в многочисленных приложениях.

В нашем случае - по протоколу HTTP отправляются запросы к серверу ```Yandex SpeechKitCloud```. 

<a name="diagrams"></a>  
## UML-диаграммы

Представлена общая схема проекта:

![J.A.R.V.I.S. brain](/docs/UML1.png)

Ниже Вы можете увидеть диаграмму классов (```По мере добавления будет меняться```):

![J.A.R.V.I.S. brain](/docs/UML3.png)

Рассмотрим поподробнее схему общения системы ```J.A.R.V.I.S.``` с сервером ```Yandex SpeechKitCloud```:

[J.A.R.V.I.S. brain](/docs/UML2.png)
