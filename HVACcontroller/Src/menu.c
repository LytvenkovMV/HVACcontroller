
#include "menu.h"
#include "menu_config.h"



MENU_ItemType MENU_GetItemType(MENU_ItemID ItemID)
{
	if		(ItemID == MENU_ITEM_01) return MENU_CONF_ITEM01_TYPE;
	else if (ItemID == MENU_ITEM_02) return MENU_CONF_ITEM02_TYPE;
	else if (ItemID == MENU_ITEM_03) return MENU_CONF_ITEM03_TYPE;
	else if (ItemID == MENU_ITEM_04) return MENU_CONF_ITEM04_TYPE;
	else if (ItemID == MENU_ITEM_05) return MENU_CONF_ITEM05_TYPE;
	else if (ItemID == MENU_ITEM_06) return MENU_CONF_ITEM06_TYPE;
	else if (ItemID == MENU_ITEM_07) return MENU_CONF_ITEM07_TYPE;
	else if (ItemID == MENU_ITEM_08) return MENU_CONF_ITEM08_TYPE;
	else if (ItemID == MENU_ITEM_09) return MENU_CONF_ITEM09_TYPE;
	else if (ItemID == MENU_ITEM_10) return MENU_CONF_ITEM10_TYPE;
	else if (ItemID == MENU_ITEM_11) return MENU_CONF_ITEM11_TYPE;
	else if (ItemID == MENU_ITEM_12) return MENU_CONF_ITEM12_TYPE;
	else if (ItemID == MENU_ITEM_13) return MENU_CONF_ITEM13_TYPE;
	else if (ItemID == MENU_ITEM_14) return MENU_CONF_ITEM14_TYPE;
	else if (ItemID == MENU_ITEM_15) return MENU_CONF_ITEM15_TYPE;
	else if (ItemID == MENU_ITEM_16) return MENU_CONF_ITEM16_TYPE;
	else if (ItemID == MENU_ITEM_17) return MENU_CONF_ITEM17_TYPE;
	else if (ItemID == MENU_ITEM_18) return MENU_CONF_ITEM18_TYPE;
	else if (ItemID == MENU_ITEM_19) return MENU_CONF_ITEM19_TYPE;
	else if (ItemID == MENU_ITEM_20) return MENU_CONF_ITEM20_TYPE;
	else if (ItemID == MENU_ITEM_21) return MENU_CONF_ITEM21_TYPE;
	else if (ItemID == MENU_ITEM_22) return MENU_CONF_ITEM22_TYPE;
	else if (ItemID == MENU_ITEM_23) return MENU_CONF_ITEM23_TYPE;
	else if (ItemID == MENU_ITEM_24) return MENU_CONF_ITEM24_TYPE;
	else if (ItemID == MENU_ITEM_25) return MENU_CONF_ITEM25_TYPE;
	else if (ItemID == MENU_ITEM_26) return MENU_CONF_ITEM26_TYPE;
	else if (ItemID == MENU_ITEM_27) return MENU_CONF_ITEM27_TYPE;
	else if (ItemID == MENU_ITEM_28) return MENU_CONF_ITEM28_TYPE;
	else if (ItemID == MENU_ITEM_29) return MENU_CONF_ITEM29_TYPE;
	else if (ItemID == MENU_ITEM_30) return MENU_CONF_ITEM30_TYPE;
	
	return MENU_CONF_ITEM01_TYPE;
}



uint8_t MENU_GetLastLine(MENU_ItemID ItemID)
{
	if		(ItemID == MENU_ITEM_01) return MENU_CONF_ITEM01_LAST_LINE;
	else if (ItemID == MENU_ITEM_02) return MENU_CONF_ITEM02_LAST_LINE;
	else if (ItemID == MENU_ITEM_03) return MENU_CONF_ITEM03_LAST_LINE;
	else if (ItemID == MENU_ITEM_04) return MENU_CONF_ITEM04_LAST_LINE;
	else if (ItemID == MENU_ITEM_05) return MENU_CONF_ITEM05_LAST_LINE;
	else if (ItemID == MENU_ITEM_06) return MENU_CONF_ITEM06_LAST_LINE;
	else if (ItemID == MENU_ITEM_07) return MENU_CONF_ITEM07_LAST_LINE;
	else if (ItemID == MENU_ITEM_08) return MENU_CONF_ITEM08_LAST_LINE;
	else if (ItemID == MENU_ITEM_09) return MENU_CONF_ITEM09_LAST_LINE;
	else if (ItemID == MENU_ITEM_10) return MENU_CONF_ITEM10_LAST_LINE;
	else if (ItemID == MENU_ITEM_11) return MENU_CONF_ITEM11_LAST_LINE;
	else if (ItemID == MENU_ITEM_12) return MENU_CONF_ITEM12_LAST_LINE;
	else if (ItemID == MENU_ITEM_13) return MENU_CONF_ITEM13_LAST_LINE;
	else if (ItemID == MENU_ITEM_14) return MENU_CONF_ITEM14_LAST_LINE;
	else if (ItemID == MENU_ITEM_15) return MENU_CONF_ITEM15_LAST_LINE;
	else if (ItemID == MENU_ITEM_16) return MENU_CONF_ITEM16_LAST_LINE;
	else if (ItemID == MENU_ITEM_17) return MENU_CONF_ITEM17_LAST_LINE;
	else if (ItemID == MENU_ITEM_18) return MENU_CONF_ITEM18_LAST_LINE;
	else if (ItemID == MENU_ITEM_19) return MENU_CONF_ITEM19_LAST_LINE;
	else if (ItemID == MENU_ITEM_20) return MENU_CONF_ITEM20_LAST_LINE;
	else if (ItemID == MENU_ITEM_21) return MENU_CONF_ITEM21_LAST_LINE;
	else if (ItemID == MENU_ITEM_22) return MENU_CONF_ITEM22_LAST_LINE;
	else if (ItemID == MENU_ITEM_23) return MENU_CONF_ITEM23_LAST_LINE;
	else if (ItemID == MENU_ITEM_24) return MENU_CONF_ITEM24_LAST_LINE;
	else if (ItemID == MENU_ITEM_25) return MENU_CONF_ITEM25_LAST_LINE;
	else if (ItemID == MENU_ITEM_26) return MENU_CONF_ITEM26_LAST_LINE;
	else if (ItemID == MENU_ITEM_27) return MENU_CONF_ITEM27_LAST_LINE;
	else if (ItemID == MENU_ITEM_28) return MENU_CONF_ITEM28_LAST_LINE;
	else if (ItemID == MENU_ITEM_29) return MENU_CONF_ITEM29_LAST_LINE;
	else if (ItemID == MENU_ITEM_30) return MENU_CONF_ITEM30_LAST_LINE;
	
	return 2;
}



SETTING_ArrayID MENU_GetSettingArrayID(MENU_ItemID ItemID)
{
	if		(ItemID == MENU_ITEM_01) return MENU_CONF_ITEM01_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_02) return MENU_CONF_ITEM02_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_03) return MENU_CONF_ITEM03_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_04) return MENU_CONF_ITEM04_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_05) return MENU_CONF_ITEM05_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_06) return MENU_CONF_ITEM06_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_07) return MENU_CONF_ITEM07_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_08) return MENU_CONF_ITEM08_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_09) return MENU_CONF_ITEM09_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_10) return MENU_CONF_ITEM10_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_11) return MENU_CONF_ITEM11_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_12) return MENU_CONF_ITEM12_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_13) return MENU_CONF_ITEM13_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_14) return MENU_CONF_ITEM14_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_15) return MENU_CONF_ITEM15_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_16) return MENU_CONF_ITEM16_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_17) return MENU_CONF_ITEM17_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_18) return MENU_CONF_ITEM18_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_19) return MENU_CONF_ITEM19_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_20) return MENU_CONF_ITEM20_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_21) return MENU_CONF_ITEM21_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_22) return MENU_CONF_ITEM22_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_23) return MENU_CONF_ITEM23_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_24) return MENU_CONF_ITEM24_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_25) return MENU_CONF_ITEM25_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_26) return MENU_CONF_ITEM26_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_27) return MENU_CONF_ITEM27_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_28) return MENU_CONF_ITEM28_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_29) return MENU_CONF_ITEM29_SETTING_ARRAY_ID;
	else if (ItemID == MENU_ITEM_30) return MENU_CONF_ITEM30_SETTING_ARRAY_ID;

	return MENU_CONF_ITEM01_SETTING_ARRAY_ID;
}



void MENU_GetLine(MENU_ItemID ItemID, uint8_t lineNumber, char line[24])
{
	if			(ItemID == MENU_ITEM_01)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM01_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM01_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM01_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM01_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM01_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM01_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM01_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM01_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM01_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM01_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM01_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM01_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM01_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM01_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM01_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM01_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM01_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM01_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM01_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM01_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM01_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM01_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM01_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM01_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM01_LINE25);
	}
	else if	(ItemID == MENU_ITEM_02)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM02_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM02_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM02_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM02_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM02_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM02_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM02_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM02_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM02_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM02_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM02_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM02_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM02_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM02_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM02_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM02_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM02_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM02_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM02_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM02_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM02_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM02_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM02_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM02_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM02_LINE25);
	}
	else if	(ItemID == MENU_ITEM_03)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM03_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM03_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM03_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM03_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM03_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM03_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM03_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM03_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM03_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM03_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM03_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM03_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM03_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM03_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM03_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM03_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM03_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM03_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM03_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM03_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM03_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM03_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM03_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM03_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM03_LINE25);
	}
	else if	(ItemID == MENU_ITEM_04)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM04_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM04_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM04_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM04_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM04_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM04_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM04_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM04_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM04_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM04_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM04_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM04_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM04_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM04_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM04_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM04_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM04_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM04_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM04_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM04_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM04_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM04_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM04_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM04_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM04_LINE25);
	}
	else if	(ItemID == MENU_ITEM_05)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM05_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM05_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM05_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM05_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM05_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM05_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM05_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM05_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM05_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM05_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM05_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM05_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM05_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM05_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM05_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM05_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM05_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM05_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM05_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM05_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM05_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM05_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM05_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM05_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM05_LINE25);
	}	
	else if	(ItemID == MENU_ITEM_06)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM06_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM06_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM06_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM06_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM06_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM06_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM06_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM06_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM06_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM06_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM06_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM06_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM06_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM06_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM06_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM06_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM06_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM06_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM06_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM06_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM06_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM06_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM06_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM06_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM06_LINE25);
	}
	else if	(ItemID == MENU_ITEM_07)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM07_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM07_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM07_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM07_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM07_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM07_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM07_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM07_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM07_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM07_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM07_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM07_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM07_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM07_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM07_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM07_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM07_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM07_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM07_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM07_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM07_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM07_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM07_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM07_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM07_LINE25);
	}
	else if	(ItemID == MENU_ITEM_08)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM08_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM08_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM08_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM08_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM08_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM08_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM08_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM08_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM08_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM08_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM08_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM08_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM08_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM08_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM08_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM08_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM08_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM08_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM08_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM08_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM08_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM08_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM08_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM08_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM08_LINE25);
	}
	else if	(ItemID == MENU_ITEM_09)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM09_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM09_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM09_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM09_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM09_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM09_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM09_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM09_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM09_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM09_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM09_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM09_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM09_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM09_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM09_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM09_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM09_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM09_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM09_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM09_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM09_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM09_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM09_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM09_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM09_LINE25);
	}
	else if	(ItemID == MENU_ITEM_10)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM10_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM10_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM10_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM10_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM10_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM10_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM10_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM10_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM10_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM10_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM10_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM10_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM10_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM10_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM10_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM10_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM10_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM10_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM10_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM10_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM10_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM10_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM10_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM10_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM10_LINE25);
	}
	else if	(ItemID == MENU_ITEM_11)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM11_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM11_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM11_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM11_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM11_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM11_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM11_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM11_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM11_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM11_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM11_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM11_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM11_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM11_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM11_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM11_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM11_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM11_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM11_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM11_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM11_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM11_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM11_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM11_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM11_LINE25);
	}
	else if	(ItemID == MENU_ITEM_12)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM12_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM12_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM12_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM12_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM12_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM12_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM12_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM12_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM12_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM12_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM12_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM12_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM12_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM12_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM12_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM12_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM12_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM12_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM12_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM12_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM12_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM12_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM12_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM12_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM12_LINE25);
	}
	else if	(ItemID == MENU_ITEM_13)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM13_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM13_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM13_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM13_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM13_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM13_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM13_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM13_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM13_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM13_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM13_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM13_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM13_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM13_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM13_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM13_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM13_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM13_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM13_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM13_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM13_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM13_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM13_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM13_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM13_LINE25);
	}
	else if	(ItemID == MENU_ITEM_14)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM14_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM14_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM14_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM14_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM14_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM14_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM14_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM14_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM14_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM14_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM14_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM14_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM14_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM14_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM14_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM14_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM14_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM14_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM14_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM14_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM14_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM14_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM14_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM14_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM14_LINE25);
	}
	else if	(ItemID == MENU_ITEM_15)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM15_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM15_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM15_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM15_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM15_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM15_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM15_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM15_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM15_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM15_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM15_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM15_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM15_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM15_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM15_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM15_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM15_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM15_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM15_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM15_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM15_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM15_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM15_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM15_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM15_LINE25);
	}
	else if	(ItemID == MENU_ITEM_16)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM16_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM16_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM16_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM16_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM16_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM16_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM16_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM16_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM16_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM16_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM16_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM16_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM16_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM16_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM16_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM16_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM16_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM16_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM16_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM16_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM16_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM16_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM16_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM16_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM16_LINE25);
	}
	else if	(ItemID == MENU_ITEM_17)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM17_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM17_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM17_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM17_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM17_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM17_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM17_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM17_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM17_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM17_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM17_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM17_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM17_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM17_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM17_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM17_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM17_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM17_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM17_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM17_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM17_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM17_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM17_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM17_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM17_LINE25);
	}
	else if	(ItemID == MENU_ITEM_18)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM18_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM18_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM18_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM18_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM18_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM18_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM18_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM18_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM18_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM18_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM18_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM18_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM18_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM18_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM18_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM18_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM18_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM18_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM18_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM18_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM18_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM18_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM18_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM18_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM18_LINE25);
	}
	else if	(ItemID == MENU_ITEM_19)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM19_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM19_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM19_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM19_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM19_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM19_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM19_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM19_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM19_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM19_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM19_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM19_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM19_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM19_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM19_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM19_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM19_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM19_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM19_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM19_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM19_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM19_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM19_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM19_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM19_LINE25);
	}
	else if	(ItemID == MENU_ITEM_20)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM20_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM20_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM20_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM20_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM20_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM20_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM20_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM20_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM20_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM20_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM20_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM20_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM20_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM20_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM20_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM20_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM20_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM20_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM20_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM20_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM20_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM20_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM20_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM20_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM20_LINE25);
	}
	else if	(ItemID == MENU_ITEM_21)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM21_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM21_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM21_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM21_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM21_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM21_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM21_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM21_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM21_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM21_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM21_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM21_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM21_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM21_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM21_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM21_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM21_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM21_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM21_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM21_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM21_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM21_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM21_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM21_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM21_LINE25);
	}
	else if	(ItemID == MENU_ITEM_22)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM22_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM22_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM22_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM22_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM22_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM22_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM22_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM22_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM22_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM22_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM22_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM22_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM22_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM22_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM22_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM22_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM22_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM22_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM22_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM22_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM22_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM22_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM22_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM22_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM22_LINE25);
	}
	else if	(ItemID == MENU_ITEM_23)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM23_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM23_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM23_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM23_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM23_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM23_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM23_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM23_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM23_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM23_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM23_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM23_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM23_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM23_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM23_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM23_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM23_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM23_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM23_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM23_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM23_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM23_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM23_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM23_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM23_LINE25);
	}
	else if	(ItemID == MENU_ITEM_24)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM24_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM24_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM24_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM24_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM24_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM24_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM24_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM24_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM24_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM24_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM24_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM24_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM24_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM24_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM24_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM24_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM24_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM24_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM24_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM24_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM24_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM24_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM24_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM24_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM24_LINE25);
	}
	else if	(ItemID == MENU_ITEM_25)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM25_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM25_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM25_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM25_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM25_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM25_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM25_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM25_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM25_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM25_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM25_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM25_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM25_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM25_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM25_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM25_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM25_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM25_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM25_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM25_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM25_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM25_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM25_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM25_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM25_LINE25);
	}
	else if	(ItemID == MENU_ITEM_26)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM26_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM26_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM26_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM26_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM26_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM26_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM26_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM26_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM26_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM26_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM26_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM26_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM26_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM26_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM26_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM26_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM26_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM26_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM26_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM26_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM26_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM26_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM26_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM26_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM26_LINE25);
	}
	else if	(ItemID == MENU_ITEM_27)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM27_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM27_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM27_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM27_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM27_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM27_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM27_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM27_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM27_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM27_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM27_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM27_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM27_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM27_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM27_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM27_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM27_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM27_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM27_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM27_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM27_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM27_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM27_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM27_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM27_LINE25);
	}
	else if	(ItemID == MENU_ITEM_28)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM28_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM28_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM28_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM28_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM28_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM28_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM28_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM28_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM28_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM28_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM28_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM28_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM28_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM28_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM28_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM28_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM28_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM28_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM28_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM28_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM28_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM28_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM28_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM28_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM28_LINE25);
	}
	else if	(ItemID == MENU_ITEM_29)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM29_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM29_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM29_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM29_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM29_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM29_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM29_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM29_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM29_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM29_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM29_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM29_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM29_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM29_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM29_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM29_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM29_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM29_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM29_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM29_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM29_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM29_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM29_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM29_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM29_LINE25);
	}
	else if	(ItemID == MENU_ITEM_30)
	{
		if		(lineNumber == 1)  strcpy(line, MENU_CONF_ITEM30_LINE01);
		else if	(lineNumber == 2)  strcpy(line, MENU_CONF_ITEM30_LINE02);
		else if	(lineNumber == 3)  strcpy(line, MENU_CONF_ITEM30_LINE03);
		else if	(lineNumber == 4)  strcpy(line, MENU_CONF_ITEM30_LINE04);
		else if	(lineNumber == 5)  strcpy(line, MENU_CONF_ITEM30_LINE05);
		else if	(lineNumber == 6)  strcpy(line, MENU_CONF_ITEM30_LINE06);
		else if	(lineNumber == 7)  strcpy(line, MENU_CONF_ITEM30_LINE07);
		else if	(lineNumber == 8)  strcpy(line, MENU_CONF_ITEM30_LINE08);
		else if	(lineNumber == 9)  strcpy(line, MENU_CONF_ITEM30_LINE09);
		else if	(lineNumber == 10) strcpy(line, MENU_CONF_ITEM30_LINE10);
		else if	(lineNumber == 11) strcpy(line, MENU_CONF_ITEM30_LINE11);
		else if	(lineNumber == 12) strcpy(line, MENU_CONF_ITEM30_LINE12);
		else if	(lineNumber == 13) strcpy(line, MENU_CONF_ITEM30_LINE13);
		else if	(lineNumber == 14) strcpy(line, MENU_CONF_ITEM30_LINE14);
		else if	(lineNumber == 15) strcpy(line, MENU_CONF_ITEM30_LINE15);
		else if	(lineNumber == 16) strcpy(line, MENU_CONF_ITEM30_LINE16);
		else if	(lineNumber == 17) strcpy(line, MENU_CONF_ITEM30_LINE17);
		else if	(lineNumber == 18) strcpy(line, MENU_CONF_ITEM30_LINE18);
		else if	(lineNumber == 19) strcpy(line, MENU_CONF_ITEM30_LINE19);
		else if	(lineNumber == 20) strcpy(line, MENU_CONF_ITEM30_LINE20);
		else if	(lineNumber == 21) strcpy(line, MENU_CONF_ITEM30_LINE21);
		else if	(lineNumber == 22) strcpy(line, MENU_CONF_ITEM30_LINE22);
		else if	(lineNumber == 23) strcpy(line, MENU_CONF_ITEM30_LINE23);
		else if	(lineNumber == 24) strcpy(line, MENU_CONF_ITEM30_LINE24);
		else if	(lineNumber == 25) strcpy(line, MENU_CONF_ITEM30_LINE25);
	}
	else
	{
		strcpy(line, "");
	}
}



MENU_ItemID MENU_GetLink(MENU_ItemID ItemID, uint8_t lineNumber)
{
	if			(ItemID == MENU_ITEM_01)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM01_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM01_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM01_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM01_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM01_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM01_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM01_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM01_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM01_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM01_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM01_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM01_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM01_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM01_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM01_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM01_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM01_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM01_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM01_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM01_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM01_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM01_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM01_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM01_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM01_LINK25;
	}
	else if	(ItemID == MENU_ITEM_02)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM02_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM02_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM02_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM02_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM02_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM02_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM02_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM02_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM02_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM02_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM02_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM02_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM02_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM02_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM02_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM02_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM02_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM02_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM02_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM02_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM02_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM02_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM02_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM02_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM02_LINK25;
	}
	else if	(ItemID == MENU_ITEM_03)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM03_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM03_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM03_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM03_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM03_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM03_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM03_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM03_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM03_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM03_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM03_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM03_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM03_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM03_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM03_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM03_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM03_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM03_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM03_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM03_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM03_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM03_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM03_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM03_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM03_LINK25;
	}
	else if	(ItemID == MENU_ITEM_04)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM04_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM04_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM04_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM04_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM04_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM04_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM04_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM04_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM04_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM04_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM04_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM04_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM04_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM04_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM04_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM04_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM04_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM04_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM04_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM04_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM04_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM04_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM04_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM04_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM04_LINK25;
	}
	else if	(ItemID == MENU_ITEM_05)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM05_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM05_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM05_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM05_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM05_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM05_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM05_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM05_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM05_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM05_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM05_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM05_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM05_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM05_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM05_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM05_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM05_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM05_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM05_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM05_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM05_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM05_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM05_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM05_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM05_LINK25;
	}	
	else if	(ItemID == MENU_ITEM_06)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM06_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM06_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM06_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM06_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM06_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM06_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM06_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM06_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM06_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM06_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM06_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM06_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM06_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM06_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM06_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM06_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM06_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM06_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM06_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM06_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM06_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM06_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM06_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM06_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM06_LINK25;
	}
	else if	(ItemID == MENU_ITEM_07)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM07_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM07_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM07_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM07_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM07_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM07_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM07_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM07_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM07_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM07_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM07_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM07_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM07_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM07_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM07_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM07_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM07_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM07_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM07_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM07_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM07_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM07_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM07_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM07_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM07_LINK25;
	}
	else if	(ItemID == MENU_ITEM_08)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM08_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM08_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM08_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM08_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM08_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM08_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM08_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM08_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM08_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM08_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM08_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM08_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM08_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM08_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM08_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM08_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM08_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM08_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM08_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM08_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM08_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM08_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM08_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM08_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM08_LINK25;
	}
	else if	(ItemID == MENU_ITEM_09)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM09_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM09_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM09_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM09_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM09_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM09_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM09_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM09_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM09_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM09_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM09_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM09_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM09_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM09_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM09_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM09_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM09_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM09_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM09_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM09_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM09_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM09_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM09_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM09_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM09_LINK25;
	}
	else if	(ItemID == MENU_ITEM_10)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM10_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM10_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM10_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM10_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM10_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM10_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM10_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM10_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM10_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM10_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM10_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM10_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM10_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM10_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM10_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM10_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM10_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM10_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM10_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM10_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM10_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM10_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM10_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM10_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM10_LINK25;
	}
	else if	(ItemID == MENU_ITEM_11)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM11_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM11_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM11_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM11_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM11_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM11_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM11_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM11_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM11_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM11_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM11_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM11_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM11_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM11_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM11_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM11_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM11_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM11_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM11_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM11_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM11_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM11_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM11_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM11_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM11_LINK25;
	}
	else if	(ItemID == MENU_ITEM_12)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM12_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM12_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM12_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM12_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM12_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM12_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM12_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM12_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM12_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM12_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM12_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM12_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM12_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM12_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM12_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM12_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM12_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM12_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM12_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM12_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM12_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM12_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM12_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM12_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM12_LINK25;
	}
	else if	(ItemID == MENU_ITEM_13)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM13_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM13_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM13_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM13_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM13_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM13_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM13_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM13_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM13_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM13_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM13_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM13_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM13_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM13_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM13_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM13_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM13_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM13_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM13_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM13_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM13_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM13_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM13_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM13_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM13_LINK25;
	}
	else if	(ItemID == MENU_ITEM_14)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM14_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM14_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM14_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM14_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM14_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM14_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM14_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM14_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM14_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM14_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM14_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM14_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM14_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM14_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM14_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM14_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM14_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM14_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM14_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM14_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM14_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM14_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM14_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM14_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM14_LINK25;
	}
	else if	(ItemID == MENU_ITEM_15)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM15_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM15_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM15_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM15_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM15_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM15_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM15_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM15_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM15_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM15_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM15_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM15_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM15_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM15_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM15_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM15_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM15_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM15_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM15_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM15_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM15_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM15_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM15_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM15_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM15_LINK25;
	}
	else if	(ItemID == MENU_ITEM_16)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM16_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM16_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM16_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM16_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM16_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM16_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM16_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM16_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM16_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM16_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM16_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM16_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM16_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM16_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM16_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM16_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM16_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM16_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM16_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM16_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM16_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM16_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM16_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM16_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM16_LINK25;
	}
	else if	(ItemID == MENU_ITEM_17)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM17_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM17_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM17_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM17_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM17_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM17_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM17_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM17_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM17_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM17_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM17_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM17_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM17_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM17_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM17_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM17_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM17_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM17_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM17_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM17_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM17_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM17_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM17_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM17_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM17_LINK25;
	}
	else if	(ItemID == MENU_ITEM_18)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM18_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM18_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM18_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM18_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM18_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM18_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM18_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM18_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM18_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM18_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM18_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM18_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM18_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM18_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM18_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM18_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM18_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM18_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM18_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM18_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM18_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM18_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM18_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM18_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM18_LINK25;
	}
	else if	(ItemID == MENU_ITEM_19)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM19_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM19_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM19_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM19_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM19_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM19_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM19_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM19_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM19_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM19_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM19_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM19_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM19_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM19_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM19_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM19_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM19_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM19_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM19_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM19_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM19_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM19_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM19_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM19_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM19_LINK25;
	}
	else if	(ItemID == MENU_ITEM_20)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM20_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM20_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM20_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM20_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM20_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM20_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM20_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM20_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM20_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM20_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM20_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM20_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM20_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM20_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM20_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM20_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM20_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM20_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM20_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM20_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM20_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM20_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM20_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM20_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM20_LINK25;
	}
	else if	(ItemID == MENU_ITEM_21)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM21_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM21_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM21_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM21_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM21_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM21_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM21_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM21_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM21_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM21_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM21_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM21_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM21_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM21_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM21_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM21_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM21_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM21_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM21_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM21_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM21_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM21_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM21_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM21_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM21_LINK25;
	}
	else if	(ItemID == MENU_ITEM_22)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM22_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM22_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM22_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM22_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM22_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM22_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM22_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM22_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM22_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM22_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM22_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM22_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM22_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM22_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM22_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM22_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM22_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM22_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM22_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM22_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM22_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM22_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM22_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM22_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM22_LINK25;
	}
	else if	(ItemID == MENU_ITEM_23)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM23_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM23_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM23_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM23_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM23_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM23_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM23_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM23_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM23_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM23_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM23_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM23_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM23_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM23_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM23_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM23_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM23_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM23_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM23_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM23_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM23_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM23_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM23_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM23_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM23_LINK25;
	}
	else if	(ItemID == MENU_ITEM_24)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM24_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM24_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM24_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM24_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM24_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM24_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM24_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM24_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM24_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM24_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM24_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM24_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM24_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM24_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM24_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM24_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM24_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM24_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM24_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM24_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM24_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM24_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM24_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM24_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM24_LINK25;
	}
	else if	(ItemID == MENU_ITEM_25)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM25_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM25_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM25_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM25_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM25_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM25_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM25_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM25_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM25_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM25_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM25_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM25_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM25_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM25_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM25_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM25_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM25_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM25_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM25_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM25_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM25_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM25_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM25_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM25_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM25_LINK25;
	}
	else if	(ItemID == MENU_ITEM_26)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM26_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM26_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM26_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM26_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM26_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM26_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM26_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM26_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM26_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM26_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM26_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM26_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM26_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM26_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM26_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM26_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM26_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM26_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM26_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM26_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM26_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM26_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM26_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM26_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM26_LINK25;
	}
	else if	(ItemID == MENU_ITEM_27)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM27_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM27_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM27_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM27_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM27_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM27_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM27_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM27_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM27_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM27_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM27_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM27_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM27_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM27_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM27_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM27_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM27_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM27_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM27_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM27_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM27_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM27_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM27_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM27_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM27_LINK25;
	}
	else if	(ItemID == MENU_ITEM_28)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM28_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM28_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM28_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM28_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM28_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM28_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM28_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM28_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM28_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM28_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM28_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM28_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM28_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM28_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM28_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM28_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM28_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM28_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM28_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM28_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM28_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM28_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM28_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM28_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM28_LINK25;
	}
	else if	(ItemID == MENU_ITEM_29)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM29_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM29_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM29_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM29_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM29_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM29_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM29_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM29_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM29_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM29_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM29_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM29_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM29_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM29_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM29_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM29_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM29_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM29_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM29_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM29_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM29_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM29_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM29_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM29_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM29_LINK25;
	}
	else if	(ItemID == MENU_ITEM_30)
	{
		if		(lineNumber == 1)  return MENU_CONF_ITEM30_LINK01;
		else if	(lineNumber == 2)  return MENU_CONF_ITEM30_LINK02;
		else if	(lineNumber == 3)  return MENU_CONF_ITEM30_LINK03;
		else if	(lineNumber == 4)  return MENU_CONF_ITEM30_LINK04;
		else if	(lineNumber == 5)  return MENU_CONF_ITEM30_LINK05;
		else if	(lineNumber == 6)  return MENU_CONF_ITEM30_LINK06;
		else if	(lineNumber == 7)  return MENU_CONF_ITEM30_LINK07;
		else if	(lineNumber == 8)  return MENU_CONF_ITEM30_LINK08;
		else if	(lineNumber == 9)  return MENU_CONF_ITEM30_LINK09;
		else if	(lineNumber == 10) return MENU_CONF_ITEM30_LINK10;
		else if	(lineNumber == 11) return MENU_CONF_ITEM30_LINK11;
		else if	(lineNumber == 12) return MENU_CONF_ITEM30_LINK12;
		else if	(lineNumber == 13) return MENU_CONF_ITEM30_LINK13;
		else if	(lineNumber == 14) return MENU_CONF_ITEM30_LINK14;
		else if	(lineNumber == 15) return MENU_CONF_ITEM30_LINK15;
		else if	(lineNumber == 16) return MENU_CONF_ITEM30_LINK16;
		else if	(lineNumber == 17) return MENU_CONF_ITEM30_LINK17;
		else if	(lineNumber == 18) return MENU_CONF_ITEM30_LINK18;
		else if	(lineNumber == 19) return MENU_CONF_ITEM30_LINK19;
		else if	(lineNumber == 20) return MENU_CONF_ITEM30_LINK20;
		else if	(lineNumber == 21) return MENU_CONF_ITEM30_LINK21;
		else if	(lineNumber == 22) return MENU_CONF_ITEM30_LINK22;
		else if	(lineNumber == 23) return MENU_CONF_ITEM30_LINK23;
		else if	(lineNumber == 24) return MENU_CONF_ITEM30_LINK24;
		else if	(lineNumber == 25) return MENU_CONF_ITEM30_LINK25;
	}
	
	return MENU_CONF_ITEM01_LINK01;
}
