ifndef QUANTUM_DIR
	include ../../../../Makefile
endif

AUDIO_ENABLE = no           # Audio output on port C6
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
CONSOLE_ENABLE = no         # Console for debug(+400)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
MIDI_ENABLE = yes           # MIDI controls
MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
STENO_ENABLE = no           # Additional protocols for Stenography(+1700), requires VIRTSER
