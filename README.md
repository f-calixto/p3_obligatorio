# Obligatorio - Programación III (Curso 2026)

Este proyecto consiste en el diseño e implementación de un sistema de gestión académica para la Universidad, enfocado en el manejo eficiente de planes de estudio, asignaturas, alumnos e historiales de escolaridad utilizando Estructuras de Datos Avanzadas.

## 🛠️ Modelado y Estructuras Utilizadas

El sistema fue descompuesto en componentes modulares, seleccionando los Tipos Abstractos de Datos (TAD) y estructuras más eficientes para cada objeto de la realidad:

* **Materias:** Modelado como un **TAD Diccionario** e implementado mediante un **Mapeo**, aprovechando que los códigos de las asignaturas son números naturales consecutivos para obtener búsquedas en tiempo constante $O(1)$.
* **Alumnos:** Modelado como un **TAD Diccionario** e implementado con una **Tabla de Hash**, utilizando la cédula de identidad como clave única para búsquedas y accesos directos de alta eficiencia.
* **Escolaridad:** Modelado como un **TAD Secuencia** e implementado mediante una **Lista con Puntero al Principio y Puntero al Final (LPPF)**, optimizando la inserción cronológica de nuevas materias al final del historial en $O(1)$.
* **Previaturas:** Modelado mediante un **Grafo Dirigido Acíclico** e implementado con una **Matriz de Adyacencia**, debido a la alta densidad de aristas (relaciones estrictas de previaturas) del plan de estudios, garantizando accesos instantáneos $O(1)$.

## 🚀 Requisitos e Instalación

Para compilar y ejecutar este proyecto de forma local, se requiere un entorno compatible con C++ (como **Code::Blocks**)

