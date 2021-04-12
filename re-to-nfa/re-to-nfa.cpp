// re-to-nfa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int parBul(int a, vector<bool> pKont);
string tesp(string a, string b);
string tesp2(string a);
int main() {
	string deneme = "ab*a+a*s|+da+s^d+0a^das"; 
	
	for (int i = 0; i < deneme.length(); i++) {
		switch (deneme[i]) {
		case '*': { cout << "closure "; string a(1, deneme[i + 1]); string b = tesp2(a); cout << b << endl; break; }
		case '|': {cout << "union " << endl; }
		case '^': {cout << "epsilon " << endl; }
		case '+': { cout << "artı "; string a(1, deneme[i + 1]); string b = tesp2(a); cout << b<<endl; break; }
		default: {
			if (i + 1 < deneme.length()) {
				string aa(1, deneme[i]); string bb(1, deneme[i + 1]);
				string a = tesp(aa, bb); cout << a; break;
			}
		}
		}
	}
	return 0;
}
string tesp(string a,string b) {
	string ascii[] = { "!", "#", "$", "%", "&", "'", "," ,"-", ".", "/","1", "2", "3", "4", "5", "6", "7", "8", "9", ":", ";", "<", "=", ">", "?", "@", "A", "B", "C", "D", "E", "F", "G" , "H", "I", "J", "K", "L", "M", "N", "O", "P" ,"Q" ,"R" ,"S" ,"T", "U", "V", "W","X" ,"Y" ,"Z" ,"[", "]" , "_", "`", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o" ,"p", "q","r", "s","t", "u", "v", "w", "x", "y", "z", "{", "}", "~", "", "€", "‚", "ƒ", "„", "†", "‡",  "‰", "Š", "‹", "Œ", "Ž", "‘", "'", "“", "”", "•", "–", "—", "˜", "™", "š", "›", "œ", "ž", "Ÿ", "¡", "¢", "£", "¤", "¥", "§",  "©", "ª", "«"  "¬", "¯", "°", "±", "²", "³", "´", "µ", "¶", "·", "¸", "¹", "º", "»", "¼", "½", "¾", "¿", "À", "Á", "Â", "Ã", "Ä", "Å", "Æ", "Ç", "È", "Ê", "Ë", "Ì", "Î", "Ï", "Ğ", "Ñ", "Ò", "Ó", "Ô", "Õ", "Ö", "×", "Ø","Ù", "Ú", "Û", "Ü", "İ", "Ş", "ß", "à", "â", "ã", "ä", "å", "ç", "è", "é", "ê", "ë", "ì", "í", "î", "ğ", "ñ", "ò", "ô", "õ", "ö", "÷", "ø", "ù", "ú", "û", "ü", "ı" ,"ş" ,"ÿ" };
	int asciiS = sizeof(ascii) / sizeof(ascii[0]);
	
	for (int i = 0; i < asciiS; i++) {
		if (a == ascii[i]) {
			break;
		}
		else if(a!=ascii[i]&&i==194)
			return " Geçersiz bir karakter girdiniz";
	}
	for (int i = 0; i < asciiS; i++) {
		if (b == ascii[i]) break;
		else if(b != ascii[i] && i==194 ){ 
			if(b=="*"|| b == "^" || b == "|" || b == "+"  )
				return " elemandan sonra operatör var\n"; }
	}
	return  " Concata geldik\n";
}
string tesp2(string a){
	string ascii[] = { "!", "#", "$", "%", "&", "'", "," ,"-", ".", "/","1", "2", "3", "4", "5", "6", "7", "8", "9", ":", ";", "<", "=", ">", "?", "@", "A", "B", "C", "D", "E", "F", "G" , "H", "I", "J", "K", "L", "M", "N", "O", "P" ,"Q" ,"R" ,"S" ,"T", "U", "V", "W","X" ,"Y" ,"Z" ,"[", "]" , "_", "`", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o" ,"p", "q","r", "s","t", "u", "v", "w", "x", "y", "z", "{", "}", "~", "", "€", "‚", "ƒ", "„", "†", "‡",  "‰", "Š", "‹", "Œ", "Ž", "‘", "'", "“", "”", "•", "–", "—", "˜", "™", "š", "›", "œ", "ž", "Ÿ", "¡", "¢", "£", "¤", "¥", "§",  "©", "ª", "«"  "¬", "¯", "°", "±", "²", "³", "´", "µ", "¶", "·", "¸", "¹", "º", "»", "¼", "½", "¾", "¿", "À", "Á", "Â", "Ã", "Ä", "Å", "Æ", "Ç", "È", "Ê", "Ë", "Ì", "Î", "Ï", "Ğ", "Ñ", "Ò", "Ó", "Ô", "Õ", "Ö", "×", "Ø","Ù", "Ú", "Û", "Ü", "İ", "Ş", "ß", "à", "â", "ã", "ä", "å", "ç", "è", "é", "ê", "ë", "ì", "í", "î", "ğ", "ñ", "ò", "ô", "õ", "ö", "÷", "ø", "ù", "ú", "û", "ü", "ı" ,"ş" ,"ÿ" };
	int asciiS = sizeof(ascii) / sizeof(ascii[0]);
	for (int i = 0; i < asciiS; i++) {
		if (a == ascii[i]) break;
		else if (a != ascii[i] && i == 194) {
			if (a == "*" || a == "^" || a == "|" || a == "+")
				return " iki operatör ard arda yazılmıştır \n";
		}
	}
	return  " Concata geldik \n";

}
string ParTespit(string regex) {
	
	vector<int> acikPar;
	vector<int> kapaliPar;
	vector<bool> esPar;
	for (int i = 0; i < regex.length(); i++)
	{
		string gecici(1, regex[i]);
		if (gecici == "(")
		{
			acikPar.push_back(i);
			kapaliPar.push_back(0);
			esPar.push_back(0);
		}
		if (gecici == ")")
		{
			int a = parBul(i, esPar);
			esPar[a] = 1;
			kapaliPar[a] = i;
			cout << "Kapalı Parantezin Eşi=" << acikPar[a] << "    Şu anki bulunduğumuz indis= " << i << endl;

		}
	}
	return "ok";
}
int parBul(int a,vector<bool> pKont){
	int eb = 0;
	for (int i = 0; i < pKont.size(); i++) 
	{
		if (pKont.at(i) == 0)
			eb = i;
	}
	return eb;
}
