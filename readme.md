# Dean Ezra's Layout for his Planck EZ Glow.

# Whats cool about this layout?

## Cross platform keyboard: A seperate set of layers for Windows and Mac OS X
As I use both a Mac and a Windows laptop daily, I wanted a layout that can support both OS's.
Therefore this layout uses the default layer QMK feature to switch between seperate Windows and Mac layers.
Accessible via the Adjust layer (Press Layer Up + Layer Down at same time)

Switch the keyboard to Windows via Adjust+W, Mac via Adjust+M

NOTE: I do NOT use the persistent set default layer, so this keymap wont wear out the EEPROM. Although 100K writes is a lot, so it could be used.

## A UK keyboard layout that uses mnemonic keys to make it easy to remember
I found that remembering how to produce the UK British Pound hard on the planck, so I mapped it to Oryx key + P for Pound.
I then found that I could do the same for 'at' symbol (Oxyx + A for At).

# Requirements for use:
Make sure that you set the OS to 'English (United Kingdom) keyboard layout - as this keymap uses QMK's Keymap_uk.h Key codes.

# How to compile from source:

1. Git clone the zsa/qmk_firware into a directory.

2. Cd into top level dir of the cloned source and run:
qmk setup zsa/qmk_firmware -b firmware21

Note: firmware21 is the latest in ZSA's fork of QMK firmware as of 02/07/2022.

Answer yes to the question when asked if you want to clone the sub dirs.

3. Now cd into the keyboards\planck\ez\glow\keymaps\ directory and git clone this repo into it:

git clone https://github.com/deanezra/planck_ez_glow_deanezra-mac-win-keymap.git

You shoyld end up with a folder called 'planck_ez_glow_deanezra-mac-win-keymap'

4. Compile keymap using following command from the root dir of the ZDA QMK firmware directory:

make planck/ez/glow:planck_ez_glow_deanezra-mac-win-keymap

or

qmk compile -kb planck/ez/glow -km planck_ez_glow_deanezra-mac-win-keymap

5. Using QMK toolbar select and flash the resulting bin file to your planck ez glow keyboard. The bin file is located under:

<QMK root dir>/.build/planck_ez_glow_deanezra-mac-win-keyma.bin

# Would like to do/bugs:

- Add more Mac/Windows specific key combos in.
- Add MEH key/Window manager keys (Not sure which window manager Powertoys on Windows?)


