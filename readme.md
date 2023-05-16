# afk79

![afk79](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [datapaganism](https://github.com/datapaganism)
* Hardware Supported: STM32F401 Black Pill
* Hardware Availability: Handwire only atm

Make example for this keyboard (after setting up your build environment):

    make afk79:default

Flashing example for this keyboard:

    make afk79:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available


Features include:

Page Up/Down and Home/End are accessible using the cursor keys while FUNC is held. Media Keys are accessible using FUNC and F row Alt Code support; hold AltGr and use the number row to type alt codes; no need for numpad. FUNC + 4 = £, sends an alt code macro, £ is now OS language independent. FUNC + ESC = RESET for flashing.