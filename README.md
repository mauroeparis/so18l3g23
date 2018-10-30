# Sistemas Operativos Laboratiorio 3

## Planificador original de xv6.

El planificador original de xv6, tomaba procesos del **process table**.

#### Planificar un proceso que duerme.

Un proceso que duerme tiene el estado de `SLEEP`, con un `wakeup(1)` cambiamos su estado a `RUNNABLE`.

#### Ejecutar un proceso planificable.

Le pasa el contexto del proceso al Scheduler, tomando el proceso de la **process table**  pasando su estado de `RUNNABLE` a `RUNNING`.

#### Replanificar un proceso.

Al proceso se le aplica un `yield()`, lo que le baja la prioridad (se le asigna un quanto más grande), y se vuelve a encolar como `RUNNABLE` y con su nueva prioridad.

#### Bloquear un proceso que espera I/O.

Al proceso se le aplica un `sleep()`, pasando el estado de `RUNNING` a `SLEEPING`.

## El nuevo planificador.

El nuevo Scheduler toma los procesos `RUNNABLE` del **buffer**, agregando una capa de abstracción encima de la **process table** con punteros a los procesos allí encontrados.

#### Planificar un proceso que duerme.

Un proceso que duerme tiene el estado de `SLEEPING`, con un `wakeup(1)` (o cualquier método que cambie un proceso a estado `RUNNABLE`) cambiamos su estado a `RUNNABLE`, en nuestro caso, además lo agregamos al **buffer**.

#### Ejecutar un proceso planificable.

Le pasa el contexto del proceso al Scheduler, tomando el proceso del **buffer** pasando su estado de `RUNNABLE` a `RUNNING`.

#### Replanificar un proceso.

Al proceso se le aplica un `yield()`, lo que le baja la prioridad (se le asigna un quanto mas grande), y se vuelve a encolar como `RUNNABLE`, en el **buffer** y con su nueva prioridad.
frutaflops &
#### Bloquear un proceso que espera I/O.

Al proceso se le aplica un `sleep()`, pasando el estado de `RUNNING` a `SLEEPING`.

## Comparaciones.
