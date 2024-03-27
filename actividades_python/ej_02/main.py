from gpiozero import LED
from time import sleep

# Importo LED para reconocerlo, e importo sleep de time

led_rojo = LED(19)
led_azul = LED(26)
led_verde = LED(13)

# le asigno a los leds (azul, rojo y verde) una variable a cada uno

while True:
	led_rojo.on()
	sleep(1)
	led_rojo.off()
	led_azul.on()
	sleep(0.5)
	led_azul.off()
	led_verde.on()
	sleep(0.25)
	led_verde.off()

# prendo el led rojo, pauso el programa por 1 segundo, apago el led 
# y prendo el siguiente, asi en bucle
