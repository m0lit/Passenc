// (c) Clive Martin 2020 with a little help from Ian Leitch
// Version 1.2 now accepts command line parameters

// Add Libraries to the program.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define variables, constants etc.
const float _version = 1.23;
const int _minPassLen = 4;
const int _maxPassLen = 24;
const int _minColPos = 0;
const int _maxColPos = 999;
const int _maxEnc = 3;

int _passlen;
int _colPos;
int _pcharCount;
int _shift;
int _charPos;
int _enc;

// Assign cyphers, charSel is the cypher used for encoding.
char* _password;
const char *_charSel1 = "XvotGBGUd8anJUTS5wBKuMXFcXDXEuwoqni711bfBFTVlyxqxBBtak9DKOmbJjSBXBKZEyHQEkv0mvsk97gjtswFHksbWLo7Y9im80FMmBOb7KNJR63Ly3cHpVsOshVRqGH0GWO6iphrA7DdEHyDMeUCAPc699X3Pq3iOTq9JY3ViH9waBCypjD29p8J1iMTZRC0w59JfFoOY1N9Ca84KL6VDFqFxFiZiwag2l2h1s7btWk87uCTIJ2WasnaBWAtTmcXZeFcYOFUv2d5xrbIBdqnYgOjDZgiOJGx1Ybbws6uul1ugeGtI9isq7d4iMp8f88iglKgeTbcHeXxJnsbxdXomDuYZmiHvq1cfLJMqvy9aX9wN4YNh8EXLC6uyoDuhEYPbtmVrleTLpQju19eCOEXaKTZBiXvw6La286uwmQIds4avEH8cWgFsCq7uO5rWSUZdbUaQws6pxilE1usZd8UpydkQiewE9Yrm5UE2PMrP6gd9dWkHeF7gvt9eY8uhhmXoHnrhAl9IUnR8KCP2SYkQSt7123llrLbC9VvLH5ems6wELNIpx3GRyNU1QInJfRVowRDGWr3S01gLQ1BO4Tr5rP6IjvdQPBFMcUdCOiePlNmCQ1dWUXbMwhhhgN86ZPVEw9SLr7mgWcswdYTA75Z6pHpYg0eGSAXPL0kGAYwgDrgqRC1aKciAvbkdbRt4eRT0UHGerFL584xbHyEbeynaaYED2BHgenh950nyGC4QI22Z3IDhH3JsdZ8gmPNSF7dM8ULQiPq1TudXDqHWwcPaDXH00hUFoBcwf0POQGPvB3TQwn0tQRUf2oi2YDJNOxN6ymUR4wNH2tkyhksAEQqGHZIpoeFGecMfQt9WsXpuTcuDPpNeIEuZpGRfwhxbMMKoITNB3E7Ws4jJtA0FQuqHDJyA3woPL9FeccrisyFm5282E8He58vJRwVWvKwITEy9sqrms9bxDl0TvH91S7Mv5uT3FSLlgMwZEqO9207InIUGDIUGRIUGSkjlkjkjhfksdf79324guygv980w9euoviuhv098ubhZxc09UH0UHDHBJSDVFyg23ghvbcaaxscdclmlmlmLKSJDLJAljTwnv5CsC7MFPodB";
const char *_charSel2 = "W91ie?%e0ZY0v97AV8IDJD!vpnl@6$wxCBh4Ix%dXoyf?6ypZT36pF2f30xU4vTbJBkL&btmh56t%oN7%QW66iGHEfDqTfEVcimQwtQq#fk3ULVZuEDATdX93ay%1gt&TK5Zt&hl$@Hao3h34%Mhu63AEFF%9WkokKv$Fh@XBsMNaZnq8VlOt9c9jPYA$WqyZ6trm5kMoL&cCPKB0QfmiPLdZegIVs4wm&w4J5Naqv0NJAx#9sXAEB&$4Ok@bu&trMvBaWuee72?Q0Iu625TYNil?g&ub1oTixnKgu#L2MeoW@jl82RpYBnfsao7cIyaIVTDpxaDcP&iAq3LU5$£u#h$FKLQ7y@jO#t0LWYQR%TdP#re0?lF6UIg1!JUyPEaY9j6UgTZAJBUO!qVx6wSjpdv98#ihiT3Su5@btr#D4okGfSE?PqrFg!Y1#T%q98V4YoegD@2mMrRw2n6Sg7D$F?JBRxbCyp!s3yEYISVgfVvLCFhRewYA8DK&YKulDAnOk@Ffb&Y75$eTw6KtdFE#K#eSt4xtbi?u#!WGY!Ube#k?SfB7%kRasIF!VE@J9HEHH?hyAOmxWX80PSSTD6HJXrV36nVb5@V4vUNLTX42DaUH%7tZnl5!id8ory5gbYALlXNCL5PlLgf%gdLtrZch$da$rnjfY6DWnw%92U7iN#y4lKAe$vM?Z9Dd99V$OsaOpeg4L0v%KuLJReAUbrnN2DEWVsa%xNSnEMjh0!3%LVh1DxsDL7aun6aMy?ynLXHF2IdImL1wMZuG#TWuaK2b7jbEuPjSc1rnehJS4TbZFjyNPWJ03glKcZhYBd1w5lfw5K1t@j9pjrFSNaeGYB$8$bSslQ@4Om1oJNuPJGR3KqrdW8OqBg@vL3u?9#h&LWP%d1N$cmOqdSgMj6Q&#W4Ti#n5JVMnFu%9S9?FsxLfP5?yM6hauduirFREFpMK%qvDxNI#Pmn15uCmD7Z9tVx@eOXUtZk";
const char *_charSel3 = "AOfjsld8WFLOeastZdLZwhOjsigDV5j6uTBsgy1PEiw6JpC5UgnROONTJG2VxHcdcVKbs@2b$T7@oLmhMQI@wucE1n&#5tm$PJqUP$6fiMxY%kScNuiKpLt3L2Ca&BphphCGwe8f16QH3$$Zxy6!WD4ObogveOlYvEVahOx0xFC4V?2gQFDmSFN4G4C8nApwkYXS@hc7A1LoLihu?%hZW5yvVNGVt7Seo1J?r8EEJi3netil2cYt$jY8J52Zga$Lh#d&M9l9fr4d$pCws@!eQVsn5lpoNW11niVgnsZ4Xo$&y0E2nngsnuqpv&EeIaS27gr7ZdL7TaPSjmdjnWobRsSZxEHce&iWDVBhx!UNSFBIBBxDvb6aBGckgSmLXi5tEbnOnJvStJtHd%dlf&N3MCwF!vwYqEeHyfpyBxR5HLh%bMpHdPfCxobxwYiovOI?4K@OIXou5W2p55J&d#Hn0m@aV?i6cJ@#$Pr%W@ni#wR?mlPbudOddR6CxD&X8gQCDi08rF5VYIAdDxERPTnu2xK465X#qsMZ6pdg&AFAbZw1jNc9!cGFmkS$2025jbWaSDflcyZO#j8VYchN5@B2kED@bFCM4r@f6xd%0DeK9v2rksFy3Z2w0O%l!S84WQslaWv&gSEod6lihl?H0&djCPj!s0WVVIkXQpRHGrW3aQ1i%M!hIOJ3OCC7$RlLOK?F?0rNaln2vi6UiwwJGC$njBqB@OjcVBjq3K%m6r1FnGsWPp3E6o#QrVjSRMAxJD1mH15MNTAnZPb5R!LG#?Ldq0IQKG&gdrB!9sNy3BYHkAWOM4!UBLLFVyo2Ft%xRJKQIiw!1tNgIs@JaH!8rh7gsVm1YwbmT@DuoN#2HVrvOxFBSRSKAiEFFDP0NEv!WMuXs$jMkbIAmsgRLAuqL6Tifc66Z6l8DJ1H3iE2jn7RRbkYem%uTmm65Kn9s7VAKFYXcIXs&#hpgMpkHJj4YxImU68OZnt63emAKt";
const char *_charSel = "";

// Procedure to exit cleanly on error capture.
 int errorTrap(int errType){
	printf("\nPassword Encoder v%.2f\n", _version);
	switch (errType){
		case 1:
			printf("\nEncoder value should be between 1 and %d.\n\n\n", _maxEnc);
		exit(1);
		break;
		case 2:
			printf("\nPIN needs to between %d and %d.\n\n\n", _minColPos, _maxColPos);
		exit(2);
		break;
		case 3:
			printf("\nYour password should be between %d and %d characters.\n\n\n", _minPassLen,  _maxPassLen);
		exit(3);
		break;
		case 4:
			printf("\nUsaage: passenc [Encoder (1-%d), Pin (%d-%d), Password (aa-ZZ, 0-9)]\n", _maxEnc, _minColPos, _maxColPos);
			printf("e.g.    passenc 1 100 Password1\n\n");
		exit(4);
		break;
		default:
		printf("\n\n");
	}
	return 0;
}

// Main program executes from here.
 int main(int argc, char** argv){

// Check to see if we have the correct number of paramters passed to the program from command line
 if (argc < 4){
	errorTrap(4);
 }

// Convert Encoder value to decimal from command line args.
 _enc = atoi(argv[1]);
// Convert Pin value to decimal from command line args.
 _colPos = atoi(argv[2]);
// Assign password to variable
 _password = argv[3];

// Get Encoder vaule, quit gracefully if necessary.
 if (_enc < 1 || _enc > 3){
	errorTrap(1);
 }

 _passlen = strlen(_password);

// Check pin vaule and quit gracefully if necessary.
 if (_colPos < 0 || _colPos >999){
	errorTrap(2);
 }

// Check password limits and quit gracefully if necessary.
 if (_passlen < _minPassLen || _passlen > _maxPassLen){ 
      	errorTrap(3);
 }

// Select the cypher depoending on users selection.
 switch (_enc){
 	case 1:
	_charSel = _charSel1;
	break;
	case 2:
 	_charSel = _charSel2;
	break;
	case 3:
	_charSel = _charSel3;
	break;
 }

 printf("Password Encoder v%.2f\n\n", _version);
 printf("%d %d %s = ", _enc, _colPos, _password);

//Here is where we encode the password.
	for (_pcharCount = _colPos; _pcharCount < (_passlen + _colPos); _pcharCount++){
		// Loop from Pin pos to Pin Pos + password length.
		_shift = _charSel[_pcharCount] ^ _password[_pcharCount-_colPos];
		// Take a characacter from from charSel at poition from loop above, xor it with the character from  password at postition within password length.
		_charPos = _shift + _colPos;
		// Shift position from colPos.
		if (_charPos < 1){
			_charPos = 1;
		}
		if (_charPos >= 1000){
			_charPos = (_pcharCount-_colPos)+_passlen;
		}
		// Lets print the encrypted character selected from the cypher.
		printf("%c", _charSel[_charPos]);
	}
 for (int count = 0; count<2; count++){
 	printf("\n");
 }
 return 0;
}
