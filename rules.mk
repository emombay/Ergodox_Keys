# Having a file like this allows you to override Makefile definitions
# for your own particular keymap

SLEEP_LED_ENABLE = no  # Breathing sleep LED during USB suspend
COMMAND_ENABLE   = no  # Commands for debug and configuration
TAP_DANCE_ENABLE = yes
NKRO_ENABLE = true
RGBLIGHT_ENABLE = no

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif