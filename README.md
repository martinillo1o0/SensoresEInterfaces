🔐 Proyecto 1: Sistema de Seguridad con Sensor IR, Buzzer y LCD1602 (I2C)
📌 Descripción

En este proyecto se desarrolló un sistema básico de seguridad utilizando un sensor infrarrojo (IR), un buzzer y una pantalla LCD1602 con comunicación I2C. El objetivo fue simular un sistema de acceso mediante contraseña, brindando retroalimentación visual y auditiva al usuario.

⚙️ ¿Cómo funciona?

Al iniciar el sistema, la pantalla LCD muestra un mensaje de espera.

El sistema queda listo para recibir una contraseña definida en el código (1, 2, 3).

Si el usuario ingresa una contraseña incorrecta:

El buzzer emite un sonido fuerte.

La LCD muestra un mensaje de error.

Si la contraseña es correcta:

Se muestra un mensaje de bienvenida en la pantalla.

🧩 Componentes utilizados

Sensor IR

Buzzer

Pantalla LCD1602 (I2C)

Arduino (Uno / Nano / Mega)

🎯 Objetivo del proyecto

Simular un método básico de seguridad basado en contraseña, combinando sensores, actuadores y retroalimentación visual/sonora para comprender la interacción entre hardware y software.

🚀 Posibles mejoras

Guardar historial de intentos

Añadir temporizador de bloqueo

Integrar un teclado físico

Añadir conexión inalámbrica

<br><br>

🔐 Proyecto 2: Sistema de Acceso con Tarjeta, Teclado 4x4 y Servomotor
📌 Descripción

Este proyecto consiste en un sistema de control de acceso de doble autenticación, combinando la lectura de una tarjeta mediante sensor y un teclado matricial 4x4. Cuando el acceso es validado, un servomotor simula la apertura de una cerradura.

⚙️ ¿Cómo funciona?

El sistema espera la lectura de una tarjeta mediante un sensor.

Si la tarjeta es válida:

El sistema habilita el teclado matricial 4x4.

El usuario debe ingresar una contraseña usando el teclado.

Si la contraseña es correcta:

El servomotor gira simulando la apertura de una cerradura.

Si la contraseña es incorrecta:

Se bloquea el acceso o se puede mostrar un mensaje de error.

🧩 Componentes utilizados

Sensor de lectura de tarjeta (IR/RFID)

Teclado matricial 4x4

Servomotor (SG90 o similar)

Arduino (Uno / Nano / Mega)

🎯 Objetivo del proyecto

Implementar un sistema de seguridad con doble verificación, combinando lectura de tarjetas y contraseña, para simular un control de acceso similar al de sistemas reales.

🚀 Posibles mejoras

Implementar pantalla LCD para mensajes

Añadir buzzer para alertas

Registrar intentos fallidos

Integrar conexión a una base de datos
