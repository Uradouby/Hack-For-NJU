#include<iostream>
#include<fstream>
using namespace std;

class HASH
{
	public:
//=====================================================================================	
		void ht_insert(char *s)
		{
			to_lower(s);
			int i1 = f(s);
			if (hash1[i1] == NULL)
			{
				node *p = new node;
				int l = 0;
				for (int i = 0; s[i] != '\0'; i++) l++;
				for (int i = 0; i <= l + 1; i++)
					p->s[i] = s[i];
				p->next = NULL;
				hash1[i1] = p;
			}
			else
			{
				int flag = 0;
				node *head = hash1[i1];
				while (head)
				{
					if (str_equal(s, head->s) == 1)
					{		
						flag = 1;
						break;
					}
					head = head->next;
				}
				if (flag == 0)
				{
					node *p = new node;
					int l = 0;
					for (int i = 0; s[i] != '\0'; i++) l++;
					for (int i = 0; i <= l + 1; i++)
						p->s[i] = s[i];
					p->next = hash1[i1];
					hash1[i1] = p;
				}
			}
		}
//=====================================================================================	
		int ht_find(char *s)
		{
			to_lower(s);
			int i1 = f(s);
			node *p = hash1[i1];
			while (p != NULL)
			{
				if (str_equal(s, p->s) == 1) return 1;
				p = p->next;
			}
			return 0;
		}
//=====================================================================================	
		 HASH()
		{
			 for (int i = 0; i <= 233; i++)
				 hash1[i] = NULL;
		}

	private:

		struct node
		{
			char s[200];
			node *next;
		};
		node *hash1[2334];
//=====================================================================================	
		int str_equal(char *s1, char *s2)
		{
			int l1 = 0, l2 = 0;
			for (int i = 0; s1[i] != '\0'; i++) l1++;
			for (int i = 0; s2[i] != '\0'; i++) l2++;
			if (l1 != l2) return 0;
			for (int i = 0; i <= l1; i++)
				if (s1[i] != s2[i]) return 0;
			return 1;
		}
//=====================================================================================	
		void to_lower(char *s)
		{
			for (int i = 0; s[i] != '\0'; i++)
				if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
		}
//=====================================================================================	
		int f(char *s)
		{
			int res = 0;
			for (char *c = s; *c != '\0'; ++c)
			{
				res = res * 26 + (*c - 'a');
				res = res % 2333;
			}
			return res;
		}

};



int main()
{
	HASH a;
	int l = -1;
	char str[2000], str1[100], str2[100];

	ifstream fin("article.txt");
	fin.getline(str, 2000);
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] <= 'z' && str[i] >= 'a')
		{
			l++;
			str1[l] = str[i];
		}
		else
			if (l != -1)
			{
				str1[l + 1] = '\0';
				a.ht_insert(str1);
				l = -1;
			}
	}
	if (l != -1)
	{
		str1[l + 1] = '\0';
		a.ht_insert(str1);
	}
	fin.close();

	while (cin >> str2)
	{
		if (a.ht_find(str2) == 1) cout << "True" << endl;
		else cout << "False" << endl;
	}

	return 0;
}





