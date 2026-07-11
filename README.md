**Juego de adivinar el número**
**Escuela Politécnica Nacional** 
**Integrantes:**
* Kaya Alfusi
* Mónica Caiza
* Tifanny Pillajo
**Curso** : GR1CD

## 1. Descripción del Proyecto
Este proyecto consiste en la evolución e ingeniería de un software de entretenimiento y lógica matemática desarrollado en C++ para la consola de comandos. El sistema centraliza una suite de tres retos interactivos de adivinanza numérica, gestionados a través de un menú principal persistente y robusto. 
Esta iteración implementa un salto cualitativo hacia la **programación estructurada avanzada y defensiva**, incorporando modularidad estricta, el uso de arreglos, manipulación de memoria mediante el paso de parámetros por referencia, y un subsistema de persistencia física de datos a través del manejo de archivos (.txt).

---
##  2. Descripción de la Lógica y Estructuras Avanzadas

### Uso de Condicionales (`if`, `else if`, `else`)
Estas estructuras lógicas operan como los elementos de bifurcación y toma de decisiones del software, permitiendo:
- Comparar los valores ingresados por los usuarios frente al número objetivo generado de forma pseudoaleatoria por la computadora.
- Proveer retroalimentación interactiva indicando si el objetivo es más alto o más bajo.
- Evaluar instantáneamente el estado del flujo de entrada de datos estándar, detectando inserciones de caracteres alfabéticos inválidos para neutralizar bloqueos del sistema.
- Resolver escenarios de victoria por acierto numérico, derrota por agotamiento de recursos (vidas) o empates técnicos en la modalidad competitiva.

### Uso de Bucles 
* **`do-while`**: Implementado estratégicamente en el menú principal y en los submódulos de selección de nivel. Su naturaleza garantiza que las interfaces y solicitudes se rendericen al menos una vez, manteniendo el sistema activo hasta que se ingrese de forma explícita la opción de salida (`5`).
* **`while`**: Utilizado para gobernar el núcleo del bucle de juego interactivo en los turnos. Permite la ejecución continua de intentos mientras el jugador cuente con vidas disponibles o hasta que se resuelva el acertijo. También se emplea para la lectura secuencial de los registros históricos dentro de los archivos de texto línea por línea.
* **`for`**: Aplicado para la automatización de procesos repetitivos por lotes. Se utiliza para recorrer y poblar arreglos de almacenamiento de datos, inicializar los nombres de los jugadores concurrentes en arreglos estáticos, y renderizar visualmente las vidas en la pantalla mediante caracteres simbólicos (`*`).

### Aplicación de funciones.
El código se organiza mediante subprogramas especializados con responsabilidades únicas.
* **`mostrarMenu()` y `limpiarEntrada()`**: Encargados exclusivos de la gestión del entorno visual básico de la terminal y de la desinfección electrónica del buffer del teclado.
* **`seleccionarRango()`**: Centraliza la lógica de validación matemática y la asignación de fronteras de juego.
* **`ejecutarTurno()`**: Módulo dinámico que gobierna el juego de un jugador de manera aislada, recibiendo parámetros numéricos y pasando variables por referencia.
* **`mostrarHistorial()`**: Implementa lógica de travesía sobre arrays para imprimir el camino exacto de aproximación del usuario.
* **`guardarHistorialEnTXT()` y `mostrarHistorialCompletoTXT()`**: Administran la pasarela de persistencia secundaria abriendo y cerrando canales físicos de comunicación con el disco duro.

---
## 3. Detalle Estructurado de los Retos
### Reto 1 – Modo 1 vs 1 
En esta modalidad, dos competidores registran sus identidades en el sistema y se enfrentan secuencialmente a números secretos independientes generados de forma pseudoaleatoria. A diferencia de la versión previa donde el código estaba duplicado, ahora el sistema utiliza un único módulo reutilizable (`ejecutarTurno`). 
El programa registra las secuencias exactas de juego de cada participante y, al concluir ambos turnos, analiza matemáticamente el rendimiento guardado en un arreglo de intentos para declarar de manera exacta al ganador o un empate.

### Reto 2 – Niveles y Vidas 
El jugador se enfrenta a una escala de cinco dificultades (Desde "Muy Fácil" hasta "Muy Difícil"). La lógica del programa erradica las cadenas ineficientes de condicionales anidados utilizando arreglos estáticos paralelos indexados numéricamente:
* Un arreglo define los límites numéricos máximos del juego (`{10, 25, 50, 75, 100}`).
* Otro arreglo define los recursos de vidas asignados al jugador (`{3, 5, 7, 10, 12}`).
  
Al seleccionar el nivel, el programa accede instantáneamente por índice a las dos colecciones. El juego deduce vidas por cada intento fallido y asiste al usuario con alertas de proximidad graduadas ("Más alto", "Muchísimo más alto", etc.).

### Reto 3 – El Adivino Digital 
Se invierten los roles lógicos: el operador humano retiene mentalmente un número dentro del rango seleccionado y la computadora asume el rol activo de adivinación. Para garantizar la máxima eficiencia informática, la máquina implementa el algoritmo de **búsqueda binaria**, calculando algebraicamente el punto medio del espacio de búsqueda en cada paso para descartar la mitad de las opciones posibles de manera sistemática. 

El usuario retroalimenta al software mediante comandos numéricos para indicarle si su intento es mayor, menor o correcto. Como mejora defensiva, el bucle incluye un diagnóstico de quiebre de fronteras lógicas: si el usuario introduce pistas contradictorias o falsas que provoquen un cruce entre el límite inferior y superior, la computadora detiene la ejecución del juego y notifica una anomalía en la auditoría.

---
## 4. El Subsistema de Persistencia Física.
Se integro flujos de entrada y salida mediante la biblioteca `<fstream>`.
Al culminar cualquier partida de los tres retos descritos, los datos de la sesión (nombre del jugador, rango de juego, número secreto, cantidad de intentos y la secuencia exacta cronológica de números ingresados) son guardados en el archivo  `historial_partidas.txt`. La apertura del archivo se realiza bajo la modalidad de persistencia aditiva (`ios::app`), lo que garantiza que los nuevos datos se anexen ordenadamente al final del documento sin alterar, corromper o borrar las partidas jugadas con anterioridad. El usuario puede consultar este historial completo en cualquier momento desde la opción `4` del menú principal.

---
## 5. Conclusiones
Se consolidó con éxito la aplicación práctica de condicionales anidados y bucles de control de flujos (`for`, `while`, `do-while`), logrando un programa altamente interactivo en consola.
La modularización mediante funciones específicas y el paso de parámetros optimizado por referencia redujo drásticamente el tamaño del código monolítico original, eliminando la duplicación de datos y mejorando la legibilidad general.
La incorporación de rutinas de programación defensiva inmunizó al software contra errores típicos de ingreso de datos por parte del usuario, previniendo ciclos infinitos y bloqueos lógicos.
La integración de canales de archivos externos resolvió la volatilidad del software, permitiendo llevar un registro transparente e imborrable del rendimiento de los usuarios.
