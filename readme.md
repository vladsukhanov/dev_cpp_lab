# dev_cpp_lab

Это простой шаблонный проект на C++.
Проект использует **CMake** для управления сборкой.

## Требования

- **CMake** (минимальная версия 3.10)
- **MinGW** или **MSYS2** для использования Makefiles на Windows, или любая поддерживаемая среда для компиляции C++.

## Сборка проекта

### 1. Подготовка

- Убедитесь, что у вас установлен **CMake** и компилятор C++.
- Для сборки с использованием Makefiles на Windows рекомендуется установить **MinGW** или **MSYS2**.

### 2. Сборка с использованием CMake

1. Перейдите в корневой каталог проекта:

2. Создайте каталог для сборки:
    * `mkdir build`
    * `cd build`

3. Запустите CMake с указанием генератора:
    * `cmake -G "Unix Makefiles" ..`

4. Соберите проект: 
    * `make`
    * или `cmake --build .`

5. Запустите программу: 
    * `./sample_program.exe`

### 3. Очистка проекта

Для очистки проекта и удаления сгенерированных файлов выполните следующую команду:

Для удаления всех файлов:
    * `cd build`
    * `del /Q *.*`

Для удаления всех подкаталогов и файлов:
    * `cd build`
    * `rmdir /S /Q .`
    * или с использованием PowerShell:
        * `Remove-Item * -recurse -force`
        * или `ri * -recurse -force`

так как Remove-Item – это Alias
    * `Get-Alias -Definition Remove-Item`
        * Alias           del → Remove-Item
        * Alias           erase → Remove-Item
        * Alias           rd → Remove-Item
        * Alias           ri → Remove-Item
        * Alias           rm → Remove-Item
        * Alias           rmdir → Remove-Item

## Doxygen
    * создать Doxyfile
    * добавить имя проекта PROJECT_NAME
    * добавить выходную директорию OUTPUT_DIRECTORY
    * disable опцию GENERATE_LATEX = NO
    * запустить doxygen `doxygen .\Doxyfile`

## Tests & Coverage

### Запуск тестов

1. Перейдите в каталог сборки:
    * `cd build`

2. Запустите тесты с помощью CTest:
    * `ctest --output-on-failure`

### Проверка покрытия кода (Coverage)

1. Соберите проект с поддержкой покрытия (флаги `-fprofile-arcs -ftest-coverage` уже добавлены в CMakeLists.txt).
2. После запуска тестов выполните команду для генерации отчёта покрытия:

    * Для lcov (использовать MSYS2):
        * `cd /c/User/.../coverage_lcov`
        * `lcov --capture --directory . --output-file coverage.info --rc lcov_branch_coverage=1`
        * `genhtml coverage.info --output-directory coverage_report`

    * Для gcovr:
        * `cd coverage_gcovr`
        * `gcovr ../build -v -r ../source --html --html-details -o coverage.html`

3. Откройте файл `coverage_report/index.html` для просмотра отчёта покрытия в браузере.

**Примечание:** Для работы покрытия используйте компилятор GCC/MinGW. На MSVC покрытие не поддерживается.
