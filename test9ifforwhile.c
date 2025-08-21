// if条件 switch条件
// while循环 for循环 do while循环
// goto语句（goto xxx;    xxx: 到goto xxx;会跳转到xxx:的下一行(不能跨函数跳转)
//<Plus0818>分支和循环语句
//<Plus0820>tips:选中+tab 集体右移；选中+shift+tab 集体左移

// C语句分为5类：1.表达式语句 2.函数调用语句 3.控制语句 4.复合语句 5.空语句
// 本文件涉及3.控制语句
// 控制语句包含3类：1.条件判断语句/分支语句：if,switch 2.循环执行语句while for do..while 3.转向语句break goto continue return
#include <stdio.h>
#include <unistd.h> //mac系统中sleep函数的库
#include <string.h> //strlen，strcmp所需库
#include <stdlib.h> //system函数的库
int main()
{
  int input = 0;
  // if(5==num)和if(num==5)是一样的，但是=就不行因为是赋值
  if (input == 1)       // if： if... else ...   双分支 ;  if... else if ... else 多分支
    printf("未成年\n"); // 单语句的可以省略大括号
  else
    printf("成年\n");
  // if分支

  int day = 0;
  scanf("%d", &day);
  switch (day) // switch要求必须整形表达式（可以是字符，因为字符也是以ASCII码存储）
  {
  case 1: // day==1的case,case后必须是整形常量表达式（可以是字符，因为字符也是以ASCII码存储）
    printf("Monday\n");
    break; // 不加break就会把后面的输出全走一遍
  case 2:
    printf("Tuesday\n");
    break;
  case 3:
    printf("Wednesday\n");
    break;
  } // 若没满足的取等关系，直接跳过本switch

  switch (day) // 1—5输出weekday 6-7输出weekend
  {
  // 利用不加break就会把后面的输出全走一遍的原理
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
    printf("weekday\n");
    break;
  case 6:
  case 7:
    printf("weekend\n");
    break;
  default: // 但每个switch最多一个default子句,
           // default可以放在任意case前后，不影响判别结果。case表达式也不要求顺序
    printf("Error\n");
    break; // 报错程序，当前面都不满足时
  }
  // switch分支

  input = 0;
  while (input < 20)
  {
    input++;
    if (10 == input)
    {
      // break;终止循环
      continue; // continue跳过循环后续部分，直接开始下一轮循环
      // continue只能用于循环
    }
    // printf("%d\n",input);
  }

  // int ch=getchar();//getchar输入字符然后获取字符的ASCII码值
  // printf("%c\n",ch);//输出ch的码对应的字符
  // putchar(ch);//与上行同理

  // int ch=0;
  // while((ch=getchar())!=EOF)//当getchar输入报错(control+Z)则会EOF(end of file)，反之不会
  // {
  //     putchar(ch);
  // }

  // char cha='\0';
  // while((cha=getchar())!=EOF)
  // {
  //     if(cha<'0'||cha>'9')//实际比较的是ASCII码
  //     continue;
  //     putchar(cha);
  // }//只输出数字字符(串)

  // while循环

  int i = 0;
  for (i = 1; i <= 10; i++) // for(初始化语句；条件判断语句；调整)
  // 如果条件判断句是i=0则0次循环，因为此为赋值i为0，0为假条件失败
  {
    printf("%d\n", i);
  }
  // for循环

  i = 0;
  do
  {
    printf("%d\n", i);
    i++;
  } while (i <= 10); // 先执行一次循环之后才进行判断(循环至少会执行一次)
  // do..while循环

  char arr1[] = "Welcome to yaomeng!";
  char arr2[] = "###################";
  int left = 0;
  int right = strlen(arr2) - 1;
  while (left <= right)
  {
    arr2[left] = arr1[left];
    arr2[right] = arr1[right];
    printf("%s\n", arr2);
    sleep(1);        // 休眠函数，休眠1s
    system("clear"); // 执行系统命令，清空屏幕
    left++;
    right--;
  }

  char inputs[20] = {0};
  system("sudo shutdown -h +1 "); // mac系统 1 分钟后关机
again:
  printf("请注意,你的电脑将在60s内关机,若输入我是猪,则阻止关机\n");
  scanf("%s", inputs);
  if ((strcmp(inputs, "我是猪") == 0))
    system("sudo killall shutdown"); // 取消关机
  else
    goto again;
  // goto语句

  return 0;
}
