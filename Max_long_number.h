#pragma once
string find_max(string s1, string s2, string s3)
{
	int n1, n2, n3;
	n1 = s1.length(); n2 = s2.length(); n3 = s3.length();

	if (n1 == n2 and n1 == n3)
		if (s1 > s2 and s1 > s3) return s1;
		else
			if (s2 > s3) return s2;
			else return s3;

	if (n1 == n2 and n2 > n3)
		if (s1 > s2) return s1;
		else return s2;
	if (n1 == n3 and n3 > n2)
		if (s1 > s3) return s1;
		else return s3;
	if (n3 == n2 and n2 > n1)
		if (s3 > s2) return s3;
		else return s2;

	if (n1 > n2 and n1 > n3) return s1;
	else
		if (n2 > n3) return s2;
		else return s3;
	if (n2 > n1 and n2 > n3) return s2;
	else
		if (n1 > n3) return s1;
		else return s3;
	if (n3 > n2 and n3 > n1) return s3;
	else
		if (n2 > n1) return s2;
		else return s1;
}