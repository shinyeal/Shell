/*************************************************************************
	> File Name: fget.c
	> Author: 
	> Mail: 
	> Created Time: 2018年09月30日 星期日 10时59分25秒
 ************************************************************************/

//从一个配置文件中读取某个配置的值

#include <stdio.h>
#include <string.h>

//pathname: 配置文件的路径, key_name: 需要找的配置字段名, value: 配置的值存放变量
int get_conf_value(char *pathname, char *key_name, char *value) {

    FILE *fp = NULL;
    char *line = NULL, *find_word = NULL;
    size_t len = 0, find_len = 0;
    ssize_t read;
    fp = fopen(pathname, "r");
    if(fp == NULL) {
        printf("error fp");
    }

    while((read = getline(&line, &len, fp)) > 0) {
        find_word = strstr(line, key_name);
        if(find_word != NULL) {
            find_len = strlen(key_name);
            if(line[find_len] == '=') {
                strncpy(value, &line[find_len + 1], (int)read - find_len - 1);
                find_len = strlen(value);
                *(value + find_len - 1) = '\0';
                //value ：等号后边value值 首地址的值
                break;
            }
        }
    }
}

int main() {

    FILE *fp;
    char filepath[20] = "/etc/PiHealth.conf";
    fp = fopen(filepath, "r");
    char key_name[20] = "IP";
    char value[20] = {0};
    get_conf_value(filepath, key_name, value);
    printf("%s\n", value);
    return 0;
}

