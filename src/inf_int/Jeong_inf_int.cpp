#include "inf_int.h"

/*
Originally written by
��ǻ�Ͱ��к�
������
*/

inf_int::inf_int()
{
	this->digits=new char[2];	// �����Ҵ�

	this->digits[0]='0';		// default �� 0 ����
	this->digits[1]='\0';
	this->length=1;
	this->thesign=true;
}

inf_int::inf_int(int n){
	char buf[100];

	if(n<0){		// ���� ó��
		this->thesign=false;
		n=-n;
	}else{
		this->thesign=true;
	}

	int i=0;
	while(n>0){			// ���ڸ� ���ڿ��� ��ȯ�ϴ� ����
		buf[i]=n%10+'0';

		n/=10;
		i++;
	}

	if(i==0){	// ������ ������ 0�� ���
		new (this) inf_int();	// ������ ��ȣ��...gcc���� �����Ͽ����� �ִٰ� ��. inf_int()�� ��� ������ �ν��Ͻ��� ������. 
	}else{
		buf[i]='\0';

		this->digits=new char[i+1];
		this->length=i;
		strcpy(this->digits, buf);
	}
}

inf_int::inf_int(const char* str)
{
	// to be filled 
	// ��ȣ ó�� 
	// "100"�� ���Դٸ� ���� ǥ���� �°� "001"�� ��ȯ
	// ex) "-1053" -> thesign=false, digits="3501", len=4
}

inf_int::inf_int(const inf_int& a){
	this->digits=new char[a.length+1];

	strcpy(this->digits, a.digits);
	this->length=a.length;
	this->thesign=a.thesign;
}

inf_int::~inf_int(){
	delete digits;		// �޸� �Ҵ� ����
}

inf_int& inf_int::operator=(const inf_int& a)
{
	if(this->digits) {
		delete this->digits;		// �̹� ���ڿ��� ���� ��� ����.
	}
	this->digits=new char[a.length+1];

	strcpy(this->digits, a.digits);
	this->length=a.length;
	this->thesign=a.thesign;

	return *this; 
}

bool operator==(const inf_int& a, const inf_int& b)
{
    // we assume 0 is always positive.
    if ( (strcmp(a.digits , b.digits)==0) && a.thesign==b.thesign )	// ��ȣ�� ����, ������ ��ġ�ؾ���.
        return true;
    return false;
}

bool operator!=(const inf_int& a, const inf_int& b)
{
	return !operator==(a, b);
}

bool operator>(const inf_int& a, const inf_int& b)
{
	// to be filled
	// ���밪 ��
	// �� �� ����� ��� ���� ���� ���� �״�� return
	// �� �� ������ ��� ���� ���� ���� �����Ͽ� return
	// ��ȣ�� �ٸ� ���, a�� ����� ��� b�� ����, a�� ������ ��� b�� ����̱⿡ a�� ��ȣ�������� ��ȯ�ϸ� ��
}

bool operator<(const inf_int& a, const inf_int& b)
{
	if(operator>(a, b) || operator==(a, b)) {
		return false;
	}else{
		return true;
	}
}

inf_int operator+(const inf_int& a, const inf_int& b)
{
	inf_int c;
	unsigned int i;

	if(a.thesign==b.thesign){	// ������ ��ȣ�� ���� ��� + �����ڷ� ����
		for(i=0; i<a.length; i++){
			c.Add(a.digits[i], i+1);
		}	
		for(i=0; i<b.length; i++){
			c.Add(b.digits[i], i+1);
		}

		c.thesign=a.thesign;	

		return c;
	}else{	// ������ ��ȣ�� �ٸ� ��� - �����ڷ� ����
		c=b;
		c.thesign=a.thesign;

		return a-c;
	}
}

inf_int operator-(const inf_int& a, const inf_int& b)
{
	// to be filled
}

inf_int operator*(const inf_int& a, const inf_int& b)
{
    // to be filled
}


ostream& operator<<(ostream& out, const inf_int& a)
{
	int i;

	if(a.thesign==false){
		out<<'-';
	}
	for(i=a.length-1; i>=0; i--){
		out<<a.digits[i];
	}
	return out;
}

void inf_int::Add(const char num, const unsigned int index)	// a�� index �ڸ����� n�� ���Ѵ�. 0<=n<=9, ex) a�� 391�϶�, Add(a, 2, 2)�� ����� 411
{
	if(this->length<index){
		this->digits=(char*)realloc(this->digits, index+1);

		if(this->digits==NULL){		// �Ҵ� ���� ����ó��
			cout<<"Memory reallocation failed, the program will terminate."<<endl;

			exit(0);
		}

		this->length=index;					// ���� ����
		this->digits[this->length]='\0';	// �ι��� ����
	}

	if(this->digits[index-1]<'0'){	// ���� ���� '0'���� ���� �ƽ�Ű���� ��� 0���� ä��. �������� �ʾҴ� ���ο� �ڸ����� ��� �߻�
		this->digits[index-1]='0';
	}

	this->digits[index-1]+=num-'0';	// �� ����


	if(this->digits[index-1]>'9'){	// �ڸ��ø��� �߻��� ���
		this->digits[index-1]-=10;	// ���� �ڸ������� (�ƽ�Ű��) 10�� ����
		Add('1', index+1);			// ���ڸ��� 1�� ���Ѵ�
	}
}

