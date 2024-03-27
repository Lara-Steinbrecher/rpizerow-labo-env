from gpiozero import LED, Button
from signal import pause

# Importo de la libreria gpiozero  LED y Buttom
# De signal importo pause, solo para usar estas funciones, por que la
# liberia completa no es requerida

led = LED(26)
button = Button(18)

# Creo variables a las que les asigno el gpio del led
# y del boton respectivamente

button.when_pressed = led.on
button.when_released = led.off

# Cuando el boton esta apretado, el led se va a prender
# Cuando el boton deja de estar apretado, el led se va a apagar

pause()

