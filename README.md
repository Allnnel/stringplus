## Отчет по заданию "stringplus":



## Проект "stringplus"

Этот проект представляет собой разработку библиотеки функций для работы со строками в языке программирования C. Основная цель проекта заключается в создании набора функций, которые будут аналогичны функциям из стандартной библиотеки string.h, но реализованные с учетом современных стандартов и лучших практик программирования.

В частности, проект включает в себя следующие аспекты:

Реализация основных функций из библиотеки string.h, включая операции копирования, сравнения, поиска и манипуляций со строками.

Реализация функции sprintf, позволяющей форматировать и записывать данные в строку.

Дополнительная поддержка модификаторов и форматирования для sprintf.

Реализация функции sscanf для разбора строк с заданным форматом.

## Дополненная информация о запуске проекта:

Для сборки проекта используются флаги компиляции CFLAGS и LDFLAGS, которые включают опции -c, -Wall, -Werror и -Wextra для обработки предупреждений как ошибок, а также стандарт языка -std=c11.

Переменная SOURCE содержит список исходных файлов с префиксом s21_, а переменная OBJECTS формирует список объектных файлов.

В зависимости от операционной системы UNAME_S выбирается команда для открытия файлов, а также определяются дополнительные библиотеки и флаги компиляции.


Цель all компилирует и архивирует библиотеку s21_string.a.

Цель test собирает и запускает тесты, используя собранную библиотеку.

Цель leaks проверяет утечки памяти с помощью утилиты leaks.

Цель clean удаляет все временные файлы и папки, созданные в процессе сборки и тестирования.

Цель style форматирует код в стиле Google и проверяет его на наличие ошибок с помощью утилит clang-format и cppcheck.

Цель gcov_report генерирует отчет о покрытии кода тестами с использованием gcov и lcov.

Цель valgrind проверяет проект на утечки памяти и другие проблемы с помощью инструмента valgrind.




