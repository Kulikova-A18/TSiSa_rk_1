# РК №1 ПО ПРЕДМЕТУ ТСИСА

для рк был подготовлен оптимальный код, где благодаря cmake можно выбрать тот метод который требуется для рк

фрагмент где нужно изменить на нужный метод:

CMakeLists.txt

```
#
# CHANGE METOD:
#
# passive search, method dichotomy, golden ratio, Fibonacci (lab 1)
# OR..
# random (lab 2)
#

#target_compile_definitions(TSiSa_RK_1 PRIVATE RANDOM)

#target_compile_definitions(TSiSa_RK_1 PRIVATE PASSIVE_SEARCH)
#target_compile_definitions(TSiSa_RK_1 PRIVATE DICHOTOMY)
#target_compile_definitions(TSiSa_RK_1 PRIVATE GOLDEN_RATIO)
target_compile_definitions(TSiSa_RK_1 PRIVATE FIBONACCI)
```

func.h

```
#define CONST_A -2
#define CONST_B 4

#define UNIMODAL_FUNCTION(x)\
    ((double)-cos(0.5 * x) - 1)
```

# запуск в vscode

создать и перенести launch.json в папку .vscode
