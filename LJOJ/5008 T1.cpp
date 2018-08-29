// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

ll readll() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

void init(void);

map < ll, int > p;
int t, ans;
ll n;

int main() {
	freopen("T1.in", "r", stdin);
	freopen("T1.out", "w", stdout);

	init();

	t = read();
	while (t--) {
		n = readll(), ans = 0;
		for (map < ll, int > ::iterator it = p.begin(); it != p.end(); it++) 
			if (n >= it->first) ans = it->second;
			else break;
		printf("%d\n", ans);
	}

	return 0;
}


void init() {
	p[1] = 1;
	p[2] = 2;
	p[4] = 3;
	p[6] = 4;
	p[12] = 6;
	p[24] = 8;
	p[36] = 9;
	p[48] = 10;
	p[60] = 12;
	p[120] = 16;
	p[180] = 18;
	p[240] = 20;
	p[360] = 24;
	p[720] = 30;
	p[840] = 32;
	p[1260] = 36;
	p[1680] = 40;
	p[2520] = 48;
	p[5040] = 60;
	p[7560] = 64;
	p[10080] = 72;
	p[15120] = 80;
	p[20160] = 84;
	p[25200] = 90;
	p[27720] = 96;
	p[45360] = 100;
	p[50400] = 108;
	p[55440] = 120;
	p[83160] = 128;
	p[110880] = 144;
	p[166320] = 160;
	p[221760] = 168;
	p[277200] = 180;
	p[332640] = 192;
	p[498960] = 200;
	p[554400] = 216;
	p[665280] = 224;
	p[720720] = 240;
	p[1081080] = 256;
	p[1441440] = 288;
	p[2162160] = 320;
	p[2882880] = 336;
	p[3603600] = 360;
	p[4324320] = 384;
	p[6486480] = 400;
	p[7207200] = 432;
	p[8648640] = 448;
	p[10810800] = 480;
	p[14414400] = 504;
	p[17297280] = 512;
	p[21621600] = 576;
	p[32432400] = 600;
	p[36756720] = 640;
	p[43243200] = 672;
	p[61261200] = 720;
	p[73513440] = 768;
	p[110270160] = 800;
	p[122522400] = 864;
	p[147026880] = 896;
	p[183783600] = 960;
	p[245044800] = 1008;
	p[294053760] = 1024;
	p[367567200] = 1152;
	p[551350800] = 1200;
	p[698377680] = 1280;
	p[735134400] = 1344;
	p[1102701600] = 1440;
	p[1396755360] = 1536;
	p[2095133040] = 1600;
	p[2205403200] = 1680;
	p[2327925600] = 1728;
	p[2793510720] = 1792;
	p[3491888400] = 1920;
	p[4655851200] = 2016;
	p[5587021440] = 2048;
	p[6983776800] = 2304;
	p[10475665200] = 2400;
	p[13967553600] = 2688;
	p[20951330400] = 2880;
	p[27935107200] = 3072;
	p[41902660800] = 3360;
	p[48886437600] = 3456;
	p[64250746560] = 3584;
	p[73329656400] = 3600;
	p[80313433200] = 3840;
	p[97772875200] = 4032;
	p[128501493120] = 4096;
	p[146659312800] = 4320;
	p[160626866400] = 4608;
	p[240940299600] = 4800;
	p[293318625600] = 5040;
	p[321253732800] = 5376;
	p[481880599200] = 5760;
	p[642507465600] = 6144;
	p[963761198400] = 6720;
	p[1124388064800] = 6912;
	p[1606268664000] = 7168;
	p[1686582097200] = 7200;
	p[1927522396800] = 7680;
	p[2248776129600] = 8064;
	p[3212537328000] = 8192;
	p[3373164194400] = 8640;
	p[4497552259200] = 9216;
	p[6746328388800] = 10080;
	p[8995104518400] = 10368;
	p[9316358251200] = 10752;
	p[13492656777600] = 11520;
	p[18632716502400] = 12288;
	p[26985313555200] = 12960;
	p[27949074753600] = 13440;
	p[32607253879200] = 13824;
	p[46581791256000] = 14336;
	p[48910880818800] = 14400;
	p[55898149507200] = 15360;
	p[65214507758400] = 16128;
	p[93163582512000] = 16384;
	p[97821761637600] = 17280;
	p[130429015516800] = 18432;
	p[195643523275200] = 20160;
	p[260858031033600] = 20736;
	p[288807105787200] = 21504;
	p[391287046550400] = 23040;
	p[577614211574400] = 24576;
	p[782574093100800] = 25920;
	p[866421317361600] = 26880;
	p[1010824870255200] = 27648;
	p[1444035528936000] = 28672;
	p[1516237305382800] = 28800;
	p[1732842634723200] = 30720;
	p[2021649740510400] = 32256;
	p[2888071057872000] = 32768;
	p[3032474610765600] = 34560;
	p[4043299481020800] = 36864;
	p[6064949221531200] = 40320;
	p[8086598962041600] = 41472;
	p[10108248702552000] = 43008;
	p[12129898443062400] = 46080;
	p[18194847664593600] = 48384;
	p[20216497405104000] = 49152;
	p[24259796886124800] = 51840;
	p[30324746107656000] = 53760;
	p[36389695329187200] = 55296;
	p[48519593772249600] = 57600;
	p[60649492215312000] = 61440;
	p[72779390658374400] = 62208;
	p[74801040398884800] = 64512;
	p[106858629141264000] = 65536;
	p[112201560598327200] = 69120;
	p[149602080797769600] = 73728;
	p[224403121196654400] = 80640;
	p[299204161595539200] = 82944;
	p[374005201994424000] = 86016;
	p[448806242393308800] = 92160;
	p[673209363589963200] = 96768;
	p[748010403988848000] = 98304;
	p[897612484786617600] = 103680;
}