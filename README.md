# energy-management-system
this is the repository for energy maneging system iot so (still under development)


#initalizing
BEGIN
  Import necessary libraries for WiFi and Blynk
  Define WiFi credentials and Blynk Auth Token
  Define sensor and relay pins
  Set up calibration constants for ACS712 sensor

  Connect ESP8266 to WiFi
  Connect to Blynk app

  Set relay pin as OUTPUT
  Set relay to OFF state (LOW)

  Start timer to repeatedly measure and send current data
END

 #main loop
LOOP
  Run Blynk connection
  Run the timer functions
END LOOP

 #current monitering function
FUNCTION sendCurrent:
  READ analog value from ACS712
  CONVERT analog value to voltage
  CALCULATE current using calibration formula
  SEND current value to Blynk virtual pin (V1)
END FUNCTION

#relay control via app
ON Blynk button press (V2):
  IF button state is ON
    SET relay pin HIGH (turn appliance ON)
  ELSE
    SET relay pin LOW (turn appliance OFF)
  END IF
END EVENT
