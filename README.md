# Лабораторные работы по программированию

**Лабараторная работа №8**
Необходимо разработать классы в соответствии с заданиями по вариантам. Классы должны быть обеспечены модульными тестами. Разработайте демонстрационную программу.
Разработайте классы, моделирующие работников с почасовой (класс I) и комиссионной оплатой труда (класс II). У каждого работника есть ФИО и пол. Добавьте в класс I метод Работать, в который передаётся количество часов, отработанных работником. Добавьте в класс II метод Продать, в который передаётся сумма, на которую были проданы товары. Объекты накапливают объёмы отработанных часов и суммы проданных товаров соответственно. Добавьте в оба класса метод Рассчитать зарплату, который обнуляет накопленный объём/сумму и возвращает зарплату к выплате работнику. Работник с почасовой оплатой труда получает фиксированную сумму за каждый час работы до некоторого нормативного значения, а потом увеличенную сумму за каждый час переработки. Работник с комиссионной оплатой труда получает фиксированный оклад, а также некоторый процент с продаж.

**Лабораторная работа №9**
Необходимо провести рефакторинг кода предыдущей лабораторной работы: определить базовые классы и построить иерархии наследования. Доработайте программу в соответствии с индивидуальным заданием. При работе с объектами одной иерархии классов вы должны пользоваться как можно более абстрактным классом из имеющихся, а поэтому и динамическим полиморфизмом. Разработайте демонстрационную программу.
Создайте класс предприятие с возможностью приема на работу и увольнения сотрудников. Добавьте метод МоделироватьРаботу, принимающий количество дней, в течение которых моделируется работа компании. Каждый сотрудник каждый день выполняет случайный объём работы. Два раза в месяц каждый сотрудник получает ЗП.


**Лабораторная работа №10**
Необходимо реализовать сериализацию объектов ваших классов из предыдущей лабораторной работы, т.е. их преобразование в поток (последовательность) байтов и обратно для возможности передачи по сети, записи в БД и т.д. В качестве формата можете использовать любой, например, JSON, XML, BSON, свой собственный.
