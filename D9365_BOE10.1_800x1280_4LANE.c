/**************************************************/		
// I2C power module controller		
/**************************************************/ 

voidReadOperation()
{
	//Cleanmemory:BUFFER	
	memset(0);//BUFFERsize:8Bytes

	//ReadvaluetoBUFFER
	//DCS_Short_Read_NP(0xF0,1,BUFFER+0);

	DCS_Short_Read_NP(0xDA,1,BUFFER+0);
	DCS_Short_Read_NP(0xDB,1,BUFFER+1);
	DCS_Short_Read_NP(0xDC,1,BUFFER+2);
}

void DisplayOn()
{
	Delay(300); 
	Set_POWER(1,1,1,1);//1.8V ON, 2.8V ON, 5V ON, BL ON
	// Read_ADC(1.8);//ID voltage, 0V - 3.3V 

} 
//
void PowerOffSequence()
{
	DCS_Short_Write_NP(0x28);
	Delay(200);
	DCS_Short_Write_NP(0x10);
	Delay(100);
	Set_STANDBY();//Video transfer stop
	Delay(50);

	//Delay(10000);  
	//Delay(10000);
	//Delay(10000);

	Set_RESET(1,0);//MIPI RESET 1, LCD RESET 0
	Delay(50);
	Set_RESET(0,0);//MIPI RESET 0, LCD RESET 0
	Delay(50);

	Set_POWER(1,1,0,1);//1.8V ON, 2.8V ON, 5V OFF, BL ON
	Delay(50);

	Set_BOOST(5.00, 5.00, 0x81, 50);//VDD, VEE, OFF:VDD->VEE, 10ms
	Delay(50);

	Set_POWER(1,0,0,1);//1.8V ON, 2.8V OFF, 5V OFF, BL ON
	Delay(100);
	Set_POWER(0,0,0,0);//1.8V OFF, 2.8V OFF, 5V OFF, BL OFF

}
void main()
{

	//Delay(100);
	Set_POWER(1,0,0,0);//1.8V ON, 2.8V OFF, 5V OFF, BL OFF
	Delay(100);
	Set_POWER(1,1,1,0);//1.8V ON, 2.8V ON, 5V ON, BL OFF

	Delay(200);//????IIC,????40mS??


	//Set_BOOST(5.5,5.5,0x01,200);//50




	Set_RESET(1,0);//MIPI RESET 1, LCD RESET 0
	Delay(100);
	Set_RESET(1,1);//MIPI RESET 1, LCD RESET 1
	Delay(200);	
	
	SSD_LANE(4,0);


//
//
//	/**************************************************/		
//	//LCDD (Peripheral) Setting		
//      /**************************************************/	

//JD9365 initial code

//JD9365 initial code

DCS_Short_Write_1P(0xE0,0x00);
DCS_Short_Write_1P(0xE1,0x93);
DCS_Short_Write_1P(0xE2,0x65);
DCS_Short_Write_1P(0xE3,0xF8);

DCS_Short_Write_1P(0xE0,0x01);
DCS_Short_Write_1P(0x00,0x11);
DCS_Short_Write_1P(0x01,0x0C);
DCS_Short_Write_1P(0x03,0x00);
DCS_Short_Write_1P(0x04,0x00);
DCS_Short_Write_1P(0x0C,0x74);

DCS_Short_Write_1P(0x17,0x00);
DCS_Short_Write_1P(0x18,0x77);
DCS_Short_Write_1P(0x19,0x01);
DCS_Short_Write_1P(0x1A,0x00);
DCS_Short_Write_1P(0x1B,0xE7);
DCS_Short_Write_1P(0x1C,0x01);

DCS_Short_Write_1P(0x1F,0x3E);
DCS_Short_Write_1P(0x20,0x28);
DCS_Short_Write_1P(0x21,0x28);
DCS_Short_Write_1P(0x22,0x7E);

DCS_Short_Write_1P(0x24,0xFE);

DCS_Short_Write_1P(0x35,0x26);
DCS_Short_Write_1P(0x37,0x09);

DCS_Short_Write_1P(0x38,0x04);
DCS_Short_Write_1P(0x39,0x00);
DCS_Short_Write_1P(0x3A,0x01);
DCS_Short_Write_1P(0x3C,0x7C);
DCS_Short_Write_1P(0x3D,0xFF);
DCS_Short_Write_1P(0x3E,0xFF);
DCS_Short_Write_1P(0x3F,0x7F);

DCS_Short_Write_1P(0x40,0x06);
DCS_Short_Write_1P(0x41,0xA0);
DCS_Short_Write_1P(0x42,0x81);
DCS_Short_Write_1P(0x43,0x08);
DCS_Short_Write_1P(0x44,0x0B);
DCS_Short_Write_1P(0x45,0x28);

DCS_Short_Write_1P(0x55,0x02);
DCS_Short_Write_1P(0x56,0x01);
DCS_Short_Write_1P(0x57,0x25);
DCS_Short_Write_1P(0x58,0x0A);
DCS_Short_Write_1P(0x59,0x0A);
DCS_Short_Write_1P(0x5A,0x06);
DCS_Short_Write_1P(0x5B,0x06);
DCS_Short_Write_1P(0x5C,0x15);

DCS_Short_Write_1P(0x5D,0x7F);
DCS_Short_Write_1P(0x5E,0x49);
DCS_Short_Write_1P(0x5F,0x37);
DCS_Short_Write_1P(0x60,0x28);
DCS_Short_Write_1P(0x61,0x23);
DCS_Short_Write_1P(0x62,0x13);
DCS_Short_Write_1P(0x63,0x16);
DCS_Short_Write_1P(0x64,0x00);
DCS_Short_Write_1P(0x65,0x19);
DCS_Short_Write_1P(0x66,0x18);
DCS_Short_Write_1P(0x67,0x1A);
DCS_Short_Write_1P(0x68,0x39);
DCS_Short_Write_1P(0x69,0x2B);
DCS_Short_Write_1P(0x6A,0x33);
DCS_Short_Write_1P(0x6B,0x27);
DCS_Short_Write_1P(0x6C,0x24);
DCS_Short_Write_1P(0x6D,0x17);
DCS_Short_Write_1P(0x6E,0x08);
DCS_Short_Write_1P(0x6F,0x00);
DCS_Short_Write_1P(0x70,0x7F);

DCS_Short_Write_1P(0x71,0x49);
DCS_Short_Write_1P(0x72,0x37);
DCS_Short_Write_1P(0x73,0x28);
DCS_Short_Write_1P(0x74,0x23);
DCS_Short_Write_1P(0x75,0x13);
DCS_Short_Write_1P(0x76,0x16);
DCS_Short_Write_1P(0x77,0x00);
DCS_Short_Write_1P(0x78,0x19);
DCS_Short_Write_1P(0x79,0x18);
DCS_Short_Write_1P(0x7A,0x1A);
DCS_Short_Write_1P(0x7B,0x39);
DCS_Short_Write_1P(0x7C,0x2B);
DCS_Short_Write_1P(0x7D,0x33);
DCS_Short_Write_1P(0x7E,0x27);
DCS_Short_Write_1P(0x7F,0x24);
DCS_Short_Write_1P(0x80,0x17);
DCS_Short_Write_1P(0x81,0x08);
DCS_Short_Write_1P(0x82,0x00);

DCS_Short_Write_1P(0xE0,0x02);

DCS_Short_Write_1P(0x00,0x1F);
DCS_Short_Write_1P(0x01,0x1F);
DCS_Short_Write_1P(0x02,0x1F);
DCS_Short_Write_1P(0x03,0x40);
DCS_Short_Write_1P(0x04,0x41);
DCS_Short_Write_1P(0x05,0x5F);
DCS_Short_Write_1P(0x06,0x5E);
DCS_Short_Write_1P(0x07,0x5E);
DCS_Short_Write_1P(0x08,0x50);
DCS_Short_Write_1P(0x09,0x1F);
DCS_Short_Write_1P(0x0A,0x1F);
DCS_Short_Write_1P(0x0B,0x1F);
DCS_Short_Write_1P(0x0C,0x1F);
DCS_Short_Write_1P(0x0D,0x1F);
DCS_Short_Write_1P(0x0E,0x1F);
DCS_Short_Write_1P(0x0F,0x5F);
DCS_Short_Write_1P(0x10,0x5F);
DCS_Short_Write_1P(0x11,0x46);
DCS_Short_Write_1P(0x12,0x47);
DCS_Short_Write_1P(0x13,0x44);
DCS_Short_Write_1P(0x14,0x45);
DCS_Short_Write_1P(0x15,0x1F);

DCS_Short_Write_1P(0x16,0x1F);
DCS_Short_Write_1P(0x17,0x1F);
DCS_Short_Write_1P(0x18,0x1F);
DCS_Short_Write_1P(0x19,0x40);
DCS_Short_Write_1P(0x1A,0x41);
DCS_Short_Write_1P(0x1B,0x5F);
DCS_Short_Write_1P(0x1C,0x5E);
DCS_Short_Write_1P(0x1D,0x5E);
DCS_Short_Write_1P(0x1E,0x50);
DCS_Short_Write_1P(0x1F,0x1F);
DCS_Short_Write_1P(0x20,0x1F);
DCS_Short_Write_1P(0x21,0x1F);
DCS_Short_Write_1P(0x22,0x1F);
DCS_Short_Write_1P(0x23,0x1F);
DCS_Short_Write_1P(0x24,0x1F);
DCS_Short_Write_1P(0x25,0x5F);
DCS_Short_Write_1P(0x26,0x5F);
DCS_Short_Write_1P(0x27,0x46);
DCS_Short_Write_1P(0x28,0x47);
DCS_Short_Write_1P(0x29,0x44);
DCS_Short_Write_1P(0x2A,0x45);
DCS_Short_Write_1P(0x2B,0x1F);

DCS_Short_Write_1P(0x2C,0x1F);
DCS_Short_Write_1P(0x2D,0x1F);
DCS_Short_Write_1P(0x2E,0x1F);
DCS_Short_Write_1P(0x2F,0x41);
DCS_Short_Write_1P(0x30,0x40);
DCS_Short_Write_1P(0x31,0x5E);
DCS_Short_Write_1P(0x32,0x5F);
DCS_Short_Write_1P(0x33,0x5E);
DCS_Short_Write_1P(0x34,0x50);
DCS_Short_Write_1P(0x35,0x1F);
DCS_Short_Write_1P(0x36,0x1F);
DCS_Short_Write_1P(0x37,0x1F);
DCS_Short_Write_1P(0x38,0x1F);
DCS_Short_Write_1P(0x39,0x1F);
DCS_Short_Write_1P(0x3A,0x1F);
DCS_Short_Write_1P(0x3B,0x5F);
DCS_Short_Write_1P(0x3C,0x5F);
DCS_Short_Write_1P(0x3D,0x45);
DCS_Short_Write_1P(0x3E,0x44);
DCS_Short_Write_1P(0x3F,0x47);
DCS_Short_Write_1P(0x40,0x46);
DCS_Short_Write_1P(0x41,0x1F);

DCS_Short_Write_1P(0x42,0x1F);
DCS_Short_Write_1P(0x43,0x1F);
DCS_Short_Write_1P(0x44,0x1F);
DCS_Short_Write_1P(0x45,0x41);
DCS_Short_Write_1P(0x46,0x40);
DCS_Short_Write_1P(0x47,0x5E);
DCS_Short_Write_1P(0x48,0x5F);
DCS_Short_Write_1P(0x49,0x5E);
DCS_Short_Write_1P(0x4A,0x50);
DCS_Short_Write_1P(0x4B,0x1F);
DCS_Short_Write_1P(0x4C,0x1F);
DCS_Short_Write_1P(0x4D,0x1F);
DCS_Short_Write_1P(0x4E,0x1F);
DCS_Short_Write_1P(0x4F,0x1F);
DCS_Short_Write_1P(0x50,0x1F);
DCS_Short_Write_1P(0x51,0x5F);
DCS_Short_Write_1P(0x52,0x5F);
DCS_Short_Write_1P(0x53,0x45);
DCS_Short_Write_1P(0x54,0x44);
DCS_Short_Write_1P(0x55,0x47);
DCS_Short_Write_1P(0x56,0x46);
DCS_Short_Write_1P(0x57,0x1F);


DCS_Short_Write_1P(0x58,0x40);
DCS_Short_Write_1P(0x5B,0x10);
DCS_Short_Write_1P(0x5C,0x08);
DCS_Short_Write_1P(0x5D,0x10);
DCS_Short_Write_1P(0x5E,0x01);
DCS_Short_Write_1P(0x5F,0x02);
DCS_Short_Write_1P(0x60,0x10);
DCS_Short_Write_1P(0x63,0x04);
DCS_Short_Write_1P(0x64,0x64);
DCS_Short_Write_1P(0x65,0x50);
DCS_Short_Write_1P(0x66,0x06);
DCS_Short_Write_1P(0x67,0x30);
DCS_Short_Write_1P(0x68,0x0A);
DCS_Short_Write_1P(0x69,0x04);
DCS_Short_Write_1P(0x6A,0x64);
DCS_Short_Write_1P(0x6B,0x04);
DCS_Short_Write_1P(0x6C,0x00);
DCS_Short_Write_1P(0x6D,0x00);
DCS_Short_Write_1P(0x6E,0x00);
DCS_Short_Write_1P(0x6F,0x88);


DCS_Short_Write_1P(0xE0,0x04);
DCS_Short_Write_1P(0x02,0x23);
DCS_Short_Write_1P(0x0E,0x48);
DCS_Short_Write_1P(0x36,0x49);

DCS_Short_Write_1P(0xE0,0x00);
DCS_Short_Write_1P(0xE6,0x02);
DCS_Short_Write_1P(0xE7,0x0C);
//--- TE----//
DCS_Short_Write_1P(0x35,0x00);

DCS_Short_Write_NP(0x11); // SLPOUT
Delay(120);
//DISP ON
DCS_Short_Write_NP(0x29); // DSPON
Delay(5);
	//Cleanmemory:BUFFER	
	memset(0);//
	ReadOperation();

	if(memcmp("0x93,0x65,0xf8"))//CheckBUFFER:290000RM72010;104C5ES6D7AA0
	{
		Set_TEXT(0,0,0x10);//DrawText:"PASS"
		//Set_POWER(1,0,0,0);//1.8VON,2.8VON,5VON,BLON
	}
	else
	{
		Set_TEXT(0,0,0x00);//DrawText:"FAIL"
		//Set_POWER(0,1,0,0);//1.8VON,2.8VON,5VON,BLON
	}
	//Tips:	Set_TEXT([0], [1], [2])
	//		[0]	Title:	0 - "ID"
	//					1 - "OTP"
	//		[1]	Screen:	0 - UnLock
	//					1 - Lock
	//		[2]	Text:		0x0_	Black		0x_0	Memory Data
	//					0x1_	Green		0x_1	"PASS"
	//					0x2_	Red		0x_2	"FAIL"
	//					0x3_	Yellow	0x_3	"OLD"


	SSD_MODE(1,1);

}
