/*************************************************************************
	> File Name: common.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月12日 星期日 19时18分31秒
 ************************************************************************/

#include "./head.h"


void printfName() {
    struct passwd *pwd;
    uid_t uid = getuid();
    pwd = getpwuid(uid);
    printf("[%s@", pwd->pw_name);
    //printf("\npw_dir = %s", pwd->pw_dir);
}
void printfHostName() {
    char name[100] = {0};
    gethostname(name, sizeof(name) - 1);
    for (int i = 0; i < sizeof(name); i++) {
        if (name[i] == '.') return ;
        printf("%c", name[i]);
    }
}

void printfDir() {
    char dir[100] = {0};
    getcwd(dir, sizeof(dir));
    int len = strlen(dir);
    int cnt = 1;
    while (dir[len - cnt] != '/') {
        cnt++;
    }
    printf(" %s]$ ", dir + len - cnt + 1);
}


void myShell() {
    while (1) {
        printfName();
        printfHostName();
        printfDir();
        char line[512];
        fgets(line, sizeof(line), stdin);
        char* argv[10];
        char* start = line;
        argv[0] = start;
        int n = strlen(start);
        int cnt = 0;
        int flagStart;
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (line[i] == ' ') {
                line[i] = '\0';
                if (i + 1 < n && line[i + 1] != ' ') 
                    flag = 1;
            } 
            if (flag == 1) {
                cnt++;
                argv[cnt] = line + i + 1;
                flag = 0;
            }
        }
        for (int i = 0; i <= cnt; i++) {
            printf("%s\n", argv[i]);
        }


        if ()
    }
}
