sbit in1 = P1^0;//左电机

sbit in2 = P1^1;//左电机

sbit in3 = P1^2;//右电机

sbit in4 = P1^3;//右电机

char i;

/*前进*/

void forward()

{

in1=1;

in2=0;

in3=1;

in4=0;

}

/*后退*/

void back()

{

in1=0;

in2=1;

in3=0;

in4=1;

}

                                                                                                                                                                                             

/*左转*/

void left()

{

in1=1;

in2=1;

in3=1;

in4=0;

}

/*右转*/

void right()

{

in1=1;

in2=0;

in3=1;

in4=1;

}

/*停止*/

void stop()

{

in1=1;

in2=1;

in3=1;

in4=1;

}

void main (void)               

{

TMOD=0x20;                         //设置T1为工作方式2

      TH1=0xfd;                        //装入初值，比特率为9600bps

      TL1=0xfd;

      TR1=1;                              //开启T1

      REN=1;                             //接收允许

      SM0=0;                             //方式1

      SM1=1;

      EA=1;                               //开全局中断

      ES=1;                                //开串口中断

while(1)

{i=SBUF;//SBUF为单片机接收到的数据，单片机接收到的数据都存放在SBUF里；

RI=0;

if (i==0x02){forward();}     //如果蓝牙助手发送0x02，小车前进

if (i==0x08){back();}        //如果蓝牙助手发送0x08，小车后退

if (i==0x01){left();}         //如果蓝牙助手发送0x01，小车左转

if (i==0x03){right();}        //如果蓝牙助手发送0x03，小车右转

if (i==0x05){stop();}        //如果蓝牙助手发送0x05，小车停止

}

}
————————————————
版权声明：本文为CSDN博主「一颗小树x」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://guo-pu.blog.csdn.net/article/details/87924196
