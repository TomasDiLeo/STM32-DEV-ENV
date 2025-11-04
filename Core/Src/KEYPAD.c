#include "KEYPAD.h"

static void select_row(uint8_t row);

static uint32_t key_timer;
static uint8_t last_key = 0;
static Key_t key = {
		.value = 0,
		.state = KEY_NO_READ
};

Key_t keypad_read(void){
	key.value = 0;

	for(uint8_t row = 0; row < 4; row++){
		HAL_Delay(1);
		select_row(row + 1);

		if (READ_PIN(COL_1) == GPIO_PIN_SET) {key.value = keymap[row][0];break;};
		if (READ_PIN(COL_2) == GPIO_PIN_SET) {key.value = keymap[row][1];break;};
		if (READ_PIN(COL_3) == GPIO_PIN_SET) {key.value = keymap[row][2];break;};
		if (READ_PIN(COL_4) == GPIO_PIN_SET) {key.value = keymap[row][3];break;};
	}

	select_row(0); //RESET ALL ROWS

	if(key.value == 0 && key.value != last_key){
		key.value = last_key;
		key.state = KEY_RELEASED;

		last_key = 0;
		return key;
	}

	if (key.value == 0 && key.value == last_key){
		key.state = KEY_NO_READ;
		return key;
	}

	if(key.value != last_key){
		key.state = KEY_PRESSED;

		key_timer = HAL_GetTick();
		last_key = key.value;

		return key;
	}

	if(key.value == last_key){
		if(HAL_GetTick() - key_timer >= 700){
			key.state = KEY_HELD;
		} else {
			key.state = KEY_NO_READ;
		}

		return key;
	}

	return key;
}

static void select_row(uint8_t row){
	WRITE_PIN(ROW_1, (row == 1) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	WRITE_PIN(ROW_2, (row == 2) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	WRITE_PIN(ROW_3, (row == 3) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	WRITE_PIN(ROW_4, (row == 4) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}
