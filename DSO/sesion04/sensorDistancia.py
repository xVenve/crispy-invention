import signal
import RPi.GPIO as GPIO
import time
import sys

# set GPIO Pins
pingTrigger = 18
pinEcho = 24


def close(signal, frame):
    print("\nTurning off ultrasonic distance detection...\n")
    GPIO.cleanup()
    sys.exit(0)


signal.signal(signal.SIGINT, close)

# set GPIO input and output chanels
GPIO.setmode(GPIO.BCM)
GPIO.setup(pingTrigger, GPIO.OUT)
GPIO.setup(pinEcho, GPIO.IN)

while True:
    # set Trigger to HIGH
    GPIO.output(pingTrigger, True)
    # set Trigger afete 0.01ms to LOW
    time.sleep(0.00001)
    GPIO.output(pingTrigger, False)

    startTime = time.time()
    stopTime = time.time()
    
    # save start time
    while 0 == GPIO.input(pinEcho):
        startTime = time.time()

    # save time of arrival
    while 1 == GPIO.input(pinEcho):
        stopTime = time.time()

    # time difference between start and arrival
    TimeElapse = stopTime - startTime
    # multiply with the sonic speec (34300 cm/s)
    # and divide by 2, because there and back
    distance = (TimeElapse * 34300) / 2

    print("Distance: %.1f cm" % distance)
    time.sleep(1)