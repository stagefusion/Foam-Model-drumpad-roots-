# Foam-Model-drumpad-roots-
Arduino code used to control the individually addressable LED strips used for The Dubstrument full sized foam model

In order to run 964 led pixels used in the foam model display, I had to split the code up into two different Arduinos.  One ran Root A, B, and one of the F holes,  the other Arduino ran Root's C, D, and the other F hole (labeled root E)    It's basically a timer running a case switch to trigger the first led in the strip.  Then the code moves the led down the line, all the while dimming the strip.  Uses the FastLED.io library from MIT and the led strips we used ran with APA102 chips.
