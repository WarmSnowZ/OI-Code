/*

	����: memset0
	��վ: https:// memset0.cn 
	
	����汾������Ҫ�����ʴɸ��๦�ܣ��Լ���֤һ���ȶ��ԡ�
	���ܻ������һЩע�͵�����ˮƽ������ܻ�����©���� issue ָ����
	ԭ��������ĳЩԭ���޷��ҵ����������Ȩ����ϵ�ң��һ��������� / ɾ���� 
	
	TODO:
	1. ��������Ϊ����ʱ���������ʶ����ε�����
	2. �ʴɶ���û�ͳ�ƺͱȽ� 
	3. �ʴɶ��߳� 

*/
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

#ifdef URLDownloadToFile // ���� URLDownloadToFile �����ظ� 
#undef URLDownloadToFile
#endif

typedef int (__stdcall *UDF) (LPVOID,LPCSTR,LPCSTR,DWORD,LPVOID);

UDF URLDownloadToFile = (UDF) GetProcAddress(LoadLibrary("urlmon.dll"), "URLDownloadToFileA");

char* strfind(char *text, char *temp) {
    int i = -1, j, l = strlen(temp);
    while (text[++i]) {
        for (j = 0; j < l; j++)
			if (text[i + j] == 0 || text[i + j] != temp[j])
				break;
        if (j == l)
			return text+i+l;
    }
    return 0;
}
void UTF8ToANSI(char *str) { // ����ȡ���� UTF8 ��ʽ����ҳԴ��ת��Ϊ ANSI ��ʽ 
    int len = MultiByteToWideChar(CP_UTF8, 0, str, -1, 0, 0);
    WCHAR *wsz = new WCHAR[len+1];
    len = MultiByteToWideChar(CP_UTF8, 0,str,-1,wsz,len);
    wsz[len] = 0;
    len = WideCharToMultiByte(CP_ACP, 0, wsz, -1, 0, 0, 0, 0);
    len = WideCharToMultiByte(CP_ACP, 0, wsz, -1, str, len, 0, 0);
    str[len] = 0;
    delete []wsz;
}
HANDLE hOutput;
char name[32];
int count[9];

int GetProblemDifficulty(char *file) { // ��õ�ǰ��Ŀ���Ѷ� 
    file = strfind(file, "lg-bg-");
    if (file[0] == 'r') return 0;
	if (file[0] == 'o') return 1;
    if (file[0] == 'y') return 2;
    if (file[0] == 'g' && file[2] == 'e') return 3;
    if (file[0] == 'b' && file[4] == 'l') return 4; 
    if (file[0] == 'p') return 5;
    if (file[0] == 'b' && file[4] == 'd') return 6;
    if (file[0] == 'g' && file[2] == 'a') return 7;
    return 8;
}

char DifficultyName[9][32] = {
	"�����Ѷ�",
	"�ռ�-",
	"�ռ�/���-",
	"�ռ�+/���",
	"���+/ʡѡ-",
	"ʡѡ/NOI-",
	"NOI/NOI+/CTSC",
	"��������",
	"δ֪����"
};
char DifficultySpace[9][32] = { "     ", "        ", "   ", "   ", "  ", "    ", "", "     ", "     " };

void Output(char *prob, int diff) { // ��� 
    COORD pos = {0,2};
	SetConsoleCursorPosition(hOutput, pos); 
    printf("%s ��ͳ��: %s > %s        \n", name, prob, DifficultyName[diff]);
	for (int i = 0; i < 9; i++) {
		printf("  %s:%s%6d\n", DifficultyName[i], DifficultySpace[i], count[i]);
	}
}

void problem(char *str) {
    int i = 0,len;
    DWORD unused;
    char prob[32],url[128],*file,*ptr;
    HANDLE hFile;
    while(*str != '<')prob[i++] = *str++;
    prob[i] = 0;
    sprintf(url, "https://www.luogu.org/problemnew/show/%s", prob);
    URLDownloadToFile(0,url,"download.tmp",0,0);
    hFile = CreateFile("download.tmp",GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
    len = GetFileSize(hFile,0);
    file = ptr = new char[len+3];
    ReadFile(hFile,file,len,&unused,0);
    file[len] = file[len+1] = 0;
    CloseHandle(hFile);
    file = strfind(file, "\xE9\x9A\xBE\xE5\xBA\xA6");
    if (file) {	
		int diff = GetProblemDifficulty(file);
		count[diff]++; 
		Output(prob, diff);
	} else {
		count[8]++;
		Output(prob, 8);
	}
    delete []ptr;
}

int main() {
    int uid, len, i = 0;
    DWORD unused;
    char url[128], user[16], *file, *ptr;
    HANDLE hFile;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("���������UID: ");
    scanf("%d", &uid);
    sprintf(url, "https://www.luogu.org/space/show?uid=%d",uid);
    URLDownloadToFile(0,url,"download.tmp",0,0);
    hFile = CreateFile("download.tmp",GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
    len = GetFileSize(hFile,0);
    file = new char[len+3];
    ReadFile(hFile,file,len,&unused,0);
    file[len] = file[len+1] = 0;
    CloseHandle(hFile);
    UTF8ToANSI(file);
    sprintf(user,"U%d ",uid);
    ptr = strfind(file,user);
    if (ptr != nullptr) {
        while (ptr[0] != '<' || ptr[1] != '/' || ptr[2] != 'h')
			name[i++] = *ptr++;
        printf("\n%s ��ͳ��: ",name);
        ptr = strfind(file,"ͨ����Ŀ</h2>\n[<");
        if (ptr) {
            while (*ptr != '<') {
                ptr = strfind(ptr,"\">");
                problem(ptr);
                ptr = strfind(ptr,"]\n");
            }
            int ans = 0;
            for (int i = 0; i < 9; i++)
            	ans += count[i];
            printf("�ܹ�ͨ������Ŀ��: %d\n",ans);
        } else {
			printf("δ�ҵ�ͨ������Ŀ\n");
		}
    } else {
		printf("�û�������\n");
	}
    DeleteFile("download.tmp");
    delete []file;
    printf("\n����κμ��˳�...");
    getchar();
    return 0;
}
