# Sensor de pH con control de motores DC y LCD

Este proyecto consiste en un sensor de pH que controla dos motores DC en función del valor de pH detectado y muestra la información en una pantalla LCD 16x2.

## Funcionamiento

El sensor de pH está conectado a un pin analógico del microcontrolador. Se realiza una lectura del sensor, se promedia a partir de 10 lecturas y se convierte en un valor de pH. Este valor se muestra en la pantalla LCD junto con el voltaje de salida del sensor.

Si el valor de pH es inferior a 6.8, se activan los motores conectados a los pines correspondientes. Tras un periodo de tiempo, los motores se desactivan.

## Librerías

El código utiliza las siguientes librerías:
- `Wire.h`: Para la comunicación I2C.
- `LiquidCrystal_I2C.h`: Para controlar la pantalla LCD mediante I2C.

## Componentes

- Sensor de pH.
- modulo de reles
- Dos motores DC.
- Pantalla LCD 16x2.
- montaje físico

## Esquema de pines

- `ph_pin`: Pin analógico para la lectura del sensor de pH.
- `motor_1`: Pin de control para el primer motor DC.
- `motor_2`: Pin de control para el segundo motor DC.

## Constantes

- `ph_val_c1`: Constante para la calibración del sensor de pH.
- `ph_val_c2`: Constante para la calibración del sensor de pH.

## Autores

- Victor Rincón
- Miguel Cucanchon

- código elaborado por jmasmelac

## Instrucciones de uso

1. Encender el sistema.
2. Observar el valor de pH y el voltaje en la pantalla LCD.
3. Si el valor de pH es inferior a 6.8, se activarán los motores durante un tiempo determinado para realizar una acción específica.
4. Esperar a que los motores se desactiven.

## Notas

- Se pueden ajustar las constantes de calibración del sensor (`ph_val_c1` y `ph_val_c2`) según sea necesario.
- Se recomienda realizar pruebas adicionales para ajustar los tiempos de activación de los motores según las necesidades del proyecto.