import signal
import sys
import time
import RPi.GPIO as GPIO

BUTTON_GPIO = 16
LED_GPIO = 20
should_blink = False

def signal_handler(sig, frame):
    GPIO.cleanup()
    sys.exit(0)

def button_released_callback(channel):
    global should_blink
    should_blink = not should_blink

if __name__ == '__main__':
    GPIO.setmode(GPIO.BCM)

    GPIO.setup(BUTTON_GPIO, GPIO.IN, pull_up_down=GPIO.PUD_UP)
    GPIO.setup(LED_GPIO, GPIO.OUT)
    GPIO.add_event_detect(BUTTON_GPIO, GPIO.RISING, callback=button_released_callback, bouncetime= 200)

    signal.signal(signal.SIGINT,signal_handler)

    while True:
        if should_blink:
            GPIO.output(LED_GPIO,GPIO.HIGH)
        time.sleep(0.5)
        if should_blink:
            GPIO.output(LED_GPIO, GPIO.LOW)
        time.sleep(0.5)
