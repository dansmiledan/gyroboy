#include "PinChangeInterrupt.h"


#define PinA 4 //外部中断0

#define PinB 8 //编码器的OUTB信号连接到数字端口8

unsigned long time1 = 0; // 时间标记

long count = 0;

void setup()

{

pinMode(PinA, INPUT_PULLUP);

pinMode(PinB, INPUT);
attachPinChangeInterrupt(digitalPinToPinChangeInterrupt(PinA), Code, FALLING);
Serial.begin (112500);

}

void loop()

{

Serial.println (count);

}

// 编码器计数中断子程序

void Code()

{

//为了不计入噪音干扰脉冲，

//当2次中断之间的时间大于5ms时，计一次有效计数

if ((millis() - time1) > 5)

{

//当编码器码盘的OUTA脉冲信号下跳沿每中断一次，

if ((digitalRead(PinA) == LOW) && (digitalRead(PinB) == HIGH))

{

count--;

}

else

{

count++;

}

}

time1 == millis();

}