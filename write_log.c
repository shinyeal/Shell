/*************************************************************************
	> File Name: write_log.c
	> Author: 
	> Mail: 
	> Created Time: 2018年09月30日 星期日 16时27分35秒
 ************************************************************************/

//向文件写日志

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int write_Pi_log(char *PiHealthLog, const char *format, ...) {
    va_list arg;
    int done;
    FILE *fp = fopen(PiHealthLog, "a+");
    va_start(arg, format);

    done = vfprintf(fp, format, arg);
    va_end(arg);

    fflush(fp);
    fclose(fp);
   // return done;
}

int main() {

    char filename[50] = "/home/xinyue/test.cpp";
    char value[50] = "1010";
    write_Pi_log(filename, "Connection to %s success\n", value);

}

