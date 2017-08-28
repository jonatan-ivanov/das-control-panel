# das-control-panel
A small Arduino-based controller to automate (keyboard) actions.

## What features does the example have?
- Volume control
- Play/Pause music
- Previous Track
- Next Track
- Mute
- Lock the screen

My ugly prototype looks like this:

![das-control-panel.png](/resources/das-control-panel.png)

## What you will need for the example in this repo
- An ~Arduino which
	- operates on 5V
	- supports USB HID (Human Interface Device): acts as a keyboard and/or mouse
	- has interrupt pin(s) and pins with pull-up resistors
	- is small
	- check [ebay](https://www.ebay.com/sch/i.html?_nkw=arduino+pro+micro)
- A [rotary encoder](https://en.wikipedia.org/wiki/Rotary_encoder)
	- with a push button
	- check [ebay](https://www.ebay.com/sch/i.html?_nkw=rotary+encoder), probably you will find a board with pins
- A couple of (the example has 4) momentary push buttons (check ebay, there are boards with pins too)
- A cap for the rotary encoder so that it will look nice
- [Jumper wires](https://en.wikipedia.org/wiki/Jump_wire) if you bought boards and don't need to solder/create PCB
- A box

## Notes
Unfortunately, the [Arduino Keyboard lib](https://github.com/arduino-libraries/Keyboard) does not support every key code, [accordint to the docs](https://www.arduino.cc/en/Reference/MouseKeyboard): "Not every possible ASCII character, particularly the non-printing ones, can be sent with the Keyboard library." This means you cannot send wathever key code you want through the wire. Check [asciitable.com](http://www.asciitable.com/) for the ASCII char codes (some of them are not supported) and the [docs](https://www.arduino.cc/en/Reference/KeyboardModifiers) or the [code](https://github.com/arduino-libraries/Keyboard/blob/master/src/Keyboard.h) for the available modifier keys.  

This means that using the Keyboard lib, the Arduino will not be able to send multimedia key events. That's why you can see weird events (`Ctrl+Alt+F9`) in the example program which are mapped to the real key event using [AutoHotKey](https://autohotkey.com/) (Windows) or [QuckSilver](https://qsapp.com/) + AppleScripts (Mac) but you can use any other key mapper solution.

At the moment, the AppleScripts in this repo only support Spotify but iTunes/etc. support is similar, just Google around. The AHK script support anything which listens to multimedia key events.

The wiring should be straightforward, check the pin layout of your Arduino, rotary encoder, push button board and modify the example program if necessary.
