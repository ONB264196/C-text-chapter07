#include<stdio.h>
#define _0711

#ifdef _0701
int main(void) 
{
	int n;
	
	printf("sizeof 1 = %u\n", (unsigned)sizeof 1);  //int�^ = 4
	printf("sizeof+1 = %u\n", sizeof +1);           //int�^ = 4
	printf("sizeof-1 = %u\n", sizeof -1);           //int�^ = 4
	
	printf("sizeof(unsigned)-1  = %u\n", sizeof(unsigned)-1);  //[int�^ - 1] �� 4 - 1 = 3
	printf("sizeof(double)-1    = %u\n", sizeof(double)-1);    //[double�^ - 1] �� 8 - 1 = 7
	printf("sizeof((double)-1)) = %u\n", sizeof((double)-1));  //double�^��int�^�̌v�Z��bouble�^�Ɋi�グ = 8
	
	printf("sizeof n+2   = %u\n", sizeof n + 2);     //[int�^ + 2] �� 4 + 2 = 6
	printf("sizeof(n+2)  = %u\n", sizeof(n + 2));    //(n+2)��int�^ = 4
	printf("sizeof n+2.0 = %u\n", sizeof(n + 2.0));  //int�^��double�^�̌v�Z��bouble�^�Ɋi�グ = 8

	return 0;
}
#endif

#ifdef _0702
unsigned expo(unsigned n)
{
	unsigned pw = 1;
	while (n--) {
	    pw *= 2;
	}
	return(pw);
}

int main(void) 
{
	unsigned n_mul, n_div, L_shift, R_shift;
	unsigned a, n;

	printf("��������͂��Ă��������F");    scanf_s("%u", &a);
	printf("�����V�t�g���܂����F");    scanf_s("%u", &n);

	n_mul = a * expo(n);
	n_div = a / expo(n);
	L_shift = a << n;
	R_shift = a >> n;

	printf("%u �~ (2��%u��) = %u\n", a, n, n_mul);
	printf("%u << %u = %u\n", a, n, L_shift);
	putchar('\n');
	printf("%u �� (2��%u��) = %u\n", a, n, n_div);
	printf("%u >> %u = %u\n", a, n, R_shift);

	return 0;
}
#endif

#ifdef _0703
int count_bits(unsigned x)
{
	int bits = 0;
	while (x) {
		if (x & 1U) bits++;
		x >>= 1;
	}
	return bits;
}

int int_bits()
{
	return count_bits(~0U);
}

void print_bits(unsigned x)
{
	int i;
	for (i = int_bits() - 1; i >= 0; i--)
		putchar(((x >> i) & 1U) ? '1' : '0');
}
unsigned Rrotate(unsigned x, int n)
{
	int i = int_bits();
	return((x >> n | (x << (i - n))));
}
unsigned Lrotate(unsigned x, int n)
{
	int i = int_bits();
	return((x << n | (x >> (i - n))));
}
int main(void)
{
	unsigned x, n;

	printf("���̐�������͂��Ă��������F");    scanf_s("%u", &x);
	printf("���r�b�g��]���܂����F");    scanf_s("%u", &n);

	printf("\n����       �F"); print_bits(x);
	printf("\n�E��%d��]  �F", n); print_bits(Rrotate(x, n));
	printf("\n����%d��]  �F", n); print_bits(Lrotate(x, n));

	return 0;
}
#endif

#ifdef _0704
int count_bits(unsigned x)
{
	int bits = 0;
	while (x) {
		if (x & 1U) bits++;
		x >>= 1;
	}
	return bits;
}

int int_bits()
{
	return count_bits(~0U);
}

void print_bits(unsigned x)
{
	int i;
	for (i = int_bits() - 1; i >= 0; i--)
		putchar(((x >> i) & 1U) ? '1' : '0');
}
unsigned Lrotate(unsigned x, int n)
{
	int i = int_bits();
	return((x << n | (x >> (i - n))));
}
unsigned set(unsigned x, int pos) {
	return(x | Lrotate(1U, pos - 1));
}
unsigned reset(unsigned x, int pos) {
	return(x & ~Lrotate(1U, pos - 1));
}
unsigned inverse(unsigned x, int pos) {
	return(x ^ Lrotate(1U, pos - 1));
}

int main(void)
{
	unsigned x, pos;

	printf("���̐�������͂��Ă��������F");    scanf_s("%u", &x);
	printf("���r�b�g�ڂ�ύX���܂����F");    scanf_s("%u", &pos);

	printf("\n����              �F"); print_bits(x);
	printf("\n%d�r�b�g�ڂ�1�ɕύX�F", pos); print_bits(set(x, pos));
	printf("\n%d�r�b�g�ڂ�0�ɕύX�F", pos); print_bits(reset(x, pos));
	printf("\n%d�r�b�g�ڂ𔽓]   �F", pos); print_bits(inverse(x, pos));

	return 0;
}
#endif

#ifdef _0705
int count_bits(unsigned x)
{
	int bits = 0;
	while (x) {
		if (x & 1U) bits++;
		x >>= 1;
	}
	return bits;
}

int int_bits()
{
	return count_bits(~0U);
}

void print_bits(unsigned x)
{
	int i;
	for (i = int_bits() - 1; i >= 0; i--)
		putchar(((x >> i) & 1U) ? '1' : '0');
}
unsigned Lrotate(unsigned x, int n)
{
	int i = int_bits();
	return((x << n | (x >> (i - n))));
}
unsigned set_n(unsigned x, int pos, int n) {
	for (int i = pos; i <= (pos + n); i++) {
		x = (x | Lrotate(1U, i));
	}
	return x;
}
unsigned reset_n(unsigned x, int pos, int n) {
	for (int i = pos; i <= (pos + n); i++) {
		x = (x & ~Lrotate(1U, i));
	}
	return x;
}
unsigned inverse_n(unsigned x, int pos, int n) {
	for (int i = pos; i <= (pos + n); i++) {
		x = (x ^ Lrotate(1U, i));
	}
	return x;
}

int main(void)
{
	int x, pos, n;

	printf("���̐�������͂��Ă��������F");    scanf_s("%u", &x);
	printf("���r�b�g�ڂ�ύX���܂����F");    scanf_s("%u", &pos);
	printf("���ύX���܂����F");    scanf_s("%u", &n);

	printf("\n����:"); print_bits(x);
	printf("\n%d�r�b�g�ڂ���%d�̃r�b�g��1�ɕύX�F", pos, n);
	print_bits(set_n(x, pos, n));
	printf("\n%d�r�b�g�ڂ���%d�̃r�b�g��0�ɕύX�F", pos, n);
	print_bits(reset_n(x, pos, n));
	printf("\n%d�r�b�g�ڂ���%d�̃r�b�g�𔽓]   �F", pos, n);
	print_bits(inverse_n(x, pos, n));

	return 0;
}
#endif

#ifdef _0706
/*Visual Studio�ɂ����Ă͊m�F�s��*/
int main(void)
{
	int x, y, z;
	unsigned X, Y, Z;

	x = 30000;  X = 30000;
	y = 40000;  Y = 40000;
	z = x + y;  Z = X + Y;

	printf("%d\n%d", z, Z);

	return 0;
}
#endif

#ifdef _0707
int main(void)
{
	float a;
	double b;
	long double c;
	
	printf("float�^       : ");	scanf_s("%f", &a);
	printf("double�^      : "); scanf_s("%lf", &b);
	printf("long double�^ : "); scanf_s("%Lf", &c);
	putchar('\n');

	printf("float�^       : %f\n", a);
	printf("double�^      : %f\n", b);
	printf("long double�^ : %Lf\n", c);

	return 0;
}
#endif

#ifdef _0708
int main(void)
{
	printf("float�^       : %d\n", sizeof(float));
	printf("double�^      : %d\n", sizeof(double));
	printf("long double�^ : %d\n", sizeof(long double));

	return 0;
}
#endif

#ifdef _0709
#include<math.h>
int main(void)
{
	double m2;
	printf("�����`�̖ʐ� : "); scanf_s("%lf", &m2);

	printf("��ӂ̒�����%.3f�ł��B", sqrt(m2));

	return 0;
}
#endif

#ifdef _0710
int main(void)
{
	float a = 0;
	float x = 0;
	int i = 0;

	while (i <= 100) {
		a += 0.01f; x = i / 100.0;
		printf("x = %f   ", a); printf("x = %f", x);
		putchar('\n');
		i++;
	}

	return 0;
}
#endif

#ifdef _0711
int main(void)
{
	float X = 0;
	float Y = 0;
	float x = 0;
	float y = 0;
	
	printf("List7-11\n");
	for (X = 0.0; X <= 1.0; X += 0.01) {
		Y += X;
		printf("x = %f\n", Y);
	}
	putchar('\n');

	printf("List7-11\n");
	for (int i = 0; i <= 100; i++) {
		x = i / 100.0;
		y += x;
		printf("x = %f\n", y);
	}


	return 0;
}
#endif

