# Filas feitas com as seguintes estruturas:

* Array (Fila básica)
* Ponteiro (Fila com redimensionamento)
* Struct (Fila encadeada circular)

## Como compilar e executar:

### Para usar a fila estatica:

* descomentar 

```
#include "fila_estatica_int.h"
//#include "fila_continua_int.h"
//#include "fila_lista_encadeada_circular_int.h"
```
* compilar

```
gcc -o prog fila_estatica_int.c main.c
```

### Para usar a fila continua:

* descomentar 

```
//#include "fila_estatica_int.h"
#include "fila_continua_int.h"
//#include "fila_lista_encadeada_circular_int.h"
```
* compilar

```
gcc -o prog fila_continua_int.c main.c
```

### Para usar a fila encadeada:

* descomentar 

```
//#include "fila_estatica_int.h"
//#include "fila_continua_int.h"
#include "fila_lista_encadeada_circular_int.h"
```
* compilar

```
gcc -o prog fila_lista_encadeada_circular_int.c main.c
```

### Para executar todos:

```
./prog
```