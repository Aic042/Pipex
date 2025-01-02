# Pipex
# Pipex

Este repositorio contiene la implementación del proyecto **Pipex** de 42 School. El objetivo es entender el funcionamiento de los pipes en Unix, conectando la salida de un comando con la entrada de otro. Aquí encontrarás todo lo necesario para comprender y ejecutar el proyecto, incluyendo ejemplos prácticos y explicaciones detalladas.

---

## Índice
1. [Introducción](#introducción)
2. [Requisitos del proyecto](#requisitos-del-proyecto)
3. [Cómo funciona Pipex](#cómo-funciona-pipex)
4. [Uso del programa](#uso-del-programa)
   - [Ejemplo básico](#ejemplo-básico)
   - [Errores comunes](#errores-comunes)
5. [Parte bonus](#parte-bonus)
6. [Compilación y ejecución](#compilación-y-ejecución)
7. [Recursos y enlaces](#recursos-y-enlaces)

---

## Introducción
El proyecto **Pipex** busca replicar la funcionalidad del siguiente comando shell:

```bash
< archivo1 comando1 | comando2 > archivo2
```

El objetivo principal es profundizar en conceptos como:
- Procesos y manejo de pipes.
- Redirección de entrada/salida.
- Creación de procesos con `fork`.
- Ejecución de comandos con `execve`.

---

## Requisitos del proyecto
Para superar este proyecto, debes cumplir con las siguientes condiciones:

- Implementar el programa en **C** siguiendo la **Norma** de 42.
- Gestionar correctamente los errores.
- Evitar fugas de memoria.
- Proveer un **Makefile** que compile el proyecto con las flags `-Wall -Werror -Wextra`.
- Utilizar únicamente las siguientes funciones:
  - `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`.

---

## Cómo funciona Pipex
Tu programa debe aceptar los siguientes argumentos:

```bash
./pipex archivo1 comando1 comando2 archivo2
```

- **`archivo1`**: Archivo de entrada.
- **`comando1`**: Primer comando a ejecutar.
- **`comando2`**: Segundo comando a ejecutar.
- **`archivo2`**: Archivo de salida.

Por ejemplo:
```bash
./pipex infile "ls -l" "wc -l" outfile
```

Debería comportarse como:
```bash
< infile ls -l | wc -l > outfile
```

---

## Uso del programa
### Ejemplo básico
Para ejecutar Pipex con un archivo de entrada y salida:

```bash
./pipex input.txt "grep error" "wc -l" output.txt
```

### Errores comunes
- **Archivo no encontrado**: Asegúrate de que `archivo1` existe.
- **Comando inválido**: Revisa que los comandos sean válidos y estén en tu `$PATH`.
- **Permisos insuficientes**: Verifica los permisos de lectura/escritura en los archivos.

---

## Parte bonus
El bonus incluye:
- **Múltiples pipes**: Permitir varios comandos encadenados.
- **Here documents**: Implementar funcionalidad para:

```bash
./pipex here_doc LIMITADOR comando comando1 archivo
```

---

## Compilación y ejecución
Para compilar el proyecto, utiliza el **Makefile** incluido:

```bash
make
```

Esto generará el ejecutable `pipex`. Para limpiar los archivos compilados:

```bash
make clean
```

Para eliminar todo con los .o incluido:

make fclean
```

---

## Recursos y enlaces
- [Manuales de funciones permitidas](https://man7.org/linux/man-pages/)
- [Introducción a pipes en Unix](https://www.geeksforgeeks.org/pipe-system-call/)
- [Norma de 42](https://github.com/42School/norminette)

---

**Autor:** [Chatgpt me esta ayudando mucho pero soy, el autor, Álvaro]

