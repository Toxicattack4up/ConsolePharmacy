# Система управления аптекой

## Описание

Система управления аптекой предназначена для управления лекарствами, сотрудниками и продажами в аптеке. Она позволяет администратору добавлять и удалять лекарства, а также добавлять и удалять сотрудников. Сотрудники могут просматривать рецепты и добавлять продажи.

## Структура классов

1. **Класс `User`**:
   - **Описание**: Абстрактный базовый класс для всех пользователей системы.
   - **Поля**:
     - `username`: Имя пользователя.
     - `password`: Хешированный пароль.
     - `type`: Тип пользователя (администратор или сотрудник).
   - **Методы**:
     - `getUsername()`: Возвращает имя пользователя.
     - `getPassword()`: Возвращает хешированный пароль.
     - `checkPassword(const std::string& password)`: Проверяет введенный пароль с хешированным.
     - `setType(const std::string& type)`: Устанавливает тип пользователя.
     - `getType()`: Возвращает тип пользователя.
     - `displayInfo()`: Абстрактный метод для отображения информации о пользователе.

2. **Класс `Administrator`**:
   - **Описание**: Класс администратора, наследующий от `User`.
   - **Поля**:
     - `medicineStorage`: Хранилище лекарств.
     - `employees`: Вектор сотрудников.
   - **Методы**:
     - `addMedicine()`: Добавляет новое лекарство.
     - `removeMedicine()`: Удаляет лекарство.
     - `displayAllMedicines()`: Отображает все лекарства.
     - `addEmployee()`: Добавляет нового сотрудника.
     - `removeEmployee()`: Удаляет сотрудника.
     - `displayAllEmployees()`: Отображает всех сотрудников.
     - `getMedicineStorage()`: Возвращает хранилище лекарств.
     - `displayInfo()`: Отображает информацию о администраторе.

3. **Класс `Employee`**:
   - **Описание**: Класс сотрудника, наследующий от `User`.
   - **Поля**:
     - `position`: Должность сотрудника.
     - `salary`: Зарплата сотрудника.
   - **Методы**:
     - `getPosition()`: Возвращает должность сотрудника.
     - `setPosition(const std::string& newPosition)`: Устанавливает новую должность сотрудника.
     - `getSalary()`: Возвращает зарплату сотрудника.
     - `setSalary(double newSalary)`: Устанавливает новую зарплату сотрудника.
     - `displayInfo()`: Отображает информацию о сотруднике.

4. **Класс `Medicine`**:
   - **Описание**: Класс лекарства.
   - **Поля**:
     - `name`: Название лекарства.
     - `manufacturer`: Производитель лекарства.
     - `price`: Цена лекарства.
     - `stockQuantity`: Количество на складе.
     - `expirationDate`: Срок годности.
     - `prescriptionRequired`: Требуется ли рецепт для лекарства.
   - **Методы**:
     - `getName()`: Возвращает название лекарства.
     - `setName(const std::string& newName)`: Устанавливает новое название лекарства.
     - `getPrice()`: Возвращает цену лекарства.
     - `setPrice(double newPrice)`: Устанавливает новую цену лекарства.
     - `getStockQuantity()`: Возвращает количество на складе.
     - `updateStock(int amount)`: Обновляет количество на складе.
     - `isExpired()`: Проверяет, истек ли срок годности лекарства.
     - `isPrescriptionRequired()`: Проверяет, требуется ли рецепт для лекарства.
     - `setPrescriptionRequired(bool required)`: Устанавливает, требуется ли рецепт для лекарства.
     - `displayInfo()`: Отображает информацию о лекарстве.
     - `getManufacturer()`: Возвращает производителя лекарства.
     - `getExpirationDate()`: Возвращает срок годности лекарства.

5. **Класс `Customer`**:
   - **Описание**: Класс клиента.
   - **Поля**:
     - `name`: Имя клиента.
     - `phoneNumber`: Номер телефона клиента.
     - `address`: Адрес клиента.
   - **Методы**:
     - `getName()`: Возвращает имя клиента.
     - `setName(const std::string& newName)`: Устанавливает новое имя клиента.
     - `getPhoneNumber()`: Возвращает номер телефона клиента.
     - `setPhoneNumber(const std::string& newPhoneNumber)`: Устанавливает новый номер телефона клиента.
     - `displayInfo()`: Отображает информацию о клиенте.

6. **Класс `Prescription`**:
   - **Описание**: Класс рецепта.
   - **Поля**:
     - `prescriptionID`: Идентификатор рецепта.
     - `customer`: Клиент, которому выдан рецепт.
     - `medicines`: Вектор лекарств, указанных в рецепте.
     - `doctorName`: Имя врача, выдавшего рецепт.
     - `issueDate`: Дата выдачи рецепта.
   - **Методы**:
     - `addMedicine(const Medicine& medicine)`: Добавляет лекарство в рецепт.
     - `removeMedicine(const std::string& medicineName)`: Удаляет лекарство из рецепта.
     - `displayPrescription()`: Отображает информацию о рецепте.

7. **Класс `Sale`**:
   - **Описание**: Класс продажи.
   - **Поля**:
     - `itemsSold`: Вектор пар, состоящий из лекарства и количества проданного лекарства.
     - `customer`: Клиент, совершающий покупку.
     - `totalPrice`: Общая сумма продажи.
     - `logger`: Логгер для записи действий.
   - **Методы**:
     - `addItem(Medicine& medicine, int quantity)`: Добавляет лекарство в продажу.
     - `calculateTotalPrice()`: Вычисляет общую сумму продажи.
     - `displayReceipt()`: Отображает квитанцию о продаже.

8. **Класс `Logger`**:
   - **Описание**: Класс для логирования действий в системе.
   - **Поля**:
     - `logFile`: Файл для записи логов.
   - **Методы**:
     - `log(const std::string& message)`: Записывает сообщение в лог файл.

9. **Класс `MedicineStorage`**:
   - **Описание**: Класс для хранения и управления лекарствами и сотрудниками.
   - **Поля**:
     - `medicines`: Вектор лекарств.
     - `employees`: Вектор сотрудников.
   - **Методы**:
     - `addMedicine(const Medicine& medicine)`: Добавляет лекарство.
     - `removeMedicine(const std::string& name)`: Удаляет лекарство.
     - `displayAllMedicines()`: Отображает все лекарства.
     - `getMedicines()`: Возвращает вектор лекарств.
     - `saveToFile()`: Сохраняет лекарства и сотрудников в файлы.
     - `getEmployees()`: Возвращает вектор сотрудников.
     - `loadEmployees()`: Загружает сотрудников из файла.
     - `removeEmployee(const std::string& username)`: Удаляет сотрудника.

10. **Класс `Utils`**:
    - **Описание**: Вспомогательные функции.
    - **Методы**:
      - `hashPassword(const std::string& password)`: Хеширует пароль.
      - `splitString(const std::string& str, char delimiter)`: Разделяет строку по заданному разделителю.

## Функции программы

1. **Администратор**:
   - Добавление и удаление лекарств.
   - Просмотр всех лекарств.
   - Добавление и удаление сотрудников.
   - Просмотр всех сотрудников.

2. **Сотрудник**:
   - Добавление продаж.
   - Просмотр рецептов.
   - Просмотр всех лекарств.

3. **Хеширование паролей**:
   - Пароли сотрудников хранятся в зашифрованном виде в файле `employees.txt`.

4. **Логирование**:
   - Все действия (вход в систему, добавление продаж, просмотр рецептов) логируются в файл `log.txt`.

5. **Сохранение данных**:
   - Лекарства сохраняются в файл `medicines.txt`.
   - Сотрудники сохраняются в файл `employees.txt`.

## Структура проекта

## Структура проекта
pharmacy_management_system/
├── CMakeLists.txt
├── main.cpp
├── Medicine.h
├── Medicine.cpp
├── Customer.h
├── Customer.cpp
├── Prescription.h
├── Prescription.cpp
├── Employee.h
├── Employee.cpp
├── Administrator.h
├── Administrator.cpp
├── Sale.h
├── Sale.cpp
├── User.h
├── User.cpp
├── utils.h
├── utils.cpp
├── logger.h
├── logger.cpp
├── medicine_storage.h
└── medicine_storage.cpp


## Как работает программа

1. **Запуск программы**:
   - При запуске программы пользователь видит главное меню с возможностью входа как администратор или сотрудник.

2. **Вход как администратор**:
   - Введите имя пользователя и пароль администратора (`admin`, `adminpass`).
   - После успешного входа откроется меню администратора с различными опциями.

3. **Вход как сотрудник**:
   - Введите имя пользователя и пароль сотрудника.
   - После успешного входа откроется меню сотрудника с различными опциями.

4. **Добавление лекарства**:
   - В меню администратора выберите пункт "Добавить лекарство".
   - Введите название, производителя, цену, количество на складе, срок годности и информацию о необходимости рецепта.

5. **Удаление лекарства**:
   - В меню администратора выберите пункт "Удалить лекарство".
   - Введите название лекарства для удаления.

6. **Просмотр всех лекарств**:
   - В меню администратора или сотрудника выберите пункт "Показать все лекарства".

7. **Добавление сотрудника**:
   - В меню администратора выберите пункт "Добавить сотрудника".
   - Введите имя пользователя, пароль, должность и зарплату.

8. **Удаление сотрудника**:
   - В меню администратора выберите пункт "Удалить сотрудника".
   - Введите имя пользователя сотрудника для удаления.

9. **Просмотр всех сотрудников**:
   - В меню администратора выберите пункт "Показать всех сотрудников".

10. **Добавление продажи**:
    - В меню сотрудника выберите пункт "Добавить продажу".
    - Выберите лекарства и их количество для добавления в продажу.
    - Если лекарство требует рецепта, программа запросит подтверждение наличия рецепта.

11. **Просмотр рецепта**:
    - В меню сотрудника выберите пункт "Просмотреть рецепт".

12. **Выход**:
    - В любой момент можно выйти из текущего меню, выбрав соответствующий пункт.

## Как собрать проект

### Использование CMake

1. **Установка CMake**:
   - Скачайте и установите CMake с официального сайта: [CMake Download](https://cmake.org/download/).

2. **Создание директории для сборки**:
   - Создайте новую директорию для сборки проекта, например, `build`.

3. **Генерация файлов сборки**:
   - Откройте командную строку и перейдите в директорию `build`.
   - Запустите команду для генерации файлов сборки:
     ```sh
     cmake ..
     ```

4. **Сборка проекта**:
   - Запустите команду для сборки проекта:
     ```sh
     cmake --build .
     ```

5. **Запуск программы**:
   - После сборки программа будет находиться в директории `build`.
   - Запустите программу:
     ```sh
     ./pharmacy_management_system
     ```

### Использование Visual Studio 2022

1. **Создание нового проекта**:
   - Запустите Visual Studio 2022.
   - Выберите `File` -> `New` -> `Project from Existing Code`.
   - Выберите тип проекта `CMake` и укажите путь к вашей папке проекта (`pharmacy_management_system`).

2. **Настройка CMake**:
   - После создания проекта Visual Studio автоматически обнаружит файл `CMakeLists.txt` и начнёт процесс конфигурации.
   - Выберите желаемую конфигурацию (например, `x64-Debug` или `x64-Release`).

3. **Сборка проекта**:
   - Нажмите `Build` -> `Build All` или используйте сочетание клавиш `Ctrl+Shift+B` для сборки проекта.
   - Если сборка прошла успешно, запустите программу через `Debug` -> `Start Without Debugging` или `F5` для запуска с отладкой.

## Зависимости

- **CMake**: Для управления сборкой проекта.
- **Visual Studio 2022**: Для сборки и запуска проекта на Windows.
