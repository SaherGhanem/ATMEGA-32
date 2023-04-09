/****************************************************************************/
/**************************		Author: SAHER GHANEM 	*********************/
/**************************		   ITI-INTAKE43         *********************/
/**************************		   Map_Function     	*********************/
/**************************		   Version:1.00 	    *********************/
/**************************		  DATE: 02/08/2023      *********************/
/****************************************************************************/
/****************************************************************************/




s32 Map(s32 Copy_s32InputMin, s32 Copy_s32InputMax ,s32 Copy_s32OutputMin,s32 Copy_s32OutputMax, s32 Copy_s32InputVal )
{
	s32 Local_s32OutputVal;
	Local_s32OutputVal=Copy_s32InputVal-Copy_s32InputMin;
	Local_s32OutputVal*=Copy_s32OutputMax-Copy_s32OutputMin;
	Local_s32OutputVal/=Copy_s32OutputMax-Copy_s32InputMin;
	Local_s32OutputVal+=Copy_s32OutputMin;
	return Local_s32OutputVal;
}