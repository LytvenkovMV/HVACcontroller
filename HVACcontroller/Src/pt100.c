
#include "pt100.h"
#include "pt100_lookup.h"



uint8_t PT100_CalcDecimalDigits(uint32_t value, uint32_t const lowerValue, uint32_t const upperValue)
{
	uint8_t decimalDigits = 0;

	decimalDigits = (100 * (value - lowerValue)) / (upperValue - lowerValue);

	return decimalDigits;
}



int32_t PT100_CalcTemperature(uint32_t resistance1000000)
{
	int32_t temp = 0;
	uint32_t resistance = resistance1000000;

	/* If resistance is outside the limits, return */
	if (resistance <= PT100_000) return -5000;
	if (resistance >= PT100_200) return 15000;

	/* Calculate the relative temperature (Trel = Treal + SHIFT) */
	if      (resistance < PT100_001) temp = 0     + PT100_CalcDecimalDigits(resistance, PT100_000, PT100_001);
	else if (resistance < PT100_002) temp = 100   + PT100_CalcDecimalDigits(resistance, PT100_001, PT100_002);
	else if (resistance < PT100_003) temp = 200   + PT100_CalcDecimalDigits(resistance, PT100_002, PT100_003);
	else if (resistance < PT100_004) temp = 300   + PT100_CalcDecimalDigits(resistance, PT100_003, PT100_004);
	else if (resistance < PT100_005) temp = 400   + PT100_CalcDecimalDigits(resistance, PT100_004, PT100_005);
	else if (resistance < PT100_006) temp = 500   + PT100_CalcDecimalDigits(resistance, PT100_005, PT100_006);
	else if (resistance < PT100_007) temp = 600   + PT100_CalcDecimalDigits(resistance, PT100_006, PT100_007);
	else if (resistance < PT100_008) temp = 700   + PT100_CalcDecimalDigits(resistance, PT100_007, PT100_008);
	else if (resistance < PT100_009) temp = 800   + PT100_CalcDecimalDigits(resistance, PT100_008, PT100_009);
	else if (resistance < PT100_010) temp = 900   + PT100_CalcDecimalDigits(resistance, PT100_009, PT100_010);
	else if (resistance < PT100_011) temp = 1000  + PT100_CalcDecimalDigits(resistance, PT100_010, PT100_011);
	else if (resistance < PT100_012) temp = 1100  + PT100_CalcDecimalDigits(resistance, PT100_011, PT100_012);
	else if (resistance < PT100_013) temp = 1200  + PT100_CalcDecimalDigits(resistance, PT100_012, PT100_013);
	else if (resistance < PT100_014) temp = 1300  + PT100_CalcDecimalDigits(resistance, PT100_013, PT100_014);
	else if (resistance < PT100_015) temp = 1400  + PT100_CalcDecimalDigits(resistance, PT100_014, PT100_015);
	else if (resistance < PT100_016) temp = 1500  + PT100_CalcDecimalDigits(resistance, PT100_015, PT100_016);
	else if (resistance < PT100_017) temp = 1600  + PT100_CalcDecimalDigits(resistance, PT100_016, PT100_017);
	else if (resistance < PT100_018) temp = 1700  + PT100_CalcDecimalDigits(resistance, PT100_017, PT100_018);
	else if (resistance < PT100_019) temp = 1800  + PT100_CalcDecimalDigits(resistance, PT100_018, PT100_019);
	else if (resistance < PT100_020) temp = 1900  + PT100_CalcDecimalDigits(resistance, PT100_019, PT100_020);
	else if (resistance < PT100_021) temp = 2000  + PT100_CalcDecimalDigits(resistance, PT100_020, PT100_021);
	else if (resistance < PT100_022) temp = 2100  + PT100_CalcDecimalDigits(resistance, PT100_021, PT100_022);
	else if (resistance < PT100_023) temp = 2200  + PT100_CalcDecimalDigits(resistance, PT100_022, PT100_023);
	else if (resistance < PT100_024) temp = 2300  + PT100_CalcDecimalDigits(resistance, PT100_023, PT100_024);
	else if (resistance < PT100_025) temp = 2400  + PT100_CalcDecimalDigits(resistance, PT100_024, PT100_025);
	else if (resistance < PT100_026) temp = 2500  + PT100_CalcDecimalDigits(resistance, PT100_025, PT100_026);
	else if (resistance < PT100_027) temp = 2600  + PT100_CalcDecimalDigits(resistance, PT100_026, PT100_027);
	else if (resistance < PT100_028) temp = 2700  + PT100_CalcDecimalDigits(resistance, PT100_027, PT100_028);
	else if (resistance < PT100_029) temp = 2800  + PT100_CalcDecimalDigits(resistance, PT100_028, PT100_029);
	else if (resistance < PT100_030) temp = 2900  + PT100_CalcDecimalDigits(resistance, PT100_029, PT100_030);
	else if (resistance < PT100_031) temp = 3000  + PT100_CalcDecimalDigits(resistance, PT100_030, PT100_031);
	else if (resistance < PT100_032) temp = 3100  + PT100_CalcDecimalDigits(resistance, PT100_031, PT100_032);
	else if (resistance < PT100_033) temp = 3200  + PT100_CalcDecimalDigits(resistance, PT100_032, PT100_033);
	else if (resistance < PT100_034) temp = 3300  + PT100_CalcDecimalDigits(resistance, PT100_033, PT100_034);
	else if (resistance < PT100_035) temp = 3400  + PT100_CalcDecimalDigits(resistance, PT100_034, PT100_035);
	else if (resistance < PT100_036) temp = 3500  + PT100_CalcDecimalDigits(resistance, PT100_035, PT100_036);
	else if (resistance < PT100_037) temp = 3600  + PT100_CalcDecimalDigits(resistance, PT100_036, PT100_037);
	else if (resistance < PT100_038) temp = 3700  + PT100_CalcDecimalDigits(resistance, PT100_037, PT100_038);
	else if (resistance < PT100_039) temp = 3800  + PT100_CalcDecimalDigits(resistance, PT100_038, PT100_039);
	else if (resistance < PT100_040) temp = 3900  + PT100_CalcDecimalDigits(resistance, PT100_039, PT100_040);
	else if (resistance < PT100_041) temp = 4000  + PT100_CalcDecimalDigits(resistance, PT100_040, PT100_041);
	else if (resistance < PT100_042) temp = 4100  + PT100_CalcDecimalDigits(resistance, PT100_041, PT100_042);
	else if (resistance < PT100_043) temp = 4200  + PT100_CalcDecimalDigits(resistance, PT100_042, PT100_043);
	else if (resistance < PT100_044) temp = 4300  + PT100_CalcDecimalDigits(resistance, PT100_043, PT100_044);
	else if (resistance < PT100_045) temp = 4400  + PT100_CalcDecimalDigits(resistance, PT100_044, PT100_045);
	else if (resistance < PT100_046) temp = 4500  + PT100_CalcDecimalDigits(resistance, PT100_045, PT100_046);
	else if (resistance < PT100_047) temp = 4600  + PT100_CalcDecimalDigits(resistance, PT100_046, PT100_047);
	else if (resistance < PT100_048) temp = 4700  + PT100_CalcDecimalDigits(resistance, PT100_047, PT100_048);
	else if (resistance < PT100_049) temp = 4800  + PT100_CalcDecimalDigits(resistance, PT100_048, PT100_049);
	else if (resistance < PT100_050) temp = 4900  + PT100_CalcDecimalDigits(resistance, PT100_049, PT100_050);
	else if (resistance < PT100_051) temp = 5000  + PT100_CalcDecimalDigits(resistance, PT100_050, PT100_051);
	else if (resistance < PT100_052) temp = 5100  + PT100_CalcDecimalDigits(resistance, PT100_051, PT100_052);
	else if (resistance < PT100_053) temp = 5200  + PT100_CalcDecimalDigits(resistance, PT100_052, PT100_053);
	else if (resistance < PT100_054) temp = 5300  + PT100_CalcDecimalDigits(resistance, PT100_053, PT100_054);
	else if (resistance < PT100_055) temp = 5400  + PT100_CalcDecimalDigits(resistance, PT100_054, PT100_055);
	else if (resistance < PT100_056) temp = 5500  + PT100_CalcDecimalDigits(resistance, PT100_055, PT100_056);
	else if (resistance < PT100_057) temp = 5600  + PT100_CalcDecimalDigits(resistance, PT100_056, PT100_057);
	else if (resistance < PT100_058) temp = 5700  + PT100_CalcDecimalDigits(resistance, PT100_057, PT100_058);
	else if (resistance < PT100_059) temp = 5800  + PT100_CalcDecimalDigits(resistance, PT100_058, PT100_059);
	else if (resistance < PT100_060) temp = 5900  + PT100_CalcDecimalDigits(resistance, PT100_059, PT100_060);
	else if (resistance < PT100_061) temp = 6000  + PT100_CalcDecimalDigits(resistance, PT100_060, PT100_061);
	else if (resistance < PT100_062) temp = 6100  + PT100_CalcDecimalDigits(resistance, PT100_061, PT100_062);
	else if (resistance < PT100_063) temp = 6200  + PT100_CalcDecimalDigits(resistance, PT100_062, PT100_063);
	else if (resistance < PT100_064) temp = 6300  + PT100_CalcDecimalDigits(resistance, PT100_063, PT100_064);
	else if (resistance < PT100_065) temp = 6400  + PT100_CalcDecimalDigits(resistance, PT100_064, PT100_065);
	else if (resistance < PT100_066) temp = 6500  + PT100_CalcDecimalDigits(resistance, PT100_065, PT100_066);
	else if (resistance < PT100_067) temp = 6600  + PT100_CalcDecimalDigits(resistance, PT100_066, PT100_067);
	else if (resistance < PT100_068) temp = 6700  + PT100_CalcDecimalDigits(resistance, PT100_067, PT100_068);
	else if (resistance < PT100_069) temp = 6800  + PT100_CalcDecimalDigits(resistance, PT100_068, PT100_069);
	else if (resistance < PT100_070) temp = 6900  + PT100_CalcDecimalDigits(resistance, PT100_069, PT100_070);
	else if (resistance < PT100_071) temp = 7000  + PT100_CalcDecimalDigits(resistance, PT100_070, PT100_071);
	else if (resistance < PT100_072) temp = 7100  + PT100_CalcDecimalDigits(resistance, PT100_071, PT100_072);
	else if (resistance < PT100_073) temp = 7200  + PT100_CalcDecimalDigits(resistance, PT100_072, PT100_073);
	else if (resistance < PT100_074) temp = 7300  + PT100_CalcDecimalDigits(resistance, PT100_073, PT100_074);
	else if (resistance < PT100_075) temp = 7400  + PT100_CalcDecimalDigits(resistance, PT100_074, PT100_075);
	else if (resistance < PT100_076) temp = 7500  + PT100_CalcDecimalDigits(resistance, PT100_075, PT100_076);
	else if (resistance < PT100_077) temp = 7600  + PT100_CalcDecimalDigits(resistance, PT100_076, PT100_077);
	else if (resistance < PT100_078) temp = 7700  + PT100_CalcDecimalDigits(resistance, PT100_077, PT100_078);
	else if (resistance < PT100_079) temp = 7800  + PT100_CalcDecimalDigits(resistance, PT100_078, PT100_079);
	else if (resistance < PT100_080) temp = 7900  + PT100_CalcDecimalDigits(resistance, PT100_079, PT100_080);
	else if (resistance < PT100_081) temp = 8000  + PT100_CalcDecimalDigits(resistance, PT100_080, PT100_081);
	else if (resistance < PT100_082) temp = 8100  + PT100_CalcDecimalDigits(resistance, PT100_081, PT100_082);
	else if (resistance < PT100_083) temp = 8200  + PT100_CalcDecimalDigits(resistance, PT100_082, PT100_083);
	else if (resistance < PT100_084) temp = 8300  + PT100_CalcDecimalDigits(resistance, PT100_083, PT100_084);
	else if (resistance < PT100_085) temp = 8400  + PT100_CalcDecimalDigits(resistance, PT100_084, PT100_085);
	else if (resistance < PT100_086) temp = 8500  + PT100_CalcDecimalDigits(resistance, PT100_085, PT100_086);
	else if (resistance < PT100_087) temp = 8600  + PT100_CalcDecimalDigits(resistance, PT100_086, PT100_087);
	else if (resistance < PT100_088) temp = 8700  + PT100_CalcDecimalDigits(resistance, PT100_087, PT100_088);
	else if (resistance < PT100_089) temp = 8800  + PT100_CalcDecimalDigits(resistance, PT100_088, PT100_089);
	else if (resistance < PT100_090) temp = 8900  + PT100_CalcDecimalDigits(resistance, PT100_089, PT100_090);
	else if (resistance < PT100_091) temp = 9000  + PT100_CalcDecimalDigits(resistance, PT100_090, PT100_091);
	else if (resistance < PT100_092) temp = 9100  + PT100_CalcDecimalDigits(resistance, PT100_091, PT100_092);
	else if (resistance < PT100_093) temp = 9200  + PT100_CalcDecimalDigits(resistance, PT100_092, PT100_093);
	else if (resistance < PT100_094) temp = 9300  + PT100_CalcDecimalDigits(resistance, PT100_093, PT100_094);
	else if (resistance < PT100_095) temp = 9400  + PT100_CalcDecimalDigits(resistance, PT100_094, PT100_095);
	else if (resistance < PT100_096) temp = 9500  + PT100_CalcDecimalDigits(resistance, PT100_095, PT100_096);
	else if (resistance < PT100_097) temp = 9600  + PT100_CalcDecimalDigits(resistance, PT100_096, PT100_097);
	else if (resistance < PT100_098) temp = 9700  + PT100_CalcDecimalDigits(resistance, PT100_097, PT100_098);
	else if (resistance < PT100_099) temp = 9800  + PT100_CalcDecimalDigits(resistance, PT100_098, PT100_099);
	else if (resistance < PT100_100) temp = 9900  + PT100_CalcDecimalDigits(resistance, PT100_099, PT100_100);
	else if (resistance < PT100_101) temp = 10000 + PT100_CalcDecimalDigits(resistance, PT100_100, PT100_101);
	else if (resistance < PT100_102) temp = 10100 + PT100_CalcDecimalDigits(resistance, PT100_101, PT100_102);
	else if (resistance < PT100_103) temp = 10200 + PT100_CalcDecimalDigits(resistance, PT100_102, PT100_103);
	else if (resistance < PT100_104) temp = 10300 + PT100_CalcDecimalDigits(resistance, PT100_103, PT100_104);
	else if (resistance < PT100_105) temp = 10400 + PT100_CalcDecimalDigits(resistance, PT100_104, PT100_105);
	else if (resistance < PT100_106) temp = 10500 + PT100_CalcDecimalDigits(resistance, PT100_105, PT100_106);
	else if (resistance < PT100_107) temp = 10600 + PT100_CalcDecimalDigits(resistance, PT100_106, PT100_107);
	else if (resistance < PT100_108) temp = 10700 + PT100_CalcDecimalDigits(resistance, PT100_107, PT100_108);
	else if (resistance < PT100_109) temp = 10800 + PT100_CalcDecimalDigits(resistance, PT100_108, PT100_109);
	else if (resistance < PT100_110) temp = 10900 + PT100_CalcDecimalDigits(resistance, PT100_109, PT100_110);
	else if (resistance < PT100_111) temp = 11000 + PT100_CalcDecimalDigits(resistance, PT100_110, PT100_111);
	else if (resistance < PT100_112) temp = 11100 + PT100_CalcDecimalDigits(resistance, PT100_111, PT100_112);
	else if (resistance < PT100_113) temp = 11200 + PT100_CalcDecimalDigits(resistance, PT100_112, PT100_113);
	else if (resistance < PT100_114) temp = 11300 + PT100_CalcDecimalDigits(resistance, PT100_113, PT100_114);
	else if (resistance < PT100_115) temp = 11400 + PT100_CalcDecimalDigits(resistance, PT100_114, PT100_115);
	else if (resistance < PT100_116) temp = 11500 + PT100_CalcDecimalDigits(resistance, PT100_115, PT100_116);
	else if (resistance < PT100_117) temp = 11600 + PT100_CalcDecimalDigits(resistance, PT100_116, PT100_117);
	else if (resistance < PT100_118) temp = 11700 + PT100_CalcDecimalDigits(resistance, PT100_117, PT100_118);
	else if (resistance < PT100_119) temp = 11800 + PT100_CalcDecimalDigits(resistance, PT100_118, PT100_119);
	else if (resistance < PT100_120) temp = 11900 + PT100_CalcDecimalDigits(resistance, PT100_119, PT100_120);
	else if (resistance < PT100_121) temp = 12000 + PT100_CalcDecimalDigits(resistance, PT100_120, PT100_121);
	else if (resistance < PT100_122) temp = 12100 + PT100_CalcDecimalDigits(resistance, PT100_121, PT100_122);
	else if (resistance < PT100_123) temp = 12200 + PT100_CalcDecimalDigits(resistance, PT100_122, PT100_123);
	else if (resistance < PT100_124) temp = 12300 + PT100_CalcDecimalDigits(resistance, PT100_123, PT100_124);
	else if (resistance < PT100_125) temp = 12400 + PT100_CalcDecimalDigits(resistance, PT100_124, PT100_125);
	else if (resistance < PT100_126) temp = 12500 + PT100_CalcDecimalDigits(resistance, PT100_125, PT100_126);
	else if (resistance < PT100_127) temp = 12600 + PT100_CalcDecimalDigits(resistance, PT100_126, PT100_127);
	else if (resistance < PT100_128) temp = 12700 + PT100_CalcDecimalDigits(resistance, PT100_127, PT100_128);
	else if (resistance < PT100_129) temp = 12800 + PT100_CalcDecimalDigits(resistance, PT100_128, PT100_129);
	else if (resistance < PT100_130) temp = 12900 + PT100_CalcDecimalDigits(resistance, PT100_129, PT100_130);
	else if (resistance < PT100_131) temp = 13000 + PT100_CalcDecimalDigits(resistance, PT100_130, PT100_131);
	else if (resistance < PT100_132) temp = 13100 + PT100_CalcDecimalDigits(resistance, PT100_131, PT100_132);
	else if (resistance < PT100_133) temp = 13200 + PT100_CalcDecimalDigits(resistance, PT100_132, PT100_133);
	else if (resistance < PT100_134) temp = 13300 + PT100_CalcDecimalDigits(resistance, PT100_133, PT100_134);
	else if (resistance < PT100_135) temp = 13400 + PT100_CalcDecimalDigits(resistance, PT100_134, PT100_135);
	else if (resistance < PT100_136) temp = 13500 + PT100_CalcDecimalDigits(resistance, PT100_135, PT100_136);
	else if (resistance < PT100_137) temp = 13600 + PT100_CalcDecimalDigits(resistance, PT100_136, PT100_137);
	else if (resistance < PT100_138) temp = 13700 + PT100_CalcDecimalDigits(resistance, PT100_137, PT100_138);
	else if (resistance < PT100_139) temp = 13800 + PT100_CalcDecimalDigits(resistance, PT100_138, PT100_139);
	else if (resistance < PT100_140) temp = 13900 + PT100_CalcDecimalDigits(resistance, PT100_139, PT100_140);
	else if (resistance < PT100_141) temp = 14000 + PT100_CalcDecimalDigits(resistance, PT100_140, PT100_141);
	else if (resistance < PT100_142) temp = 14100 + PT100_CalcDecimalDigits(resistance, PT100_141, PT100_142);
	else if (resistance < PT100_143) temp = 14200 + PT100_CalcDecimalDigits(resistance, PT100_142, PT100_143);
	else if (resistance < PT100_144) temp = 14300 + PT100_CalcDecimalDigits(resistance, PT100_143, PT100_144);
	else if (resistance < PT100_145) temp = 14400 + PT100_CalcDecimalDigits(resistance, PT100_144, PT100_145);
	else if (resistance < PT100_146) temp = 14500 + PT100_CalcDecimalDigits(resistance, PT100_145, PT100_146);
	else if (resistance < PT100_147) temp = 14600 + PT100_CalcDecimalDigits(resistance, PT100_146, PT100_147);
	else if (resistance < PT100_148) temp = 14700 + PT100_CalcDecimalDigits(resistance, PT100_147, PT100_148);
	else if (resistance < PT100_149) temp = 14800 + PT100_CalcDecimalDigits(resistance, PT100_148, PT100_149);
	else if (resistance < PT100_150) temp = 14900 + PT100_CalcDecimalDigits(resistance, PT100_149, PT100_150);
	else if (resistance < PT100_151) temp = 15000 + PT100_CalcDecimalDigits(resistance, PT100_150, PT100_151);
	else if (resistance < PT100_152) temp = 15100 + PT100_CalcDecimalDigits(resistance, PT100_151, PT100_152);
	else if (resistance < PT100_153) temp = 15200 + PT100_CalcDecimalDigits(resistance, PT100_152, PT100_153);
	else if (resistance < PT100_154) temp = 15300 + PT100_CalcDecimalDigits(resistance, PT100_153, PT100_154);
	else if (resistance < PT100_155) temp = 15400 + PT100_CalcDecimalDigits(resistance, PT100_154, PT100_155);
	else if (resistance < PT100_156) temp = 15500 + PT100_CalcDecimalDigits(resistance, PT100_155, PT100_156);
	else if (resistance < PT100_157) temp = 15600 + PT100_CalcDecimalDigits(resistance, PT100_156, PT100_157);
	else if (resistance < PT100_158) temp = 15700 + PT100_CalcDecimalDigits(resistance, PT100_157, PT100_158);
	else if (resistance < PT100_159) temp = 15800 + PT100_CalcDecimalDigits(resistance, PT100_158, PT100_159);
	else if (resistance < PT100_160) temp = 15900 + PT100_CalcDecimalDigits(resistance, PT100_159, PT100_160);
	else if (resistance < PT100_161) temp = 16000 + PT100_CalcDecimalDigits(resistance, PT100_160, PT100_161);
	else if (resistance < PT100_162) temp = 16100 + PT100_CalcDecimalDigits(resistance, PT100_161, PT100_162);
	else if (resistance < PT100_163) temp = 16200 + PT100_CalcDecimalDigits(resistance, PT100_162, PT100_163);
	else if (resistance < PT100_164) temp = 16300 + PT100_CalcDecimalDigits(resistance, PT100_163, PT100_164);
	else if (resistance < PT100_165) temp = 16400 + PT100_CalcDecimalDigits(resistance, PT100_164, PT100_165);
	else if (resistance < PT100_166) temp = 16500 + PT100_CalcDecimalDigits(resistance, PT100_165, PT100_166);
	else if (resistance < PT100_167) temp = 16600 + PT100_CalcDecimalDigits(resistance, PT100_166, PT100_167);
	else if (resistance < PT100_168) temp = 16700 + PT100_CalcDecimalDigits(resistance, PT100_167, PT100_168);
	else if (resistance < PT100_169) temp = 16800 + PT100_CalcDecimalDigits(resistance, PT100_168, PT100_169);
	else if (resistance < PT100_170) temp = 16900 + PT100_CalcDecimalDigits(resistance, PT100_169, PT100_170);
	else if (resistance < PT100_171) temp = 17000 + PT100_CalcDecimalDigits(resistance, PT100_170, PT100_171);
	else if (resistance < PT100_172) temp = 17100 + PT100_CalcDecimalDigits(resistance, PT100_171, PT100_172);
	else if (resistance < PT100_173) temp = 17200 + PT100_CalcDecimalDigits(resistance, PT100_172, PT100_173);
	else if (resistance < PT100_174) temp = 17300 + PT100_CalcDecimalDigits(resistance, PT100_173, PT100_174);
	else if (resistance < PT100_175) temp = 17400 + PT100_CalcDecimalDigits(resistance, PT100_174, PT100_175);
	else if (resistance < PT100_176) temp = 17500 + PT100_CalcDecimalDigits(resistance, PT100_175, PT100_176);
	else if (resistance < PT100_177) temp = 17600 + PT100_CalcDecimalDigits(resistance, PT100_176, PT100_177);
	else if (resistance < PT100_178) temp = 17700 + PT100_CalcDecimalDigits(resistance, PT100_177, PT100_178);
	else if (resistance < PT100_179) temp = 17800 + PT100_CalcDecimalDigits(resistance, PT100_178, PT100_179);
	else if (resistance < PT100_180) temp = 17900 + PT100_CalcDecimalDigits(resistance, PT100_179, PT100_180);
	else if (resistance < PT100_181) temp = 18000 + PT100_CalcDecimalDigits(resistance, PT100_180, PT100_181);
	else if (resistance < PT100_182) temp = 18100 + PT100_CalcDecimalDigits(resistance, PT100_181, PT100_182);
	else if (resistance < PT100_183) temp = 18200 + PT100_CalcDecimalDigits(resistance, PT100_182, PT100_183);
	else if (resistance < PT100_184) temp = 18300 + PT100_CalcDecimalDigits(resistance, PT100_183, PT100_184);
	else if (resistance < PT100_185) temp = 18400 + PT100_CalcDecimalDigits(resistance, PT100_184, PT100_185);
	else if (resistance < PT100_186) temp = 18500 + PT100_CalcDecimalDigits(resistance, PT100_185, PT100_186);
	else if (resistance < PT100_187) temp = 18600 + PT100_CalcDecimalDigits(resistance, PT100_186, PT100_187);
	else if (resistance < PT100_188) temp = 18700 + PT100_CalcDecimalDigits(resistance, PT100_187, PT100_188);
	else if (resistance < PT100_189) temp = 18800 + PT100_CalcDecimalDigits(resistance, PT100_188, PT100_189);
	else if (resistance < PT100_190) temp = 18900 + PT100_CalcDecimalDigits(resistance, PT100_189, PT100_190);
	else if (resistance < PT100_191) temp = 19000 + PT100_CalcDecimalDigits(resistance, PT100_190, PT100_191);
	else if (resistance < PT100_192) temp = 19100 + PT100_CalcDecimalDigits(resistance, PT100_191, PT100_192);
	else if (resistance < PT100_193) temp = 19200 + PT100_CalcDecimalDigits(resistance, PT100_192, PT100_193);
	else if (resistance < PT100_194) temp = 19300 + PT100_CalcDecimalDigits(resistance, PT100_193, PT100_194);
	else if (resistance < PT100_195) temp = 19400 + PT100_CalcDecimalDigits(resistance, PT100_194, PT100_195);
	else if (resistance < PT100_196) temp = 19500 + PT100_CalcDecimalDigits(resistance, PT100_195, PT100_196);
	else if (resistance < PT100_197) temp = 19600 + PT100_CalcDecimalDigits(resistance, PT100_196, PT100_197);
	else if (resistance < PT100_198) temp = 19700 + PT100_CalcDecimalDigits(resistance, PT100_197, PT100_198);
	else if (resistance < PT100_199) temp = 19800 + PT100_CalcDecimalDigits(resistance, PT100_198, PT100_199);
	else if (resistance < PT100_200) temp = 19900 + PT100_CalcDecimalDigits(resistance, PT100_199, PT100_200);

	/* Shift temperature */
	temp = temp - PT100_LOOKUP_SHIFT;

	return temp;
}
