# Dean Ezra's Layout for his Planck EZ Glow.

# Whats cool about this layout?

## Cross platform keyboard: A seperate set of layer for Windows and Mac OS X
As I use both a Mac and a Windows laptop daily, I wanted a layout that can support both OS's.
Therefore this layout uses the default layer QMK feature to switch between seperate Windows and Mac layers.
Accessible via the Adjust layer (Press Layer Up + Layer Down at same time)

Switch the keyboard to Windows via Adjust+W, Mac via Adjust+M

## A USA international layout that uses mnemonic keys to make it easy to remember
I found that remembering how to produce the UK British Pound hard on the planck, so I mapped it to Oryx key + P for Pound.
I then found that I could do the same for 'at' symbol (Oxyx + A for At).

# Requirements for use:
Make sure that you set the OS to USA Internation keyboard - as QMK uses that by default.

# How to compile from source:
Compile by copying the deanezra-mac-win dir into the ZSA fork of QMK firmware under the following directory:

keyboards\planck\ez\glow\keymaps\

and then compile using following command from the root dir of the ZDA QMK firmware directory:

make planck/ez/glow:deanezra-mac-win

or

qmk compile -kb planck/ez/glow -km deanezra-mac-win

Bugs and todo list:

- Windows: fix ' key, it currently needs two presses to get either '' or ". ONLY happens in US International, not in US (non international)
- All: Fix call to update_tri_layer_state() to cover for entering different adjust layers (need for mac and win modes)
- Windows: Fix Onyx + P for £ - Make the Windows Onyx layer send: Alt+0163 (numpad on)

