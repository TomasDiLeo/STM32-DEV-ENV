![Logo of the project](imagenes/untref_logo.jpg)
# STM32-DEV-ENV

Este repositorio contiene una plantilla de proyecto para programa el entorno de desarrollo provisto por la catedra de Electronica de la UnTref. 

Este proyecto esta pensado para el desarrollo de aplicaciones bajo el IDE STM32CubeIDE y se basa en las siguientes características:

| MCU reference                     | STM32F103C6Tx          |
| --------------------------------- | ---------------------- |
| Firmware Package name and version | STM32Cube FW_F1 V1.8.6 |

![[imagenes/pin_cfg.png]]
Referencia de pines detallada en la inicialización de pines en main.c
## Importar proyecto

Para importar el proyecto solo es necesario indicar el directorio del proyecto dentro de la opción de importar proyecto existente de STM32CubeIDE.

![[imagenes/import.png]]
## Desarrollo



## Building



## Características

### LCD_NH
Helper provisto por la catedra para manejar operaciones con el display LCD, este paquete esta pensado para el entorno de desarrollo especifico de este proyecto y no va a funcionar en otro entorno de manera nativa.

* Funciones:

| Funcion                        | Uso                                                |
| ------------------------------ | -------------------------------------------------- |
| lcd_init ();                   | Inicializa el display LCD                          |
| lcd_clear ();                  | Borra todo el contenido del display                |
| lcd_put_cur(Row, Col);         | Posiciona el cursor en (Row, Col)                  |
| lcd_send_string("HOLA MUNDO"); | Envía un string a mostrar                          |
| send_lcd_ASCII (238);          | Envía un carácter a mostrar bajo el estándar ASCII |
* Comandos:

Este paquete incluye una función para enviar comandos útiles para controlar el display LCD

```C
lcd_send_cmd(COMANDO EN HEX)
```

| Comando en HEX | Uso                             | KEYWORD           |
| -------------- | ------------------------------- | ----------------- |
| 0x02           | Posiciona el cursor en (0,0)    | HOME              |
| 0x00           | Apaga el display                | DISP_OFF          |
| 0x08           | Prende el display               | DISP_ON           |
| 0x0C           | CURSOR OFF ; BLINK OFF          | CUR_OFF_BLINK_OFF |
| 0x0E           | CURSOR ON ; BLINK OFF           | CUR_ON_BLINK_OFF  |
| 0x0D           | CURSOR OFF ; BLINK ON           | CUR_OFF_BLINK_ON  |
| 0x0F           | CURSOR ON ; BLINK ON            | CUR_ON_BLINK_ON   |
| 0x06           | Position right ; Display Fix    | POS_R_DFIX        |
| 0x04           | Position left ; Display Fix     | POS_L_DFIX        |
| 0x07           | Position right ; Cursor Fix     | POS_R_CFIX        |
| 0x05           | Position left ; Cursor Fix      | POS_L_CFIX        |
| 0x10           | Mueve el cursor a la izquierda  | MOV_CUR_LEFT      |
| 0x14           | Mueve el cursor a la derecha    | MOV_CUR_RIGHT     |
| 0x18           | Mueve el display a la izquierda | MOV_DISP_LEFT     |
| 0x1C           | Mueve el display a la derecha   | MOV_DISP_RIGHT    |

### CLOCK
Helper hecho por el alumno, Tomás Di Leo, para controlar las operaciones de reloj referidos a fecha y hora.


## Links

- Repository: https://github.com/TomasDiLeo/STM32-DEV-ENV
- Issue tracker: https://github.com/TomasDiLeo/STM32-DEV-ENV/issues
- Contacto
  tomasjdle@gmail.com

## Licencia 

The code in this project is licensed under [MIT license](https://mit-license.org/)