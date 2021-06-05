//全局静态变量
static int g_static_int = 291;//.data
//全局变量
int g_int = 564;//.data

//全局静态常量
const static int g_const_static_int = 789;//.rodata
//全局常量
const int g_const_int = 845;//.rodata

void ShowStatic(int nNum)
{
    static int gnNumber = 0;
    printf("%d\n", gnNumber++);
}


int main(int argc, char *argv[])//.text
{
    //局部静态变量
    static int g_f_static_int = 12;//.data
    //局部静态常量
    const static int g_f_const_static_int = 20;//.rodata
    int a = 10;

    int b = 20;
    int c = a + b;
    int d = g_static_int + g_const_static_int + g_const_int + g_int + g_f_static_int + g_f_const_static_int;
    ShowStatic(12);
    ShowStatic(13);
    return 0;
}
