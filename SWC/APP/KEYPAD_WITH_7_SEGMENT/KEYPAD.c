#include "DIO.h"
#include "KEYPAD.h"
#include "KEYPAD_Cfg.h"
#include "KEYPAD_prv.h"


u8 Local_u8PinState;
u8 KPD_u8GetPressedKey(void)
{

	static u8 Local_u8PressedKey=KPD_NO_PRESSED_KEY, Local_u8ColumnIdx,Local_u8RowIdx;
	static u8 Local_u8KEYPAD_Arr[ROWS_NUM][COLUMNS_NUM]=KPD_ARR_VAL;
	static DIO_tenuPins Local_u8KEYPADColumnArr[COLUMNS_NUM]= {KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	static DIO_tenuPins Local_u8KEYPADRowArr[ROWS_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
	for(Local_u8ColumnIdx=0 ; Local_u8ColumnIdx<COLUMNS_NUM; Local_u8ColumnIdx++){
	     /*Activate current column*/
		DIO_enuSetPin(Local_u8KEYPADColumnArr[Local_u8ColumnIdx]);

		for(Local_u8RowIdx=0; Local_u8RowIdx<ROWS_NUM; Local_u8RowIdx++){
			/*Read the Current Row*/
			DIO_enuGetPin(Local_u8KEYPADRowArr[Local_u8RowIdx],&Local_u8PinState);
			if(Local_u8PinState==0){

				Local_u8PressedKey= Local_u8KEYPAD_Arr[Local_u8RowIdx][Local_u8ColumnIdx];
				/*Busy waiting until the key is released*/
				while(Local_u8PinState==0){
					DIO_enuGetPin(Local_u8KEYPADRowArr[Local_u8RowIdx],&Local_u8PinState);
				}
				return Local_u8PressedKey;
			}
		}
		/*Deactivate current column*/
		DIO_enuClearPin(Local_u8KEYPADColumnArr[Local_u8ColumnIdx]);
	}

	return Local_u8PressedKey;
}



















