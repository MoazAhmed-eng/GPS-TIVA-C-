void port_init(void);
void uart_init(void);
unsigned char UART1_Available(void);
unsigned char UART1_Read(void);
void turnOnRedLed( char distance);
void turnOffRedLed(void);
void LCD_comm (unsigned char command);
void LCD_Data(unsigned char data);
void LCD_init(void);
void LCD_prnt_str( char *str);
double degToRad(double deg);
double calculate_distance ( double lat1 , double lat2 , double long1 , double long2 );
void delay_ms(int n);
void delay_us(int n);
char* doubleToStr (double dobl);

