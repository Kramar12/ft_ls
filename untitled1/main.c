#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

struct   s_ql
{
	char *cont;

	struct s_ql *next;
	struct s_ql *prev;
};

struct s_ql *prev(struct s_ql *s);
int     listsize(struct s_ql *s);
struct s_ql *new(char *data);
struct  s_ql    *spin(struct s_ql *s, int i, int code);



struct s_ql *verw(struct s_ql *s, int cols)
{
	struct s_ql *d;
	struct s_ql *u;
	int i;
	int j;
	int w;
	int l;
	int t;

	i = 0;
	j = 0;
	w = 0;
	l = 0;
	t = 0;

	d = s;
	l = listsize(s);
	while (1)
	{
		if (d->next)
		{
			d = d->next;
			w++;
		}
		if (w == l || !d->next)
			break ;
		t = i + cols;

		if (spin(s, t, 1) || t > l)
		{
			j++;
			while (s)
				s = s->prev;
			spin(s, cols,1);
		}
		else
			spin(s, cols, 1);


	}

	return (d);
}


char *ver(char *s, int cols)
{
	char *d;
	int i;
	int j;
	int w;

	i = 0;
	j = 0;
	w = 0;
	d = strdup(s);
	while (1)
	{
		d[w++] = s[i];
		if (w == strlen(s))
			break ;
		if (s[i + cols] == '\0' || (i + cols > strlen(s)))
			i = ++j;
		else
			i += cols;
	}
	return (d);
}

main()
{
	char *s = "123456789123456789";
	char *d;
	int i = 0;

	while (s[i])
		if (i % 3 || i == 0)
			printf("%c\t", s[i++]);
		else
			printf("\n%c\t", s[i++]);

	i = 0;
	int j = 0;
	int w = 0;

	d = ver(s, 6);
	printf("\n\n");
	i = 0;

	while (d[i])
		if (i % 3 || i == 0)
			printf("%c\t", d[i++]);
		else
			printf("\n%c\t", d[i++]);


	struct s_ql *list;
	struct s_ql *l2;

	list = new("1");
	list->next = new("2");
	list->next->next = new("3");
	list->next->next->next = new("4");
	list->next->next->next->next = new("5");
	list->next->next->next->next->next = new("6");
	list->next->next->next->next->next->next = new("7");
	list->next->next->next->next->next->next->next = new("8");
	list->next->next->next->next->next->next->next->next = new("9");

	list = prev(list);
	l2 = verw(list, 3);



}

struct s_ql *prev(struct s_ql *s)
{
	struct s_ql *d;

	d = s;
	s->next->prev = s;
	while (s)
	{
		if (s->next)
		{
			s->next->prev = s;
			s = s->next;
		}
		else
			break ;
	}
	while (1)
	{
		if (s->prev)
			s = s->prev;
		else
			break ;
	}
	return (s);
}
int     listsize(struct s_ql *s)
{
	int i;

	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}

struct s_ql *new(char *data)
{
	struct s_ql *root;
	int i = 0;

	root = (struct s_ql *)malloc(sizeof(struct s_ql));
	if (data)
	{
		root->cont = (char *)malloc(sizeof(char) * (strlen(data) + 1));
		while (data[i])
		{
			root->cont[i] = data[i];
			i++;
		}
		root->cont[i] = '\0';
	}
	else
		root->cont = NULL;
	root->prev = NULL;
	root->next = NULL;
	return (root);
}

struct  s_ql    *spin(struct s_ql *s, int i, int code)
{
	while (i > 0)
	{
		if (code == 1)
			if (s && s->next)
				s = s->next;
		if (code == 2)
			if (s->prev)
				s = s->prev;
		i--;
	}

	return (s);
}



//struct list
//{
//	int data;
//	struct list *next;
//};
//
//struct list * insert( struct list *node, int data )
//{
//	struct list *tmp = malloc( sizeof( struct list ) );
//
//	if ( tmp != NULL )
//	{
//		tmp->data = data;
//
//		if ( node != NULL )
//		{
//			tmp->next = node->next;
//			node->next = tmp;
//		}
//		else
//		{
//			tmp->next = NULL;
//		}
//	}
//
//	return tmp;
//}
//
//void display( struct list *node )
//{
//	for ( ; node != NULL; node = node->next ) printf( "%d ", node->data );
//}
//
//struct list * clear( struct list *node )
//{
//	while ( node != NULL )
//	{
//		struct list *tmp = node;
//		node = node->next;
//
//		free( tmp );
//	}
//
//	return node;
//}
//
//struct list * sort( struct list *root )
//{
//	struct list *new_root;
//	struct list *node;
//	struct list *current;
//
//	new_root = NULL;
//
//	while ( root != NULL )
//	{
//		node = root;
//		root = root->next;
//
//		if ( new_root == NULL || node->data < new_root->data )
//		{
//			node->next = new_root;
//			new_root = node;
//		}
//		else
//		{
//			current = new_root;
//			while ( current->next != NULL && node->data >= current->next->data)
//				current = current->next;
//			node->next = current->next;
//			current->next = node;
//		}
//	}
//
//	return new_root;
//}
//
//#define N   10
//
//int main()
//{
//	char *a[N] = {7, 3, 2, 1, 0, 0, 0, 5, 9, 4};
//	struct list *root = NULL;
//	struct list **tmp = &root;
//
//	for ( size_t i = 0; i < N; i++ )
//	{
//		*tmp = insert( *tmp, a[i] );
//		tmp = &( *tmp )->next;
//	}
//
//	display( root );
//	printf( "\n" );
//
//	root = sort( root );
//
//	display( root );
//	printf( "\n" );
//
//	root = clear( root );
//}